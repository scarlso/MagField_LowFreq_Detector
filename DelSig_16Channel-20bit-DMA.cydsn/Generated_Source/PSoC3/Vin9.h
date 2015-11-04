/*******************************************************************************
* File Name: Vin9.h  
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

#if !defined(CY_PINS_Vin9_H) /* Pins Vin9_H */
#define CY_PINS_Vin9_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vin9_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vin9_Write(uint8 value) ;
void    Vin9_SetDriveMode(uint8 mode) ;
uint8   Vin9_ReadDataReg(void) ;
uint8   Vin9_Read(void) ;
uint8   Vin9_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vin9_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vin9_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vin9_DM_RES_UP          PIN_DM_RES_UP
#define Vin9_DM_RES_DWN         PIN_DM_RES_DWN
#define Vin9_DM_OD_LO           PIN_DM_OD_LO
#define Vin9_DM_OD_HI           PIN_DM_OD_HI
#define Vin9_DM_STRONG          PIN_DM_STRONG
#define Vin9_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vin9_MASK               Vin9__MASK
#define Vin9_SHIFT              Vin9__SHIFT
#define Vin9_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vin9_PS                     (* (reg8 *) Vin9__PS)
/* Data Register */
#define Vin9_DR                     (* (reg8 *) Vin9__DR)
/* Port Number */
#define Vin9_PRT_NUM                (* (reg8 *) Vin9__PRT) 
/* Connect to Analog Globals */                                                  
#define Vin9_AG                     (* (reg8 *) Vin9__AG)                       
/* Analog MUX bux enable */
#define Vin9_AMUX                   (* (reg8 *) Vin9__AMUX) 
/* Bidirectional Enable */                                                        
#define Vin9_BIE                    (* (reg8 *) Vin9__BIE)
/* Bit-mask for Aliased Register Access */
#define Vin9_BIT_MASK               (* (reg8 *) Vin9__BIT_MASK)
/* Bypass Enable */
#define Vin9_BYP                    (* (reg8 *) Vin9__BYP)
/* Port wide control signals */                                                   
#define Vin9_CTL                    (* (reg8 *) Vin9__CTL)
/* Drive Modes */
#define Vin9_DM0                    (* (reg8 *) Vin9__DM0) 
#define Vin9_DM1                    (* (reg8 *) Vin9__DM1)
#define Vin9_DM2                    (* (reg8 *) Vin9__DM2) 
/* Input Buffer Disable Override */
#define Vin9_INP_DIS                (* (reg8 *) Vin9__INP_DIS)
/* LCD Common or Segment Drive */
#define Vin9_LCD_COM_SEG            (* (reg8 *) Vin9__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vin9_LCD_EN                 (* (reg8 *) Vin9__LCD_EN)
/* Slew Rate Control */
#define Vin9_SLW                    (* (reg8 *) Vin9__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vin9_PRTDSI__CAPS_SEL       (* (reg8 *) Vin9__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vin9_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vin9__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vin9_PRTDSI__OE_SEL0        (* (reg8 *) Vin9__PRTDSI__OE_SEL0) 
#define Vin9_PRTDSI__OE_SEL1        (* (reg8 *) Vin9__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vin9_PRTDSI__OUT_SEL0       (* (reg8 *) Vin9__PRTDSI__OUT_SEL0) 
#define Vin9_PRTDSI__OUT_SEL1       (* (reg8 *) Vin9__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vin9_PRTDSI__SYNC_OUT       (* (reg8 *) Vin9__PRTDSI__SYNC_OUT) 


#if defined(Vin9__INTSTAT)  /* Interrupt Registers */

    #define Vin9_INTSTAT                (* (reg8 *) Vin9__INTSTAT)
    #define Vin9_SNAP                   (* (reg8 *) Vin9__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Vin9_H */


/* [] END OF FILE */
