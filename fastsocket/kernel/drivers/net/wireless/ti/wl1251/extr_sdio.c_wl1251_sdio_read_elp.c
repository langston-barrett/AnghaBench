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
typedef  int /*<<< orphan*/  u32 ;
struct wl1251_sdio {int /*<<< orphan*/  elp_val; struct sdio_func* func; } ;
struct wl1251 {struct wl1251_sdio* if_priv; } ;
struct sdio_func {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sdio_claim_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_release_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_writeb_readb (struct sdio_func*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  wl1251_error (char*,int) ; 

__attribute__((used)) static void wl1251_sdio_read_elp(struct wl1251 *wl, int addr, u32 *val)
{
	int ret = 0;
	struct wl1251_sdio *wl_sdio = wl->if_priv;
	struct sdio_func *func = wl_sdio->func;

	/*
	 * The hardware only supports RAW (read after write) access for
	 * reading, regular sdio_readb won't work here (it interprets
	 * the unused bits of CMD52 as write data even if we send read
	 * request).
	 */
	sdio_claim_host(func);
	*val = sdio_writeb_readb(func, wl_sdio->elp_val, addr, &ret);
	sdio_release_host(func);

	if (ret)
		wl1251_error("sdio_readb failed (%d)", ret);
}