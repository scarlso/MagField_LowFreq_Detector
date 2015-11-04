/*******************************************************************************
* File Name: CH_PD.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CH_PD_H) /* Pins CH_PD_H */
#define CY_PINS_CH_PD_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CH_PD_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CH_PD__PORT == 15 && ((CH_PD__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CH_PD_Write(uint8 value) ;
void    CH_PD_SetDriveMode(uint8 mode) ;
uint8   CH_PD_ReadDataReg(void) ;
uint8   CH_PD_Read(void) ;
uint8   CH_PD_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CH_PD_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CH_PD_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CH_PD_DM_RES_UP          PIN_DM_RES_UP
#define CH_PD_DM_RES_DWN         PIN_DM_RES_DWN
#define CH_PD_DM_OD_LO           PIN_DM_OD_LO
#define CH_PD_DM_OD_HI           PIN_DM_OD_HI
#define CH_PD_DM_STRONG          PIN_DM_STRONG
#define CH_PD_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CH_PD_MASK               CH_PD__MASK
#define CH_PD_SHIFT              CH_PD__SHIFT
#define CH_PD_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CH_PD_PS                     (* (reg8 *) CH_PD__PS)
/* Data Register */
#define CH_PD_DR                     (* (reg8 *) CH_PD__DR)
/* Port Number */
#define CH_PD_PRT_NUM                (* (reg8 *) CH_PD__PRT) 
/* Connect to Analog Globals */                                                  
#define CH_PD_AG                     (* (reg8 *) CH_PD__AG)                       
/* Analog MUX bux enable */
#define CH_PD_AMUX                   (* (reg8 *) CH_PD__AMUX) 
/* Bidirectional Enable */                                                        
#define CH_PD_BIE                    (* (reg8 *) CH_PD__BIE)
/* Bit-mask for Aliased Register Access */
#define CH_PD_BIT_MASK               (* (reg8 *) CH_PD__BIT_MASK)
/* Bypass Enable */
#define CH_PD_BYP                    (* (reg8 *) CH_PD__BYP)
/* Port wide control signals */                                                   
#define CH_PD_CTL                    (* (reg8 *) CH_PD__CTL)
/* Drive Modes */
#define CH_PD_DM0                    (* (reg8 *) CH_PD__DM0) 
#define CH_PD_DM1                    (* (reg8 *) CH_PD__DM1)
#define CH_PD_DM2                    (* (reg8 *) CH_PD__DM2) 
/* Input Buffer Disable Override */
#define CH_PD_INP_DIS                (* (reg8 *) CH_PD__INP_DIS)
/* LCD Common or Segment Drive */
#define CH_PD_LCD_COM_SEG            (* (reg8 *) CH_PD__LCD_COM_SEG)
/* Enable Segment LCD */
#define CH_PD_LCD_EN                 (* (reg8 *) CH_PD__LCD_EN)
/* Slew Rate Control */
#define CH_PD_SLW                    (* (reg8 *) CH_PD__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CH_PD_PRTDSI__CAPS_SEL       (* (reg8 *) CH_PD__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CH_PD_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CH_PD__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CH_PD_PRTDSI__OE_SEL0        (* (reg8 *) CH_PD__PRTDSI__OE_SEL0) 
#define CH_PD_PRTDSI__OE_SEL1        (* (reg8 *) CH_PD__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CH_PD_PRTDSI__OUT_SEL0       (* (reg8 *) CH_PD__PRTDSI__OUT_SEL0) 
#define CH_PD_PRTDSI__OUT_SEL1       (* (reg8 *) CH_PD__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CH_PD_PRTDSI__SYNC_OUT       (* (reg8 *) CH_PD__PRTDSI__SYNC_OUT) 


#if defined(CH_PD__INTSTAT)  /* Interrupt Registers */

    #define CH_PD_INTSTAT                (* (reg8 *) CH_PD__INTSTAT)
    #define CH_PD_SNAP                   (* (reg8 *) CH_PD__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CH_PD_H */


/* [] END OF FILE */
