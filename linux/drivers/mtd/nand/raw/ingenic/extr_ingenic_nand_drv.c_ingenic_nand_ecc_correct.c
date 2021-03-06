#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
struct nand_chip {int dummy; } ;
struct ingenic_nfc {int /*<<< orphan*/  ecc; } ;
struct TYPE_3__ {int /*<<< orphan*/  strength; int /*<<< orphan*/  bytes; int /*<<< orphan*/  size; } ;
struct TYPE_4__ {TYPE_1__ ecc; int /*<<< orphan*/  controller; } ;
struct ingenic_nand {TYPE_2__ chip; } ;
struct ingenic_ecc_params {int /*<<< orphan*/  strength; int /*<<< orphan*/  bytes; int /*<<< orphan*/  size; } ;

/* Variables and functions */
 int ingenic_ecc_correct (int /*<<< orphan*/ ,struct ingenic_ecc_params*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nand_to_mtd (struct nand_chip*) ; 
 struct ingenic_nand* to_ingenic_nand (int /*<<< orphan*/ ) ; 
 struct ingenic_nfc* to_ingenic_nfc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int ingenic_nand_ecc_correct(struct nand_chip *chip, u8 *dat,
				    u8 *read_ecc, u8 *calc_ecc)
{
	struct ingenic_nand *nand = to_ingenic_nand(nand_to_mtd(chip));
	struct ingenic_nfc *nfc = to_ingenic_nfc(nand->chip.controller);
	struct ingenic_ecc_params params;

	params.size = nand->chip.ecc.size;
	params.bytes = nand->chip.ecc.bytes;
	params.strength = nand->chip.ecc.strength;

	return ingenic_ecc_correct(nfc->ecc, &params, dat, read_ecc);
}