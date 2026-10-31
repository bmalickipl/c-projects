#include <stdio.h>

int main(void){

    int pin;                        /* Inicjalizacja zmiennej pin jako 0 - zbędna, poniewaz scanf() i tak nadpisuje tą wartość przez adres*/
    printf("\n");

    do
    {
        printf("Podaj kod PIN: ");
        scanf("%d", &pin);

        if(pin != 4321)
        {
            printf("Nieprawidłowy PIN\n");
            printf("\n");
        }
     
    } while (pin != 4321);
    
    printf("Dostęp przyznany\n");

    return 0;
}