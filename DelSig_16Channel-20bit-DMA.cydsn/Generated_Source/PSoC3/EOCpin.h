/*******************************************************************************
* File Name: EOCpin.h  
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

#if !defined(CY_PINS_EOCpin_H) /* Pins EOCpin_H */
#define CY_PINS_EOCpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "EOCpin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EOCpin_Write(uint8 value) ;
void    EOCpin_SetDriveMode(uint8 mode) ;
uint8   EOCpin_ReadDataReg(void) ;
uint8   EOCpin_Read(void) ;
uint8   EOCpin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EOCpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define EOCpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define EOCpin_DM_RES_UP          PIN_DM_RES_UP
#define EOCpin_DM_RES_DWN         PIN_DM_RES_DWN
#define EOCpin_DM_OD_LO           PIN_DM_OD_LO
#define EOCpin_DM_OD_HI           PIN_DM_OD_HI
#define EOCpin_DM_STRONG          PIN_DM_STRONG
#define EOCpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define EOCpin_MASK               EOCpin__MASK
#define EOCpin_SHIFT              EOCpin__SHIFT
#define EOCpin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EOCpin_PS                     (* (reg8 *) EOCpin__PS)
/* Data Register */
#define EOCpin_DR                     (* (reg8 *) EOCpin__DR)
/* Port Number */
#define EOCpin_PRT_NUM                (* (reg8 *) EOCpin__PRT) 
/* Connect to Analog Globals */                                                  
#define EOCpin_AG                     (* (reg8 *) EOCpin__AG)                       
/* Analog MUX bux enable */
#define EOCpin_AMUX                   (* (reg8 *) EOCpin__AMUX) 
/* Bidirectional Enable */                                                        
#define EOCpin_BIE                    (* (reg8 *) EOCpin__BIE)
/* Bit-mask for Aliased Register Access */
#define EOCpin_BIT_MASK               (* (reg8 *) EOCpin__BIT_MASK)
/* Bypass Enable */
#define EOCpin_BYP                    (* (reg8 *) EOCpin__BYP)
/* Port wide control signals */                                                   
#define EOCpin_CTL                    (* (reg8 *) EOCpin__CTL)
/* Drive Modes */
#define EOCpin_DM0                    (* (reg8 *) EOCpin__DM0) 
#define EOCpin_DM1                    (* (reg8 *) EOCpin__DM1)
#define EOCpin_DM2                    (* (reg8 *) EOCpin__DM2) 
/* Input Buffer Disable Override */
#define EOCpin_INP_DIS                (* (reg8 *) EOCpin__INP_DIS)
/* LCD Common or Segment Drive */
#define EOCpin_LCD_COM_SEG            (* (reg8 *) EOCpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define EOCpin_LCD_EN                 (* (reg8 *) EOCpin__LCD_EN)
/* Slew Rate Control */
#define EOCpin_SLW                    (* (reg8 *) EOCpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define EOCpin_PRTDSI__CAPS_SEL       (* (reg8 *) EOCpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define EOCpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) EOCpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define EOCpin_PRTDSI__OE_SEL0        (* (reg8 *) EOCpin__PRTDSI__OE_SEL0) 
#define EOCpin_PRTDSI__OE_SEL1        (* (reg8 *) EOCpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define EOCpin_PRTDSI__OUT_SEL0       (* (reg8 *) EOCpin__PRTDSI__OUT_SEL0) 
#define EOCpin_PRTDSI__OUT_SEL1       (* (reg8 *) EOCpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define EOCpin_PRTDSI__SYNC_OUT       (* (reg8 *) EOCpin__PRTDSI__SYNC_OUT) 


#if defined(EOCpin__INTSTAT)  /* Interrupt Registers */

    #define EOCpin_INTSTAT                (* (reg8 *) EOCpin__INTSTAT)
    #define EOCpin_SNAP                   (* (reg8 *) EOCpin__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins EOCpin_H */


/* [] END OF FILE */
