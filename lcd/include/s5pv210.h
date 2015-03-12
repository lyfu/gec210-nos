
//------GPIO------
#define rGPD0CON                 (*(volatile unsigned long *)0xE02000A0)
#define rGPD0DAT                 (*(volatile unsigned long *)0xE02000A4)


#define rGPE0CON                 (*(volatile unsigned long *)0xE02000E0)                                 
#define rGPE0DAT                 (*(volatile unsigned long *)0xE02000E4)  

#define rGPF0CON                 (*(volatile unsigned long *)0xE0200120)
#define rGPF1CON                 (*(volatile unsigned long *)0xE0200140)
#define rGPF2CON                 (*(volatile unsigned long *)0xE0200160)
#define rGPF3CON                 (*(volatile unsigned long *)0xE0200180)

#define rGPH2CON  (*(volatile unsigned long *) 0xE0200C40)
#define rGPH2DAT  (*(volatile unsigned long *) 0xE0200C44)
#define rGPH3CON  (*(volatile unsigned long *) 0xE0200C60)


#define rGPJ2CON  (*(volatile unsigned long *) 0xE0200280)
#define rGPJ2DAT  (*(volatile unsigned long *) 0xE0200284)
#define rGPJ2PUD  (*(volatile unsigned long *) 0xE0200288)

#define rGPH3CON  (*(volatile unsigned long *) 0xE0200C60)
#define rGPH3DAT  (*(volatile unsigned long *) 0xE0200C64)
#define rGPH3PUD  (*(volatile unsigned long *) 0xE0200C68)

#define rEXT_INT_0_CON  ( *((volatile unsigned long *)0xE0200E00) )
#define rEXT_INT_1_CON  ( *((volatile unsigned long *)0xE0200E04) )
#define rEXT_INT_2_CON  ( *((volatile unsigned long *)0xE0200E08) )
#define rEXT_INT_3_CON  ( *((volatile unsigned long *)0xE0200E0C) )

#define rEXT_INT_0_MASK  ( *((volatile unsigned long *)0xE0200F00) )
#define rEXT_INT_1_MASK  ( *((volatile unsigned long *)0xE0200F04) )
#define rEXT_INT_2_MASK  ( *((volatile unsigned long *)0xE0200F08) )
#define rEXT_INT_3_MASK  ( *((volatile unsigned long *)0xE0200F0C) )
    
#define rEXT_INT_0_PEND  ( *((volatile unsigned long *)0xE0200F40) )
#define rEXT_INT_1_PEND  ( *((volatile unsigned long *)0xE0200F44) )
#define rEXT_INT_2_PEND  ( *((volatile unsigned long *)0xE0200F48) )
#define rEXT_INT_3_PEND  ( *((volatile unsigned long *)0xE0200F4C) )


//------- exception ------

#define _Exception_Vector	0xD0037400
#define pExcRESET               ( *((volatile unsigned long *)(_Exception_Vector + 0x0)) )
#define pExcUNDEF               ( *((volatile unsigned long *)(_Exception_Vector + 0x4)) )
#define pExcSWI                 ( *((volatile unsigned long *)(_Exception_Vector + 0x8)) )
#define pExcPABORT              ( *((volatile unsigned long *)(_Exception_Vector + 0xc)) )
#define pExcDABORT              ( *((volatile unsigned long *)(_Exception_Vector + 0x10)) )
#define pExcRESERVED            ( *((volatile unsigned long *)(_Exception_Vector + 0x14)) )
#define pExcIRQ                 ( *((volatile unsigned long *)(_Exception_Vector + 0x18)) )
#define pExcFIQ                 ( *((volatile unsigned long *)(_Exception_Vector + 0x1c)) )

//---------- interupt init ----------------------------
#define VIC0_BASE       (0xF2000000)
#define VIC1_BASE       (0xF2100000)
#define VIC2_BASE       (0xF2200000)
#define VIC3_BASE       (0xF2300000)

// VIC0
#define   	rVIC0IRQSTATUS                   ( *((volatile unsigned long *)(VIC0_BASE + 0x00)) )
#define         rVIC0FIQSTATUS                   ( *((volatile unsigned long *)(VIC0_BASE + 0x04)) )
#define         rVIC0RAWINTR                     ( *((volatile unsigned long *)(VIC0_BASE + 0x08)) )
#define         rVIC0INTSELECT                   ( *((volatile unsigned long *)(VIC0_BASE + 0x0c)) )
#define         rVIC0INTENABLE                   ( *((volatile unsigned long *)(VIC0_BASE + 0x10)) )
#define         rVIC0INTENCLEAR                  ( *((volatile unsigned long *)(VIC0_BASE + 0x14)) )
#define         rVIC0SOFTINT                     ( *((volatile unsigned long *)(VIC0_BASE + 0x18)) )
#define         rVIC0SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC0_BASE + 0x1c)) )
#define         rVIC0PROTECTION                  ( *((volatile unsigned long *)(VIC0_BASE + 0x20)) )
#define         rVIC0SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC0_BASE + 0x24)) )
#define         rVIC0PRIORITYDAISY               ( *((volatile unsigned long *)(VIC0_BASE + 0x28)) )

#define         rVIC0VECTADDR                    (VIC0_BASE + 0x100)
#define         rVIC0VECPRIORITY                 ( *((volatile unsigned long *)(VIC0_BASE + 0x200)) )
#define         rVIC0ADDRESS                     ( *((volatile unsigned long *)(VIC0_BASE + 0xf00)) )
#define         rVIC0PERID0                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe0)) )
#define         rVIC0PERID1                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe4)) )
#define         rVIC0PERID2                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfe8)) )
#define         rVIC0PERID3                      ( *((volatile unsigned long *)(VIC0_BASE + 0xfec)) )
#define         rVIC0PCELLID0                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff0)) )
#define         rVIC0PCELLID1                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff4)) )
#define         rVIC0PCELLID2                    ( *((volatile unsigned long *)(VIC0_BASE + 0xff8)) )
#define         rVIC0PCELLID3                    ( *((volatile unsigned long *)(VIC0_BASE + 0xffc)) )

// VIC1
#define         rVIC1IRQSTATUS                   ( *((volatile unsigned long *)(VIC1_BASE + 0x00)) )
#define         rVIC1FIQSTATUS                   ( *((volatile unsigned long *)(VIC1_BASE + 0x04)) )
#define         rVIC1RAWINTR                     ( *((volatile unsigned long *)(VIC1_BASE + 0x08)) )
#define         rVIC1INTSELECT                   ( *((volatile unsigned long *)(VIC1_BASE + 0x0c)) )
#define         rVIC1INTENABLE                   ( *((volatile unsigned long *)(VIC1_BASE + 0x10)) )
#define         rVIC1INTENCLEAR                  ( *((volatile unsigned long *)(VIC1_BASE + 0x14)) )
#define         rVIC1SOFTINT                     ( *((volatile unsigned long *)(VIC1_BASE + 0x18)) )
#define         rVIC1SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC1_BASE + 0x1c)) )
#define         rVIC1PROTECTION                  ( *((volatile unsigned long *)(VIC1_BASE + 0x20)) )
#define         rVIC1SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC1_BASE + 0x24)) )
#define         rVIC1PRIORITYDAISY               ( *((volatile unsigned long *)(VIC1_BASE + 0x28)) )

#define         rVIC1VECTADDR                    (VIC1_BASE + 0x100)
#define         rVIC1VECPRIORITY                 ( *((volatile unsigned long *)(VIC1_BASE + 0x200)) )
#define         rVIC1ADDRESS                     ( *((volatile unsigned long *)(VIC1_BASE + 0xf00)) )
#define         rVIC1PERID0                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe0)) )
#define         rVIC1PERID1                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe4)) )
#define         rVIC1PERID2                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfe8)) )
#define         rVIC1PERID3                      ( *((volatile unsigned long *)(VIC1_BASE + 0xfec)) )
#define         rVIC1PCELLID0                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff0)) )
#define         rVIC1PCELLID1                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff4)) )
#define         rVIC1PCELLID2                    ( *((volatile unsigned long *)(VIC1_BASE + 0xff8)) )
#define         rVIC1PCELLID3                    ( *((volatile unsigned long *)(VIC1_BASE + 0xffc)) )

// VIC2
#define         rVIC2IRQSTATUS                   ( *((volatile unsigned long *)(VIC2_BASE + 0x00)) )
#define         rVIC2FIQSTATUS                   ( *((volatile unsigned long *)(VIC2_BASE + 0x04)) )
#define         rVIC2RAWINTR                     ( *((volatile unsigned long *)(VIC2_BASE + 0x08)) )
#define         rVIC2INTSELECT                   ( *((volatile unsigned long *)(VIC2_BASE + 0x0c)) )
#define         rVIC2INTENABLE                   ( *((volatile unsigned long *)(VIC2_BASE + 0x10)) )
#define         rVIC2INTENCLEAR                  ( *((volatile unsigned long *)(VIC2_BASE + 0x14)) )
#define         rVIC2SOFTINT                     ( *((volatile unsigned long *)(VIC2_BASE + 0x18)) )
#define         rVIC2SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC2_BASE + 0x1c)) )
#define         rVIC2PROTECTION                  ( *((volatile unsigned long *)(VIC2_BASE + 0x20)) )
#define         rVIC2SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC2_BASE + 0x24)) )
#define         rVIC2PRIORITYDAISY               ( *((volatile unsigned long *)(VIC2_BASE + 0x28)) )

#define         rVIC2VECTADDR                    (VIC2_BASE + 0x100)
#define         rVIC2VECPRIORITY                 ( *((volatile unsigned long *)(VIC2_BASE + 0x200)) )
#define         rVIC2ADDRESS                     ( *((volatile unsigned long *)(VIC2_BASE + 0xf00)) )
#define         rVIC2PERID0                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe0)) )
#define         rVIC2PERID1                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe4)) )
#define         rVIC2PERID2                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfe8)) )
#define         rVIC2PERID3                      ( *((volatile unsigned long *)(VIC2_BASE + 0xfec)) )
#define         rVIC2PCELLID0                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff0)) )
#define         rVIC2PCELLID1                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff4)) )
#define         rVIC2PCELLID2                    ( *((volatile unsigned long *)(VIC2_BASE + 0xff8)) )
#define         rVIC2PCELLID3                    ( *((volatile unsigned long *)(VIC2_BASE + 0xffc)) )

// VIC3
#define         rVIC3IRQSTATUS                   ( *((volatile unsigned long *)(VIC3_BASE + 0x00)) )
#define         rVIC3FIQSTATUS                   ( *((volatile unsigned long *)(VIC3_BASE + 0x04)) )
#define         rVIC3RAWINTR                     ( *((volatile unsigned long *)(VIC3_BASE + 0x08)) )
#define         rVIC3INTSELECT                   ( *((volatile unsigned long *)(VIC3_BASE + 0x0c)) )
#define         rVIC3INTENABLE                   ( *((volatile unsigned long *)(VIC3_BASE + 0x10)) )
#define         rVIC3INTENCLEAR                  ( *((volatile unsigned long *)(VIC3_BASE + 0x14)) )
#define         rVIC3SOFTINT                     ( *((volatile unsigned long *)(VIC3_BASE + 0x18)) )
#define         rVIC3SOFTINTCLEAR                ( *((volatile unsigned long *)(VIC3_BASE + 0x1c)) )
#define         rVIC3PROTECTION                  ( *((volatile unsigned long *)(VIC3_BASE + 0x20)) )
#define         rVIC3SWPRIORITYMASK              ( *((volatile unsigned long *)(VIC3_BASE + 0x24)) )
#define         rVIC3PRIORITYDAISY               ( *((volatile unsigned long *)(VIC3_BASE + 0x28)) )

#define         rVIC3VECTADDR                    (VIC3_BASE + 0x100)
#define         rVIC3VECPRIORITY                 ( *((volatile unsigned long *)(VIC3_BASE + 0x200)) )
#define         rVIC3ADDRESS                     ( *((volatile unsigned long *)(VIC3_BASE + 0xf00)) )
#define         rVIC3PERID0                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe0)) )
#define         rVIC3PERID1                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe4)) )
#define         rVIC3PERID2                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfe8)) )
#define         rVIC3PERID3                      ( *((volatile unsigned long *)(VIC3_BASE + 0xfec)) )
#define         rVIC3PCELLID0                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff0)) )
#define         rVIC3PCELLID1                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff4)) )
#define         rVIC3PCELLID2                    ( *((volatile unsigned long *)(VIC3_BASE + 0xff8)) )
#define         rVIC3PCELLID3                    ( *((volatile unsigned long *)(VIC3_BASE + 0xffc)) )



#define INT_LIMIT                               (96)

//INT NUM - VIC0
#define NUM_EINT0                               (0)
#define NUM_EINT1                               (1)
#define NUM_EINT2                               (2)
#define NUM_EINT3                               (3)
#define NUM_EINT4                               (4)
#define NUM_EINT5                               (5)
#define NUM_EINT6                               (6)
#define NUM_EINT7                               (7)
#define NUM_EINT8                               (8)
#define NUM_EINT9                               (9)
#define NUM_EINT10                              (10)
#define NUM_EINT11                              (11)
#define NUM_EINT12                              (12)
#define NUM_EINT13                              (13)
#define NUM_EINT14                              (14)
#define NUM_EINT15                              (15)
#define NUM_EINT16_31                           (16)
#define NUM_Reserved17                          (17) 
#define NUM_MDMA                                (18)
#define NUM_PDMA0                               (19)
#define NUM_PDMA1                               (20)
#define NUM_TIMER0                              (21)
#define NUM_TIMER1                              (22)
#define NUM_TIMER2                              (23)
#define NUM_TIMER3                              (24)
#define NUM_TIMER4                              (25)
#define NUM_SYSTIMER                            (26)
#define NUM_WDT                                 (27)
#define NUM_RTC_ALARM                           (28)
#define NUM_RTC_TICK                            (29)
#define NUM_GPIOINT                             (30)
#define NUM_FIMC3                               (31)

//INT NUM - VIC1
#define NUM_CORTEX0                             (32+0)
#define NUM_CORTEX1                             (32+1)
#define NUM_CORTEX2                             (32+2)
#define NUM_CORTEX3                             (32+3)
#define NUM_CORTEX4                             (32+4)
#define NUM_IEM_APC                             (32+5)
#define NUM_IEM_IEC                             (32+6)
#define NUM_Reserved39                          (32+7)
#define NUM_NFC                                 (32+8)
#define NUM_CFC                                 (32+9)
#define NUM_UART0                               (32+10)
#define NUM_UART1                               (32+11)
#define NUM_UART2                               (32+12)
#define NUM_UART3                               (32+13)
#define NUM_I2C                                 (32+14)
#define NUM_SPI0                                (32+15)
#define NUM_SPI1                                (32+16)
#define NUM_SPI2                                (32+17)
#define NUM_AUDIO                               (32+18)
#define NUM_I2C_PMIC                            (32+19)
#define NUM_I2C_HDMI                            (32+20)
#define NUM_HSIRX                               (32+21)
#define NUM_HSITX                               (32+22)
#define NUM_UHOST                               (32+23)
#define NUM_OTG                                 (32+24)
#define NUM_MSM                                 (32+25)
#define NUM_HSMMC0                              (32+26)
#define NUM_HSMMC1                              (32+27)
#define NUM_HSMMC2                              (32+28)
#define NUM_MIPI_CSI                            (32+29)
#define NUM_MIPI_DSI                            (32+30)
#define NUM_ONENAND_AUDI                        (32+31)


//INT NUM - VIC2
#define NUM_LCD0                                (64+0)
#define NUM_LCD1                                (64+1)
#define NUM_LCD2                                (64+2)
#define NUM_LCD3                                (64+3)
#define NUM_ROTATOR                             (64+4)
#define NUM_FIMC_A                              (64+5)
#define NUM_FIMC_B                              (64+6)
#define NUM_FIMC_C                              (64+7)
#define NUM_JPEG                                (64+8)
#define NUM_2D                                  (64+9)
#define NUM_3D                                  (64+10)
#define NUM_MIXER                               (64+11)
#define NUM_HDMI                                (64+12)
#define NUM_HDMI_I2C                            (64+13)
#define NUM_MFC                                 (64+14)
#define NUM_TVENC                               (64+15)
#define NUM_I2S0                                (64+16)
#define NUM_I2S1                                (64+17)
#define NUM_I2S2                                (64+18)
#define NUM_AC97                                (64+19)
#define NUM_PCM0                                (64+20)
#define NUM_PCM1                                (64+21)
#define NUM_SPDIF                               (64+22)
#define NUM_ADC                                 (64+23)
#define NUM_PENDN                               (64+24)
#define NUM_KEYPAD                              (64+25)
#define NUM_Reserved90                          (64+26) 
#define NUM_HASH                                (64+27) 
#define NUM_FEEDCTRL                            (64+28) 
#define NUM_PCM2                                (64+29)
#define NUM_SDM_IRQ                             (64+30)
#define NUM_SMD_FIQ                             (64+31)


//INT NUM - VIC3
#define NUM_IPC                                 (96+0)
#define NUM_HOSTIF                              (96+1)
#define NUM_HSMMC3                              (96+2)
#define NUM_CEC                                 (96+3)
#define NUM_TSI                                 (96+4)
#define NUM_MDNIE0                              (96+5)
#define NUM_MDNIE1                              (96+6)
#define NUM_MDNIE2                              (96+7)
#define NUM_MDNIE3                              (96+8)
#define NUM_ADC1                                (96+9)
#define NUM_PENDN1                              (96+10)
#define NUM_ALL                                 (200)

//--------------------- PLL ----------------------------

#define rAPLL_LOCK (*(volatile unsigned int *)0xe0100000)
#define rMPLL_LOCK (*(volatile unsigned int *)0xe0100004)
#define rAPLL_CON0 (*(volatile unsigned int *)0xe0100100)
#define rAPLL_CON1 (*(volatile unsigned int *)0xe0100104)
#define rMPLL_CON  (*(volatile unsigned int *)0xe0100108)
#define rCLK_SRC0  (*(volatile unsigned int *)0xe0100200)
#define rCLK_SRC4  (*(volatile unsigned int *)0xe0100210)
#define rCLK_DIV0  (*(volatile unsigned int *)0xe0100300)
#define rCLK_DIV4  (*(volatile unsigned int *)0xe0100310)
#define rCLK_DIV6  (*(volatile unsigned int *)0xe0100318)






//--------------- lcd init ----------------------------
#define rDISPLAY_CONTROL (*(volatile unsigned long *)0xe0107008)

#define rVIDCON0                 (*(volatile unsigned long *)0xF8000000)
#define rVIDCON1                 (*(volatile unsigned long *)0xF8000004)
#define rVIDCON2                 (*(volatile unsigned long *)0xF8000008)
#define rVIDCON3                 (*(volatile unsigned long *)0xF800000c)
#define rVIDTCON0                (*(volatile unsigned long *)0xF8000010)
#define rVIDTCON1                (*(volatile unsigned long *)0xF8000014)
#define rVIDTCON2                (*(volatile unsigned long *)0xF8000018)
#define rVIDTCON3                (*(volatile unsigned long *)0xF800001c)
#define rWINCON0                 (*(volatile unsigned long *)0xF8000020)
#define rWINCON2                 (*(volatile unsigned long *)0xF8000028)
#define rSHADOWCON               (*(volatile unsigned long *)0xF8000034)
#define rVIDOSD0A                (*(volatile unsigned long *)0xF8000040)
#define rVIDOSD0B                (*(volatile unsigned long *)0xF8000044)
#define rVIDOSD0C                (*(volatile unsigned long *)0xF8000048)

#define rVIDW00ADD0B0    (*(volatile unsigned long *)0xF80000A0)
#define rVIDW00ADD1B0    (*(volatile unsigned long *)0xF80000D0)



// nand init----------------
#define rNFCONF 			( *((volatile unsigned long *)0xB0E00000) )
#define rNFCONT 			( *((volatile unsigned long *)0xB0E00004) )
#define rNFCMMD 			( *((volatile unsigned long *)0xB0E00008) )
#define rNFADDR 			( *((volatile unsigned long *)0xB0E0000C) )
#define rNFDATA 			( *((volatile unsigned long *)0xB0E00010) )
#define rNFSTAT 			( *((volatile unsigned long *)0xB0E00028) )

#define rMP0_1CON 		( *((volatile unsigned long *)0xE02002E0) )
#define rMP0_2CON 		( *((volatile unsigned long *)0xE0200300) )
#define rMP0_3CON 		( *((volatile unsigned long *)0xE0200320) )

//uart init--------------------
#define rGPA0CON (*(volatile unsigned *)0xe0200000)
#define rULCON0 (*(volatile unsigned *)0xe2900000)
#define rUCON0 (*(volatile unsigned *)0xe2900004)
#define rUFCON0 (*(volatile unsigned *)0xe2900008)
#define rUMCON0 (*(volatile unsigned *)0xe290000C)
#define rUBRDIV0 (*(volatile unsigned *)0xe2900028)
#define rDIVSLOT0 (*(volatile unsigned *)0xe290002C)
#define rUTRSTAT0 (*(volatile unsigned *)0xe2900010)
#define rURXH0 (*(volatile unsigned *)0xe2900024)
#define rUTXH0 (*(volatile unsigned *)0xe2900020)

//rtc init-------------------
#define			rINTP  		 		(*((volatile unsigned long *)(0xE2800030))) 
#define						rRTCCON  		  (*((volatile unsigned long *)(0xE2800040))) 
#define		    		rTICCNT  	    (*((volatile unsigned long *)(0xE2800044))) 
#define		        rRTCALM  	    (*((volatile unsigned long *)(0xE2800050))) 
#define		        rALMSEC  	    (*((volatile unsigned long *)(0xE2800054))) 
#define		        rALMMIN  	    (*((volatile unsigned long *)(0xE2800058))) 
#define	          rALMHOUR  	   (*((volatile unsigned long *)(0xE280005C))) 
#define		        rALMDAY  	    (*((volatile unsigned long *)(0xE2800060))) 
#define		        rALMMON  	    (*((volatile unsigned long *)(0xE2800064))) 
#define	          rALMYEAR  	    (*((volatile unsigned long *)(0xE2800068))) 
#define		        rBCDSEC  	    (*((volatile unsigned long *)(0xE2800070))) 
#define		        rBCDMIN  	    (*((volatile unsigned long *)(0xE2800074))) 
#define	          rBCDHOUR  	    (*((volatile unsigned long *)(0xE2800078))) 
#define	          rBCDDAYWEEK    (*((volatile unsigned long *)(0xE280007C))) 
#define		        rBCDDAY  	    (*((volatile unsigned long *)(0xE2800080))) 
#define		        rBCDMON  	    (*((volatile unsigned long *)(0xE2800084))) 
#define	          rBCDYEAR  	    (*((volatile unsigned long *)(0xE2800088))) 
#define	          rCURTICCNT     (*((volatile unsigned long *)(0xE2800090))) 

//---------------- iic ------------------------------------
#define rIICCON0                (*(volatile unsigned *)0xE1800000)
#define rIICSTAT0               (*(volatile unsigned *)0xE1800004)
#define rIICADD0                (*(volatile unsigned *)0xE1800008)      
#define rIICDS0                 (*(volatile unsigned *)0xE180000C)
#define rIICLC0                 (*(volatile unsigned *)0xE1800010)      

#define rIICCON2                (*(volatile unsigned *)0xE1A00000)
#define rIICSTAT2               (*(volatile unsigned *)0xE1A00004)
#define rIICADD2                (*(volatile unsigned *)0xE1A00008)      
#define rIICDS2                 (*(volatile unsigned *)0xE1A0000C)
#define rIICLC2                 (*(volatile unsigned *)0xE1A00010)  

//adc-----------------------------
#define		ADCTS_PRSCVL		65
#define 	ADCTS_BASE			0xE1700000
#define 	TSADCCON0			( *((volatile unsigned long *)(ADCTS_BASE+0x0)) )
#define    	TSCON0				( *((volatile unsigned long *)(ADCTS_BASE+0x4)) )
#define    	TSDLY0				( *((volatile unsigned long *)(ADCTS_BASE+0x8)) )
#define    	TSDATX0				( *((volatile unsigned long *)(ADCTS_BASE+0xc)) )
#define    	TSDATY0				( *((volatile unsigned long *)(ADCTS_BASE+0x10)) )
#define    	TSPENSTAT0			( *((volatile unsigned long *)(ADCTS_BASE+0x14)) )
#define    	CLRINTADC0			( *((volatile unsigned long *)(ADCTS_BASE+0x18)) )
#define  	ADCMUX				( *((volatile unsigned long *)(ADCTS_BASE+0x1c)) )
#define		CLRINTPEN0			( *((volatile unsigned long *)(ADCTS_BASE+0x20)) )

//timer
#define rTCFG0	(*(volatile unsigned int *)0xe2500000)
#define rTCFG1	(*(volatile unsigned int *)0xe2500004)
#define rTCON	(*(volatile unsigned int *)0xe2500008)
#define rTCNTB0	(*(volatile unsigned int *)0xe250000C)

#define rTCMPB0	(*(volatile unsigned int *)0xe2500010)

#define rTCNTB1	(*(volatile unsigned int *)0xe2500018)

#define rTCNTB4	(*(volatile unsigned int *)0xe250003C)

#define rTINT_CSTAT (*(volatile unsigned int *)0xe2500044)


//wtd------------------
#define rWTCON (*(volatile unsigned*)0xe2700000)
#define rWTDAT (*(volatile unsigned*)0xe2700004)
#define rWTCNT (*(volatile unsigned*)0xe2700008)
#define rWTCLRINT (*(volatile unsigned*)0xe270000c)


