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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  i2c_config_t ;

/* Variables and functions */
 int DATA_LENGTH ; 
 int /*<<< orphan*/  I2C_MASTER_NUM ; 
 int /*<<< orphan*/  I2C_MASTER_RX_BUF_DISABLE ; 
 int /*<<< orphan*/  I2C_MASTER_TX_BUF_DISABLE ; 
 int /*<<< orphan*/  I2C_MODE_MASTER ; 
 int /*<<< orphan*/  TEST_ESP_OK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  disp_buf (int*,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  i2c_driver_delete (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_driver_install (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_master_init () ; 
 int /*<<< orphan*/  i2c_master_write_slave (int /*<<< orphan*/ ,int*,int) ; 
 int /*<<< orphan*/  i2c_param_config (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  unity_send_signal (char*) ; 
 int /*<<< orphan*/  unity_wait_for_signal (char*) ; 

__attribute__((used)) static void i2c_master_write_test(void)
{
    uint8_t *data_wr = (uint8_t *) malloc(DATA_LENGTH);
    int i;

    i2c_config_t conf_master = i2c_master_init();
    TEST_ESP_OK(i2c_param_config(I2C_MASTER_NUM, &conf_master));

    TEST_ESP_OK(i2c_driver_install(I2C_MASTER_NUM, I2C_MODE_MASTER,
                                   I2C_MASTER_RX_BUF_DISABLE,
                                   I2C_MASTER_TX_BUF_DISABLE, 0));
    unity_wait_for_signal("i2c slave init finish");

    unity_send_signal("master write");
    for (i = 0; i < DATA_LENGTH / 2; i++) {
        data_wr[i] = i;
    }
    i2c_master_write_slave(I2C_MASTER_NUM, data_wr, DATA_LENGTH / 2);
    disp_buf(data_wr, i + 1);
    free(data_wr);
    unity_wait_for_signal("ready to delete");
    TEST_ESP_OK(i2c_driver_delete(I2C_MASTER_NUM));
}