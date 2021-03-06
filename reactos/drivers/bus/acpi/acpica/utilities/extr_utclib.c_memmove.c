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
typedef  int ACPI_SIZE ;

/* Variables and functions */

void *
memmove (
    void                    *Dest,
    const void              *Src,
    ACPI_SIZE               Count)
{
    char                    *New = (char *) Dest;
    char                    *Old = (char *) Src;


    if (Old > New)
    {
        /* Copy from the beginning */

        while (Count)
        {
            *New = *Old;
            New++;
            Old++;
            Count--;
        }
    }
    else if (Old < New)
    {
        /* Copy from the end */

        New = New + Count - 1;
        Old = Old + Count - 1;
        while (Count)
        {
            *New = *Old;
            New--;
            Old--;
            Count--;
        }
    }

    return (Dest);
}