build:
	gcc -std=c99 t9search.c -o t9search
	./t9search 603123456 <inTable.txt
release:
	gcc -std=c99 -Wall -Wextra -Werror t9search.c -o t9search
	./t9search
