#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct uart_port {int dummy; } ;
struct sci_port {TYPE_1__* params; } ;
struct plat_sci_reg {scalar_t__ size; } ;
struct TYPE_2__ {int fifosize; } ;

/* Variables and functions */
 int /*<<< orphan*/  SCFDR ; 
 int /*<<< orphan*/  SCRFDR ; 
 int /*<<< orphan*/  SCxSR ; 
 unsigned int SCxSR_RDxF (struct uart_port*) ; 
 struct plat_sci_reg* sci_getreg (struct uart_port*,int /*<<< orphan*/ ) ; 
 unsigned int serial_port_in (struct uart_port*,int /*<<< orphan*/ ) ; 
 struct sci_port* to_sci_port (struct uart_port*) ; 

__attribute__((used)) static int sci_rxfill(struct uart_port *port)
{
	struct sci_port *s = to_sci_port(port);
	unsigned int fifo_mask = (s->params->fifosize << 1) - 1;
	const struct plat_sci_reg *reg;

	reg = sci_getreg(port, SCRFDR);
	if (reg->size)
		return serial_port_in(port, SCRFDR) & fifo_mask;

	reg = sci_getreg(port, SCFDR);
	if (reg->size)
		return serial_port_in(port, SCFDR) & fifo_mask;

	return (serial_port_in(port, SCxSR) & SCxSR_RDxF(port)) != 0;
}