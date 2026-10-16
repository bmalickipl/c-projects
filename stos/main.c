#include "stack.h"
#include <stdio.h>

int main(){

	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	tstack* pStos1 = init();											
	tstack* pStos2 = init();	
	
	if(pStos1 == NULL || pStos2 == NULL)
	{
		printf("Alokacja pamięci na stos nie powiodła się\n");
		return 1;
	}	
		
	printf("Podaj pierwszą wartość: ");
	scanf("%d", &a);	
		
	printf("Podaj drugą wartość: ");		
	scanf("%d", &b);				
	
	printf("Podaj trzecią wartość: ");
	scanf("%d", &c);	
	
	printf("Podaj czwartą wartość: ");
	scanf("%d", &d);
	
	push(pStos1, a);		
	push(pStos2, b);																		
	push(pStos1, c);
	push(pStos2, d);																						
	
	a = pop(pStos1);
	b = pop(pStos2);
	c = pop(pStos1);
	d = pop(pStos2);
	
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
	printf("%d\n", d);
	
	if(isempty(pStos1) == 1)
		printf("Stos 1 jest pusty\n");
	else
		printf("Stos 1 jest niepusty\n");	

	if(isempty(pStos2) == 1)
		printf("Stos 2 jest pusty\n");
	else
		printf("Stos 2 jest niepusty\n");			
		
	close(pStos1);
	close(pStos2);
	
	return 0;
}

	
