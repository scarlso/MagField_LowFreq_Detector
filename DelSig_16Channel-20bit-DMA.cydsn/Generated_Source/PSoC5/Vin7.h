/*******************************************************************************
* File Name: Vin7.h  
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

#if !defined(CY_PINS_Vin7_H) /* Pins Vin7_H */
#define CY_PINS_Vin7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vin7_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vin7__PORT == 15 && ((Vin7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Vin7_Write(uint8 value) ;
void    Vin7_SetDriveMode(uint8 mode) ;
uint8   Vin7_ReadDataReg(void) ;
uint8   Vin7_Read(void) ;
uint8   Vin7_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vin7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vin7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vin7_DM_RES_UP          PIN_DM_RES_UP
#define Vin7_DM_RES_DWN         PIN_DM_RES_DWN
#define Vin7_DM_OD_LO           PIN_DM_OD_LO
#define Vin7_DM_OD_HI           PIN_DM_OD_HI
#define Vin7_DM_STRONG          PIN_DM_STRONG
#define Vin7_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vin7_MASK               Vin7__MASK
#define Vin7_SHIFT              Vin7__SHIFT
#define Vin7_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vin7_PS                     (* (reg8 *) Vin7__PS)
/* Data Register */
#define Vin7_DR                     (* (reg8 *) Vin7__DR)
/* Port Number */
#define Vin7_PRT_NUM                (* (reg8 *) Vin7__PRT) 
/* Connect to Analog Globals */                                                  
#define Vin7_AG                     (* (reg8 *) Vin7__AG)                       
/* Analog MUX bux enable */
#define Vin7_AMUX                   (* (reg8 *) Vin7__AMUX) 
/* Bidirectional Enable */                                                        
#define Vin7_BIE                    (* (reg8 *) Vin7__BIE)
/* Bit-mask for Aliased Register Access */
#define Vin7_BIT_MASK               (* (reg8 *) Vin7__BIT_MASK)
/* Bypass Enable */
#define Vin7_BYP                    (* (reg8 *) Vin7__BYP)
/* Port wide control signals */                                                   
#define Vin7_CTL                    (* (reg8 *) Vin7__CTL)
/* Drive Modes */
#define Vin7_DM0                    (* (reg8 *) Vin7__DM0) 
#define Vin7_DM1                    (* (reg8 *) Vin7__DM1)
#define Vin7_DM2                    (* (reg8 *) Vin7__DM2) 
/* Input Buffer Disable Override */
#define Vin7_INP_DIS                (* (reg8 *) Vin7__INP_DIS)
/* LCD Common or Segment Drive */
#define Vin7_LCD_COM_SEG            (* (reg8 *) Vin7__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vin7_LCD_EN                 (* (reg8 *) Vin7__LCD_EN)
/* Slew Rate Control */
#define Vin7_SLW                    (* (reg8 *) Vin7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vin7_PRTDSI__CAPS_SEL       (* (reg8 *) Vin7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vin7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vin7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vin7_PRTDSI__OE_SEL0        (* (reg8 *) Vin7__PRTDSI__OE_SEL0) 
#define Vin7_PRTDSI__OE_SEL1        (* (reg8 *) Vin7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vin7_PRTDSI__OUT_SEL0       (* (reg8 *) Vin7__PRTDSI__OUT_SEL0) 
#define Vin7_PRTDSI__OUT_SEL1       (* (reg8 *) Vin7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vin7_PRTDSI__SYNC_OUT       (* (reg8 *) Vin7__PRTDSI__SYNC_OUT) 


#if defined(Vin7__INTSTAT)  /* Interrupt Registers */

    #define Vin7_INTSTAT                (* (reg8 *) Vin7__INTSTAT)
    #define Vin7_SNAP                   (* (reg8 *) Vin7__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vin7_H */


/* [] END OF FILE */
