/*******************************************************************************
* File Name: Count2.h  
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

#if !defined(CY_PINS_Count2_H) /* Pins Count2_H */
#define CY_PINS_Count2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Count2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Count2_Write(uint8 value) ;
void    Count2_SetDriveMode(uint8 mode) ;
uint8   Count2_ReadDataReg(void) ;
uint8   Count2_Read(void) ;
uint8   Count2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Count2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Count2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Count2_DM_RES_UP          PIN_DM_RES_UP
#define Count2_DM_RES_DWN         PIN_DM_RES_DWN
#define Count2_DM_OD_LO           PIN_DM_OD_LO
#define Count2_DM_OD_HI           PIN_DM_OD_HI
#define Count2_DM_STRONG          PIN_DM_STRONG
#define Count2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Count2_MASK               Count2__MASK
#define Count2_SHIFT              Count2__SHIFT
#define Count2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Count2_PS                     (* (reg8 *) Count2__PS)
/* Data Register */
#define Count2_DR                     (* (reg8 *) Count2__DR)
/* Port Number */
#define Count2_PRT_NUM                (* (reg8 *) Count2__PRT) 
/* Connect to Analog Globals */                                                  
#define Count2_AG                     (* (reg8 *) Count2__AG)                       
/* Analog MUX bux enable */
#define Count2_AMUX                   (* (reg8 *) Count2__AMUX) 
/* Bidirectional Enable */                                                        
#define Count2_BIE                    (* (reg8 *) Count2__BIE)
/* Bit-mask for Aliased Register Access */
#define Count2_BIT_MASK               (* (reg8 *) Count2__BIT_MASK)
/* Bypass Enable */
#define Count2_BYP                    (* (reg8 *) Count2__BYP)
/* Port wide control signals */                                                   
#define Count2_CTL                    (* (reg8 *) Count2__CTL)
/* Drive Modes */
#define Count2_DM0                    (* (reg8 *) Count2__DM0) 
#define Count2_DM1                    (* (reg8 *) Count2__DM1)
#define Count2_DM2                    (* (reg8 *) Count2__DM2) 
/* Input Buffer Disable Override */
#define Count2_INP_DIS                (* (reg8 *) Count2__INP_DIS)
/* LCD Common or Segment Drive */
#define Count2_LCD_COM_SEG            (* (reg8 *) Count2__LCD_COM_SEG)
/* Enable Segment LCD */
#define Count2_LCD_EN                 (* (reg8 *) Count2__LCD_EN)
/* Slew Rate Control */
#define Count2_SLW                    (* (reg8 *) Count2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Count2_PRTDSI__CAPS_SEL       (* (reg8 *) Count2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Count2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Count2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Count2_PRTDSI__OE_SEL0        (* (reg8 *) Count2__PRTDSI__OE_SEL0) 
#define Count2_PRTDSI__OE_SEL1        (* (reg8 *) Count2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Count2_PRTDSI__OUT_SEL0       (* (reg8 *) Count2__PRTDSI__OUT_SEL0) 
#define Count2_PRTDSI__OUT_SEL1       (* (reg8 *) Count2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Count2_PRTDSI__SYNC_OUT       (* (reg8 *) Count2__PRTDSI__SYNC_OUT) 


#if defined(Count2__INTSTAT)  /* Interrupt Registers */

    #define Count2_INTSTAT                (* (reg8 *) Count2__INTSTAT)
    #define Count2_SNAP                   (* (reg8 *) Count2__SNAP)

#endif /* Interrupt Registers */

#endif /* End Pins Count2_H */


/* [] END OF FILE */
