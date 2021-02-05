//******************************************************************************
// Archivo: main.c
// Autor: Axel Mazariegos
// Fecha: 05 - febrero - 2021
//******************************************************************************


//******************************************************************************
// Importación de Librerías
//******************************************************************************
#include <xc.h>
#include <stdint.h>


//******************************************************************************
// Palabra de configuración
//******************************************************************************

// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#define _XTAL_FREQ 8000000

//******************************************************************************
// Variables
//******************************************************************************
uint8_t flagc;      //banderas para el anti rebote de cada una de los botones
uint8_t count;       //contador de pulsos de cada boton
uint8_t b_inc;
uint8_t b_dec;

//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void setup(void);       //Funcion para definir la configuracion inicial
void fun1(void);

//******************************************************************************
// Vector de interrupción
//******************************************************************************
void __interrupt() ISR(void){
    
}

//******************************************************************************
// Ciclo Principal
//******************************************************************************

void main(void) 
{

    setup();

    //**************************************************************************
    // Loop Principal
    //**************************************************************************

    while (1) 
    {
        
    }
}

//******************************************************************************
// Configuración
//******************************************************************************

void setup(void) {
    TRISE = 0;  // todos las salidas del puerto E estan en OUTPUT
    PORTE = 0;  // Todos los puertos de E empiezan apagados
    
    TRISC = 0;  // TODO C esta en OUTPUT
    PORTC = 0;  // TODO C empieza apagado
    
    TRISA = 0;  // TODO A OUTPUT
    PORTA = 0;  // TODA A APAGADO
    
    TRISB = 0;  // TODO B OUTPUT
    PORTB = 0;  // TODA B APAGADO

    TRISD = 0;  // TODO D OUTPUT
    PORTD = 0;  // TODO D EMPIEZA APAGADO
    
    ANSEL = 0;  // PARA NO USARLO COMO ANALOGICO
    ANSELH = 0; // PARA NO USARLO COMO ANALOGICO
    
    
}

//******************************************************************************
// Funciones
//******************************************************************************

void fun1(void) 
{
    
    

}




