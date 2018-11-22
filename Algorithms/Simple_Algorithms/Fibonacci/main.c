#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter a number for n:\n");
    scanf("%d",&n);
    fib(n);
    return 0;
}




void fib(int n){


    int i, nextterm;
    int t1=0;
    int t2=1;

    for(i=0;i<n;i++){
    nextterm = t1 + t2;
    t1=t2;
    t2 = nextterm;
    printf("%d\n",nextterm);
    }

}
