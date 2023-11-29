# c-log

## Overview

Lightweight (single header file) C module implementing logging.
The only dependency is the `stdio.h` providing `fprintf()`.

The module provides 5 logging macros: `error`, `warn`, `info`, `debug`, and `trace`.
There is no `fatal` level.
If you want to `fatal`, then you should probably [panic](https://github.com/m-kru/c-panic).

The macros do not have popular `log_` prefix.
Why?
Because the names are quite self explanatory.
There is no need to clutter the code with the extra `log_` prefix.
The `warn` macro conflicts with the `warn()` function from the `err.h`.
However, let's be honest, no one uses `err.h` as the functions it provides are pretty much useless.

**The module is not thread safe.**
If you want thread safety, then you must implement it on your own.

## Installation

Simply copy the `log.h` file to your project.

## Configuration

The module is statically configurable during the compilation time.
There are 5 following configuration macros (alphabetical order):
- `LOG_COLOR` - if defined, log level will be printed in color.
If you don't like the default colors simply edit proper macros in the `log.h` file.
- `LOG_LEVEL` - log level. Valid values are:
	- 0 - no logs.
	- 1 - only errors.
	- 2 - errors and warnings.
	- 3 - errors, warnings, and infos.
	- 4 - errors, warnings, infos and debugs,
	- 5 - errors, warnings, infos, debugs, and traces.
- `LOG_PREFIX` - optional logging prefix.
If defined in the Makefile or command line, remember to double quote, for example, `-DLOG_PREFIX="\"your prefix:\""`
- `LOG_STREAM` - stream for logging. The default one is `stderr`.
- `LOG_TIME` - if defined, the log will include the time.
The time format is custom format.
The user must provide implementation for the `struct log_time log_time(void);` function.
For more details check the documentation in the `log.h` file.

The configuration can also be done per source file scope, which is sometimes desired, especially for the `LOG_PREFIX`.
In such a case simply configure the module before include.
Example:
```C
#define LOG_PREFIX "my_prefix: "
#define LOG_LEVEL 5
#include "log.h"
```

## Example

Check `main.c` file.

<p align="center"><img src="example.png?raw=true"/></p>
