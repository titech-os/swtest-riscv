SRCS = swtest.c
ASM_SRCS = swtch.S
OBJS = $(SRCS:%.c=%.o) $(ASM_SRCS:%.S=%.o)
EXES = swtest

CC = riscv64-unknown-elf-gcc
CPPFLAGS =
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS =
SPIKE = spike
SPIKE_OPTS = pk

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

%.o: %.S
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY: build run clean allclean

build: swtest

run: swtest
	$(SPIKE) $(SPIKE_OPTS) $<

swtest: swtest.o swtch.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(EXES)
	$(RM) $(OBJS)

allclean: clean
	$(RM) *.o a.out
	$(RM) *~
