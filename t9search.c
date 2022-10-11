

int sanitizeInput(int argc, char *argv[])
{
    if (argc < 2) {return 10;}
    for (int i = 1; argc > i; i++) {
        
    }
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
