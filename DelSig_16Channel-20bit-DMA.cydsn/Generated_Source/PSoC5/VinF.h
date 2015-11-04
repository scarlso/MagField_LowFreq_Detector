/*******************************************************************************
* File Name: VinF.h  
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

#if !defined(CY_PINS_VinF_H) /* Pins VinF_H */
#define CY_PINS_VinF_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VinF_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v1_90 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VinF__PORT == 15 && ((VinF__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VinF_Write(uint8 value) ;
void    VinF_SetDriveMode(uint8 mode) ;
uint8   VinF_ReadDataReg(void) ;
uint8   VinF_Read(void) ;
uint8   VinF_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VinF_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VinF_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VinF_DM_RES_UP          PIN_DM_RES_UP
#define VinF_DM_RES_DWN         PIN_DM_RES_DWN
#define VinF_DM_OD_LO           PIN_DM_OD_LO
#define VinF_DM_OD_HI           PIN_DM_OD_HI
#define VinF_DM_STRONG          PIN_DM_STRONG
#define VinF_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VinF_MASK               VinF__MASK
#define VinF_SHIFT              VinF__SHIFT
#define VinF_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VinF_PS                     (* (reg8 *) VinF__PS)
/* Data Register */
#define VinF_DR                     (* (reg8 *) VinF__DR)
/* Port Number */
#define VinF_PRT_NUM                (* (reg8 *) VinF__PRT) 
/* Connect to Analog Globals */                                                  
#define VinF_AG                     (* (reg8 *) VinF__AG)                       
/* Analog MUX bux enable */
#define VinF_AMUX                   (* (reg8 *) VinF__AMUX) 
/* Bidirectional Enable */                                                        
#define VinF_BIE                    (* (reg8 *) VinF__BIE)
/* Bit-mask for Aliased Register Access */
#define VinF_BIT_MASK               (* (reg8 *) VinF__BIT_MASK)
/* Bypass Enable */
#define VinF_BYP                    (* (reg8 *) VinF__BYP)
/* Port wide control signals */                                                   
#define VinF_CTL                    (* (reg8 *) VinF__CTL)
/* Drive Modes */
#define VinF_DM0                    (* (reg8 *) VinF__DM0) 
#define VinF_DM1                    (* (reg8 *) VinF__DM1)
#define VinF_DM2                    (* (reg8 *) VinF__DM2) 
/* Input Buffer Disable Override */
#define VinF_INP_DIS                (* (reg8 *) VinF__INP_DIS)
/* LCD Common or Segment Drive */
#define VinF_LCD_COM_SEG            (* (reg8 *) VinF__LCD_COM_SEG)
/* Enable Segment LCD */
#define VinF_LCD_EN                 (* (reg8 *) VinF__LCD_EN)
/* Slew Rate Control */
#define VinF_SLW                    (* (reg8 *) VinF__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VinF_PRTDSI__CAPS_SEL       (* (reg8 *) VinF__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VinF_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VinF__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VinF_PRTDSI__OE_SEL0        (* (reg8 *) VinF__PRTDSI__OE_SEL0) 
#define VinF_PRTDSI__OE_SEL1        (* (reg8 *) VinF__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VinF_PRTDSI__OUT_SEL0       (* (reg8 *) VinF__PRTDSI__OUT_SEL0) 
#define VinF_PRTDSI__OUT_SEL1       (* (reg8 *) VinF__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VinF_PRTDSI__SYNC_OUT       (* (reg8 *) VinF__PRTDSI__SYNC_OUT) 


#if defined(VinF__INTSTAT)  /* Interrupt Registers */

    #define VinF_INTSTAT                (* (reg8 *) VinF__INTSTAT)
    #define VinF_SNAP                   (* (reg8 *) VinF__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VinF_H */


/* [] END OF FILE */
