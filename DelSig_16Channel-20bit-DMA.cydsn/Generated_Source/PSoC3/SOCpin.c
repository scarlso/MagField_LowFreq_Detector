/*******************************************************************************
* File Name: SOCpin.c  
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
#include "SOCpin.h"


/*******************************************************************************
* Function Name: SOCpin_Write
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
void SOCpin_Write(uint8 value) 
{
    uint8 staticBits = (SOCpin_DR & (uint8)(~SOCpin_MASK));
    SOCpin_DR = staticBits | ((uint8)(value << SOCpin_SHIFT) & SOCpin_MASK);
}


/*******************************************************************************
* Function Name: SOCpin_SetDriveMode
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
void SOCpin_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SOCpin_0, mode);
}


/*******************************************************************************
* Function Name: SOCpin_Read
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
*  Macro SOCpin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SOCpin_Read(void) 
{
    return (SOCpin_PS & SOCpin_MASK) >> SOCpin_SHIFT;
}


/*******************************************************************************
* Function Name: SOCpin_ReadDataReg
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
uint8 SOCpin_ReadDataReg(void) 
{
    return (SOCpin_DR & SOCpin_MASK) >> SOCpin_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SOCpin_INTSTAT) 

    /*******************************************************************************
    * Function Name: SOCpin_ClearInterrupt
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
    uint8 SOCpin_ClearInterrupt(void) 
    {
        return (SOCpin_INTSTAT & SOCpin_MASK) >> SOCpin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
