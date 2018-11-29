#include <stdio.h>
#include <stdlib.h>


int fact(int n){

    if(n < 2) return 1;
    return n * fact(n-1);

}

int ack(m,n){


if(m == 0) return n+1;
if(n == 0) return ack(m-1,1);
else return ack(m-1, ack(m,n-1));

}

int fib(int n){

    if(n < 2)
        return 1;

    return fib(n-1) + fib(n-2);

}

int fib_memo(int n){            //Memoize

    int * memo = malloc(sizeof(int) * n+1);
    int i;
    for(i=0;i<=n+1;i++)
        *(memo + i) = 0;

    return fib_memo_2(n,memo);

}

int fib_memo_2(int n, int *memo){

    int result;

    if(*(memo + n) != 0)
        return *(memo + n);

    if(n < 2)
        result = 1;
    else
    {
        result = fib_memo_2(n-1, memo) + fib_memo_2(n-2, memo);
        *(memo + n) = result;
    }

    return result;

}

int main()
{
    printf("%d\n", fib_bottom_up(5));
    return 0;

}
