#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Search by position

typedef struct list_node{

    int value;
    int index;
    struct list_node * next;

} list_node;


typedef struct list{

    int size;
    list_node * head;


} list;


list * create_list(){

    list * l = (list *) malloc(sizeof(list));
    l->size = 0;
    l->head = NULL;

    return l;
}

bool empty_list(list * l){
    return l->size==0;
}

void push_element(list * l, int value){


    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;


    if(empty_list(l))
    {
        l->head = ln;
        l->size++;
        ln->index = l->size;
        return ;
    }


    list_node * p = l->head;

    while(p != NULL)
    {
        if(p->next == NULL)
        {
            p->next = ln;
            l->size++;
            ln->index = l->size;
            return ;
        }
        p = p->next;
    }

}


void search_by_position(list * l, int position){

    if(empty_list(l))
    {
        printf("List is empty...");
        return ;
    }

    if(position > l->size)
    {
        printf("List only contains %d elements...", l->size);
        return ;
    }

    int index = 1;
    list_node * p = l->head;

    while(index <= l->size && p != NULL)
    {
        if(index == position)
        {
            printf("The value at element %d is %d\n", position, p->value);
            return ;
        }
        index++;
        p = p->next;
    }
}

void search_by_recursion(list * l,list_node * ln, int position){

    if(empty_list(l))
    {
        printf("List is empty...");
        return ;
    }
    if(ln == NULL)
    {
        printf("Position does not exist...");
        return ;
    }

    if(position == ln->index)
    {
        printf("The value at element %d is %d\n", position, ln->value);
        return ;
    }

    search_by_recursion(l,ln->next, position);


}

int main()
{
    list * l = create_list();
    push_element(l,5);
    push_element(l,3);
    push_element(l,7);


    //search_by_position(l,2);
    search_by_recursion(l,l->head,1);
    search_by_recursion(l,l->head,2);
    search_by_recursion(l,l->head,3);
    return 0;
}


