#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getWordCount(string word, int points[]);

int main()
{
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int wordCount1 = getWordCount(word1, points);
    int wordCount2 = getWordCount(word2, points);

    if (wordCount1 > wordCount2)
    {
        printf("Player 1 wins!\n");
    }
    else if (wordCount2 > wordCount1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int getWordCount(string word, int points[])
{
    int count = 0;
    // Loop over each alphabet
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        // Turn each alphabet to uppercase
        char alphabet = toupper(word[i]);
        // Check if its alphabet only and not other characters
        if (alphabet >= 'A' && alphabet <= 'Z')
        {
            // Subtract from 'A' to get the index number
            // i.e. 'B' - 'A' will be 66 - 65 i.e. 1 index of B in points
            count = count + points[alphabet - 'A'];
        }
    }
    return count;
}
