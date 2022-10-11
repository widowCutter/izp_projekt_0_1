#include <stdio.h>
#include <stdlib.h>

struct string {
    char *text;
    int lenght;
};
struct numArray{
    int *numbers;
    int allocatedLen;
    int trueLenght;
};
//Checks if parameters are within expected patterns
//If not returns with specified error code
int sanitizeInput(int argc, char *argv[])
{
    if (argc < 2) {return 10;}
    for (int i = 1; argc > i; i++) {
        for (int o = 0; (argv[i][o]) != '\0'; o++) {
            printf("%c", argv[i][o]);
        }
        printf("\n");
    }
    return 0;
}

//Parse parameters(p>1) into array of numbers
struct numArray getParameters(int argc, char* argv[])
{
    int *pureArray;
    pureArray = malloc(sizeof(int) * 10);
    struct numArray array;
    array.numbers = pureArray;
    return array;
}

//Program will run with one argument: {
//CISLO
//this number will be uninterupted sequence of numbers 0-9
//if the program is run without argument, treat as unexpected behav and exit with code 10;
//}
int main (int argc, char *argv[])
{
    int op = 0;
    op = sanitizeInput(argc,argv);
    switch (op) {
        case 0:
            break;
        case 10:
            return 10;
            break;
        default:
            return -99;
    }
    
    return 0;
}
