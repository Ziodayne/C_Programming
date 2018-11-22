# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

//////////////////////          Dynamic Structure


struct stack_node{

    int value;
    struct stack_node * next;

};

typedef struct stack_node stack_node;

struct stack{

    int size;
    stack_node * top;

};

typedef struct stack stack;

stack * create_stack(){

    stack * s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;
    return s;

}

bool empty_stack(stack *s){

    return s->size==0;

}

void push_stack(stack * s, int value){

    stack_node * n = (stack *) malloc(sizeof(stack));
    n->value = value;
    n->next = s->top;
    s->top = n;
    s->size++;

}

int pop_stack(stack * s){

    int value = s->top->value;
    stack_node *sn = s->top;
    s->top = s->top->next;
    s->size--;
    free(sn);
    return value;

}

int main(){

    stack * s = create_stack();
    push_stack(s,5);
    push_stack(s,7);
    push_stack(s,14);

    while(!empty_stack(s)) printf("%d\t",pop_stack(s));

    return 0;
}
