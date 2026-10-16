#include <stdio.h>
typedef unsigned int uint;

int main(void){

    uint choice = 0;
    float voltage = 0.0;
    float temp = 0.0;

    printf("\n");
    printf("========== PANEL STEROWANIA ==========");
    printf("\n");
    printf("1. Sprawdź napiecie zasilania\n");
    printf("2. Sprawdź temperaturę urządzenia\n");
    printf("3. Diagnostyka urządzenia\n");
    printf("4. Sprawdz stan zasilania\n"); 
    printf("Wybierz opcję: ");

    if(scanf("%u", &choice) != 1)
    {
        printf("BŁĄD: Wprowadzono nieprawidłową opcję!\n");
        return 1;
    }

    switch(choice)
    {
        case 1:
            printf("Podaj napięcię zasilania [V]: ");
            if(scanf("%f", &voltage) != 1)
            {
                printf("BŁĄD: Nieprawidlowa wartosc napiecia!\n");
                return 1;
            }

            if(voltage > 5.0)
                printf("UWAGA: Przekroczono dopuszczalne napięcie!\n");

            else
                printf("Napięcie w dopuszczalnym zakresie\n");

            break;

        case 2:
            printf("Podaj temperaturę [stopnie Celsjusza]: ");

            if(scanf("%f", &temp) != 1)
            {
                printf("BŁĄD: Nieprawidłowa wartość temperatury!\n");
                return 1;
            }
            
            if(temp < 40.0)
                printf("Temperatura prawidłowa\n");

            else if(temp < 70.0 )
                printf("Temperatura podwyzszona\n");

            else 
                printf("Temperatura krytyczna!\n");

            break;

        case 3:
            printf("Podaj napięcie [V]: ");

            if(scanf("%f", &voltage) != 1)
            {
                printf("BŁĄD: Nieprawidłowa wartość napięcia!\n");
                return 1;
            }

            if(voltage > 0.0 && voltage <= 5.0) 
            {
                printf("Podaj temperaturę [stopnie Celsjusza]: ");
                if(scanf("%f", &temp) != 1)
                {
                    printf("BŁĄD: Nieprawidlowa wartość temperatury!\n");
                    return 1;
                }

                if(temp < 70.0)
                    printf("Urządzenie pracuje prawidłowo\n");

                else
                    printf("Urządzenie jest przegrzane\n");
            }

            else
                printf("BŁĄD ZASILANIA\n");

            break;

        case 4:
            printf("Podaj napięcie [V]: ");

            if(scanf("%f", &voltage) != 1)
            {
                printf("BŁĄD: Nieprawidlowa wartosc napiecia!\n");
                return 1;
            }

            if(voltage > 0.0)
                printf("Zasilanie aktywne\n");
            
            else
                printf("Brak zasilania\n");

            break;

        default:
            printf("BŁĄD: Nieprawidłowa opcja!");
            break;

    }
    return 0;
}