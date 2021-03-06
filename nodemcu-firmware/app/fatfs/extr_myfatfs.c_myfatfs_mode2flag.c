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
typedef  int BYTE ;

/* Variables and functions */
 int FA_CREATE_ALWAYS ; 
 int FA_OPEN_ALWAYS ; 
 int FA_OPEN_EXISTING ; 
 int FA_READ ; 
 int FA_WRITE ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int strlen (char const*) ; 

__attribute__((used)) static BYTE myfatfs_mode2flag( const char *mode )
{
  if (strlen( mode ) == 1) {
    if(strcmp( mode, "w" ) == 0)
      return FA_WRITE | FA_CREATE_ALWAYS;
    else if (strcmp( mode, "r" ) == 0)
      return FA_READ | FA_OPEN_EXISTING;
    else if (strcmp( mode, "a" ) == 0)
      return FA_WRITE | FA_OPEN_ALWAYS;
    else
      return FA_READ | FA_OPEN_EXISTING;
  } else if (strlen( mode ) == 2) {
    if (strcmp( mode, "r+" ) == 0)
      return FA_READ | FA_WRITE | FA_OPEN_EXISTING;
    else if (strcmp( mode, "w+" ) == 0)
      return FA_READ | FA_WRITE | FA_CREATE_ALWAYS;
    else if (strcmp( mode, "a+" ) ==0 )
      return FA_READ | FA_WRITE | FA_OPEN_ALWAYS;
    else
      return FA_READ | FA_OPEN_EXISTING;
  } else {
    return FA_READ | FA_OPEN_EXISTING;
  }
}