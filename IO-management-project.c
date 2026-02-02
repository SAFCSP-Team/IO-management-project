#include <stdio.h>
void read() {
    FILE* fptr;
    fptr = fopen("file.txt", "r");
    if (fptr == NULL) {
        printf("There was an issue opening the file \n");
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fptr)) {
        printf("%s", line);
    }

    fclose(fptr);



}

void writeToFile(const char info[20]) {
    FILE* fptr;
    fptr = fopen("file.txt", "a");

    if (fptr == NULL) {
        printf("File pointer is NULL\n");
        return;
    }

    fprintf(fptr, "%s\n", info);
    fclose(fptr);

}
void deleteFile(){

    if (remove("file.txt") != 0) {
        printf("There was an issue deleting the file.\n");
    }

    printf("File deleted successfully.\n");
}



int main() {
  
    FILE* fptr;

    fptr = fopen("file.txt", "w");
    if (fptr == NULL) {
        printf("There was an issue creating the file \n");
        return 1;
    }
    printf("File created successfully! \n");
    fclose(fptr);

    
    int number = 0;
    char info[20];
    while (number != 4){
        printf("1: read\n");
        printf("2: write\n");
        printf("3: delete\n");
        printf("4: quit\n");

        scanf("%d", &number);

        if(number == 1){
            read();
        }else if(number == 2){
              printf("Enter what do you want to write: ");
              scanf("%s", info);
              writeToFile(info);
        }else if(number == 3){
            deleteFile();
            number = 4;
            
        }
    }





    
}
