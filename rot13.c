#include <stdio.h>
#include <ctype.h>

// 'ALPHABET_LENGHT' will be rounded up by defect if it's not even, try putting 27 instead of 26.
#define ALPHABET_LENGHT 26
#define CYPHER_OFFSET   ALPHABET_LENGHT/2 

int main(int argc, char ** argv) {
	char alphabet[ALPHABET_LENGHT] = {'a', 'b', 'c', 'd', 'e', 'f',
					  'g', 'h', 'i', 'j', 'k', 'l',
					  'm', 'n', 'o', 'p', 'q', 'r',
					  's', 't', 'u', 'v', 'w', 'x',
					  'y', 'z'};
	int isInAlphabet = 0;
	char * argument_string = NULL;

	if (argc == 1) {
		fprintf(stderr, "One argument is expected.\n");
		fprintf(stderr, "Usage: %s \"This is the argument.\"\n", argv[0]);
		return 1;
	} else if (argc > 2) {
		fprintf(stderr, "If you want to cypher more then one word,\nput aphostrophes(\") at the start and end of the phrase.\n");
		fprintf(stderr, "Usage: %s \"This is the argument.\"\n", argv[0]);
		return 1;
	}

	argument_string = argv[1];

	// first for loop, go trough the argument_string until reaching \0
	for (int i = 0; argument_string[i] != '\0'; ++i) {
		// second for loop, check if the character is in the lowercase or uppercase alphabet (and print it if it is).
		for (int x = 0; x < ALPHABET_LENGHT; ++x) {
			if (argument_string[i] == alphabet[x]) {
				isInAlphabet = 1;
				putc(x < CYPHER_OFFSET ? alphabet[x + CYPHER_OFFSET] : alphabet[x - CYPHER_OFFSET], stdout);
			} else if (argument_string[i] == toupper(alphabet[x])) {
				isInAlphabet = 1;
				putc(x < CYPHER_OFFSET ? toupper(alphabet[x + CYPHER_OFFSET]) : toupper(alphabet[x - CYPHER_OFFSET]), stdout);
			}
		}
		// prints the character if it's not in the alphabet.
		if (!isInAlphabet) putc(argument_string[i], stdout);
		isInAlphabet = 0;
	}
	putc('\n', stdout);
	return 0;
}
