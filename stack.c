#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int SizeOfStack(Stack *s){
    return s->top +1;
}

void stackInit(Stack* s, int maxSize){
    
    s->top = -1;
    s->maxSize =maxSize;
    s->c = malloc(sizeof(int) * maxSize);
 
    if(s->c == NULL  ){
    printf("Stack Init Failed");
    exit(EXIT_FAILURE);
    }
}

void stackDestroy(Stack* s ){
	s->top = -1; 
	free(s->c);
        s->c = NULL;	
}

int isFull(Stack *s){
    return SizeOfStack(s) == s->maxSize;

}
int isEmpty(Stack *s){
    return s->top <= EMPTY;
}

void push(Stack *s, int num){
    if (isFull(s)){
        printf("Can't Push, Stack is Full\n");
        exit(EXIT_FAILURE);  
    }

    s->top++;
    s->c[s->top] = num;
}

int pop(Stack *s){
    if(isEmpty(s)) {
        printf("Can't pop from empty stack");
        exit(EXIT_FAILURE);
    }

    
    return s->c[s->top--];
    
}

