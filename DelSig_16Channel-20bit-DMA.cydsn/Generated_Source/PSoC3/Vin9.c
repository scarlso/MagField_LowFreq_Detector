/*******************************************************************************
* File Name: Vin9.c  
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
#include "Vin9.h"


/*******************************************************************************
* Function Name: Vin9_Write
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
void Vin9_Write(uint8 value) 
{
    uint8 staticBits = (Vin9_DR & (uint8)(~Vin9_MASK));
    Vin9_DR = staticBits | ((uint8)(value << Vin9_SHIFT) & Vin9_MASK);
}


/*******************************************************************************
* Function Name: Vin9_SetDriveMode
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
void Vin9_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vin9_0, mode);
}


/*******************************************************************************
* Function Name: Vin9_Read
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
*  Macro Vin9_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vin9_Read(void) 
{
    return (Vin9_PS & Vin9_MASK) >> Vin9_SHIFT;
}


/*******************************************************************************
* Function Name: Vin9_ReadDataReg
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
uint8 Vin9_ReadDataReg(void) 
{
    return (Vin9_DR & Vin9_MASK) >> Vin9_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vin9_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vin9_ClearInterrupt
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
    uint8 Vin9_ClearInterrupt(void) 
    {
        return (Vin9_INTSTAT & Vin9_MASK) >> Vin9_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
