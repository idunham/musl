#ifndef _SYS_VM86_H
#define _SYS_VM86_H

#include <bits/vm86.h>

static int vm86old(struct vm86_struct *info);
static int vm86(unsigned long fn, struct vm86plus_struct *v86);

#endif
