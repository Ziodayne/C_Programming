#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void selection_sort(int * arr, int n){

    int target;
    for(target = 0; target < n-1; target++)
    {
        int i;
        int min_index = target;
        for(i = target + 1; i < n; i++)
        {
            if(*(arr+min_index)>*(arr+i))
                min_index = i;
        }
        int temp = *(arr+target);
        *(arr+target) = *(arr+min_index);
        *(arr+min_index) = temp;
    }

}

int main()
{
    int arr[10] = {9,86,735,6,56,4,33436,2,135,0};
    int i;

    selection_sort(arr,10);

    for(i=0;i<10;i++)
    {
        printf("%d\t", *(arr + i));
    }

    return 0;
}

