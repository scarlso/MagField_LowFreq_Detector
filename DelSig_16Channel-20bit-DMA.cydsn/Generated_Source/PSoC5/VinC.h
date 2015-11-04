/*******************************************************************************
* File Name: VinC.h  
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

#if !defined(CY_PINS_VinC_H) /* Pins VinC_H */
#define CY_PINS_VinC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VinC_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VinC__PORT == 15 && ((VinC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VinC_Write(uint8 value) ;
void    VinC_SetDriveMode(uint8 mode) ;
uint8   VinC_ReadDataReg(void) ;
uint8   VinC_Read(void) ;
uint8   VinC_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VinC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VinC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VinC_DM_RES_UP          PIN_DM_RES_UP
#define VinC_DM_RES_DWN         PIN_DM_RES_DWN
#define VinC_DM_OD_LO           PIN_DM_OD_LO
#define VinC_DM_OD_HI           PIN_DM_OD_HI
#define VinC_DM_STRONG          PIN_DM_STRONG
#define VinC_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VinC_MASK               VinC__MASK
#define VinC_SHIFT              VinC__SHIFT
#define VinC_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VinC_PS                     (* (reg8 *) VinC__PS)
/* Data Register */
#define VinC_DR                     (* (reg8 *) VinC__DR)
/* Port Number */
#define VinC_PRT_NUM                (* (reg8 *) VinC__PRT) 
/* Connect to Analog Globals */                                                  
#define VinC_AG                     (* (reg8 *) VinC__AG)                       
/* Analog MUX bux enable */
#define VinC_AMUX                   (* (reg8 *) VinC__AMUX) 
/* Bidirectional Enable */                                                        
#define VinC_BIE                    (* (reg8 *) VinC__BIE)
/* Bit-mask for Aliased Register Access */
#define VinC_BIT_MASK               (* (reg8 *) VinC__BIT_MASK)
/* Bypass Enable */
#define VinC_BYP                    (* (reg8 *) VinC__BYP)
/* Port wide control signals */                                                   
#define VinC_CTL                    (* (reg8 *) VinC__CTL)
/* Drive Modes */
#define VinC_DM0                    (* (reg8 *) VinC__DM0) 
#define VinC_DM1                    (* (reg8 *) VinC__DM1)
#define VinC_DM2                    (* (reg8 *) VinC__DM2) 
/* Input Buffer Disable Override */
#define VinC_INP_DIS                (* (reg8 *) VinC__INP_DIS)
/* LCD Common or Segment Drive */
#define VinC_LCD_COM_SEG            (* (reg8 *) VinC__LCD_COM_SEG)
/* Enable Segment LCD */
#define VinC_LCD_EN                 (* (reg8 *) VinC__LCD_EN)
/* Slew Rate Control */
#define VinC_SLW                    (* (reg8 *) VinC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VinC_PRTDSI__CAPS_SEL       (* (reg8 *) VinC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VinC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VinC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VinC_PRTDSI__OE_SEL0        (* (reg8 *) VinC__PRTDSI__OE_SEL0) 
#define VinC_PRTDSI__OE_SEL1        (* (reg8 *) VinC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VinC_PRTDSI__OUT_SEL0       (* (reg8 *) VinC__PRTDSI__OUT_SEL0) 
#define VinC_PRTDSI__OUT_SEL1       (* (reg8 *) VinC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VinC_PRTDSI__SYNC_OUT       (* (reg8 *) VinC__PRTDSI__SYNC_OUT) 


#if defined(VinC__INTSTAT)  /* Interrupt Registers */

    #define VinC_INTSTAT                (* (reg8 *) VinC__INTSTAT)
    #define VinC_SNAP                   (* (reg8 *) VinC__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VinC_H */


/* [] END OF FILE */
