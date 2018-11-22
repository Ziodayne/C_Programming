# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

///////////////////// Chinrank's Code

char* encrpyt(char* str, char* result) {
    int i = 0;
    for(; *(str + i); i++) {
        result[i] = str[i] + 1;
        printf("%c\n",result[i]);
    }
    result[i] = '\0';
    return result;
}

int main(int argc, char **argv) {


    char result[8];
    if(argc < 2) printf("Call this program with an argument as whereIsTheString <str>\n");
    else if(strcmp(encrpyt(argv[1], result), "Kpsebo") == 0) printf("Good job hacker dood!\n");
    else printf("Nope, wrong key\n");
    return 0;
}
