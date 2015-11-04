/*******************************************************************************
* File Name: VinC.c  
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
#include "VinC.h"


/*******************************************************************************
* Function Name: VinC_Write
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
void VinC_Write(uint8 value) 
{
    uint8 staticBits = (VinC_DR & (uint8)(~VinC_MASK));
    VinC_DR = staticBits | ((uint8)(value << VinC_SHIFT) & VinC_MASK);
}


/*******************************************************************************
* Function Name: VinC_SetDriveMode
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
void VinC_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VinC_0, mode);
}


/*******************************************************************************
* Function Name: VinC_Read
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
*  Macro VinC_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VinC_Read(void) 
{
    return (VinC_PS & VinC_MASK) >> VinC_SHIFT;
}


/*******************************************************************************
* Function Name: VinC_ReadDataReg
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
uint8 VinC_ReadDataReg(void) 
{
    return (VinC_DR & VinC_MASK) >> VinC_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VinC_INTSTAT) 

    /*******************************************************************************
    * Function Name: VinC_ClearInterrupt
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
    uint8 VinC_ClearInterrupt(void) 
    {
        return (VinC_INTSTAT & VinC_MASK) >> VinC_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
