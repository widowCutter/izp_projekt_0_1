#include <stdio.h>
#include <stdlib.h>

typedef enum { inName, inNumber, false } bool;

struct Contact {
  char name[101];
  char number[101];
};

int parse_argument(char *query, int argc, char *argv[]) {
  if (argc <= 2) {
    return 1;
  }
  return 0;
}

int compare_inputs(struct Contact contact, char *query) { return 0; }

int read_file() {
  int nextChar;
  // nextChar = getchar();
  bool isIn = false;
  struct Contact contact;

  char *buffer = contact.name;

  if (nextChar == EOF) {
    return 1;
  }
  while (nextChar != EOF) {
    for (int i = 0; i < 100; i++) {

      nextChar = getchar();
      if (isIn == false && nextChar == '\n') {
        i = -1;
        continue;
      }
      if (nextChar == EOF || nextChar == '\n') {
        if (isIn == inName) {
          buffer[i] = '\0';
          printf("Name:[%s]\n", buffer);

          buffer = contact.number;
          isIn = inNumber;

          i = -1;
        } else if (isIn == inNumber) {
          buffer[i] = '\0';
          printf("Number:[%s]\n", buffer);

          struct Contact contact;
          buffer = contact.name;
          isIn = false;

          i = -1;
        }

        if (nextChar == EOF) {
          return 0;
        }
        continue;
      }
      buffer[i] = nextChar;
      if (isIn == false) {
        isIn = inName;
      }
    }
    printf("Line longer than 100 characters, skipping");
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char query[101];
  if (parse_argument(query, argc, argv)) {
    fprintf(stderr, "Invalid query supplied, check your arguments\n");
    return 1;
  }
  return read_file();
}
