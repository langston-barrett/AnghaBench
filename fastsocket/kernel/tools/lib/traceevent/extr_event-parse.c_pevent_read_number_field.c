#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct format_field {int size; int /*<<< orphan*/  offset; TYPE_1__* event; } ;
struct TYPE_2__ {int /*<<< orphan*/  pevent; } ;

/* Variables and functions */
 unsigned long long pevent_read_number (int /*<<< orphan*/ ,void const*,int) ; 

int pevent_read_number_field(struct format_field *field, const void *data,
			     unsigned long long *value)
{
	if (!field)
		return -1;
	switch (field->size) {
	case 1:
	case 2:
	case 4:
	case 8:
		*value = pevent_read_number(field->event->pevent,
					    data + field->offset, field->size);
		return 0;
	default:
		return -1;
	}
}