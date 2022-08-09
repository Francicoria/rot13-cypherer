#include <stdio.h>
#include <ctype.h>

int main(int argc, char ** argv) {
	char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

	if (argc == 1) {
		fprintf(stderr, "At least one argument is expected.\n");
		return 1;
	} else if (argc > 2) {
		fprintf(stderr, "If you want to cypher more then one word,\nput aphostrophes at the start and end of the phrase.\n");
		return 1;
	}

	int isInAlphabet = 0;
	char * string = "";
	string = argv[1];
	
	// first for loop, go trough the string until reaching \0
	for (int i = 0; string[i] != '\0'; ++i) {
		// second for loop, check if the character is in the lowercase or uppercase alphabet.
		for (int x = 0; x < 26; ++x) {
			if (string[i] == alphabet[x]) {
				isInAlphabet = 1;
				if (x < 13) {
					printf("%c", alphabet[x + 13]);
				} else {
					printf("%c", alphabet[x - 13]);
				}
			} else if (string[i] == toupper(alphabet[x])) {
				isInAlphabet = 1;
				if (x < 13) {
					printf("%c", toupper(alphabet[x + 13]));
				} else {
					printf("%c", toupper(alphabet[x - 13]));
				}
			}
		}
		// prints the character if it's not in the alphabet.
		if (isInAlphabet == 0) {
			printf("%c", string[i]);
		}
		isInAlphabet = 0;
	}
	printf("\n");
	return 0;
}
