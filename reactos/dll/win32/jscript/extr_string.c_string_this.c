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
typedef  int /*<<< orphan*/  vdisp_t ;
typedef  int /*<<< orphan*/  StringInstance ;

/* Variables and functions */
 int /*<<< orphan*/  JSCLASS_STRING ; 
 scalar_t__ is_vclass (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * string_from_vdisp (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline StringInstance *string_this(vdisp_t *jsthis)
{
    return is_vclass(jsthis, JSCLASS_STRING) ? string_from_vdisp(jsthis) : NULL;
}