/*******************************************************************************
* File Name: Delay_PWM_PM.c
* Version 3.0
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
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
#include "Delay_PWM.h"

static Delay_PWM_backupStruct Delay_PWM_backup;


/*******************************************************************************
* Function Name: Delay_PWM_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Delay_PWM_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Delay_PWM_SaveConfig(void) 
{
    
    #if(!Delay_PWM_UsingFixedFunction)
        #if(!Delay_PWM_PWMModeIsCenterAligned)
            Delay_PWM_backup.PWMPeriod = Delay_PWM_ReadPeriod();
        #endif /* (!Delay_PWM_PWMModeIsCenterAligned) */
        Delay_PWM_backup.PWMUdb = Delay_PWM_ReadCounter();
        #if (Delay_PWM_UseStatus)
            Delay_PWM_backup.InterruptMaskValue = Delay_PWM_STATUS_MASK;
        #endif /* (Delay_PWM_UseStatus) */
        
        #if(Delay_PWM_DeadBandMode == Delay_PWM__B_PWM__DBM_256_CLOCKS || \
            Delay_PWM_DeadBandMode == Delay_PWM__B_PWM__DBM_2_4_CLOCKS)
            Delay_PWM_backup.PWMdeadBandValue = Delay_PWM_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */
        
        #if(Delay_PWM_KillModeMinTime)
             Delay_PWM_backup.PWMKillCounterPeriod = Delay_PWM_ReadKillTime();
        #endif /* (Delay_PWM_KillModeMinTime) */
        
        #if(Delay_PWM_UseControl)
            Delay_PWM_backup.PWMControlRegister = Delay_PWM_ReadControlRegister();
        #endif /* (Delay_PWM_UseControl) */
    #endif  /* (!Delay_PWM_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Delay_PWM_RestoreConfig
********************************************************************************
* 
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Delay_PWM_backup:  Variables of this global structure are used to  
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Delay_PWM_RestoreConfig(void) 
{
        #if(!Delay_PWM_UsingFixedFunction)
            #if(!Delay_PWM_PWMModeIsCenterAligned)
                Delay_PWM_WritePeriod(Delay_PWM_backup.PWMPeriod);
            #endif /* (!Delay_PWM_PWMModeIsCenterAligned) */
            Delay_PWM_WriteCounter(Delay_PWM_backup.PWMUdb);
            #if (Delay_PWM_UseStatus)
                Delay_PWM_STATUS_MASK = Delay_PWM_backup.InterruptMaskValue;
            #endif /* (Delay_PWM_UseStatus) */
            
            #if(Delay_PWM_DeadBandMode == Delay_PWM__B_PWM__DBM_256_CLOCKS || \
                Delay_PWM_DeadBandMode == Delay_PWM__B_PWM__DBM_2_4_CLOCKS)
                Delay_PWM_WriteDeadTime(Delay_PWM_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */
            
            #if(Delay_PWM_KillModeMinTime)
                Delay_PWM_WriteKillTime(Delay_PWM_backup.PWMKillCounterPeriod);
            #endif /* (Delay_PWM_KillModeMinTime) */
            
            #if(Delay_PWM_UseControl)
                Delay_PWM_WriteControlRegister(Delay_PWM_backup.PWMControlRegister); 
            #endif /* (Delay_PWM_UseControl) */
        #endif  /* (!Delay_PWM_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: Delay_PWM_Sleep
********************************************************************************
* 
* Summary:
*  Disables block's operation and saves the user configuration. Should be called 
*  just prior to entering sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Delay_PWM_backup.PWMEnableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Delay_PWM_Sleep(void) 
{
    #if(Delay_PWM_UseControl)
        if(Delay_PWM_CTRL_ENABLE == (Delay_PWM_CONTROL & Delay_PWM_CTRL_ENABLE))
        {
            /*Component is enabled */
            Delay_PWM_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            Delay_PWM_backup.PWMEnableState = 0u;
        }
    #endif /* (Delay_PWM_UseControl) */

    /* Stop component */
    Delay_PWM_Stop();
    
    /* Save registers configuration */
    Delay_PWM_SaveConfig();
}


/*******************************************************************************
* Function Name: Delay_PWM_Wakeup
********************************************************************************
* 
* Summary:
*  Restores and enables the user configuration. Should be called just after 
*  awaking from sleep.
*  
* Parameters:  
*  None
*
* Return: 
*  None
*
* Global variables:
*  Delay_PWM_backup.pwmEnable:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Delay_PWM_Wakeup(void) 
{
     /* Restore registers values */
    Delay_PWM_RestoreConfig();
    
    if(Delay_PWM_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        Delay_PWM_Enable();
    } /* Do nothing if component's block was disabled before */
    
}


/* [] END OF FILE */
