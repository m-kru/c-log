#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

#ifndef LOG_STREAM
	#define LOG_STREAM stderr
#endif

#ifndef LOG_PREFIX
	#define LOG_PREFIX 
#endif

#ifdef LOG_COLOR
	#define LOG_COLOR_RED     "\x1b[31m"
	#define LOG_COLOR_GREEN   "\x1b[32m"
	#define LOG_COLOR_YELLOW  "\x1b[33m"
	#define LOG_COLOR_BLUE    "\x1b[34m"
	#define LOG_COLOR_MAGENTA "\x1b[35m"
	#define LOG_COLOR_CYAN    "\x1b[36m"
	#define LOG_COLOR_RESET   "\x1b[0m"
#else
	#define LOG_COLOR_RED     ""
	#define LOG_COLOR_GREEN   ""
	#define LOG_COLOR_YELLOW  ""
	#define LOG_COLOR_BLUE    ""
	#define LOG_COLOR_MAGENTA ""
	#define LOG_COLOR_CYAN    ""
	#define LOG_COLOR_RESET   ""
#endif

#ifdef LOG_SOURCE
	#define info(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_BLUE "INF " LOG_COLOR_RESET \
			"%s:%d: "\
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
#else
	#define info(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_BLUE "INF " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)

#endif

#endif
