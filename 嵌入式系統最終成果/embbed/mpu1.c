#include <linux/module.h>
#include <linux/version.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/interrupt.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/serial_core.h>
#include <linux/platform_device.h>

#include <asm/mach/map.h>
#include <linux/i2c.h>
#include <linux/delay.h>



static struct i2c_board_info mpu6050_info = {
	I2C_BOARD_INFO("mpu6050", 0X68),
};

static struct i2c_client* mpu6050_client;
static int ret;
static char txbuf[] = { 0X6B, 0X00 };
static int I2C_mpu6050_init(void)
{
	struct i2c_adapter* i2c_adap;

	i2c_adap = i2c_get_adapter(1);
	mpu6050_client = i2c_new_device(i2c_adap, &mpu6050_info);
	i2c_put_adapter(i2c_adap);

	
	struct i2c_msg msg[] = {
		{mpu6050_client->addr, 0, 2, txbuf}
	};
	ret = i2c_transfer(mpu6050_client->adapter, msg, 1);
	if (ret < 0)
	{
		printk("i2c_transfer write err\n");

	}
	return 0;
}

static void I2C_mpu6050_exit(void)
{
	i2c_unregister_device(mpu6050_client);
}

module_init(I2C_mpu6050_init);
module_exit(I2C_mpu6050_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("kite");
MODULE_DESCRIPTION("A mpu6050 Module for testing module ");
MODULE_VERSION("V1.0");