#include <stdio.h>
#include <stdlib.h>

short parseQuerry(char *querry, int argc, int *argv[])
{
    int onArgument = 1;
    int indexInLine = 0;
    int querryLen = 0;
    while (1)
    {
        while (argv[onArgument][indexInLine] != '\0') {
            if (querryLen >= 100) {
                return 0;
            }
            querry[querryLen] = argv[onArgument][indexInLine];
            querryLen++;
        }
        onArgument++;
    }
    return 1;
}


int main(int argc, char *argv[])
{
    char querry[100];
    if (!parseQuerry(querry, argc, argv)) {
        printf("Wrong arguments supplied");
        return -1;
    };
    return 0;
}
