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
struct TYPE_4__ {int /*<<< orphan*/  field; scalar_t__ memory; } ;
typedef  TYPE_1__ _bdf_list_t ;
typedef  scalar_t__ FT_Memory ;

/* Variables and functions */
 int /*<<< orphan*/  FT_FREE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_ZERO (TYPE_1__*) ; 

__attribute__((used)) static void
  _bdf_list_done( _bdf_list_t*  list )
  {
    FT_Memory  memory = list->memory;


    if ( memory )
    {
      FT_FREE( list->field );
      FT_ZERO( list );
    }
  }