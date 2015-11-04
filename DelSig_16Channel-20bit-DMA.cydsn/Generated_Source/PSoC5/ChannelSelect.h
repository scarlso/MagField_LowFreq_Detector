/*******************************************************************************
* File Name: ChannelSelect.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ChannelSelect_H) /* Pins ChannelSelect_H */
#define CY_PINS_ChannelSelect_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ChannelSelect_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ChannelSelect__PORT == 15 && ((ChannelSelect__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ChannelSelect_Write(uint8 value) ;
void    ChannelSelect_SetDriveMode(uint8 mode) ;
uint8   ChannelSelect_ReadDataReg(void) ;
uint8   ChannelSelect_Read(void) ;
uint8   ChannelSelect_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ChannelSelect_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ChannelSelect_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ChannelSelect_DM_RES_UP          PIN_DM_RES_UP
#define ChannelSelect_DM_RES_DWN         PIN_DM_RES_DWN
#define ChannelSelect_DM_OD_LO           PIN_DM_OD_LO
#define ChannelSelect_DM_OD_HI           PIN_DM_OD_HI
#define ChannelSelect_DM_STRONG          PIN_DM_STRONG
#define ChannelSelect_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ChannelSelect_MASK               ChannelSelect__MASK
#define ChannelSelect_SHIFT              ChannelSelect__SHIFT
#define ChannelSelect_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ChannelSelect_PS                     (* (reg8 *) ChannelSelect__PS)
/* Data Register */
#define ChannelSelect_DR                     (* (reg8 *) ChannelSelect__DR)
/* Port Number */
#define ChannelSelect_PRT_NUM                (* (reg8 *) ChannelSelect__PRT) 
/* Connect to Analog Globals */                                                  
#define ChannelSelect_AG                     (* (reg8 *) ChannelSelect__AG)                       
/* Analog MUX bux enable */
#define ChannelSelect_AMUX                   (* (reg8 *) ChannelSelect__AMUX) 
/* Bidirectional Enable */                                                        
#define ChannelSelect_BIE                    (* (reg8 *) ChannelSelect__BIE)
/* Bit-mask for Aliased Register Access */
#define ChannelSelect_BIT_MASK               (* (reg8 *) ChannelSelect__BIT_MASK)
/* Bypass Enable */
#define ChannelSelect_BYP                    (* (reg8 *) ChannelSelect__BYP)
/* Port wide control signals */                                                   
#define ChannelSelect_CTL                    (* (reg8 *) ChannelSelect__CTL)
/* Drive Modes */
#define ChannelSelect_DM0                    (* (reg8 *) ChannelSelect__DM0) 
#define ChannelSelect_DM1                    (* (reg8 *) ChannelSelect__DM1)
#define ChannelSelect_DM2                    (* (reg8 *) ChannelSelect__DM2) 
/* Input Buffer Disable Override */
#define ChannelSelect_INP_DIS                (* (reg8 *) ChannelSelect__INP_DIS)
/* LCD Common or Segment Drive */
#define ChannelSelect_LCD_COM_SEG            (* (reg8 *) ChannelSelect__LCD_COM_SEG)
/* Enable Segment LCD */
#define ChannelSelect_LCD_EN                 (* (reg8 *) ChannelSelect__LCD_EN)
/* Slew Rate Control */
#define ChannelSelect_SLW                    (* (reg8 *) ChannelSelect__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ChannelSelect_PRTDSI__CAPS_SEL       (* (reg8 *) ChannelSelect__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ChannelSelect_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ChannelSelect__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ChannelSelect_PRTDSI__OE_SEL0        (* (reg8 *) ChannelSelect__PRTDSI__OE_SEL0) 
#define ChannelSelect_PRTDSI__OE_SEL1        (* (reg8 *) ChannelSelect__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ChannelSelect_PRTDSI__OUT_SEL0       (* (reg8 *) ChannelSelect__PRTDSI__OUT_SEL0) 
#define ChannelSelect_PRTDSI__OUT_SEL1       (* (reg8 *) ChannelSelect__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ChannelSelect_PRTDSI__SYNC_OUT       (* (reg8 *) ChannelSelect__PRTDSI__SYNC_OUT) 


#if defined(ChannelSelect__INTSTAT)  /* Interrupt Registers */

    #define ChannelSelect_INTSTAT                (* (reg8 *) ChannelSelect__INTSTAT)
    #define ChannelSelect_SNAP                   (* (reg8 *) ChannelSelect__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ChannelSelect_H */


/* [] END OF FILE */
