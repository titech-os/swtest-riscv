// Definitions from xv6-riscv

// from kernel/types.h
typedef unsigned long uint64;

// from kernel/proc.h
struct context {
  uint64 ra;
  uint64 sp;

  // callee-saved
  uint64 s0;
  uint64 s1;
  uint64 s2;
  uint64 s3;
  uint64 s4;
  uint64 s5;
  uint64 s6;
  uint64 s7;
  uint64 s8;
  uint64 s9;
  uint64 s10;
  uint64 s11;
};

// from kernel/defs.h
void swtch(struct context*, struct context*);
