#include <stdio.h>
#include <string.h>

void Encode()
{
    int length;
    char message[500], reversed[500], encoded[500];
    printf("Enter Message to Encode: ");
    fgets(message, 500, stdin);
    message[strcspn(message, "\n")] = '\0';
    length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        reversed[i] = message[length - 1 - i];
    }
    reversed[length] = '\0';
    for (int i = 0; i < length; i++)
    {
        encoded[i] = (reversed[i] ^ 18);
    }
    encoded[length] = '\0';
    printf("The Encoded Message is: %s\n", encoded);
    return;
}

void Decode()
{
    int length;
    char message[500], reversed[500], decoded[500];
    printf("Enter Message to Decode: ");
    fgets(message, 500, stdin);
    message[strcspn(message, "\n")] = '\0';
    length = strlen(message);
    for (int i = 0; i < length; i++)
    {
        reversed[i] = (message[i] ^ 18);
    }
    reversed[length] = '\0';
    for (int i = 0; i < length; i++)
    {
        decoded[i] = reversed[length - 1 - i];
    }
    decoded[length] = '\0';
    printf("The Decoded Message is : %s\n", decoded);
}

int main()
{
    int option;
    do
    {
        printf("\nMENU\n");
        printf("1. Encode\n");
        printf("2. Decode\n");
        printf("3 Exit\n");
        printf("\n");
        printf("Choose option: ");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
            printf("You chose Option1\n");
            Encode();
            break;
        case 2:
            printf("You chose Option2\n");
            Decode();
            break;
        case 3:
            printf("GOODBYE\n");
            break;
        default:
            printf("You chose an incorrect option.\n");
            break;
        }
    } while (option != 3);
    return 0;
}