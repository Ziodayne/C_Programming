#include <stdio.h>
#include <stdlib.h>

struct person{

    int id, age;


};


typedef struct person person;

int main()
{
    //person Sunny;

    //Sunny.age = 25;

    //printf("Sunny's age is %d", Sunny.age );


    int base,top,k;
    scanf("%d",&k);
    primes(k);
    //scanf("%d %d",&base,&top);
    //multiples(base,top);

}

void primes(int x){
    int i,j;
    for(i=2;i<=x;i++){
        for(j=2;j<=i;j++)
            if(i%j==0) break;
        if(i==j) printf("%d\n",i);
    }
}

void multiples(int base, int top){
    int i;
    for(i=0;i<=top;i++){
        if(i%base==0) printf("%d\n",i);
    }
}
