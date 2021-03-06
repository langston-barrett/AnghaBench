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

/* Variables and functions */
#define  DW_FORM_addr 148 
#define  DW_FORM_block 147 
#define  DW_FORM_block1 146 
#define  DW_FORM_block2 145 
#define  DW_FORM_block4 144 
#define  DW_FORM_data1 143 
#define  DW_FORM_data2 142 
#define  DW_FORM_data4 141 
#define  DW_FORM_data8 140 
#define  DW_FORM_flag 139 
#define  DW_FORM_indirect 138 
#define  DW_FORM_ref1 137 
#define  DW_FORM_ref2 136 
#define  DW_FORM_ref4 135 
#define  DW_FORM_ref8 134 
#define  DW_FORM_ref_addr 133 
#define  DW_FORM_ref_udata 132 
#define  DW_FORM_sdata 131 
#define  DW_FORM_string 130 
#define  DW_FORM_strp 129 
#define  DW_FORM_udata 128 

__attribute__((used)) static char *
dwarf_form_name (unsigned form)
{
  switch (form)
    {
    case DW_FORM_addr:
      return "DW_FORM_addr";
    case DW_FORM_block2:
      return "DW_FORM_block2";
    case DW_FORM_block4:
      return "DW_FORM_block4";
    case DW_FORM_data2:
      return "DW_FORM_data2";
    case DW_FORM_data4:
      return "DW_FORM_data4";
    case DW_FORM_data8:
      return "DW_FORM_data8";
    case DW_FORM_string:
      return "DW_FORM_string";
    case DW_FORM_block:
      return "DW_FORM_block";
    case DW_FORM_block1:
      return "DW_FORM_block1";
    case DW_FORM_data1:
      return "DW_FORM_data1";
    case DW_FORM_flag:
      return "DW_FORM_flag";
    case DW_FORM_sdata:
      return "DW_FORM_sdata";
    case DW_FORM_strp:
      return "DW_FORM_strp";
    case DW_FORM_udata:
      return "DW_FORM_udata";
    case DW_FORM_ref_addr:
      return "DW_FORM_ref_addr";
    case DW_FORM_ref1:
      return "DW_FORM_ref1";
    case DW_FORM_ref2:
      return "DW_FORM_ref2";
    case DW_FORM_ref4:
      return "DW_FORM_ref4";
    case DW_FORM_ref8:
      return "DW_FORM_ref8";
    case DW_FORM_ref_udata:
      return "DW_FORM_ref_udata";
    case DW_FORM_indirect:
      return "DW_FORM_indirect";
    default:
      return "DW_FORM_<unknown>";
    }
}