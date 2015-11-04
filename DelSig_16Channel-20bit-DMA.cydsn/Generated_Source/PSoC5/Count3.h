/*******************************************************************************
* File Name: Count3.h  
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

#if !defined(CY_PINS_Count3_H) /* Pins Count3_H */
#define CY_PINS_Count3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Count3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Count3__PORT == 15 && ((Count3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Count3_Write(uint8 value) ;
void    Count3_SetDriveMode(uint8 mode) ;
uint8   Count3_ReadDataReg(void) ;
uint8   Count3_Read(void) ;
uint8   Count3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Count3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Count3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Count3_DM_RES_UP          PIN_DM_RES_UP
#define Count3_DM_RES_DWN         PIN_DM_RES_DWN
#define Count3_DM_OD_LO           PIN_DM_OD_LO
#define Count3_DM_OD_HI           PIN_DM_OD_HI
#define Count3_DM_STRONG          PIN_DM_STRONG
#define Count3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Count3_MASK               Count3__MASK
#define Count3_SHIFT              Count3__SHIFT
#define Count3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Count3_PS                     (* (reg8 *) Count3__PS)
/* Data Register */
#define Count3_DR                     (* (reg8 *) Count3__DR)
/* Port Number */
#define Count3_PRT_NUM                (* (reg8 *) Count3__PRT) 
/* Connect to Analog Globals */                                                  
#define Count3_AG                     (* (reg8 *) Count3__AG)                       
/* Analog MUX bux enable */
#define Count3_AMUX                   (* (reg8 *) Count3__AMUX) 
/* Bidirectional Enable */                                                        
#define Count3_BIE                    (* (reg8 *) Count3__BIE)
/* Bit-mask for Aliased Register Access */
#define Count3_BIT_MASK               (* (reg8 *) Count3__BIT_MASK)
/* Bypass Enable */
#define Count3_BYP                    (* (reg8 *) Count3__BYP)
/* Port wide control signals */                                                   
#define Count3_CTL                    (* (reg8 *) Count3__CTL)
/* Drive Modes */
#define Count3_DM0                    (* (reg8 *) Count3__DM0) 
#define Count3_DM1                    (* (reg8 *) Count3__DM1)
#define Count3_DM2                    (* (reg8 *) Count3__DM2) 
/* Input Buffer Disable Override */
#define Count3_INP_DIS                (* (reg8 *) Count3__INP_DIS)
/* LCD Common or Segment Drive */
#define Count3_LCD_COM_SEG            (* (reg8 *) Count3__LCD_COM_SEG)
/* Enable Segment LCD */
#define Count3_LCD_EN                 (* (reg8 *) Count3__LCD_EN)
/* Slew Rate Control */
#define Count3_SLW                    (* (reg8 *) Count3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Count3_PRTDSI__CAPS_SEL       (* (reg8 *) Count3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Count3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Count3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Count3_PRTDSI__OE_SEL0        (* (reg8 *) Count3__PRTDSI__OE_SEL0) 
#define Count3_PRTDSI__OE_SEL1        (* (reg8 *) Count3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Count3_PRTDSI__OUT_SEL0       (* (reg8 *) Count3__PRTDSI__OUT_SEL0) 
#define Count3_PRTDSI__OUT_SEL1       (* (reg8 *) Count3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Count3_PRTDSI__SYNC_OUT       (* (reg8 *) Count3__PRTDSI__SYNC_OUT) 


#if defined(Count3__INTSTAT)  /* Interrupt Registers */

    #define Count3_INTSTAT                (* (reg8 *) Count3__INTSTAT)
    #define Count3_SNAP                   (* (reg8 *) Count3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Count3_H */


/* [] END OF FILE */
