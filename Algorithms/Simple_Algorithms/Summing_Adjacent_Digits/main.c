#include <stdio.h>
#include <stdlib.h>


//////////////////// Finding the sum of the digits that match the next digit in a circular sequence i.e 1111 = 3, 1221 = 3


int summing(int *x, int size){

    int i;
    int value = 0;

    for(i=0;*(x+i);i++)
    {
        if(*(x+i) == *(x+i+1))
            value += *(x+i);

    }

    if(*x == *(x+size-1))
            value += *x;

    return value;

}


int main(){

    int i, size;
    printf("Please enter the size of the array: \n");
    scanf("%d", &size);

    int * arr = malloc(sizeof(int)*size);

    printf("Please enter the elements of the array:\n");

    for(i=0;i<size;i++)
    {
        scanf("%d",&*(arr + i));
    }

    printf("Elements of the array are:\n");
    for(i=0; i<size ; i++)
    {

        printf("%d\n", *(arr+i));
    }


    printf("%d\n", summing(arr,size));
    return 0;
}

