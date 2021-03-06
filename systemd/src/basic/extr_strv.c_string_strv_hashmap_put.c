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
typedef  int /*<<< orphan*/  Hashmap ;

/* Variables and functions */
 int hashmap_ensure_allocated (int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  string_strv_hash_ops ; 
 int string_strv_hashmap_put_internal (int /*<<< orphan*/ *,char const*,char const*) ; 

int string_strv_hashmap_put(Hashmap **h, const char *key, const char *value) {
        int r;

        r = hashmap_ensure_allocated(h, &string_strv_hash_ops);
        if (r < 0)
                return r;

        return string_strv_hashmap_put_internal(*h, key, value);
}