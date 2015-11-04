/*******************************************************************************
* File Name: VinE.h  
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

#if !defined(CY_PINS_VinE_H) /* Pins VinE_H */
#define CY_PINS_VinE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VinE_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    VinE_Write(uint8 value) ;
void    VinE_SetDriveMode(uint8 mode) ;
uint8   VinE_ReadDataReg(void) ;
uint8   VinE_Read(void) ;
uint8   VinE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VinE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VinE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VinE_DM_RES_UP          PIN_DM_RES_UP
#define VinE_DM_RES_DWN         PIN_DM_RES_DWN
#define VinE_DM_OD_LO           PIN_DM_OD_LO
#define VinE_DM_OD_HI           PIN_DM_OD_HI
#define VinE_DM_STRONG          PIN_DM_STRONG
#define VinE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VinE_MASK               VinE__MASK
#define VinE_SHIFT              VinE__SHIFT
#define VinE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VinE_PS                     (* (reg8 *) VinE__PS)
/* Data Register */
#define VinE_DR                     (* (reg8 *) VinE__DR)
/* Port Number */
#define VinE_PRT_NUM                (* (reg8 *) VinE__PRT) 
/* Connect to Analog Globals */                                                  
#define VinE_AG                     (* (reg8 *) VinE__AG)                       
/* Analog MUX bux enable */
#define VinE_AMUX                   (* (reg8 *) VinE__AMUX) 
/* Bidirectional Enable */                                                        
#define VinE_BIE                    (* (reg8 *) VinE__BIE)
/* Bit-mask for Aliased Register Access */
#define VinE_BIT_MASK               (* (reg8 *) VinE__BIT_MASK)
/* Bypass Enable */
#define VinE_BYP                    (* (reg8 *) VinE__BYP)
/* Port wide control signals */                                                   
#define VinE_CTL                    (* (reg8 *) VinE__CTL)
/* Drive Modes */
#define VinE_DM0                    (* (reg8 *) VinE__DM0) 
#define VinE_DM1                    (* (reg8 *) VinE__DM1)
#define VinE_DM2                    (* (reg8 *) VinE__DM2) 
/* Input Buffer Disable Override */
#define VinE_INP_DIS                (* (reg8 *) VinE__INP_DIS)
/* LCD Common or Segment Drive */
#define VinE_LCD_COM_SEG            (* (reg8 *) VinE__LCD_COM_SEG)
/* Enable Segment LCD */
#define VinE_LCD_EN                 (* (reg8 *) VinE__LCD_EN)
/* Slew Rate Control */
#define VinE_SLW                    (* (reg8 *) VinE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VinE_PRTDSI__CAPS_SEL       (* (reg8 *) VinE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VinE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VinE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VinE_PRTDSI__OE_SEL0        (* (reg8 *) VinE__PRTDSI__OE_SEL0) 
#define VinE_PRTDSI__OE_SEL1        (* (reg8 *) VinE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VinE_PRTDSI__OUT_SEL0       (* (reg8 *) VinE__PRTDSI__OUT_SEL0) 
#define VinE_PRTDSI__OUT_SEL1       (* (reg8 *) VinE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VinE_PRTDSI__SYNC_OUT       (* (reg8 *) VinE__PRTDSI__SYNC_OUT) 


#if defined(VinE__INTSTAT)  /* Interrupt Registers */

    #define VinE_INTSTAT                (* (reg8 *) VinE__INTSTAT)
    #define VinE_SNAP                   (* (reg8 *) VinE__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins VinE_H */


/* [] END OF FILE */
