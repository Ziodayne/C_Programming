#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct heap
{
    int * arr;
    int size;

} heap;

heap * create_heap(int max_size)
{
    heap * h = (heap *) malloc(sizeof(heap));
    h->arr = (int *) malloc(sizeof(int) * max_size);
    h->size = 0;
    int i;
    for(i = 0;i<max_size;i++)
        h->arr[i] = 0;
    return h;
}

bool empty_heap(heap * h)
{
    return h->size == 0;
}

void swap(int * nb1,int * nb2)
{
    int tmp = * nb1;
    *nb1 = *nb2;
    *nb2 = tmp;
}

int max(int nb1,int nb2)
{
    return (nb1 > nb2) ? nb1 : nb2;

}

int min(int nb1,int nb2)
{
    return nb1 < nb2 ? nb1 : nb2;
}

void insert_max_heap(heap *h, int value)
{
    h->arr[++h->size] = value;
    int child_index = h->size;
    while(child_index > 1 && h->arr[child_index] > h->arr[child_index / 2])
    {
        swap(&h->arr[child_index], &h->arr[child_index/2]);
        child_index /= 2; //This instruction was not included in the video , it is essential to update the child to its previous parent
    }
}

int extract_max_heap(heap * h){

    if(empty_heap(h))
    {
        printf("Heap is empty");
        return -1;
    }

    int value = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size--;

    int p_index = 1;            // parent index
    int lc_index, rc_index;     //left and right child

    do
    {
        lc_index = p_index * 2;
        rc_index = p_index * 2 + 1;
        if(h->arr[p_index] > h->arr[lc_index], h->arr[rc_index])
            break;
        if(h->size == lc_index || h->arr[lc_index] > h->arr[rc_index])
        {
            swap(&h->arr[p_index], &h->arr[lc_index]);
            p_index = lc_index;
        }
        else
        {
            swap(&h->arr[p_index], &h->arr[rc_index]);
        }
    }while(p_index < h->size);
}

int main()
{
    heap * h = create_heap(100);
    insert_max_heap(h,5);
    insert_max_heap(h,2);
    insert_max_heap(h,1);
    insert_max_heap(h,6);
    return 0;

    while(!empty_heap(h))
        printf("%d\t", extract_max_heap(h));


}
