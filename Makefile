CC ?= gcc
CFLAGS += -Wall --pedantic -Werror -Wno-error=unused-but-set-variable -Werror=pedantic

all:
	$(CC) $(LDFLAGS) -o main $(CFLAGS) fonctions.c main.c -lm

test:
	$(CC) $(LDFLAGS) -g -o tests_main $(CFLAGS) main_tests/tests_main.c fonctions.c -lcunit

clean:
	rm -f *.o tests_main main
