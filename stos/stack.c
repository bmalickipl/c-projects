#include "stack.h"
#include <stdlib.h>													

struct stack															
{														
	unsigned size;														
	unsigned top;
	int* data;															
};

tstack *init(void)														
{	 
	tstack* pS = malloc(sizeof(tstack));								
	if(pS != NULL)
	{
		pS->size = 1;													
		pS->top = 0;													
		pS->data = malloc(sizeof(int)*pS->size);	
							
		if(pS->data == NULL)
		{
			free(pS);
			return NULL;
		}
	}
	return pS;
}																

int push(tstack *s, int el)												
{
	int* alloc;
	
	if(s->top == s->size)													
	{
		alloc = realloc(s->data, sizeof(int) * (s->size * 2));
		if(alloc != NULL)
		{
			s->size = s->size * 2;
			s->data = alloc;
		}
		
		if(alloc == NULL)
			return 1;													
	}
	
	s->data[s->top] = el ;
	s->top += 1;
	return 0;
}

int pop(tstack *s)														
{
	int wynik = 0;																
	s->top -= 1;
	
	wynik = s->data[s->top];
	return wynik;
	
}

int isempty(tstack *s)													
{
	if(s->top == 0)
		return 1;														
									
	else                                                                
		return 0;														
}
									
void close(tstack *s)													
{
	free(s->data);
	free(s);
}
