#include <stdio.h>
#include <stdlib.h>

typedef enum { inName, inNumber, blank } isInWord;
typedef enum { false, true } bool;

struct Contact {
  char name[101];
  char number[101];
};

int parse_argument(char *query, int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; i++) {
    if (argv[1][i] >= 48 && argv[1][i] <= 57) {
      query[i] = argv[1][i];
    }
  }
  return 0;
}

bool select_char(int asciiIndex, int offset, char inChar) {
  if (asciiIndex <= inChar && inChar <= (asciiIndex + offset - 1)) {
    return true;
  } else
    return false;
}
bool isCharEq(char qInput, char nameChar) {
  if (nameChar <= 90 && nameChar >= 65) {
    nameChar = nameChar + 32;
  }
  switch (qInput) {
  // 2 = (abc)
  case 50:
    return select_char(97, 3, nameChar);
  // 3 = (def)
  case 51:
    return select_char(100, 3, nameChar);
  // 4 = (ghi)
  case 52:
    return select_char(103, 3, nameChar);
  // 5 = (jkl)
  case 53:
    return select_char(106, 3, nameChar);
  // 6 = (mno)
  case 54:
    return select_char(109, 3, nameChar);
  // 7 = (pqrs)
  case 55:
    return select_char(112, 4, nameChar);
  // 8 = (tuv)
  case 56:
    return select_char(116, 3, nameChar);
  // 9 = (wxzy)
  case 57:
    return select_char(119, 4, nameChar);
  }
  return false;
}
float compare_name(char *query, char *name) {
  float accuracy = 0.0;
  float neededAccuracy = 1;
  // printf("\n");
  int hits = 0;
  for (int i = 0; 1; i++) {
    if (query[i] == '\0') {
      accuracy = (double)hits / i;
      break;
    }
    if (name[i] == '\0' && query[i] != '\0') {
      return (double)hits / (i - 1);
    }
    // printf("{[%c][%c]%d}", query[i], name[i], isCharEq(query[i], name[i]));
    if (isCharEq(query[i], name[i])) {
      hits++;
    }
  }
  if (accuracy < neededAccuracy && name[0] != '\0') {
    name = name + 1;
    return compare_name(query, name);
  }
  return accuracy;
}

float compare_number(char *query, char *number) {
  float accuracy = 0.0;
  float neededAccuracy = 1;
  int hits = 0;
  for (int i = 0; 1; i++) {
    if (query[i] == '\0') {
      accuracy = (double)hits / i;
      break;
    }
    if (number[i] == '\0' && query[i] != '\0') {
      return (double)hits / (i - 1);
    }
    if (number[i] == query[i]) {
      hits++;
    }
  }
  if (accuracy < neededAccuracy && number[0] != '\0') {
    number = number + 1;
    return compare_number(query, number);
  }
  return accuracy;
}

int compare_inputs(struct Contact *contact, char *query, float neededAccuracy) {
  // printf("Comparing Name:[%s] and Number:[%s] with query [%s]\n",
  // contact->name,contact->number, query);
  float nameAcuracy = compare_name(query, contact->name);
  float numberAcuracy = compare_number(query, contact->number);
  if (nameAcuracy >= neededAccuracy || numberAcuracy > neededAccuracy) {
    printf("%s\n%s\n", contact->name, contact->number);
  }
  // printf("nameAcuracy: [%f]numberAcuracy: [%f]\n", nameAcuracy,
  // numberAcuracy);
  return 0;
}

int read_file(char *query) {
  int nextChar = 0;
  isInWord isIn = blank;
  struct Contact contact;

  char *buffer = contact.name;
  
  while (nextChar != EOF) {
    for (int i = 0; i < 100; i++) {

      nextChar = getchar();
      if (isIn == blank && nextChar == '\n') {
        i = -1;
        continue;
      }
      if (nextChar == EOF || nextChar == '\n') {
        if (isIn == inName) {
          buffer[i] = '\0';
          // printf("Name:[%s]\n", buffer);

          buffer = contact.number;
          isIn = inNumber;

          i = -1;
        } else if (isIn == inNumber) {
          buffer[i] = '\0';
          // printf("Number:[%s]\n", buffer);

          compare_inputs(&contact, query, 1);
          struct Contact contact;
          buffer = contact.name;
          isIn = blank;

          i = -1;
        }
        if (nextChar == EOF) {
          return 0;
        }
        continue;
      }
      if (isIn == blank) {
        isIn = inName;
        buffer = contact.name;
      }
      buffer[i] = nextChar;
    }
    // printf("Line longer than 100 characters, skipping");
  }
  return 0;
}

int main(int argc, char *argv[]) {
  char query[101];
  if (parse_argument(query, argc, argv)) {
    fprintf(stderr, "Invalid query supplied, check your arguments\n");
    return 1;
  }
  // printf("Query:[%s]\n", query);
  return read_file(query);
}
