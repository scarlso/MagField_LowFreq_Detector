/*******************************************************************************
* File Name: Count0.c  
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
#include "Count0.h"


/*******************************************************************************
* Function Name: Count0_Write
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
void Count0_Write(uint8 value) 
{
    uint8 staticBits = (Count0_DR & (uint8)(~Count0_MASK));
    Count0_DR = staticBits | ((uint8)(value << Count0_SHIFT) & Count0_MASK);
}


/*******************************************************************************
* Function Name: Count0_SetDriveMode
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
void Count0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Count0_0, mode);
}


/*******************************************************************************
* Function Name: Count0_Read
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
*  Macro Count0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Count0_Read(void) 
{
    return (Count0_PS & Count0_MASK) >> Count0_SHIFT;
}


/*******************************************************************************
* Function Name: Count0_ReadDataReg
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
uint8 Count0_ReadDataReg(void) 
{
    return (Count0_DR & Count0_MASK) >> Count0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Count0_INTSTAT) 

    /*******************************************************************************
    * Function Name: Count0_ClearInterrupt
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
    uint8 Count0_ClearInterrupt(void) 
    {
        return (Count0_INTSTAT & Count0_MASK) >> Count0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
