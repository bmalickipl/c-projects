#include <stdio.h>

int main (void)
{
    int suma = 0;

    for(int liczba = 20; liczba >= 1; --liczba)
    {
        if(liczba % 2 == 1)
        {
            suma += liczba;
            printf("%d\n", liczba);
        }
    }
    
    printf("Suma: %d\n", suma);

    return 0;
}