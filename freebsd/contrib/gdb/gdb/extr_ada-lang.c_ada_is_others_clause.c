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
struct type {int dummy; } ;

/* Variables and functions */
 char* TYPE_FIELD_NAME (struct type*,int) ; 

int
ada_is_others_clause (struct type *type, int field_num)
{
  const char *name = TYPE_FIELD_NAME (type, field_num);
  return (name != NULL && name[0] == 'O');
}