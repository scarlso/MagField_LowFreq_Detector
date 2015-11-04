/*******************************************************************************
* File Name: Vin5.c  
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
#include "Vin5.h"


/*******************************************************************************
* Function Name: Vin5_Write
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
void Vin5_Write(uint8 value) 
{
    uint8 staticBits = (Vin5_DR & (uint8)(~Vin5_MASK));
    Vin5_DR = staticBits | ((uint8)(value << Vin5_SHIFT) & Vin5_MASK);
}


/*******************************************************************************
* Function Name: Vin5_SetDriveMode
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
void Vin5_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vin5_0, mode);
}


/*******************************************************************************
* Function Name: Vin5_Read
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
*  Macro Vin5_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vin5_Read(void) 
{
    return (Vin5_PS & Vin5_MASK) >> Vin5_SHIFT;
}


/*******************************************************************************
* Function Name: Vin5_ReadDataReg
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
uint8 Vin5_ReadDataReg(void) 
{
    return (Vin5_DR & Vin5_MASK) >> Vin5_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vin5_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vin5_ClearInterrupt
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
    uint8 Vin5_ClearInterrupt(void) 
    {
        return (Vin5_INTSTAT & Vin5_MASK) >> Vin5_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
