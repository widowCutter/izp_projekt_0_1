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
struct contact {
    struct string text;
    int number;
};
struct numberList{
    struct contact *contList;
    int alocLenght;
    int trueLenght;
};
//Checks if parameters are within expected patterns
//If not returns with specified error code
int sanitizeInput(int argc, char *argv[])
{
    if (argc < 2) {return 10;}
    for (int i = 1; argc > i; i++) {
        for (int o = 0; (argv[i][o]) != '\0'; o++) {
            if (argv[i][o] < 48 || argv[i][o] > 57) {return 10;}
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
    array.trueLenght = 0;
    for (int i = 1; argc > i; i++) {
        sscanf(argv[i], "%d", &array.numbers[i - 1]);
        array.trueLenght++;
    }
    return array;
}

void printArguments(struct numArray array)
{
    printf("Lenght of array is :%d\n", array.trueLenght);
    for (int i = 0; array.trueLenght > i; i ++) {
        printf("Cislo:%d je :[%d]\n", i,array.numbers[i]);
    }
    return;
}

//Parse input txt into struct numberList
//Format is "%s\n%d"
//

struct contact parseContact(FILE *fp)
{
    struct contact parsedContact;
    return parsedContact;
}

struct numberList parseTable(char *path)
{
    struct numberList numberList;
    numberList.contList = malloc(sizeof(struct contact) * 10);
    numberList.alocLenght = 10;
    numberList.trueLenght = 0;
    for (int i = 0; ; i++) {
    }
    FILE *fp;
    fp = fopen(path, "r");
    return numberList;
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
    struct numArray array = getParameters(argc, argv);
    printArguments(array);
    struct numberList numList = parseTable("./inTable.txt");
    return 0;
}
