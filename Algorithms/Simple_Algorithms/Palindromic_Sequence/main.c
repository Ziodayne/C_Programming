# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

//////////////////// Palindromic Sequence


bool is_palindrom(char *s){

    int start = 0;
    int end = strlen(s) - 1;

    while(start < end)
    {
        if(*(s + start) != *(s + end))
            return false;

        start++;
        end--;
    }
    return true;
}


int main(){

    char *c = "HANNAH";
    printf("%d", is_palindrom(c));

    return 0;
}
