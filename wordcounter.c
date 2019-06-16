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

    printf("%s\n", str);

    //getting 1 char as unsigned so use %c
    int letters[26] = {0};

    //making str all lowercase
    for (int i = 0; i < 100; i++) {
        str[i] = tolower(str[i]);
    }
    //unless file is empty always 0 word
    //later check if file is empty
    int wordcount = 0;
    for (int counter = 0; counter < strlen(str); counter = counter + 1) {

        char new = str[counter];
        char next = str[counter + 1];

        if ((new == ' ' || new == ';' || new == '!' || new == '?' || new == '.' || new == ',' || new == ':' || new == '[' || new == ']' || new == '(' || new == ')') && (next != ' ' && next != ';' && next != '!' && next != '?' && next != '.' && next != ',' && next != ':' && next != '[' && next != ']' && next != '(' && next != ')')) {
            //printf("Next: %c\n", next);
            //printf("Another word \n");
            wordcount = wordcount + 1;
        }
    }
    printf("Wordcount:  %d", wordcount);

    printf("\n\n");
}