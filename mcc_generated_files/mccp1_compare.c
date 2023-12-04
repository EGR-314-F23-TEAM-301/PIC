/**
  MCCP1 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp1.c

  @Summary
    This is the generated driver implementation file for the MCCP1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP1. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.1
        Device            :  PIC24FJ64GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.70
        MPLAB             :  MPLAB X v5.50
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "mccp1_compare.h"

/** OC Mode.

  @Summary
    Defines the OC Mode.

  @Description
    This data type defines the OC Mode of operation.

*/

static uint16_t         gMCCP1Mode;

/**
  Section: Driver Interface
*/


void MCCP1_COMPARE_Initialize (void)
{
    // CCPON enabled; MOD Center-Aligned Pulse; CCSEL disabled; CCPSIDL disabled; T32 16 Bit; CCPSLP disabled; TMRPS 1:1; CLKSEL FOSC/2; TMRSYNC disabled; 
    CCP1CON1L = (0x8006 & 0x7FFF); //Disabling CCPON bit
    //RTRGEN disabled; ALTSYNC disabled; ONESHOT disabled; TRIGEN disabled; OPS Each Time Base Period Match; SYNC None; OPSSRC Timer Interrupt Event; 
    CCP1CON1H = 0x00;
    //ASDGM disabled; SSDG disabled; ASDG 0; PWMRSEN disabled; 
    CCP1CON2L = 0x00;
    //OCCEN disabled; OCDEN disabled; OCEEN disabled; ICGSM Level-Sensitive mode; OCFEN disabled; ICSEL ICM1; AUXOUT Disabled; OCAEN disabled; OCBEN disabled; OENSYNC disabled; 
    CCP1CON2H = 0x00;
    //DT 0; 
    CCP1CON3L = 0x00;
    //OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP1CON3H = 0x00;
    //ICDIS disabled; SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; ICGARM disabled; TRCLR disabled; 
    CCP1STATL = 0x00;
    //TMR 65535; 
    CCP1TMRL = 0xFFFF;
    //TMR 0; 
    CCP1TMRH = 0x00;
    //PR 0; 
    CCP1PRL = 0x00;
    //PR 0; 
    CCP1PRH = 0x00;
    //CMP 255; 
    CCP1RA = 0xFF;
    //CMP 0; 
    CCP1RB = 0x00;
    //BUF 0; 
    CCP1BUFL = 0x00;
    //BUF 0; 
    CCP1BUFH = 0x00;

    CCP1CON1Lbits.CCPON = 0x1; //Enabling CCP

    gMCCP1Mode = CCP1CON1Lbits.MOD;

}

void __attribute__ ((weak)) MCCP1_COMPARE_CallBack(void)
{
    // Add your custom callback code here
}

void MCCP1_COMPARE_Tasks( void )
{
    if(IFS3bits.CCP1IF)
    {
		// MCCP1 COMPARE callback function 
		MCCP1_COMPARE_CallBack();
		
        IFS3bits.CCP1IF = 0;
    }
}

void __attribute__ ((weak)) MCCP1_COMPARE_TimerCallBack(void)
{
    // Add your custom callback code here
}


void MCCP1_COMPARE_TimerTasks( void )
{
    if(IFS6bits.CCT1IF)
    {
		// MCCP1 COMPARE Timer callback function 
		MCCP1_COMPARE_TimerCallBack();
	
        IFS6bits.CCT1IF = 0;
    }
}

void MCCP1_COMPARE_Start( void )
{
    /* Start the Timer */
    CCP1CON1Lbits.CCPON = true;
}

void MCCP1_COMPARE_Stop( void )
{
    /* Start the Timer */
    CCP1CON1Lbits.CCPON = false;
}

void MCCP1_COMPARE_SingleCompare16ValueSet( uint16_t value )
{   
    CCP1RA = value;
}


void MCCP1_COMPARE_DualCompareValueSet( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_DualEdgeBufferedConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_CenterAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_EdgeAlignedPWMConfig( uint16_t priVal, uint16_t secVal )
{

    CCP1RA = priVal;

    CCP1RB = secVal;
}

void MCCP1_COMPARE_VariableFrequencyPulseConfig( uint16_t priVal )
{
    CCP1RA = priVal;
}

bool MCCP1_COMPARE_IsCompareCycleComplete( void )
{
    return(IFS3bits.CCP1IF);
}

bool MCCP1_COMPARE_TriggerStatusGet( void )
{
    return( CCP1STATLbits.TRIG );
    
}

void MCCP1_COMPARE_TriggerStatusSet( void )
{
    CCP1STATLbits.TRSET = 1;
}

void MCCP1_COMPARE_TriggerStatusClear( void )
{
    /* Clears the trigger status */
    CCP1STATLbits.TRCLR = 1;
}

bool MCCP1_COMPARE_SingleCompareStatusGet( void )
{
    return( CCP1STATLbits.SCEVT );
}

void MCCP1_COMPARE_SingleCompareStatusClear( void )
{
    /* Clears the trigger status */
    CCP1STATLbits.SCEVT = 0;
    
}
/**
 End of File
*/
