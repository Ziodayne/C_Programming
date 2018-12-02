#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arr_node{

    int value;
    struct arr_node * next;

} arr_node;


typedef struct arr{

    int size;
    arr_node * index_zero;

} arr;


arr * create_array(){

    arr * a = (arr *) malloc(sizeof(arr));
    a->size = 0;
    a->index_zero = NULL;

    return a;
}

bool empty_array(arr * a){
    return a->size==0;
}


void add_element(arr *a,int value){

    arr_node * an = (arr_node *) malloc(sizeof(arr_node));
    an->value = value;
    an->next = NULL;

    if(empty_array(a))
    {
        a->index_zero = an;
        a->size++;
        return ;
    }

    arr_node * p = a->index_zero;

    while(p != NULL)
    {
        if(p->next == NULL)
        {
            p->next = an;
            a->size++;
            return ;
        }
        p = p->next;
    }
}


int main(){

    arr * a = create_array();
    add_element(a,5);
    add_element(a,4);
    add_element(a,8);
    add_element(a,1);

    arr_node * p = a->index_zero;

    int counter = 0;

    while(p != NULL)
    {
        printf("arr[%d] --> %d\n",counter,p->value);
        counter++;
        p = p->next;
    }

    return 0;
}












