#include "kmp.h"

#include <string.h>
#include <memory>

std::unique_ptr<size_t[]> KMP_MakeNext(const std::string &substr, bool optimize) noexcept
{
	auto next = std::make_unique<size_t[]>(substr.length());
	next[0] = kmp::npos;

	size_t j = 0;
	size_t k = next[j];

	while (j < substr.length() - 1)
	{
		if (k == kmp::npos || substr[j] == substr[k])
		{
			++j;

			if (k == kmp::npos)						k = 0;
			else									++k;

			if (optimize && substr[j] == substr[k])	next[j] = next[k];
			else									next[j] = k;

		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

size_t kmp::find(const std::string &findstr, const std::string &substr) noexcept
{
	if (substr.length() == 0 || findstr.length() < substr.length()) return kmp::npos;

	auto next = KMP_MakeNext(substr, false);

	size_t j = 0, k = 0;

	while (j < findstr.length() && (k == kmp::npos || k < substr.length()))
	{
		if (k == kmp::npos || findstr[j] == substr[k])
		{
			++j;
			if (k == kmp::npos)	k = 0;
			else				++k;
		}
		else
		{
			k = next[k];
		}
	}
	return (k == substr.length()) ? (j - k) : kmp::npos;
}

size_t kmp::find_count(const std::string &findstr, const std::string &substr) noexcept
{
	if (substr.length() == 0 || findstr.length() < substr.length()) return kmp::npos;

	auto next = KMP_MakeNext(substr, false);

	size_t count = 0;

	size_t j = 0, k = 0;
	while (j < findstr.length())
	{
		if (k == kmp::npos || findstr[j] == substr[k])
		{
			++j;

			if (k == kmp::npos)		k = 0;
			else					++k;

			if (k == substr.length())
			{
				++count;
				k = next[k - 1];
				--j;
			}
		}
		else
		{
			k = next[k];
		}
	}

	return count;
}


