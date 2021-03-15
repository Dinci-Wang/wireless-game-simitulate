#ifndef __MPU6050_H_
#define __MPU6050_H_
//�w�qMPU6050�w��a�}
#define MPU_ADDR    0X68//���a��0X68 �����q����0X69

//�w�qMPU6050�Ȧs���a�}
//#define MPU_ACCEL_OFFS_REG        0X06    //accel_offs�Ȧs��,�iŪ��������,�Ȧs����U������
//#define MPU_PROD_ID_REG           0X0C    //prod id�Ȧs��,�b�Ȧs����U������
#define MPU_SELF_TESTX_REG      0X0D    //���˼Ȧs��X
#define MPU_SELF_TESTY_REG      0X0E    //���˼Ȧs��Y
#define MPU_SELF_TESTZ_REG      0X0F    //���˼Ȧs��Z
#define MPU_SELF_TESTA_REG      0X10    //���˼Ȧs��A
#define MPU_SAMPLE_RATE_REG     0X19    //�����W�v���W��
#define MPU_CFG_REG             0X1A    //�t�m�Ȧs��
#define MPU_GYRO_CFG_REG        0X1B    //�������t�m�Ȧs��
#define MPU_ACCEL_CFG_REG       0X1C    //�[�t�׭p�t�m�Ȧs��
#define MPU_MOTION_DET_REG      0X1F    //�B���˴��֭ȳ]�w�Ȧs��
#define MPU_FIFO_EN_REG         0X23    //FIFO�ϯ�Ȧs��
#define MPU_I2CMST_CTRL_REG     0X24    //IIC�D������Ȧs��
#define MPU_I2CSLV0_ADDR_REG    0X25    //IIC�q��0����a�}�Ȧs��
#define MPU_I2CSLV0_REG         0X26    //IIC�q��0��Ʀa�}�Ȧs��
#define MPU_I2CSLV0_CTRL_REG    0X27    //IIC�q��0����Ȧs��
#define MPU_I2CSLV1_ADDR_REG    0X28    //IIC�q��1����a�}�Ȧs��
#define MPU_I2CSLV1_REG         0X29    //IIC�q��1��Ʀa�}�Ȧs��
#define MPU_I2CSLV1_CTRL_REG    0X2A    //IIC�q��1����Ȧs��
#define MPU_I2CSLV2_ADDR_REG    0X2B    //IIC�q��2����a�}�Ȧs��
#define MPU_I2CSLV2_REG         0X2C    //IIC�q��2��Ʀa�}�Ȧs��
#define MPU_I2CSLV2_CTRL_REG    0X2D    //IIC�q��2����Ȧs��
#define MPU_I2CSLV3_ADDR_REG    0X2E    //IIC�q��3����a�}�Ȧs��
#define MPU_I2CSLV3_REG         0X2F    //IIC�q��3��Ʀa�}�Ȧs��
#define MPU_I2CSLV3_CTRL_REG    0X30    //IIC�q��3����Ȧs��
#define MPU_I2CSLV4_ADDR_REG    0X31    //IIC�q��4����a�}�Ȧs��
#define MPU_I2CSLV4_REG         0X32    //IIC�q��4��Ʀa�}�Ȧs��
#define MPU_I2CSLV4_DO_REG      0X33    //IIC�q��4�g��ƼȦs��
#define MPU_I2CSLV4_CTRL_REG    0X34    //IIC�q��4����Ȧs��
#define MPU_I2CSLV4_DI_REG      0X35    //IIC�q��4Ū��ƼȦs��

#define MPU_I2CMST_STA_REG      0X36    //IIC�D�����A�Ȧs��
#define MPU_INTBP_CFG_REG       0X37    //���_/�Ǹ��]�w�Ȧs��
#define MPU_INT_EN_REG          0X38    //���_�ϯ�Ȧs��
#define MPU_INT_STA_REG         0X3A    //���_���A�Ȧs��

#define MPU_ACCEL_XOUTH_REG     0X3B    //�[�t�׭�,X�b��8��Ȧs��
#define MPU_ACCEL_XOUTL_REG     0X3C    //�[�t�׭�,X�b�C8��Ȧs��
#define MPU_ACCEL_YOUTH_REG     0X3D    //�[�t�׭�,Y�b��8��Ȧs��
#define MPU_ACCEL_YOUTL_REG     0X3E    //�[�t�׭�,Y�b�C8��Ȧs��
#define MPU_ACCEL_ZOUTH_REG     0X3F    //�[�t�׭�,Z�b��8��Ȧs��
#define MPU_ACCEL_ZOUTL_REG     0X40    //�[�t�׭�,Z�b�C8��Ȧs��

#define MPU_TEMP_OUTH_REG       0X41    //�ū׭Ȱ��K��Ȧs��
#define MPU_TEMP_OUTL_REG       0X42    //�ū׭ȧC8��Ȧs��

#define MPU_GYRO_XOUTH_REG      0X43    //��������,X�b��8��Ȧs��
#define MPU_GYRO_XOUTL_REG      0X44    //��������,X�b�C8��Ȧs��
#define MPU_GYRO_YOUTH_REG      0X45    //��������,Y�b��8��Ȧs��
#define MPU_GYRO_YOUTL_REG      0X46    //��������,Y�b�C8��Ȧs��
#define MPU_GYRO_ZOUTH_REG      0X47    //��������,Z�b��8��Ȧs��
#define MPU_GYRO_ZOUTL_REG      0X48    //��������,Z�b�C8��Ȧs��

#define MPU_I2CSLV0_DO_REG      0X63    //IIC�q��0��ƼȦs��
#define MPU_I2CSLV1_DO_REG      0X64    //IIC�q��1��ƼȦs��
#define MPU_I2CSLV2_DO_REG      0X65    //IIC�q��2��ƼȦs��
#define MPU_I2CSLV3_DO_REG      0X66    //IIC�q��3��ƼȦs��

#define MPU_I2CMST_DELAY_REG    0X67    //IIC�D�����ɺ޲z�Ȧs��
#define MPU_SIGPATH_RST_REG     0X68    //�T���q�D�_��Ȧs��
#define MPU_MDETECT_CTRL_REG    0X69    //�B���˴�����Ȧs��
#define MPU_USER_CTRL_REG       0X6A    //�ϥΪ̱���Ȧs��
#define MPU_PWR_MGMT1_REG       0X6B    //�q���޲z�Ȧs��1
#define MPU_PWR_MGMT2_REG       0X6C    //�q���޲z�Ȧs��2 
#define MPU_FIFO_CNTH_REG       0X72    //FIFO�p�ƼȦs�����K��
#define MPU_FIFO_CNTL_REG       0X73    //FIFO�p�ƼȦs���C�K��
#define MPU_FIFO_RW_REG         0X74    //FIFOŪ�g�Ȧs��
#define MPU_DEVICE_ID_REG       0X75    //����ID�Ȧs��

#endif