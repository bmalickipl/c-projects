#include <stdio.h>

int main(void){

   /* goto: */
    program:     
        int liczba;
        int suma = 0;
        int licza_wystapien = 0;
        int uruchom;

        do
        {
            printf("\n");    
            printf("Podaj liczbę całkowitą z przedziału 10-50: ");
            scanf("%d", &liczba);
            if(liczba < 10 || liczba > 50)
                printf("Nieprawidłowa liczba!\n");

        } while (liczba < 10 || liczba > 50);
    
    for(int i = 1; i <= liczba; ++i)
    {
        if(i % 2 == 0)
            continue;

        licza_wystapien += 1;
        suma += i;
        printf("%d\n", i);
    }

    printf("Suma: %d\n", suma);
    printf("Liczba wystąpień: %d\n", licza_wystapien);
    printf("\n");   

    printf("Odliczanie:\n");
    int licznik = liczba;

    while(licznik >= 5)
    {
        if(licznik == 5)
        {
            printf("Odliczanie przerwane!\n");
            printf("\n");   
            break;
        }

        printf("%d\n", licznik);
        --licznik;
    }

    wybor_uruchomienia:
        printf("Czy chcesz uruchomić program ponownie?\n");  
        printf("1 - Tak\n");  
        printf("0 - Nie\n");  
        scanf("%d", &uruchom);
        printf("\n"); 

        if(uruchom == 1)
            goto program; /* linia 10 */

        else if(uruchom == 0)
            return 0;
            
        else
        {
            printf("Niezdefiniowane polecenie. Sprobuj ponownie\n");
            printf("\n");
            goto wybor_uruchomienia;
        }
}