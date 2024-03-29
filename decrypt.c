#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decryptHash(char *message[], int len, int key);

int main(int argc, char *argv[]) //[0]
{
    if (argc >= 3)
    {
        if (atoi(argv[1]) > 0)
        {
            decryptHash(argv, (argc - 1), atoi(argv[1]));
        }
        else
        {
            printf("Error: Key Not Provided!");
        }
    }
    else
    {
        printf("Error: missing command line argument.");
        return 1;
    }
}

void decryptHash(char *message[], int len, int key)
{
    printf("Decoded Message: ");
    for (int i = 2; i <= len; i++) // avoiding the 0th argv
    {
        int n = strlen(message[i]);
        for (int j = 0; j < n; j++)
        {
            char letter = message[i][j];

            if (letter >= 'a' && letter <= 'z')
            {
                if ((letter - key) < 'a')
                    letter = (letter - key) + 26;
                else
                    letter -= key;
            }
            else if (letter >= 'A' && letter <= 'Z')
            {
                if ((letter - key) < 'A')
                    letter = (letter - key) + 26;
                else
                    letter -= key;
            }
            printf("%c", letter);
        }
        printf(" ");
    }
    printf("\n");
}