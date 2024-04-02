#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptHashStdIn(char *message[], int len, int key);
void encryptHash(char message[1000], int key);
void encryptCharacter(char *letter, int key);

int main(int argc, char *argv[]) //[0]
{
    if (argc >= 3)
    {
        if (atoi(argv[1]) > 0)
        {
            encryptHashStdIn(argv, (argc - 1), atoi(argv[1]));
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

        printf("\nEnter message to encode: ");
        fflush(stdin);
        fgets(message, 999, stdin);
        printf("\n");
        encryptHash(message, key);
    }
    else
    {
        printf("Error: missing command line argument.");
        return 1;
    }
}

void encryptCharacter(char *letter, int key_source)
{
    int key = key_source * 1;
    if (*letter >= 'a' && *letter <= 'z')
    {
        if ((*letter + key) > 'z')
            *letter = (*letter + key) - 26;
        else
            *letter += key;
    }
    else if (*letter >= 'A' && *letter <= 'Z')
    {
        if ((*letter + key) > 'Z')
            *letter = (*letter + key) - 26;
        else
            *letter += key;
    }
}

void encryptHash(char message[1000], int key)
{
    printf("Encrypted Message: ");
    int n = strlen(message);
    for (int j = 0; j < n; j++)
    {
        char letter = message[j];
        encryptCharacter(&letter, key);
        printf("%c", letter);
    }
    printf("\n");
}

void encryptHashStdIn(char *message[], int len, int key)
{
    printf("Encrypted Message: ");
    for (int i = 2; i <= len; i++) // avoiding the 0th argv
    {
        int n = strlen(message[i]);
        for (int j = 0; j < n; j++)
        {
            char letter = message[i][j];
            encryptCharacter(&letter, key);
            printf("%c", letter);
        }
        printf(" ");
    }
    printf("\n");
}