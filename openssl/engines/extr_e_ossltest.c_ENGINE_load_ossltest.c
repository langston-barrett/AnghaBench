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
typedef  int /*<<< orphan*/  ENGINE ;

/* Variables and functions */
 int /*<<< orphan*/  ENGINE_add (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ENGINE_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ERR_clear_error () ; 
 int /*<<< orphan*/ * engine_ossltest () ; 

void ENGINE_load_ossltest(void)
{
    /* Copied from eng_[openssl|dyn].c */
    ENGINE *toadd = engine_ossltest();
    if (!toadd)
        return;
    ENGINE_add(toadd);
    ENGINE_free(toadd);
    ERR_clear_error();
}