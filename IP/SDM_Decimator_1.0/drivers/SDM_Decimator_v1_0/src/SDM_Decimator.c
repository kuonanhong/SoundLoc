

/***************************** Include Files *******************************/
#include "SDM_Decimator.h"

/************************** Function Definitions ***************************/
/*
 * Set status register to Status
 *		bit 1:0:	Order select (0 to 3)
 *					Order 0 disables filter
 *		bit 2:		Enable interrupt on new value
 *		bit 3:		Enable IIR DC blocker
 *		bit 7:4:	IIR pole: by 1-2**unsigned(REG0(7:4))
 *		bit 11:8:	CIC post divide by 2**unsigned(REG0(11:8)) 
 */
void SDM_DECIM_setStatus(int BaseAddress, int Status){
	SDM_DECIMATOR_mWriteReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG0_STATUS_OFFSET, Status);
}

/*
 * Get status register
 *		bit 1:0:	Order select (0 to 3)
 *					Order 0 disables filter
 *		bit 2:		Enable interrupt on new value
 *		bit 3:		Enable IIR DC blocker
 *		bit 7:4:	IIR pole: by 1-2**unsigned(REG0(7:4))
 *		bit 11:8:	CIC post divide by 2**unsigned(REG0(11:8))
 */
int SDM_DECIM_getStatus(int BaseAddress){
	return SDM_DECIMATOR_mReadReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG0_STATUS_OFFSET);
}

/*
 * Set decimation register to Decimation
 */
void SDM_DECIM_setDecimation(int BaseAddress, unsigned int Decimation){
	SDM_DECIMATOR_mWriteReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG1_DECIMATION_OFFSET, Decimation);
}

/*
 * Get decimation register
 */
unsigned int SDM_DECIM_getDecimation(int BaseAddress){
	return SDM_DECIMATOR_mReadReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG1_DECIMATION_OFFSET);
}

/*
 * Get decimated value of mic Mic
 */
int SDM_DECIM_getValue(int BaseAddress, int mic){
	switch (mic) {
		case 0:
			return SDM_DECIMATOR_mReadReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG2_VALUE0_OFFSET);
		case 1:
			return SDM_DECIMATOR_mReadReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG3_VALUE1_OFFSET);
		case 2:
			return SDM_DECIMATOR_mReadReg(BaseAddress, SDM_DECIMATOR_S_AXI_REG4_VALUE2_OFFSET);
	}
	return 0;
}
