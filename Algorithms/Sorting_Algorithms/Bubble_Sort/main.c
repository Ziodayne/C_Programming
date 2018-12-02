#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void bubble_sort(int *arr, int n){

    bool sorted;

    do
    {
        sorted = true;
        int i;
        for(i=0;i<n;i++)
        {
            if(*(arr + i) > *(arr +i+1))
            {
                int temp = *(arr + i);
                *(arr + i) = *(arr + i+1);
                *(arr + i+1) = temp;
                sorted = false;
            }
        }
    }while(sorted == false);


}


int main(){

    int arr[10] = {9,8,7,6,5,4,3,2,1,0};

    int i;
    for(i=0;i<10;i++)
        printf("%d\t",*(arr+i));

    printf("\n\nBubbleSort\n\n");

    bubble_sort(arr,10);
    for(i=0;i<10;i++)
        printf("%d\t",*(arr+i));

    return 0;
}
