#include <stdio.h>
typedef unsigned int uint;

int main(void)
{

    char circuit_name[50];
    char circuit_sign;
    float voltage = 0.0, current = 0.0, resist = 0.0, power = 0.0;
    double mVoltage = 0.0, mCurrent = 0.0, mPower = 0.0;
    uint measure_num = 0;
    const int mili_convert = 1000;            

    printf("\n");
    printf("=== Kalkulator parametrow elektrycznych ===\n");
    printf("\n");

    printf("Podaj nazwę obwodu: ");
    scanf("%s", circuit_name);

    printf("Podaj oznaczenie obwodu (A - AC / D - DC): ");
    scanf(" %c", &circuit_sign);

    printf("Podaj wartość zmierzonego napięcia [V]: ");
    int voltage_result = scanf("%f", &voltage);

    if(voltage_result != 1 || voltage < 0)                               
    {
        printf("Podana wartość napięcia jest niepoprawna\n");
        return 1;
    }

    printf("Podaj wartość zmierzonego natęzenia [A]: ");
    int current_result = scanf("%f", &current);
    if(current_result != 1 || current < 0)      
    {                            
        printf("Podana wartość natęzenia jest niepoprawna\n");
        return 1;
    }

    else if(current == 0)
        printf("Obliczona rezystancja [Ω]: ∞\n");

    power = voltage * current;
    mVoltage = voltage * mili_convert;
    mCurrent = current * mili_convert;
    mPower = power * mili_convert;
    measure_num++;

    printf("\n");
    printf("=== RAPORT POMIAROWY ===\n");
    printf("Nazwa i oznaczenie obwodu: %s, %c\n", circuit_name, circuit_sign);  
    printf("Numer pomiaru: %u\n", measure_num);
    printf("Zmierzone napięcie [V]: %.2f\n", voltage);
    printf("Zmierzone natęzenie [A]: %.2f\n", current);
    if(current > 0)
    {
        resist = voltage / current;
        printf("Obliczona rezystancja [Ω]: %.2f\n", resist);
    }
    printf("Obliczona moc [W]: %.2f\n ", power);
    printf("\n");
    printf("Wartości po konwersji jednostek:\n");
    printf("- Napięcie [mV]: %.2lf\n", mVoltage);
    printf("- Natęzenie [mA]: %.2lf\n", mCurrent);
    printf("- Moc [mW]: %.2lf\n", mPower);
    printf("\n");

    printf("Liczba bajtow zajmowana przez jednostki:\n");
    printf("- Napięcie: %zu\n", sizeof(voltage));
    printf("- Natęzenie: %zu\n", sizeof(current));
    printf("- Rezystancja: %zu\n", sizeof(resist));
    printf("- Moc: %zu\n", sizeof(power));
    printf("- Napięcie [mV]: %zu\n", sizeof(voltage));
    printf("- Natęzenie [mA]: %zu\n", sizeof(mCurrent));
    printf("- Moc [mW]: %zu\n", sizeof(mPower));
    

    return 0;
}