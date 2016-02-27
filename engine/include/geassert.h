#ifndef GE_ASSERT_H_
#define GE_ASSERT_H_

#include <cstdio>

#ifdef _MSC_VER
#define GE_DEBUG_BREAK() __debugbreak()
#else
#include <csignal>
#define GE_DEBUG_BREAK() raise(SIGTRAP)
#endif // GE_DEBUG_BREAK()

#define GE_ASSERT(cond, msg) __GE_ASSERT(cond, msg, __FILE__, __LINE__)

#define __GE_ASSERT(cond, msg, file, line)\
do\
{\
	if (!(cond))\
	{\
		printf("%s:%i Assertion failed \"%s\"\n", file, line, msg);\
		GE_DEBUG_BREAK();\
	}\
} while (0)

#endif /* GE_ASSERT_H_ */