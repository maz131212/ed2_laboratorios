//******************************************************************************
// 
//  Archivo: main.c
//  Autor: Axel Mazariegos
//  Esclavo 1 
//  Creado 12 de Febrero de 2020
//
//******************************************************************************


//******************************************************************************
// Importación de librerías
//******************************************************************************

#include <xc.h>
#include <stdint.h>



//******************************************************************************
// Palabra de configuración
//******************************************************************************

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
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

//Frecuencia del oscilador
#define _XTAL_FREQ 500000


//******************************************************************************
// Variables
//******************************************************************************

uint8_t pot;


//******************************************************************************
// Prototipos de funciones
//******************************************************************************

void main(void);
void setup(void);
void leer(void);


//******************************************************************************
// Vector de interrupción
//******************************************************************************


//******************************************************************************
// Ciclo principal
//******************************************************************************

void main(void) {

    setup();

    //**************************************************************************
    // Loop principal
    //**************************************************************************

    while (1) {
        
        if (ADCON0bits.GO_DONE == 0){
            leer();
        }
        

    }
}



//*********************************************************************************
// Configuración
//******************************************************************************

void setup(void) {
    
    
    //Puertos
    ANSEL = 0b00000010;     // RA1 como analogico / AN1
    TRISA = 0b00000010;     // RA1 como entrada 
    PORTA = 0;              // Limpiar puerto A
    TRISC = 0;              // PORTD como salida (PRUEBA)
    PORTC = 0;              // Limpiar PORTD (PRUEBA)
    
    //Interrupciones
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.PEIE = 1;    // Habilitar interrupciones perífericas
    PIE1bits.ADIE = 1;      // Habilitar interrupciones de ADC
    
    //ADC
    ADCON0bits.CHS = 1;     // Leer AN1
    ADCON1bits.VCFG0 = 0;   // Referencia negativa=Vss
    ADCON1bits.VCFG1 = 0;   // Referencia positiva=Vdd
    ADCON0bits.ADCS = 3;    // Frecuencia de Conversion (oscilador interno)
    ADCON1bits.ADFM = 0;    // Justificado a la izquierda
    ADCON0bits.GO_DONE = 1; // Para empezar la conversión
    ADCON0bits.ADON = 1;    // ADC encendido
    
}

//******************************************************************************
// Funciones
//******************************************************************************

void leer(void){
    pot = ADRESH;   // Los bits mas significativos
    PORTC = pot;    // PRUEBA
    ADCON0bits.GO_DONE = 1; // Reiniciar la conversión
}
