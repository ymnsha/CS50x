#include <cs50.h>
#include <stdio.h>

int main()
{
    int change, coins = 0;

    // prompt input from user until its more than 0
    do
    {
        change = get_int("Change owed: ");
    }
    while (change <= 0);

    // divide the change by 25, 10, 5, 1 and add the result to coins
    while (change > 0)
    {
        if (change >= 25)
        {
            coins = coins + change / 25;
            change = change % 25;
        }
        else if (change >= 10)
        {
            coins = coins + change / 10;
            change = change % 10;
        }
        else if (change >= 5)
        {
            coins = coins + change / 5;
            change = change % 5;
        }
        else
        {
            coins = coins + change;
            change = 0;
        }
    }
    printf("%i\n", coins);
}