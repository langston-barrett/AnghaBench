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
struct max44009_data {int /*<<< orphan*/  client; } ;
struct iio_dev {int dummy; } ;
struct iio_chan_spec {scalar_t__ type; } ;
typedef  enum iio_event_type { ____Placeholder_iio_event_type } iio_event_type ;
typedef  enum iio_event_direction { ____Placeholder_iio_event_direction } iio_event_direction ;

/* Variables and functions */
 int EINVAL ; 
 int IIO_EV_TYPE_THRESH ; 
 scalar_t__ IIO_LIGHT ; 
 int /*<<< orphan*/  MAX44009_REG_INT_EN ; 
 int /*<<< orphan*/  MAX44009_REG_THR_TIMER ; 
 int i2c_smbus_write_byte_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct max44009_data* iio_priv (struct iio_dev*) ; 

__attribute__((used)) static int max44009_write_event_config(struct iio_dev *indio_dev,
				       const struct iio_chan_spec *chan,
				       enum iio_event_type type,
				       enum iio_event_direction dir,
				       int state)
{
	struct max44009_data *data = iio_priv(indio_dev);
	int ret;

	if (chan->type != IIO_LIGHT || type != IIO_EV_TYPE_THRESH)
		return -EINVAL;

	ret = i2c_smbus_write_byte_data(data->client,
					MAX44009_REG_INT_EN, state);
	if (ret < 0)
		return ret;

	/*
	 * Set device to trigger interrupt immediately upon exceeding
	 * the threshold limit.
	 */
	return i2c_smbus_write_byte_data(data->client,
					 MAX44009_REG_THR_TIMER, 0);
}