CC=afl-gcc
DEPS=main.c jsonparser.c
ASAN=-fsanitize=address
CFLAGS=-I.
LIBS=-lm

all: $(DEPS)
	$(CC) -o jsonparser $(CFLAGS) $^ $(LIBS)
	$(CC) $(ASAN) -o jsonparser_ASAN $(CFLAGS) $^ $(LIBS)

afl: fuzzgoat
	AFL_SKIP_CPUFREQ=1 afl-fuzz -i in -o out ./jsonparser @@

.PHONY: clean

clean:
	rm ./jsonparser ./jsonparser_ASAN
