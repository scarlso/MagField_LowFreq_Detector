/*******************************************************************************
* File Name: Vin0.h  
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

#if !defined(CY_PINS_Vin0_H) /* Pins Vin0_H */
#define CY_PINS_Vin0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vin0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vin0__PORT == 15 && ((Vin0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Vin0_Write(uint8 value) ;
void    Vin0_SetDriveMode(uint8 mode) ;
uint8   Vin0_ReadDataReg(void) ;
uint8   Vin0_Read(void) ;
uint8   Vin0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vin0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vin0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vin0_DM_RES_UP          PIN_DM_RES_UP
#define Vin0_DM_RES_DWN         PIN_DM_RES_DWN
#define Vin0_DM_OD_LO           PIN_DM_OD_LO
#define Vin0_DM_OD_HI           PIN_DM_OD_HI
#define Vin0_DM_STRONG          PIN_DM_STRONG
#define Vin0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vin0_MASK               Vin0__MASK
#define Vin0_SHIFT              Vin0__SHIFT
#define Vin0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vin0_PS                     (* (reg8 *) Vin0__PS)
/* Data Register */
#define Vin0_DR                     (* (reg8 *) Vin0__DR)
/* Port Number */
#define Vin0_PRT_NUM                (* (reg8 *) Vin0__PRT) 
/* Connect to Analog Globals */                                                  
#define Vin0_AG                     (* (reg8 *) Vin0__AG)                       
/* Analog MUX bux enable */
#define Vin0_AMUX                   (* (reg8 *) Vin0__AMUX) 
/* Bidirectional Enable */                                                        
#define Vin0_BIE                    (* (reg8 *) Vin0__BIE)
/* Bit-mask for Aliased Register Access */
#define Vin0_BIT_MASK               (* (reg8 *) Vin0__BIT_MASK)
/* Bypass Enable */
#define Vin0_BYP                    (* (reg8 *) Vin0__BYP)
/* Port wide control signals */                                                   
#define Vin0_CTL                    (* (reg8 *) Vin0__CTL)
/* Drive Modes */
#define Vin0_DM0                    (* (reg8 *) Vin0__DM0) 
#define Vin0_DM1                    (* (reg8 *) Vin0__DM1)
#define Vin0_DM2                    (* (reg8 *) Vin0__DM2) 
/* Input Buffer Disable Override */
#define Vin0_INP_DIS                (* (reg8 *) Vin0__INP_DIS)
/* LCD Common or Segment Drive */
#define Vin0_LCD_COM_SEG            (* (reg8 *) Vin0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vin0_LCD_EN                 (* (reg8 *) Vin0__LCD_EN)
/* Slew Rate Control */
#define Vin0_SLW                    (* (reg8 *) Vin0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vin0_PRTDSI__CAPS_SEL       (* (reg8 *) Vin0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vin0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vin0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vin0_PRTDSI__OE_SEL0        (* (reg8 *) Vin0__PRTDSI__OE_SEL0) 
#define Vin0_PRTDSI__OE_SEL1        (* (reg8 *) Vin0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vin0_PRTDSI__OUT_SEL0       (* (reg8 *) Vin0__PRTDSI__OUT_SEL0) 
#define Vin0_PRTDSI__OUT_SEL1       (* (reg8 *) Vin0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vin0_PRTDSI__SYNC_OUT       (* (reg8 *) Vin0__PRTDSI__SYNC_OUT) 


#if defined(Vin0__INTSTAT)  /* Interrupt Registers */

    #define Vin0_INTSTAT                (* (reg8 *) Vin0__INTSTAT)
    #define Vin0_SNAP                   (* (reg8 *) Vin0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vin0_H */


/* [] END OF FILE */
