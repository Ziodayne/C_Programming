# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

///////////////////             Doubly Linked List


struct l_node{

    int value;
    struct l_node * next;
    struct l_node * previous;

};

typedef struct l_node l_node;

struct list{

    int size;
    l_node *head;
    l_node *tail;

};

typedef struct list list;


bool empty_list(list *l){

    return l->size == 0;

}

list * create_list(){

    list * l = (list *) malloc(sizeof(list));
    l->size = 0;
    l->tail = l->head = NULL;
    return l;

}

void push_front(list *l, int value){

    l_node * ln = (l_node *) malloc(sizeof(l_node));
    ln->value = value;
    ln->next = ln->previous = NULL;
    if(empty_list(l)){
        l->head = l->tail = ln;
        l->size++;
        return;
    }
        ln->next = l->head;
        l->head = ln;
        l->size++;

}

void push_back(list * l,int value){

    l_node * ln = (l_node *) malloc(sizeof(l_node));
    ln->value = value;
    if(empty_list(l)){
        l->head = l->tail = ln;
        ln->next = ln->previous = NULL;
    }
    else{
        l->tail->next = ln;
        ln->previous = l->tail;
        ln->next = NULL;
        l->tail = ln;
    }
    l->size++;

}

int pop_from_front(list *l){

    if(empty_list(l)){
        printf("List is empty...");
        return;
    }

    int value;

    if(l->head == l->tail){
        value = l->head->value;
        free(l->head);
        l->head = l->tail = NULL;
        l->size--;
        return value;
    }

    value = l->head->value;
    l->head = l->head->next;
    free(l->head->previous);
    l->head->previous = NULL;
    l->size--;

    return value;
}

int pop_from_back(list *l){

    if(empty_list(l)){
        printf("List is empty...");
        return;
    }

    int value;

    if(l->head == l->tail){
        value = l->head->value;
        free(l->head);
        l->head = l->tail = NULL;
        l->size--;
        return value;
    }

    value = l->tail->value;
    l->tail = l->tail->previous;
    free(l->tail->next);
    l->tail->next = NULL;
    return value;

}

int main(){

    list *l = create_list();
     push_back(l,5);
     push_back(l,2);
     push_front(l,9);
     push_front(l,8);

     while(!empty_list(l)){
        printf("%d\t",pop_from_front(l));
     }

    return 0;
}




///////////////////             Lists

/*

struct l_node{

    int value;
    struct l_node * next;
};

typedef struct l_node l_node;

struct list{

    int size;
    l_node * head;

};

typedef struct list list;



list * create_list(){

    list * l = (list *) malloc(sizeof(list));
    l->size = 0;
    l->head = NULL;
    return l;

}

bool empty_list(list * l){

    return l->size == 0;

}


void push_front_list(list * l, int value){

    l_node * ln = (l_node *) malloc(sizeof(l_node));
    ln->value = value;
    ln->next = l->head;
    l->head = ln;
    l->size++;

}

void push_back_list(list * l,int value){

    l_node * ln = (l_node *) malloc(sizeof(l_node));
    ln->value = value;
    ln->next = NULL;
    l_node * p = l->head;
    while(p != NULL && p->next != NULL)
        p = p->next;
    if(p == NULL)
        l->head = ln;
    else
        p->next = ln;
    l->size++;


}

int pop_list(list * l){

    if(empty_list(l)){
        printf("Error, list is empty...\n");
        return 0;
    }
    int value = l->head->value;
    l_node * ln = l->head;
    l->head = l->head->next;
    free(ln);
    l->size--;
    return value;

}

int pop_back(list * l){

    if(empty_list(l)){
            printf("Error, stack is empty");
            return 0;
    }

    if(l->head->next == NULL){
            int value = l->head->value;
            free(l->head);
            l->head = NULL;
            l->size--;
            return value;
    }
    l_node * ln = l->head;
    while(ln->next->next != NULL)
        ln = ln->next;
    int value = ln->next->value;
    free(ln->next);
    ln->next = 0;
    l->size--;
    return value;

}

int main(int argc, char **argv){

    list * l = create_list();
    push_back_list(l,5);
    push_back_list(l,2);
    push_back_list(l,9);
    push_front_list(l,7);

    while(!empty_list(l))
        //printf("%d\n", pop_list(l));
        printf("%d\n", pop_back(l));

    return 0;
}
