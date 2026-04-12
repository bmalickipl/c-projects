#include <stdio.h>

int main() {
  int pierwsza_liczba; 
  int druga_liczba;	 
  int wynik;
  char operator;
	
  printf("Witaj w kalkulatorze liczb naturalnych!\n");
  
  printf("Podaj pierwszą liczbe:");
  scanf("%d" , &pierwsza_liczba);
	if(pierwsza_liczba < 1)
	{
		printf("Podaj liczbę większą od 0:");
		scanf("%d" , &pierwsza_liczba);
		if(pierwsza_liczba < 1)
			{
			printf("Podano niewłaściwą liczbę. Zamykanie programu...\n");
			return 0;
			}
	}
		
  printf("Podaj operator działania:");
  scanf(" %c" , &operator);
		if(operator != '+' && operator != '-' && operator != '*' && operator != '/')
			{
			printf("Podaj właściwy operator:");
			scanf(" %c" , &operator);
				if(operator != '+' && operator != '-' && operator != '*' && operator != '/')				
				{
				printf("Podano nieprawidłowy operator. Zamykanie programu...\n");
				return 0;
				}
			}
			
  printf("Podaj drugą liczbę:");
  scanf("%d" , &druga_liczba);
	if(druga_liczba < 1)
	{
		printf("Podaj liczbę większą od 0:");
		scanf("%d" , &druga_liczba);
		if(druga_liczba < 1)
			{
			printf("Podano niewłaściwą liczbę. Zamykanie programu...\n");
			return 0;
			}
	}
	  
	if(operator == '+')
	{
		wynik = pierwsza_liczba + druga_liczba;
		printf("Wynik = %d\n" , wynik);
	}
	
	if(operator == '-')
	{
		wynik = pierwsza_liczba - druga_liczba;
		printf("Wynik = %d\n" , wynik);
	}
	
	if(operator == '*')
	{
		wynik = pierwsza_liczba * druga_liczba;
		printf("Wynik = %d\n" , wynik);
	}
	
	if(operator == '/')
	{
		wynik = pierwsza_liczba	/ druga_liczba;
		printf("Wynik = %d\n" , wynik);
	}
return 0;
}
 
