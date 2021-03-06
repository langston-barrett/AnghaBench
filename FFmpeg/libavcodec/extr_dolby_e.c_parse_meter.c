#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {scalar_t__ meter_size; scalar_t__ key_present; } ;
typedef  TYPE_1__ DBEContext ;

/* Variables and functions */
 int skip_input (TYPE_1__*,scalar_t__) ; 

__attribute__((used)) static int parse_meter(DBEContext *s)
{
    if (s->meter_size)
        return skip_input(s, s->key_present + s->meter_size + 1);
    return 0;
}