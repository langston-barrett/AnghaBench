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
struct salinfo_data {scalar_t__ state; int /*<<< orphan*/  cpu_event; scalar_t__ log_buffer; scalar_t__ saved_num; } ;
struct TYPE_2__ {scalar_t__ severity; } ;
typedef  TYPE_1__ sal_log_record_header_t ;

/* Variables and functions */
 scalar_t__ STATE_LOG_RECORD ; 
 scalar_t__ STATE_NO_DATA ; 
 int /*<<< orphan*/  call_on_cpu (int,int /*<<< orphan*/ ,struct salinfo_data*) ; 
 int /*<<< orphan*/  cpu_clear (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_isset (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_set (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  data_saved_lock ; 
 scalar_t__ sal_log_severity_corrected ; 
 int /*<<< orphan*/  salinfo_log_clear_cpu ; 
 int /*<<< orphan*/  salinfo_log_new_read (int,struct salinfo_data*) ; 
 int /*<<< orphan*/  salinfo_work_to_do (struct salinfo_data*) ; 
 int /*<<< orphan*/  shift1_data_saved (struct salinfo_data*,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static int
salinfo_log_clear(struct salinfo_data *data, int cpu)
{
	sal_log_record_header_t *rh;
	unsigned long flags;
	spin_lock_irqsave(&data_saved_lock, flags);
	data->state = STATE_NO_DATA;
	if (!cpu_isset(cpu, data->cpu_event)) {
		spin_unlock_irqrestore(&data_saved_lock, flags);
		return 0;
	}
	cpu_clear(cpu, data->cpu_event);
	if (data->saved_num) {
		shift1_data_saved(data, data->saved_num - 1);
		data->saved_num = 0;
	}
	spin_unlock_irqrestore(&data_saved_lock, flags);
	rh = (sal_log_record_header_t *)(data->log_buffer);
	/* Corrected errors have already been cleared from SAL */
	if (rh->severity != sal_log_severity_corrected)
		call_on_cpu(cpu, salinfo_log_clear_cpu, data);
	/* clearing a record may make a new record visible */
	salinfo_log_new_read(cpu, data);
	if (data->state == STATE_LOG_RECORD) {
		spin_lock_irqsave(&data_saved_lock, flags);
		cpu_set(cpu, data->cpu_event);
		salinfo_work_to_do(data);
		spin_unlock_irqrestore(&data_saved_lock, flags);
	}
	return 0;
}