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
struct aa_profile {int dummy; } ;
struct aa_label {int dummy; } ;
typedef  int /*<<< orphan*/  gfp_t ;

/* Variables and functions */
 struct aa_label* vec_create_and_insert_label (struct aa_profile**,int,int /*<<< orphan*/ ) ; 
 struct aa_label* vec_find (struct aa_profile**,int) ; 

struct aa_label *aa_vec_find_or_create_label(struct aa_profile **vec, int len,
					     gfp_t gfp)
{
	struct aa_label *label = vec_find(vec, len);

	if (label)
		return label;

	return vec_create_and_insert_label(vec, len, gfp);
}