#include <stdio.h>
#include <string.h>
void encodeMessage(char message[]){
    int length = strlen(message);
    char reversed[length + 1];
    reversed[0] = '\0';
    message[strcspn(message, "\n")] = '\0';

    for(int i = length - 1; i >= 0; i--){
        int len = strlen(reversed);
        reversed[len] = message[i];
        reversed[len + 1] = '\0';
    }
    for(int i = 0; reversed[i] != '\0'; i++){
        int ascii;
        ascii = reversed[i];
        ascii ^= (1 << 1);
        ascii ^= (1 << 4);
        reversed[i] = ascii;
    }
    printf("%s", reversed);
}
void decocdeMessage(char message[]){
    for(int i = 0; message[i] != '\0'; i++){
        int ascii;
        ascii = message[i];
        ascii ^= (1 << 1);
        ascii ^= (1 << 4);
        message[i] = ascii;
    }
    int length = strlen(message);
    char reversed[length];
    reversed[0] = '\0';
    message[strcspn(message, "\n")] = '\0';
    for(int i = length - 1; i >= 0; i--){
        int len = strlen(reversed);
        reversed[len] = message[i];
        reversed[len + 1] = '\0';
    }
    printf("%s", reversed);
}
void main(){
    int repeat;
    do{
    int choice;
    char string[100];
    printf("What do you want to do ? Encode Message or Decode Message. Press 1 or 2 for each respectively.\n");
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
        printf("Enter your string to encode:\n");
        fgets(string, 100, stdin);
        encodeMessage(string);
        break;

        case 2:
        printf("Enter your string to decode:\n");
        fgets(string, 100, stdin);
        decocdeMessage(string);
        break;

        default:
        printf("Wrong Input");
    }
    printf("\nDo you want to continue or exit the application ? Press 1 to continue and 0 for exit\n");
    scanf("%d", &repeat);
    }while(repeat != 0);
}