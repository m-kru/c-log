#include "log.h"

struct log_time log_time(void) {
	struct log_time s = {"10:43 1 Jan 2024 "};
	return s;
}

int main(int argc, char *argv[]) {
	error("log level %d", 1);
	warn("log level %d", 2);
	info("log level %d", 3);
	debug("log level %d", 4);
	trace("log level %d", 5);

	return 0;
}
