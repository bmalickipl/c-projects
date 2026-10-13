#include <stdio.h>

typedef unsigned long uint_long;
typedef unsigned short uint_short;
typedef unsigned int uint;

int main(void)
{
    uint_long stock = 1500;
    uint min_stock = 500;
    uint max_stock = 2000;
    uint_long delivery = 350;                       /* liczba dostarczonych MCU w dostawie - zwiększa stan magazynowy */
    uint_short order = 200;                         /* liczba MCU zamowionych przez klienta - zmniejsza stan magazynowy */
    const uint package_size = 12;
    uint_long full_packages = 0;
    uint rest_mcu = 0; 
    int delivery_status = 0;                        /* flaga dla oznaczenia czy jest dostawa czy jej nie ma */
    int order_status = 0;                           /* flaga dla oznaczenia czy wpłynęło zamowienie czy nie */
    int is_available = 0;

    printf("\n");
    printf("=== RAPORT MAGAZYNOWY ===\n");
    printf("\n");

    delivery_status = 1;
        
    if(delivery_status == 1)
    {
        stock += delivery;                          /* zwiększ stan magazynowy o przyjętą dostawę */
        printf("Stan magazynowy po dostawie: %lu\n", stock);
    }

    order_status = 1;

    if(order_status == 1 && order <= stock)
    {
        stock -= order;
        printf("Stan magazynowy po zrealizowaniu zamowienia: %lu\n", stock);
    }

    full_packages = stock / package_size;
    printf("Liczba pełnych opakowań: %lu\n", full_packages);

    rest_mcu = stock % package_size;
    printf("Pozostałe jednostki MCU: %u\n", rest_mcu); 
    printf("\n");

    if(stock >= min_stock && stock <= max_stock)
    {
        is_available = 1;
        printf("Stan magazynowy w granicach dopuszczalnych widełek\n");
        printf("\n");
    }

    else
    {
        printf("Stan pagazynowy poza granicami dopuszczalnych widełek\n");
        printf("\n");
    }

    if(is_available != 1)
        return 1;

    return 0;
}
