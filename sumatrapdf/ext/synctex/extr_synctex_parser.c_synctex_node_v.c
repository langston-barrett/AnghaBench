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
typedef  int /*<<< orphan*/  synctex_node_t ;

/* Variables and functions */
 int SYNCTEX_VERT (int /*<<< orphan*/ ) ; 

int synctex_node_v(synctex_node_t node){
	if (!node) {
		return 0;
	}
	return SYNCTEX_VERT(node);
}