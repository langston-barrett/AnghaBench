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
typedef  int /*<<< orphan*/  vlc_object_t ;
typedef  int /*<<< orphan*/  JNIEnv ;

/* Variables and functions */
 int /*<<< orphan*/ * android_getEnvCommon (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char const*) ; 

JNIEnv *
android_getEnv(vlc_object_t *p_obj, const char *psz_name)
{
    return android_getEnvCommon(p_obj, NULL, psz_name);
}