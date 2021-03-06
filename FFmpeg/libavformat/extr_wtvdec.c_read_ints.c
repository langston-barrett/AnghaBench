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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  AVIOContext ;

/* Variables and functions */
 int /*<<< orphan*/  avio_rl32 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int read_ints(AVIOContext *pb, uint32_t *data, int count)
{
    int i, total = 0;
    for (i = 0; i < count; i++) {
        if ((data[total] = avio_rl32(pb)))
           total++;
    }
    return total;
}