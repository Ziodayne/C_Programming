#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Search list for a value

typedef struct list_node{

    int value;
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

void push_elements(list * l, int value){

    list_node * ln = (list_node *) malloc(sizeof(list_node));
    ln->value = value;
    ln->next = NULL;
    l->size++;

    if(empty_list(l))
    {
        l->head = ln;
        return ;
    }

    ln->next = l->head;
    l->head = ln;


}

void search_list(list * l, int search){

    if(empty_list(l))
    {
        printf("List is empty...");
        return ;
    }

    list_node * p = l->head;

    while(p != NULL)
    {
        if(p->value == search)
        {
            printf("%d found...", search);
            return ;
        }
        p = p->next;
    }

    printf("%d was not found...", search);
}

void search_list_recursive(list_node * ln, int search){


    if(ln == NULL)
    {
        printf("Could not find %d...", search);
        return;
    }

    if(ln->value == search)
    {
        printf("%d found...",search);
        return ;
    }

    search_list_recursive(ln->next, search);

}


int main()
{
    list * l = create_list();
    push_elements(l,5);
    push_elements(l,2);
    push_elements(l,1);
    push_elements(l,4);
    push_elements(l,9);


    search_list_recursive(l,0);

    return 0;
}
