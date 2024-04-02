#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decryptHashStdIn(char *message[], int len, int key);
void decryptHash(char message[1000], int key);
void decryptCharacter(char *letter, int key);

int main(int argc, char *argv[]) //[0]
{
    if (argc >= 3)
    {
        if (atoi(argv[1]) > 0)
        {
            decryptHashStdIn(argv, (argc - 1), atoi(argv[1]));
        }
        else
        {
            printf("Error: Key Not Provided!");
        }
    }
    else if (argc == 1)
    {
        int key;

        printf("Enter Key Value (int): ");
        scanf("%i", &key);

        char message[1000];

        printf("\nEnter Encoded Message: ");
        fflush(stdin);
        fgets(message, 999, stdin);
        printf("\n");
        decryptHash(message, key);
    }
    else
    {
        printf("Error: missing command line argument.");
        return 1;
    }
}

void decryptCharacter(char *letter, int key_source)
{
    int key = ((key_source) * 1024) % 127;
    *letter = ((*letter) - key) % 255;
}

void decryptHashStdIn(char *message[], int len, int key)
{
    // printf("Decoded Message: ");
    for (int i = 2; i <= len; i++) // avoiding the 0th argv
    {
        int n = strlen(message[i]);
        for (int j = 0; j < n; j++)
        {
            char letter = message[i][j];
            decryptCharacter(&letter, key);
            printf("%c", letter);
        }
        printf(" ");
    }
    printf("\n");
}

void decryptHash(char message[1000], int key)
{
    printf("Decoded Message: ");

    int n = strlen(message);
    for (int j = 0; j < n-1; j++)
    {
        char letter = message[j];
        decryptCharacter(&letter, key);
        printf("%c", letter);
    }
    printf("\n");
}