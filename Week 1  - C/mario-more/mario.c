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

        for (int a = 0; a < height - (i + 1); a++)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        for (int k = 0; k < 2; k++)
        {
            printf(" ");
        }

        for (int l = 0; l <= i; l++)
        {
            printf("#");
        }

        printf("\n");
    }
}
