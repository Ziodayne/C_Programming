#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Returns number of elements in a list;

typedef struct list_node{

    int index;
    int value;
    struct list_node * next;

} list_node;

typedef struct list{

    int size;
    list_node * head;

} list;

bool empty_list(list * l){

    return l->size==0;
}

list * create_list(){

    list * l = (list *) malloc(sizeof(list));
    l->size = 0;
    l->head = NULL;

}

void push_element(list * l, int value){

    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    l->size++;
    ln->index = l->size;

    if(l->head == NULL)
    {
        l->head = ln;
        return ;
    }

    ln->next = l->head;
    l->head = ln;


}

int count_elements(list * l){

    if(empty_list(l)) return 0;

    int counter = 1;

    list_node * p = l->head;

    while(p != NULL)
    {
        counter++;
        p = p->next;
        if(p->next == NULL) return counter;
    }

}



int main()
{
    list * l = create_list();
    push_element(l,5);
    push_element(l,2);
    push_element(l,2);
    push_element(l,1);


    printf("%d\n", count_elements(l));


    return 0;
}
