/*******************************************************************************
* File Name: VinE.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VinE.h"


/*******************************************************************************
* Function Name: VinE_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void VinE_Write(uint8 value) 
{
    uint8 staticBits = (VinE_DR & (uint8)(~VinE_MASK));
    VinE_DR = staticBits | ((uint8)(value << VinE_SHIFT) & VinE_MASK);
}


/*******************************************************************************
* Function Name: VinE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void VinE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VinE_0, mode);
}


/*******************************************************************************
* Function Name: VinE_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VinE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VinE_Read(void) 
{
    return (VinE_PS & VinE_MASK) >> VinE_SHIFT;
}


/*******************************************************************************
* Function Name: VinE_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VinE_ReadDataReg(void) 
{
    return (VinE_DR & VinE_MASK) >> VinE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VinE_INTSTAT) 

    /*******************************************************************************
    * Function Name: VinE_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VinE_ClearInterrupt(void) 
    {
        return (VinE_INTSTAT & VinE_MASK) >> VinE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
