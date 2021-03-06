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
struct TYPE_2__ {int /*<<< orphan*/  f; } ;
struct reader {struct reader* p_data; TYPE_1__ u; } ;

/* Variables and functions */
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (struct reader*) ; 

__attribute__((used)) static void
libc_close( struct reader *p_reader )
{
    fclose( p_reader->u.f );
    free( p_reader->p_data );
    free( p_reader );
}