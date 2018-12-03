#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n){

    int i,j;
    for(i = 0; i< n;i++)
    {
        int temp = *(arr + i);
        j = i;
        while(j > 0 && *(arr + j-1) > temp)
        {
            *(arr + j) = *(arr + j-1);
            j--;
        }
        *(arr + j) = temp;
    }

}

void print_arr(int * arr, int n){

    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t", *(arr+i));
    }
    printf("\n");
}


int main()
{

    int arr[6] = {2,234,43,1,35,98};
    insertion_sort(arr,6);
    print_arr(arr, 6);


    return 0;
}
