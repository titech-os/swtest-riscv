#include <stdio.h>

#include "defs.h"

struct context sch_context;
struct context foo_context;
struct context bar_context;
struct context baz_context;

#define STACK_DEPTH 512
uint64 foo_stack[STACK_DEPTH];
uint64 bar_stack[STACK_DEPTH];
uint64 baz_stack[STACK_DEPTH];

void foo() {
    uint64 c = 0;
    for (;;) {
        printf("foo : %lu\n", c);
        swtch(&foo_context, &sch_context);
        c += 1;
    }
}

void bar() {
    uint64 c = 0;
    for (;;) {
        printf("bar : %lu\n", c);
        swtch(&bar_context, &sch_context);
        c += 2;
    }
}

void baz() {
    uint64 c = 0;
    for (;;) {
        printf("baz : %lu\n", c);
        swtch(&baz_context, &sch_context);
        c += 3;
    }
}

int main() {
    // setting up initial contexts
    foo_context.ra = (uint64)foo;
    foo_context.sp = (uint64)(foo_stack + STACK_DEPTH);
    bar_context.ra = (uint64)bar;
    bar_context.sp = (uint64)(bar_stack + STACK_DEPTH);
    baz_context.ra = (uint64)baz;
    baz_context.sp = (uint64)(baz_stack + STACK_DEPTH);
    // start scheduling
    for (;;) {
        swtch(&sch_context, &foo_context);
        swtch(&sch_context, &bar_context);
        swtch(&sch_context, &baz_context);
    }
    return 0;
}
