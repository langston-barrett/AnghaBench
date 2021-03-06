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
struct TYPE_4__ {char open_mode; int /*<<< orphan*/  cache; void* compressed_block; void* uncompressed_block; } ;
typedef  TYPE_1__ BGZF ;

/* Variables and functions */
 int /*<<< orphan*/  BGZF_MAX_BLOCK_SIZE ; 
 int /*<<< orphan*/  cache ; 
 TYPE_1__* calloc (int,int) ; 
 int /*<<< orphan*/  kh_init (int /*<<< orphan*/ ) ; 
 void* malloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static BGZF *bgzf_read_init()
{
	BGZF *fp;
	fp = calloc(1, sizeof(BGZF));
	fp->open_mode = 'r';
	fp->uncompressed_block = malloc(BGZF_MAX_BLOCK_SIZE);
	fp->compressed_block = malloc(BGZF_MAX_BLOCK_SIZE);
#ifdef BGZF_CACHE
	fp->cache = kh_init(cache);
#endif
	return fp;
}