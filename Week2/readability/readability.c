#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countSentences(string text);
int countWords(string text);

int main()
{
    string text = get_string("Text: ");
    int noOfLetters = countLetters(text);
    int noOfSentences = countSentences(text);
    int noOfWords = countWords(text);

    // typecasted to float and then rounded to Int
    int grade = (int) round(0.0588 * ((noOfLetters / (float) noOfWords) * 100) -
                            0.296 * ((noOfSentences / (float) noOfWords) * 100) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int countLetters(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // A letter that comes in between A-Z or a-z, count it
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            count++;
        }
    }
    return count;
}

int countSentences(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // Count as a sentence if it ends with . ! ?
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count++;
        }
    }
    return count;
}

int countWords(string text)
{
    int count = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        // Count as a sentence if it ends with space or it's the last word
        if (text[i] == 32 || text[i + 1] == '\0')
        {
            count++;
        }
    }
    return count;
}
