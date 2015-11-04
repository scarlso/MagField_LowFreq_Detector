/*******************************************************************************
* File Name: Vin1.h  
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

#if !defined(CY_PINS_Vin1_H) /* Pins Vin1_H */
#define CY_PINS_Vin1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Vin1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Vin1__PORT == 15 && ((Vin1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Vin1_Write(uint8 value) ;
void    Vin1_SetDriveMode(uint8 mode) ;
uint8   Vin1_ReadDataReg(void) ;
uint8   Vin1_Read(void) ;
uint8   Vin1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vin1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Vin1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Vin1_DM_RES_UP          PIN_DM_RES_UP
#define Vin1_DM_RES_DWN         PIN_DM_RES_DWN
#define Vin1_DM_OD_LO           PIN_DM_OD_LO
#define Vin1_DM_OD_HI           PIN_DM_OD_HI
#define Vin1_DM_STRONG          PIN_DM_STRONG
#define Vin1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Vin1_MASK               Vin1__MASK
#define Vin1_SHIFT              Vin1__SHIFT
#define Vin1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vin1_PS                     (* (reg8 *) Vin1__PS)
/* Data Register */
#define Vin1_DR                     (* (reg8 *) Vin1__DR)
/* Port Number */
#define Vin1_PRT_NUM                (* (reg8 *) Vin1__PRT) 
/* Connect to Analog Globals */                                                  
#define Vin1_AG                     (* (reg8 *) Vin1__AG)                       
/* Analog MUX bux enable */
#define Vin1_AMUX                   (* (reg8 *) Vin1__AMUX) 
/* Bidirectional Enable */                                                        
#define Vin1_BIE                    (* (reg8 *) Vin1__BIE)
/* Bit-mask for Aliased Register Access */
#define Vin1_BIT_MASK               (* (reg8 *) Vin1__BIT_MASK)
/* Bypass Enable */
#define Vin1_BYP                    (* (reg8 *) Vin1__BYP)
/* Port wide control signals */                                                   
#define Vin1_CTL                    (* (reg8 *) Vin1__CTL)
/* Drive Modes */
#define Vin1_DM0                    (* (reg8 *) Vin1__DM0) 
#define Vin1_DM1                    (* (reg8 *) Vin1__DM1)
#define Vin1_DM2                    (* (reg8 *) Vin1__DM2) 
/* Input Buffer Disable Override */
#define Vin1_INP_DIS                (* (reg8 *) Vin1__INP_DIS)
/* LCD Common or Segment Drive */
#define Vin1_LCD_COM_SEG            (* (reg8 *) Vin1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Vin1_LCD_EN                 (* (reg8 *) Vin1__LCD_EN)
/* Slew Rate Control */
#define Vin1_SLW                    (* (reg8 *) Vin1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Vin1_PRTDSI__CAPS_SEL       (* (reg8 *) Vin1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Vin1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Vin1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Vin1_PRTDSI__OE_SEL0        (* (reg8 *) Vin1__PRTDSI__OE_SEL0) 
#define Vin1_PRTDSI__OE_SEL1        (* (reg8 *) Vin1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Vin1_PRTDSI__OUT_SEL0       (* (reg8 *) Vin1__PRTDSI__OUT_SEL0) 
#define Vin1_PRTDSI__OUT_SEL1       (* (reg8 *) Vin1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Vin1_PRTDSI__SYNC_OUT       (* (reg8 *) Vin1__PRTDSI__SYNC_OUT) 


#if defined(Vin1__INTSTAT)  /* Interrupt Registers */

    #define Vin1_INTSTAT                (* (reg8 *) Vin1__INTSTAT)
    #define Vin1_SNAP                   (* (reg8 *) Vin1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Vin1_H */


/* [] END OF FILE */
