/*******************************************************************************
* File Name: Vin3.c  
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
#include "Vin3.h"


/*******************************************************************************
* Function Name: Vin3_Write
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
void Vin3_Write(uint8 value) 
{
    uint8 staticBits = (Vin3_DR & (uint8)(~Vin3_MASK));
    Vin3_DR = staticBits | ((uint8)(value << Vin3_SHIFT) & Vin3_MASK);
}


/*******************************************************************************
* Function Name: Vin3_SetDriveMode
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
void Vin3_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vin3_0, mode);
}


/*******************************************************************************
* Function Name: Vin3_Read
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
*  Macro Vin3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vin3_Read(void) 
{
    return (Vin3_PS & Vin3_MASK) >> Vin3_SHIFT;
}


/*******************************************************************************
* Function Name: Vin3_ReadDataReg
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
uint8 Vin3_ReadDataReg(void) 
{
    return (Vin3_DR & Vin3_MASK) >> Vin3_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vin3_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vin3_ClearInterrupt
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
    uint8 Vin3_ClearInterrupt(void) 
    {
        return (Vin3_INTSTAT & Vin3_MASK) >> Vin3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */