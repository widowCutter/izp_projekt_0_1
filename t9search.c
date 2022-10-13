#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

struct result {
    float accuracy;
    char name[100];
    char number[100];
    struct result *nextResult;
};

// Checks if user supplied argument is valid
// and inserts it into char array supplied from main()
int parseQuerry(char *querry, int argc, char *argv[])
{
    if (argc < 2) {
        return 1;
    }
    for (int i = 0; i < 100 && argv[1][i]; i++) {
        querry[i] = argv[1][i];
    }
    return 0;
}

short isNumEqToChar(char input, char expectedChar)
{
    if (!((expectedChar >= 65 & expectedChar <= 90) | (expectedChar >= 97 & expectedChar <= 122))) {
        printf("encountered unknown char, skipping");
        return -1;
    }
    else if (expectedChar <= 90) {
        expectedChar += 32;
    }
    char asciiIndex;
    short lenOffset;
    switch (input) {
        // 2 (abc)
        case 50:
            input = 97;
            lenOffset = 3;
            break;
        // 3 (def)
        case 51:
            input = 97;
            lenOffset = 3;
            break;
        // 4 (ghi)
        case 52:
            input = 97;
            lenOffset = 3;
            break;
        // 5 (jkl)
        case 53:
            input = 97;
            lenOffset = 3;
            break;
        // 6 (mno)
        case 54:
            input = 97;
            lenOffset = 3;
            break;
        // 7 (pqrs)
        case 55:
            input = 97;
            lenOffset = 4;
            break;
        // 8 (tuv)
        case 56:
            input = 97;
            lenOffset = 3;
            break;
        // 9 (wxyz)
        case 57:
            input = 97;
            lenOffset = 4;
            break;
        // 0 (+)
        case 58:
            input = 97;
            lenOffset = 3;
            break;
        default:
            printf("Undefined");
            break;
    }
}

int lookForNumber(char *querry)
{
    int nextChar;
    while ((nextChar = getchar()) != EOF) {
        printf("%c", nextChar);
        struct result hit;
        hit.accuracy = 0.50;
        for (int i = 0; nextChar != '\n' ; i++) {
        }
    }
    return 0;
}


int main(int argc, char *argv[])
{
    char querry[100];
    if (parseQuerry(querry, argc, argv)) {
        printf("Wrong arguments supplied");
        return 1;
    };
    printf("Querry lodaded succesfully: %s\n", querry);
    //
    //Look for numbers in stdin
    // User querry from input supplied by user
    //
    if (lookForNumber(querry) <= 0) {
        printf("Not found");
    }
    return 0;
}
