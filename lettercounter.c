#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("\n");

    FILE *fptr;
    char fname[20];
    char str[100];
    printf("\n\nRead an existing file :\n");
    printf("------------------------------\n");
    printf("Input the filename to be opened : ");
    scanf("%s", fname);
    fptr = fopen(fname, "r");
    if (fptr == NULL) {
        printf("File does not exist or cannot be opened.\n");
        exit(0);
    }
    printf("\nThe content of the file %s is  :\n", fname);
    fgets(str, 100, fptr);

    fclose(fptr);

    printf("%s\n\n", str);

    //getting 1 char as unsigned so use %c
    int letters[26] = {0};

    //making str all lowercase
    for (int i = 0; i < 100; i++) {
        str[i] = tolower(str[i]);
    }

    for (int counter = 0; counter < strlen(str); counter = counter + 1) {

        char new = str[counter];
        int acii = ((int)new) - 97;
        //printf("Acii code %d\n", acii);

        //printf("Character %d", counter);
        //printf(": %c\n", new);

        letters[acii] = letters[acii] + 1;
        //printf("letters acii: %d", letters[acii]);
        //printf("\n");
    }
    //printf("Letter a amount: %d", lettera);

    //print in order
    int holderofvalues;
    char holderofchar;
    int n = 26;
    char alphabet[] = {'a',
                       'b',
                       'c',
                       'd',
                       'e',
                       'f',
                       'g',
                       'h',
                       'i',
                       'j',
                       'k',
                       'l',
                       'm',
                       'n',
                       'o',
                       'p',
                       'q',
                       'r',
                       's',
                       't',
                       'u',
                       'v',
                       'w',
                       'x',
                       'y',
                       'z'};

    //sort usage
    for (int i = 0; i < n; ++i) {

        for (int j = i + 1; j < n; ++j) {

            if (letters[i] < letters[j]) {

                holderofvalues = letters[i];
                holderofchar = alphabet[i];

                letters[i] = letters[j];
                alphabet[i] = alphabet[j];

                letters[j] = holderofvalues;
                alphabet[j] = holderofchar;
            }
        }
    }

    //display usage only if is not 0
    for (int i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            printf("%c ", alphabet[i]);
            printf("%d\n", letters[i]);
        }
    }

    printf("\n\n");
}