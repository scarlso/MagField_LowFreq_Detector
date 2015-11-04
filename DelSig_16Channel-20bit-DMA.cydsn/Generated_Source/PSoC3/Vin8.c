/*******************************************************************************
* File Name: Vin8.c  
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
#include "Vin8.h"


/*******************************************************************************
* Function Name: Vin8_Write
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
void Vin8_Write(uint8 value) 
{
    uint8 staticBits = (Vin8_DR & (uint8)(~Vin8_MASK));
    Vin8_DR = staticBits | ((uint8)(value << Vin8_SHIFT) & Vin8_MASK);
}


/*******************************************************************************
* Function Name: Vin8_SetDriveMode
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
void Vin8_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Vin8_0, mode);
}


/*******************************************************************************
* Function Name: Vin8_Read
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
*  Macro Vin8_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vin8_Read(void) 
{
    return (Vin8_PS & Vin8_MASK) >> Vin8_SHIFT;
}


/*******************************************************************************
* Function Name: Vin8_ReadDataReg
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
uint8 Vin8_ReadDataReg(void) 
{
    return (Vin8_DR & Vin8_MASK) >> Vin8_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vin8_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vin8_ClearInterrupt
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
    uint8 Vin8_ClearInterrupt(void) 
    {
        return (Vin8_INTSTAT & Vin8_MASK) >> Vin8_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
