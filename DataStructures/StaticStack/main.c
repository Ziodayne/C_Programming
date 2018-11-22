#include <stdio.h>
#include <stdlib.h>

int main(){

    static int head = 0;
    static int stack[10];
    int i,push,pop;
    for(i=0;i<5;++i){
        printf("Number to be pushed\n");
        scanf("%d", &push);
        pushing(stack,push,&head);
    }
    printf("Enter number of elements to pop: \n");
    scanf("%d", &pop);
    popping(stack, pop, &head);

    return 0;
}

void pushing(int * stack, int push, int * head){

    stack[*head] = push;
    ++*head;
    printf("head is now %d\n", *head);

    printf("Stack now contains: \n");
    for(int i = 0; i<*head;i++){
        printf("Stack[%d]: %d\n", i, stack[i]);
    }
}

void popping(int * stack, int pop, int * head){

    int i,temp;
    for (i=0; i<pop;i++){
        temp = stack[*head-1];
        --*head;
        stack[*head] = '\0';
        printf("The Number that was popped is: %d\n", temp);
    }
    printf("Head is now: %d\n", *head);
    printf("The stack now contains:\n");
    for(i=0;stack[i] != '\0'; ++i){
        printf("Stack[%d]: %d\n", i, stack[i]);
    }

    }



