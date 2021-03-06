#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vlc_object_t ;
struct TYPE_4__ {TYPE_2__* p_sys; } ;
typedef  TYPE_1__ addons_finder_t ;
struct TYPE_5__ {struct TYPE_5__* psz_tempfile; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_2__*) ; 
 int /*<<< orphan*/  vlc_unlink (TYPE_2__*) ; 

__attribute__((used)) static void Close(vlc_object_t *p_this)
{
    addons_finder_t *p_finder = (addons_finder_t*) p_this;
    if ( p_finder->p_sys->psz_tempfile )
    {
        vlc_unlink( p_finder->p_sys->psz_tempfile );
        free( p_finder->p_sys->psz_tempfile );
    }
    free( p_finder->p_sys );
}