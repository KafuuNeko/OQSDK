#include "kmp.h"

#include <string.h>
#include <memory>

std::unique_ptr<size_t[]> KMP_MakeNext(const char* substr, size_t len, bool optimize) noexcept
{
	auto next = std::make_unique<size_t[]>(len);
	next[0] = kmp::npos;

	size_t j = 0;
	size_t k = next[j];

	while (j < len - 1)
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

size_t kmp::find(const char* findstr, const char* substr) noexcept
{
	size_t findLen = strlen(findstr), subsLen = strlen(substr);

	if (subsLen == 0 || findLen < subsLen) return kmp::npos;

	auto next = KMP_MakeNext(substr, subsLen, false);

	size_t j = 0, k = 0;

	while (j < findLen && (k == kmp::npos || k < subsLen))
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
	return (k == subsLen) ? (j - k) : kmp::npos;
}

size_t kmp::find_count(const char* findstr, const char* substr) noexcept
{
	size_t findLen = strlen(findstr), subsLen = strlen(substr);

	if (subsLen == 0 || findLen < subsLen) return kmp::npos;

	auto next = KMP_MakeNext(substr, subsLen, false);

	size_t count = 0;

	size_t j = 0, k = 0;
	while (j < findLen)
	{
		if (k == kmp::npos || findstr[j] == substr[k])
		{
			++j;

			if (k == kmp::npos)		k = 0;
			else					++k;

			if (k == subsLen)
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


