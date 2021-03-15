#ifndef __MPU6050_H_
#define __MPU6050_H_
//定義MPU6050硬體地址
#define MPU_ADDR    0X68//接地為0X68 接高電平為0X69

//定義MPU6050暫存器地址
//#define MPU_ACCEL_OFFS_REG        0X06    //accel_offs暫存器,可讀取版本號,暫存器手冊未提到
//#define MPU_PROD_ID_REG           0X0C    //prod id暫存器,在暫存器手冊未提到
#define MPU_SELF_TESTX_REG      0X0D    //自檢暫存器X
#define MPU_SELF_TESTY_REG      0X0E    //自檢暫存器Y
#define MPU_SELF_TESTZ_REG      0X0F    //自檢暫存器Z
#define MPU_SELF_TESTA_REG      0X10    //自檢暫存器A
#define MPU_SAMPLE_RATE_REG     0X19    //取樣頻率分頻器
#define MPU_CFG_REG             0X1A    //配置暫存器
#define MPU_GYRO_CFG_REG        0X1B    //陀螺儀配置暫存器
#define MPU_ACCEL_CFG_REG       0X1C    //加速度計配置暫存器
#define MPU_MOTION_DET_REG      0X1F    //運動檢測閥值設定暫存器
#define MPU_FIFO_EN_REG         0X23    //FIFO使能暫存器
#define MPU_I2CMST_CTRL_REG     0X24    //IIC主機控制暫存器
#define MPU_I2CSLV0_ADDR_REG    0X25    //IIC從機0器件地址暫存器
#define MPU_I2CSLV0_REG         0X26    //IIC從機0資料地址暫存器
#define MPU_I2CSLV0_CTRL_REG    0X27    //IIC從機0控制暫存器
#define MPU_I2CSLV1_ADDR_REG    0X28    //IIC從機1器件地址暫存器
#define MPU_I2CSLV1_REG         0X29    //IIC從機1資料地址暫存器
#define MPU_I2CSLV1_CTRL_REG    0X2A    //IIC從機1控制暫存器
#define MPU_I2CSLV2_ADDR_REG    0X2B    //IIC從機2器件地址暫存器
#define MPU_I2CSLV2_REG         0X2C    //IIC從機2資料地址暫存器
#define MPU_I2CSLV2_CTRL_REG    0X2D    //IIC從機2控制暫存器
#define MPU_I2CSLV3_ADDR_REG    0X2E    //IIC從機3器件地址暫存器
#define MPU_I2CSLV3_REG         0X2F    //IIC從機3資料地址暫存器
#define MPU_I2CSLV3_CTRL_REG    0X30    //IIC從機3控制暫存器
#define MPU_I2CSLV4_ADDR_REG    0X31    //IIC從機4器件地址暫存器
#define MPU_I2CSLV4_REG         0X32    //IIC從機4資料地址暫存器
#define MPU_I2CSLV4_DO_REG      0X33    //IIC從機4寫資料暫存器
#define MPU_I2CSLV4_CTRL_REG    0X34    //IIC從機4控制暫存器
#define MPU_I2CSLV4_DI_REG      0X35    //IIC從機4讀資料暫存器

#define MPU_I2CMST_STA_REG      0X36    //IIC主機狀態暫存器
#define MPU_INTBP_CFG_REG       0X37    //中斷/旁路設定暫存器
#define MPU_INT_EN_REG          0X38    //中斷使能暫存器
#define MPU_INT_STA_REG         0X3A    //中斷狀態暫存器

#define MPU_ACCEL_XOUTH_REG     0X3B    //加速度值,X軸高8位暫存器
#define MPU_ACCEL_XOUTL_REG     0X3C    //加速度值,X軸低8位暫存器
#define MPU_ACCEL_YOUTH_REG     0X3D    //加速度值,Y軸高8位暫存器
#define MPU_ACCEL_YOUTL_REG     0X3E    //加速度值,Y軸低8位暫存器
#define MPU_ACCEL_ZOUTH_REG     0X3F    //加速度值,Z軸高8位暫存器
#define MPU_ACCEL_ZOUTL_REG     0X40    //加速度值,Z軸低8位暫存器

#define MPU_TEMP_OUTH_REG       0X41    //溫度值高八位暫存器
#define MPU_TEMP_OUTL_REG       0X42    //溫度值低8位暫存器

#define MPU_GYRO_XOUTH_REG      0X43    //陀螺儀值,X軸高8位暫存器
#define MPU_GYRO_XOUTL_REG      0X44    //陀螺儀值,X軸低8位暫存器
#define MPU_GYRO_YOUTH_REG      0X45    //陀螺儀值,Y軸高8位暫存器
#define MPU_GYRO_YOUTL_REG      0X46    //陀螺儀值,Y軸低8位暫存器
#define MPU_GYRO_ZOUTH_REG      0X47    //陀螺儀值,Z軸高8位暫存器
#define MPU_GYRO_ZOUTL_REG      0X48    //陀螺儀值,Z軸低8位暫存器

#define MPU_I2CSLV0_DO_REG      0X63    //IIC從機0資料暫存器
#define MPU_I2CSLV1_DO_REG      0X64    //IIC從機1資料暫存器
#define MPU_I2CSLV2_DO_REG      0X65    //IIC從機2資料暫存器
#define MPU_I2CSLV3_DO_REG      0X66    //IIC從機3資料暫存器

#define MPU_I2CMST_DELAY_REG    0X67    //IIC主機延時管理暫存器
#define MPU_SIGPATH_RST_REG     0X68    //訊號通道復位暫存器
#define MPU_MDETECT_CTRL_REG    0X69    //運動檢測控制暫存器
#define MPU_USER_CTRL_REG       0X6A    //使用者控制暫存器
#define MPU_PWR_MGMT1_REG       0X6B    //電源管理暫存器1
#define MPU_PWR_MGMT2_REG       0X6C    //電源管理暫存器2 
#define MPU_FIFO_CNTH_REG       0X72    //FIFO計數暫存器高八位
#define MPU_FIFO_CNTL_REG       0X73    //FIFO計數暫存器低八位
#define MPU_FIFO_RW_REG         0X74    //FIFO讀寫暫存器
#define MPU_DEVICE_ID_REG       0X75    //器件ID暫存器

#endif