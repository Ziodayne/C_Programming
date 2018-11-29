#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/////////////////////       Clearing a list


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

void push_front(list * l, int value){

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

void clear_list(list * l){

    if(empty_list(l))
    {
        printf("List is already empty...");
        return ;
    }

    list_node * p;

    while(l->head->next != NULL)
    {
        p = l->head->next;
        if(p->next != NULL)
        {
            l->head->next = p->next;
            free(p);
            l->size--;
        }
        else
        {
            free(p);
            l->head->next = NULL;
            l->size--;
        }
    }
    free(l->head);
    l->head = NULL;
    l->size--;

}

int main()
{
    list * l = create_list();
    push_front(l,5);
    push_front(l,2);

    printf("Size is: %d\n", l->size);
    printf("%d\n", l->head->value);
    printf("%d\n", l->head->next->value);

    clear_list(l);

    printf("Size is: %d\n", l->size);

    push_front(l,7);
    push_front(l,1);

    printf("Size is: %d\n", l->size);
    printf("%d\n", l->head->value);
    printf("%d\n", l->head->next->value);


    return 0;
}
