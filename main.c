#include "log.h"

log_string_t log_time(void) {
	log_string_t s = {"10:43 1 Jan 2024 "};
	return s;
}

int main(int argc, char *argv[]) {
	error("error %d", 1);
	warn("warn %d", 2);
	info("info %d", 3);
	debug("debug %d", 4);
	trace("trace %d", 5);

	return 0;
}
