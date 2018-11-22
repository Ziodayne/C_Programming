# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

///////////////////           Queue Data Structure



struct q_node{

    int value;
    struct q_node * next;

};

typedef struct q_node q_node;

struct queue{

    int size;
    q_node * front;
    q_node * back;

};

typedef struct queue queue;

queue * create_q(){

    queue * q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->front = q->back = NULL;
    return q;

}

bool empty_q(queue * q){

    return q->size == 0;

}

void push_q(queue * q, int value){

    q_node * qn = (q_node *) malloc(sizeof(q_node));
    qn->value = value;
    qn->next = NULL;
    if(!empty_q(q))
        q->back->next = qn, q->back = qn;
    else
    q->front = q->back = qn;
    q->size++;

}

int pop_q(queue * q){

    if(empty_q(q)) return 0;
    int value;
    q_node * qn = q->front;
    value = q->front->value;
    q->front = q->front->next;
    free(qn);
    q->size--;
    return value;

}

int main(int argc, char **argv){

    queue * q = create_q();
    push_q(q,5);
    push_q(q,2);
    push_q(q,9);


    while(!empty_q(q)){
        printf("%d\t",pop_q(q));
    }

    return 0;

}

