#include <cs50.h>
#include <stdio.h>

int main()
{
    int height;

    //prompt input from user until its more than 0
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - (i + 1); j++)
        {
            printf(" ");
        }
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
