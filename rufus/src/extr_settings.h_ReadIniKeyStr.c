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
 int /*<<< orphan*/  free (char*) ; 
 char* get_token_data_file (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ini_file ; 
 int /*<<< orphan*/  static_strcpy (char*,char*) ; 

__attribute__((used)) static __inline char* ReadIniKeyStr(const char* key) {
	static char str[512];
	char* val;
	str[0] = 0;
	val = get_token_data_file(key, ini_file);
	if (val != NULL) {
		static_strcpy(str, val);
		free(val);
	}
	return str;
}