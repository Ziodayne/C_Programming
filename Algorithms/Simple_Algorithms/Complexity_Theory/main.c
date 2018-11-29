#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    printf("Enter a number\n");
    int i, c, size;
    scanf("%d", &size);

    int * arr = malloc(sizeof(int) * size);

    for(i=0; i<size;i++)
    {
        *(arr + i) = i;
    }

    for(i=0;i<size;i++)
        printf("arr[%d]\n", *(arr+i));

    printf("Enter a value to search:\n");

    scanf("%d",&c);

    i=0;
    int counter = 0;
    int x = size-1;
    int y,z;
    y = (size-1)/2;
    z = (size-1)/2 + 1;

    printf("ixyz\n");
    while(*(arr+i) != c && *(arr+x) != c && *(arr+z) != c && *(arr+y) != c)
    {
        counter++;
        printf("%d\n", counter);
        i++;
        x--;
        y--;
        z++;
        if(counter > size) break;
    }

    printf("\n\n");
    i=0;
    counter = 0;
    x = size-1;


    printf("ix\n");
    while(*(arr+i) != c && *(arr+x) != c)
    {
        counter++;
        printf("%d\n", counter);
        i++;
        x--;
        if(counter > size) break;

    }

    printf("\n\n");
    i=0;
    counter = 0;

    printf("i\n");
    while(*(arr+i) != c)
    {
        counter++;
        printf("%d\n", counter);
        i++;
        if(counter > size) break;
    }

    return 0;
}
