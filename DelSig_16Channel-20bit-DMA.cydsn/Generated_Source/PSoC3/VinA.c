/*******************************************************************************
* File Name: VinA.c  
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
#include "VinA.h"


/*******************************************************************************
* Function Name: VinA_Write
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
void VinA_Write(uint8 value) 
{
    uint8 staticBits = (VinA_DR & (uint8)(~VinA_MASK));
    VinA_DR = staticBits | ((uint8)(value << VinA_SHIFT) & VinA_MASK);
}


/*******************************************************************************
* Function Name: VinA_SetDriveMode
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
void VinA_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VinA_0, mode);
}


/*******************************************************************************
* Function Name: VinA_Read
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
*  Macro VinA_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VinA_Read(void) 
{
    return (VinA_PS & VinA_MASK) >> VinA_SHIFT;
}


/*******************************************************************************
* Function Name: VinA_ReadDataReg
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
uint8 VinA_ReadDataReg(void) 
{
    return (VinA_DR & VinA_MASK) >> VinA_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VinA_INTSTAT) 

    /*******************************************************************************
    * Function Name: VinA_ClearInterrupt
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
    uint8 VinA_ClearInterrupt(void) 
    {
        return (VinA_INTSTAT & VinA_MASK) >> VinA_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
