HDRS = defs.h
SRCS = swtest.c schtest.c
ASM_SRCS = swtch.S
OBJS = $(SRCS:%.c=%.o) $(ASM_SRCS:%.S=%.o)
EXES = swtest schtest

CC = riscv64-unknown-elf-gcc
CPPFLAGS =
CFLAGS = -std=c11 -pedantic -Wall -Wextra -Werror -g
LDFLAGS =
SPIKE = spike
SPIKE_OPTS = pk

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.S
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: build run clean allclean

build: $(EXES)

run-swtest: swtest
	$(SPIKE) $(SPIKE_OPTS) $<

run-schtest: schtest
	$(SPIKE) $(SPIKE_OPTS) $<

swtest: swtest.o swtch.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

schtest: schtest.o swtch.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(EXES)
	$(RM) $(OBJS)

allclean: clean
	$(RM) *.o a.out
	$(RM) *~
