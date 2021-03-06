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
typedef  int /*<<< orphan*/  OTV_Validator ;
typedef  int FT_UInt ;
typedef  int FT_Bytes ;

/* Variables and functions */
 int FT_NEXT_USHORT (int) ; 
 int /*<<< orphan*/  OTV_EXIT ; 
 int /*<<< orphan*/  OTV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  OTV_NAME_ENTER (char*) ; 
 int /*<<< orphan*/  OTV_TRACE (char*) ; 
 int /*<<< orphan*/  otv_BaseScript_validate (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
  otv_BaseScriptList_validate( FT_Bytes       table,
                               OTV_Validator  otvalid )
  {
    FT_Bytes  p = table;
    FT_UInt   BaseScriptCount;


    OTV_NAME_ENTER( "BaseScriptList" );

    OTV_LIMIT_CHECK( 2 );
    BaseScriptCount = FT_NEXT_USHORT( p );

    OTV_TRACE(( " (BaseScriptCount = %d)\n", BaseScriptCount ));

    OTV_LIMIT_CHECK( BaseScriptCount * 6 );

    /* BaseScriptRecord */
    for ( ; BaseScriptCount > 0; BaseScriptCount-- )
    {
      p += 4;       /* skip BaseScriptTag */

      /* BaseScript */
      otv_BaseScript_validate( table + FT_NEXT_USHORT( p ), otvalid );
    }

    OTV_EXIT;
  }