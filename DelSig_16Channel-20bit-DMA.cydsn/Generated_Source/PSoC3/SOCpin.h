/*******************************************************************************
* File Name: SOCpin.h  
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

#if !defined(CY_PINS_SOCpin_H) /* Pins SOCpin_H */
#define CY_PINS_SOCpin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SOCpin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    SOCpin_Write(uint8 value) ;
void    SOCpin_SetDriveMode(uint8 mode) ;
uint8   SOCpin_ReadDataReg(void) ;
uint8   SOCpin_Read(void) ;
uint8   SOCpin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SOCpin_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SOCpin_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SOCpin_DM_RES_UP          PIN_DM_RES_UP
#define SOCpin_DM_RES_DWN         PIN_DM_RES_DWN
#define SOCpin_DM_OD_LO           PIN_DM_OD_LO
#define SOCpin_DM_OD_HI           PIN_DM_OD_HI
#define SOCpin_DM_STRONG          PIN_DM_STRONG
#define SOCpin_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SOCpin_MASK               SOCpin__MASK
#define SOCpin_SHIFT              SOCpin__SHIFT
#define SOCpin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SOCpin_PS                     (* (reg8 *) SOCpin__PS)
/* Data Register */
#define SOCpin_DR                     (* (reg8 *) SOCpin__DR)
/* Port Number */
#define SOCpin_PRT_NUM                (* (reg8 *) SOCpin__PRT) 
/* Connect to Analog Globals */                                                  
#define SOCpin_AG                     (* (reg8 *) SOCpin__AG)                       
/* Analog MUX bux enable */
#define SOCpin_AMUX                   (* (reg8 *) SOCpin__AMUX) 
/* Bidirectional Enable */                                                        
#define SOCpin_BIE                    (* (reg8 *) SOCpin__BIE)
/* Bit-mask for Aliased Register Access */
#define SOCpin_BIT_MASK               (* (reg8 *) SOCpin__BIT_MASK)
/* Bypass Enable */
#define SOCpin_BYP                    (* (reg8 *) SOCpin__BYP)
/* Port wide control signals */                                                   
#define SOCpin_CTL                    (* (reg8 *) SOCpin__CTL)
/* Drive Modes */
#define SOCpin_DM0                    (* (reg8 *) SOCpin__DM0) 
#define SOCpin_DM1                    (* (reg8 *) SOCpin__DM1)
#define SOCpin_DM2                    (* (reg8 *) SOCpin__DM2) 
/* Input Buffer Disable Override */
#define SOCpin_INP_DIS                (* (reg8 *) SOCpin__INP_DIS)
/* LCD Common or Segment Drive */
#define SOCpin_LCD_COM_SEG            (* (reg8 *) SOCpin__LCD_COM_SEG)
/* Enable Segment LCD */
#define SOCpin_LCD_EN                 (* (reg8 *) SOCpin__LCD_EN)
/* Slew Rate Control */
#define SOCpin_SLW                    (* (reg8 *) SOCpin__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SOCpin_PRTDSI__CAPS_SEL       (* (reg8 *) SOCpin__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SOCpin_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SOCpin__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SOCpin_PRTDSI__OE_SEL0        (* (reg8 *) SOCpin__PRTDSI__OE_SEL0) 
#define SOCpin_PRTDSI__OE_SEL1        (* (reg8 *) SOCpin__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SOCpin_PRTDSI__OUT_SEL0       (* (reg8 *) SOCpin__PRTDSI__OUT_SEL0) 
#define SOCpin_PRTDSI__OUT_SEL1       (* (reg8 *) SOCpin__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SOCpin_PRTDSI__SYNC_OUT       (* (reg8 *) SOCpin__PRTDSI__SYNC_OUT) 


#if defined(SOCpin__INTSTAT)  /* Interrupt Registers */

    #define SOCpin_INTSTAT                (* (reg8 *) SOCpin__INTSTAT)
    #define SOCpin_SNAP                   (* (reg8 *) SOCpin__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins SOCpin_H */


/* [] END OF FILE */
