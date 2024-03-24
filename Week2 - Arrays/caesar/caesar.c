#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isNumber(string argument);
void rotate(char letter, int key);

int main(int argc, string argv[])
{
    string plainText;
    string cipherText;
    int key;

    // if two arguments and the second argument is greater/equal to 0
    if (argc == 2)
    {
        // check if argument is a number or not
        if (isNumber(argv[1]))
        {
            key = atoi(argv[1]);
            plainText = get_string("plaintext:  ");
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("ciphertext: ");

    for (int i = 0, length = strlen(plainText); i < length; i++)
    {
        rotate(plainText[i], key);
    }

    printf("\n");
}

bool isNumber(string argument)
{
    for (int i = 0, length = strlen(argument); i < length; i++)
    {
        if (!isdigit(argument[i]))
        {
            return false;
        }
    }
    return true;
}

void rotate(char letter, int key)
{
    if (isalpha(letter))
    {
        // Determine the base of the alphabet (either 'A' or 'a') based on the case of the letter
        char base = isupper(letter) ? 'A' : 'a';
        // Calculate the shifted letter, wrapping around if necessary
        printf("%c", ((letter - base + key) % 26 + base));
    }
    else
    {
        // If the character is not an alphabet, print it unchanged
        printf("%c", letter);
    }
}
