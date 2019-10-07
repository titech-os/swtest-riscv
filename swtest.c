#include <stdio.h>

// taken from types.h
typedef unsigned long uint64;

// taken from proc.h
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

// taken from defs.h
void swtch(struct context*, struct context*);

struct context foo_context;
struct context bar_context;
struct context baz_context;
struct context *foo_ctx = &foo_context;
struct context *bar_ctx = &bar_context;
struct context *baz_ctx = &baz_context;

#define STACK_DEPTH 512
uint64 bar_stack[STACK_DEPTH];
uint64 baz_stack[STACK_DEPTH];

void foo() {
    uint64 c = 0;
    while (1) {
        printf("foo : %lu\n", c);
        swtch(foo_ctx, bar_ctx);
        c += 1;
    }
}

void bar() {
    uint64 c = 0;
    while (1) {
        printf("bar : %lu\n", c);
        swtch(bar_ctx, baz_ctx);
        c += 2;
    }
}

void baz() {
    uint64 c = 0;
    while (1) {
        printf("baz : %lu\n", c);
        swtch(baz_ctx, foo_ctx);
        c += 3;
    }
}

int main() {
    // setting up initial contexts of bar and baz
    bar_ctx->ra = (uint64)bar;
    bar_ctx->sp = (uint64)(bar_stack + STACK_DEPTH);
    baz_ctx->ra = (uint64)baz;
    baz_ctx->sp = (uint64)(baz_stack + STACK_DEPTH);
    // start from foo
    foo();
    return 0;
}

