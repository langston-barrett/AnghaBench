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
struct iio_dev {int dummy; } ;
struct hid_sensor_hub_device {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  data_ready; } ;
struct hid_humidity_state {int /*<<< orphan*/  humidity_data; TYPE_1__ common_attributes; } ;

/* Variables and functions */
 scalar_t__ atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iio_get_time_ns (struct iio_dev*) ; 
 struct hid_humidity_state* iio_priv (struct iio_dev*) ; 
 int /*<<< orphan*/  iio_push_to_buffers_with_timestamp (struct iio_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct iio_dev* platform_get_drvdata (void*) ; 

__attribute__((used)) static int humidity_proc_event(struct hid_sensor_hub_device *hsdev,
				unsigned int usage_id, void *pdev)
{
	struct iio_dev *indio_dev = platform_get_drvdata(pdev);
	struct hid_humidity_state *humid_st = iio_priv(indio_dev);

	if (atomic_read(&humid_st->common_attributes.data_ready))
		iio_push_to_buffers_with_timestamp(indio_dev,
					&humid_st->humidity_data,
					iio_get_time_ns(indio_dev));

	return 0;
}