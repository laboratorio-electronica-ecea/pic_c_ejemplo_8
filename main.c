/*
 * Nombre del archivo:   main.c
 * Autor:
 *
 * Descripción: 
 *        Este programa enciende y apaga un led cada 500 ms.
 *        Si se presiona una tecla, se muestra F en el display.
 */

#include <xc.h>
#include <stdint.h>

/* ------------------------ Definiciones ------------------------------------ */
#define _XTAL_FREQ  4000000L    // Frecuencia de operación del cristal

/* ------------------------ Definición de salidas --------------------------- */
#define PIN_LED1    PORTEbits.RE2
#define TRIS_LED1   TRISEbits.TRISE2

#define PIN_LED2    PORTEbits.RE1
#define TRIS_LED2   TRISEbits.TRISE1

#define PIN_LED3    PORTEbits.RE0
#define TRIS_LED3   TRISEbits.TRISE0

/* ------------------------ Definición de entradas -------------------------- */
#define PIN_TEC1    PORTBbits.RB0
#define TRIS_TEC1   TRISBbits.TRISB0

#define PIN_TEC2    PORTBbits.RB1
#define TRIS_TEC2   TRISBbits.TRISB1

/* ------------------------ Bits de configuración --------------------------- */
// CONFIG1
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
//#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

/* ------------------------ Variables globales ------------------------------ */
// TODO: Agregar tabla de conversión a 7 segmentos

/* ------------------------ Prototipos de funciones ------------------------- */
void gpio_config();
void int_config();

/* ------------------------ Implementación de funciones --------------------- */
void main(void) {               // Función principal    
    gpio_config();              // Inicializo las entradas y salidas
    int_config();               // Configuro la interrupción externa
    
    PIN_LED1 = 0;               // Apago el LED1
    PORTD = 0;                  // Apago el display de 7 segmentos
    
    while(1) {                  // Super loop
        PIN_LED1 = 1;           // Enciendo el LED1
        __delay_ms(500);
        PIN_LED1 = 0;
        __delay_ms(500);
    }
    
    return;
}

void interrupt isr() {          // Rutina de atención de interrupciones
    // TODO: Completar rutina de interrupción
}

void gpio_config() {
    ANSEL = 0;                  // Configuro todas las entradas
    ANSELH = 0;                 //   como digitales
    
    TRIS_TEC1 = 1;              // Configuro la TEC1 como entrada
    TRIS_LED1 = 0;              // Configuro el LED1 como salida
    
    TRISD = 0;                  // Pines del display como salida
}

void int_config() {
    // TODO: Completar inicialización de interrupción externa
}
/* ------------------------ Fin de archivo ---------------------------------- */