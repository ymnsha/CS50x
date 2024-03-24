#include <cs50.h>
#include <stdio.h>

int main()
{
    // Get the name from user and print it
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}
