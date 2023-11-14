#ifndef _LOG_H_
#define _LOG_H_

#include <stdio.h>

typedef struct {
	char str[32];
} log_string_t;

#ifndef LOG_STREAM
	#define LOG_STREAM stderr
#endif

#ifndef LOG_PREFIX
	#define LOG_PREFIX 
#endif

// Black        "\x1b[30m"
// Red          "\x1b[31m"
// Green        "\x1b[32m"
// Yellow       "\x1b[33m"
// Blue         "\x1b[34m"
// Magenta      "\x1b[35m"
// Cyan         "\x1b[36m"
// Bright Black "\x1b[90m"
#ifdef LOG_COLOR
	#define LOG_COLOR_ERR       "\x1b[31m"
	#define LOG_COLOR_WRN       "\x1b[33m"
	#define LOG_COLOR_INF       "\x1b[32m"
	#define LOG_COLOR_DBG       "\x1b[34m"
	#define LOG_COLOR_TRC       "\x1b[36m"
	#define LOG_COLOR_FILE_LINE "\x1b[90m"
	#define LOG_COLOR_RESET     "\x1b[0m"
#else
	#define LOG_COLOR_ERR       ""
	#define LOG_COLOR_WRN       ""
	#define LOG_COLOR_INF       ""
	#define LOG_COLOR_DBG       ""
	#define LOG_COLOR_TRC       ""
	#define LOG_COLOR_FILE_LINE ""
	#define LOG_COLOR_RESET     ""
#endif

#ifdef LOG_SOURCE
	#define error(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_ERR "ERR " \
			LOG_COLOR_FILE_LINE "%s:%d " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
	#define warn(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_WRN "WRN " LOG_COLOR_RESET \
			"%s:%d: "\
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
	#define info(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_INF "INF " LOG_COLOR_RESET \
			"%s:%d "\
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
	#define debug(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_DBG "DBG " LOG_COLOR_RESET \
			"%s:%d "\
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
	#define trace(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_TRC "TRC " LOG_COLOR_RESET \
			"%s:%d "\
			LOG_PREFIX fmt "\n",\
			__FILE__, __LINE__, ## __VA_ARGS__\
		);\
	} while (0)
#else
	#define error(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_ERR "ERR " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)
	#define warn(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_WRN "WRN " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)
	#define info(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_INF "INF " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)
	#define debug(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_DBG "DBG " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)
	#define trace(fmt, ...) do {\
		fprintf(\
			LOG_STREAM,\
			LOG_COLOR_TRC "TRC " LOG_COLOR_RESET \
			LOG_PREFIX fmt "\n",\
			## __VA_ARGS__\
		);\
	} while (0)
#endif

#endif
