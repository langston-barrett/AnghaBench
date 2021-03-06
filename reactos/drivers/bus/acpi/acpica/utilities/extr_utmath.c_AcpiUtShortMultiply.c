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
struct TYPE_3__ {int /*<<< orphan*/  Hi; int /*<<< orphan*/  Lo; } ;
struct TYPE_4__ {int /*<<< orphan*/  Full; TYPE_1__ Part; } ;
typedef  TYPE_2__ UINT64_OVERLAY ;
typedef  int /*<<< orphan*/  UINT64 ;
typedef  scalar_t__ UINT32 ;
typedef  int /*<<< orphan*/  ACPI_STATUS ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_MUL_64_BY_32 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  UtShortMultiply ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 

ACPI_STATUS
AcpiUtShortMultiply (
    UINT64                  Multiplicand,
    UINT32                  Multiplier,
    UINT64                  *OutProduct)
{
    UINT64_OVERLAY          MultiplicandOvl;
    UINT64_OVERLAY          Product;
    UINT32                  Carry32;


    ACPI_FUNCTION_TRACE (UtShortMultiply);


    MultiplicandOvl.Full = Multiplicand;

    /*
     * The Product is 64 bits, the carry is always 32 bits,
     * and is generated by the second multiply.
     */
    ACPI_MUL_64_BY_32 (0, MultiplicandOvl.Part.Hi, Multiplier,
        Product.Part.Hi, Carry32);

    ACPI_MUL_64_BY_32 (0, MultiplicandOvl.Part.Lo, Multiplier,
        Product.Part.Lo, Carry32);

    Product.Part.Hi += Carry32;

    /* Return only what was requested */

    if (OutProduct)
    {
        *OutProduct = Product.Full;
    }

    return_ACPI_STATUS (AE_OK);
}