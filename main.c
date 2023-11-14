#include "log.h"

int main(int argc, char *argv[]) {
	error("error %d", 1);
	warn("warn %d", 2);
	info("info %d", 3);
	debug("debug %d", 4);
	trace("trace %d", 5);

	return 0;
}
