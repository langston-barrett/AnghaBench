#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint64_t ;

/* Variables and functions */
 int /*<<< orphan*/  be64toh (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void unaligned_write_be64(void *_u, uint64_t a) {
        struct __attribute__((__packed__, __may_alias__)) { uint64_t x; } *u = _u;

        u->x = be64toh(a);
}