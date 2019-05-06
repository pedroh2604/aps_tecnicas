#include <stdio.h>
#include <stdlib.h>

#define LINESIZE 500

void compactFile();
void uncompactFile();

int main() {
    // char num = 1 + 48; // converts num to char... you gotta add the number to 48

    compactFile();
    uncompactFile();

    return 0;
}

void compactFile() {
    FILE *input = fopen("angra.txt", "r");
    FILE *output = fopen("lalala.txt", "w");

    char line[LINESIZE], lastChar;
    short cont = 1;

    while(fgets(line, LINESIZE, input)) {
        printf("%s", line);

        lastChar = line[0];
        for (short i = 1; i < strlen(line) - 1; i++) { // line by line, last element from the string is \n
            if(line[i] == lastChar) {
                cont++;
            } else {
                if (cont < 10) {
                    fputc(lastChar, output);
                    fputc(cont + 48, output); // or cont + '0'
                    lastChar = line[i];
                    cont = 1;
                } else {
                    char tens = (12 % 10) + 48;
                }
            }
        }
        //fputs(line, output);
    }

    fclose(input);
    fclose(output);
}

void uncompactFile() {
    printf("heeey\n");
}


