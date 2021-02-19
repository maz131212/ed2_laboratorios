//******************************************************************************
// 
//  Archivo: main.c
//  Autor: Axel Mazariegos
//  Esclavo 2 
//  Creado 19 de Febrero de 2020
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

uint8_t cont;


//******************************************************************************
// Prototipos de funciones
//******************************************************************************

void main(void);
void setup(void);
void incrementar(void);
void decrementar(void);


//******************************************************************************
// Ciclo principal
//******************************************************************************

void main(void) {

    setup();

    //**************************************************************************
    // Loop principal
    //**************************************************************************

    while (1) {
        
        if (IOCBbits.IOCB0 = 1 && PORTBbits.RB0 == 1) {
            incrementar();
        }
        if (IOCBbits.IOCB1 = 1 && PORTBbits.RB1 == 1) {
            decrementar();
        }
        

    }
}



//*********************************************************************************
// Configuración
//******************************************************************************

void setup(void) {
    
    
    //Puertos
    ANSEL = 0;      // Puerto A digital
    TRISA = 0;      // Puerto A como salida
    PORTA = 0;      // Limpiar puerto A
    
    ANSELH = 0;         // Puerto B digital
    TRISB = 0; // RB0 y RB1 como entradas
    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 1;
    PORTB = 0;          // Limpiar PORTB 
    
    //Interrupciones
    INTCONbits.GIE = 1;     // Habilitar interrupciones globales
    INTCONbits.RBIE = 1;    // Habilitar interrupciones de cambio de puerto B
    INTCONbits.RBIF = 0;    // Iniciar con la bandera en 0
    IOCBbits.IOCB0 = 1;     // Habilitar interrupcion de RB0
    IOCBbits.IOCB1 = 1;     // Habilitar interrupcion de RB1
    
}

//******************************************************************************
// Funciones
//******************************************************************************

void incrementar(void){
    PORTBbits.RB7 = 1;
            cont++;
            __delay_ms(500);
            IOCBbits.IOCB0 = 0;
            do { } while (PORTBbits.RB0 == 1);
            PORTA = cont;
}
void decrementar(void){
            cont--;
            __delay_ms(500);
            do {} while (PORTBbits.RB1 == 1);
            PORTA = cont;
            IOCBbits.IOCB3 = 0;
}
