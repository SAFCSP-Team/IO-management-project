#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("file.txt", "r");
    if (source == NULL) {
        perror("Error opening source file");
        return 1;
    }

    destination = fopen("copy.txt", "w");
    if (destination == NULL) {
        perror("Error opening destination file");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    // Close files
    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");
    return 0;
}
