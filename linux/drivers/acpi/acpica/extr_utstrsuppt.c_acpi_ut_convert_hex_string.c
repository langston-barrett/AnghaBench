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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 scalar_t__ ACPI_FAILURE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AE_HEX_OVERFLOW ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  acpi_ut_insert_digit (int /*<<< orphan*/ *,int,char) ; 
 int /*<<< orphan*/  isxdigit (char) ; 

acpi_status acpi_ut_convert_hex_string(char *string, u64 *return_value_ptr)
{
	u64 accumulated_value = 0;
	acpi_status status = AE_OK;

	/* Convert each ASCII byte in the input string */

	while (*string) {

		/* Must be ASCII A-F, a-f, or 0-9, otherwise terminate with no error */

		if (!isxdigit(*string)) {
			break;
		}

		/* Convert and insert this hex digit into the accumulator */

		status = acpi_ut_insert_digit(&accumulated_value, 16, *string);
		if (ACPI_FAILURE(status)) {
			status = AE_HEX_OVERFLOW;
			break;
		}

		string++;
	}

	/* Always return the value that has been accumulated */

	*return_value_ptr = accumulated_value;
	return (status);
}