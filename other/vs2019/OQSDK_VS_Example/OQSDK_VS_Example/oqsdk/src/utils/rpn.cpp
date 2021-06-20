#include "rpn.h"
#include <stack>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

/**
** ת������16λ����16λ���µĽ���Ϊʮ������
** @param str_beg ��ʼ������
** @param str_end ����������
** @param bit ���ƣ�2-16��
*/
template <class _iter>
static int64_t to_dec(_iter str_beg, _iter str_end, int bit) noexcept
{
	int64_t result = 0;
	for (; str_beg != str_end; ++str_beg)
	{
		int64_t ch = static_cast<int64_t>(*str_beg);
		result *= bit;
		if (ch >= '0' && ch <= '9')
		{
			result += ch - static_cast <int32_t>('0');
		}
		else if (ch >= 'a' && ch <= 'f')
		{
			result += ch - static_cast <int32_t>('a') + 10;
		}
		else if (ch >= 'A' && ch <= 'F')
		{
			result += ch - static_cast <int32_t>('A') + 10;
		}
		else
		{
			return 0;
		}
	}
	return result;
}

/**
** �ж��ַ��Ƿ��Ǻ������йص��ַ�
** @param ch �����ַ�
** @return �йط���true�����򷵻�false
*/
constexpr bool is_number_char(char ch) noexcept
{
	return (ch >= '0' && ch <= '9')	   //������
		|| (ch >= 'a' && ch <= 'f') //�Ƿ���ʮ�������ַ�
		|| (ch >= 'A' && ch <= 'F') //�Ƿ���ʮ�������ַ�
		|| (ch == 'O' || ch == 'H') //�Ƿ���λ��Ƿ�����Ƿ�B�Ѿ����ж��Ƿ�ʮ��λ��ʱ���ж��ˣ�
		|| (ch == '.');			   //�Ƿ���С����
}

/**
** �����ֻ�����������ת����double����
** @param buf ������ָ��
** @param sz ��������Ч����
*/
inline double to_double(const std::string& buf) noexcept
{
	size_t sz = buf.length();
	switch (buf[sz - 1])
	{
	case 'B':
		return static_cast<double>(to_dec(buf.cbegin(), buf.cend() - 1, 2));

	case 'O':
		return static_cast<double>(to_dec(buf.cbegin(), buf.cend() - 1, 8));

	case 'H':
		return static_cast<double>(to_dec(buf.cbegin(), buf.cend() - 1, 16));

	default:
		return atof(buf.c_str());
	}
}

/**
** ��������������ȡ����ջ��Ԫ��
** @return ��stack���Ԫ�ز����������򷵻�false��ʾ��ȡʧ��*/
template <typename T>
inline bool rpn_top2(std::stack<T>& rpn, T& e, T& s) noexcept
{
	if (rpn.size() < 2)
	{
		return false;
	}

	e = rpn.top();
	rpn.pop();
	s = rpn.top();
	rpn.pop();

	return true;
}

/**
** �ж��ַ��Ƿ�Ϊ��ѧ������
** @param ch Ҫ�жϵ��ַ�
** @return ��Ϊ��ѧ�������򷵻�true�����򷵻�false
*/
constexpr bool is_math_notation(char ch) noexcept
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^';
}

/**
** ��ȡָ�����������ȼ�
** @param ch ��ѧ�������ַ�
** @return ���ȼ�
*/
constexpr int get_math_notation_priority(char ch) noexcept
{
	if (ch == '(')
		return 0;
	if (ch == '+' || ch == '-')
		return 1;
	if (ch == '*' || ch == '/' || ch == '%')
		return 2;
	if (ch == '^')
		return 3;
	return -1;
}

/**
** �����沨�����ʽ
** @param rpn_exp �沨�����ʽ��
** @param exp_len �沨�����ʽ���ĳ���
** @return �������ռ����� */
bool rpn::calculate(const std::string& rpn_exp, double & result) noexcept
{
	std::stack<double> rpn;
	std::string number_buf;

	for (auto iter = rpn_exp.begin(); iter != rpn_exp.end(); ++iter)
	{
		if (*iter == ' ')
		{
			//�����ո������ֻ���������������ת��ת�����ֻ������ڵ����ݳ�Double���ͣ�����ջ
			if (!number_buf.empty())
			{
				rpn.push(to_double(number_buf));
				number_buf.clear();
			}
		}
		else if (is_number_char(*iter))
		{
			//���뵽���ֻ�����
			number_buf.push_back(*iter);
		}
		else
		{
			//e��stack��һ�ε�����ֵ��s��stack�ڶ��ε�����ֵ
			double s, e;
			switch (*iter)
			{
			case '+':
				if (!rpn_top2(rpn, e, s))
					return false; //���ʽ����
				rpn.push(s + e);
				break;

			case '-':
				if (!rpn_top2(rpn, e, s))
					return false; //���ʽ����
				rpn.push(s - e);
				break;

			case '*':
				if (!rpn_top2(rpn, e, s))
					return false; //���ʽ����
				rpn.push(s * e);
				break;

			case '/':
				if (!rpn_top2(rpn, e, s) || e == 0)
					return false; //��������Ϊ0
				rpn.push(s / e);
				break;

			case '%':
				if (!rpn_top2(rpn, e, s) || e == 0)
					return false; //��������Ϊ0
				rpn.push(static_cast<double>(static_cast<int64_t>(s) % static_cast<int64_t>(e)));
				break;

			case '^':
				if (!rpn_top2(rpn, e, s))
					return false; //���ʽ����
				rpn.push(pow(s, e));
				break;
			}
		}
	}

	//���������Ϻ�stackʣ��ĳ�Ա����Ϊ1��ʧ��
	if (rpn.size() != 1)
		return false; //���ʽ����

	result = rpn.top();

	return true;
}

/**
** �������� �������ַ�
** �ڽ���ѧ���ʽ����Ϊ�沨�����ʽʱ��������ѧ������ʱ����
** @param result ���
** @param notation �����Stack
** @param new_ch ���ַ�
*/
static void make_rpn_dispose_new_char(std::string& result, std::stack<char>& notation, char new_ch) noexcept
{
	int priority = get_math_notation_priority(new_ch);

	while (!notation.empty())
	{
		//���������^����������˳���Ǵ��ҵ���
		if (new_ch == '^' && new_ch == notation.top()) break;
		//�����ǰ��ջ��������ȼ���������������ȼ��������ѭ��
		if (get_math_notation_priority(notation.top()) < priority) break;

		//��ջ��������ȼ���������������ȼ������ݹ������ȼ����ڵ��ڵĵ�ȫ����ջ
		result.push_back(notation.top());
		result.push_back(' ');
		notation.pop();
	}

	notation.push(new_ch);
}

/**
** ��һ����ѧ���ʽ����Ϊ�沨�����ʽ
** @param _math_exp ���ʽ��
** @param _exp_len ���ʽ���ĳ���
** @return �����沨�����ʽ */
std::string rpn::make(const std::string& math_exp) noexcept
{
	bool first = true;

	std::stack<char> notation;
	std::string result;

	auto iter_end = math_exp.end();
	for (auto iter = math_exp.begin(); iter != iter_end; ++iter)
	{
		if (*iter == ' ')
			continue;

		//��ͷ��һ����Ч����
		if (first)
		{
			//�����ͷ��һ����Ч������+����-�����ڿ�ͷ��һ��0
			if (*iter == '-' || *iter == '+')
			{
				result.push_back('0');
				result.push_back(' ');
			}

			first = false;
		}

		//���ڱ�ʶ�Ƿ�׷�ӹ����֣���׷�ӹ����֣�����Ҫ����ɺ���ĩβ����ո�
		bool flag = false;

		while (is_number_char(*iter) || *iter == ' ')
		{
			if (*iter != ' ')
			{
				result.push_back(*iter);
				flag = true;
			}

			if (++iter == iter_end)
				break;
		}

		if (flag) //���׷�ӹ����֣����ڽ��β������ո�
			result.push_back(' ');

		if (iter == iter_end)
			break;

		if (*iter == ')')
		{
			//������������ţ��򲻶ϵ�����ѧ������ջ�з��ţ�ֱ�����������Ż�ȫ������
			while (!notation.empty())
			{
				char top_ch = notation.top();
				notation.pop();
				//���������ţ��˳�ѭ��
				if (top_ch == '(')
					break;
				//��������������������
				result.push_back(top_ch);
				result.push_back(' ');
			}
		}
		else if (*iter == '(')
		{
			//�����ţ�������ֱ�Ӽ���
			notation.push(*iter);
		}
		else if (is_math_notation(*iter))
		{
			make_rpn_dispose_new_char(result, notation, *iter);
		}
	}

	//��������ʽ�ַ��������ջ�ڻ��в������ݣ���ô���γ�ջ�����뵽���
	while (!notation.empty())
	{
		result.push_back(notation.top());
		result.push_back(' ');
		notation.pop();
	}

	return result;
}
