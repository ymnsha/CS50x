#include <cs50.h>
#include <stdio.h>
#include <string.h>

int getCheckSumOfCard(long cardNum);

int main(void)
{
    // Get Input from user, Using long for larger numbers
    long cardNum = get_long("Number: ");
    long tempNum = cardNum;
    char cardNumInString[20];
    // sprintf is a utility func from string.h
    // helps to convert number to string(array of chars)
    sprintf(cardNumInString, "%ld", cardNum);

    int checksum = getCheckSumOfCard(cardNum);

    if (checksum % 10 == 0)
    {
        if (strlen(cardNumInString) == 15 && (cardNumInString[0] == '3') &&
            (cardNumInString[1] == '4' || cardNumInString[1] == '7'))
        {
            // AMEX Card -> 15 digits, Starts with 34 or 37
            printf("AMEX\n");
        }
        else if ((strlen(cardNumInString) == 13 && cardNumInString[0] == '4') ||
                 (strlen(cardNumInString) == 16 && cardNumInString[0] == '4'))
        {
            // VISA Card -> 13 or 16 digits, Starts with 4
            printf("VISA\n");
        }
        else if (strlen(cardNumInString) == 16 && cardNumInString[0] == '5' &&
                 cardNumInString[1] - '0' <= 5 && cardNumInString[1] - '0' >= 1)
        {
            // To check if second character is <=5 and >=1, Changed cardNumInString[1](char) to int
            // by subtracting '0' from it As per Ascii, Chars are represented by integers. '0' is
            // 48, '1' is 49 etc so, subtracting '0' which is 48 in ascii from '4' i.e. 52 in ascii,
            // we get 4 in integer

            // MASTERCARD Card -> 16 digits, Starts with 51, 52, 53, 54, 55
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int getCheckSumOfCard(long cardNum)
{
    int sum = 0;
    int lastDigit;
    int secondToLastDigit;
    while (cardNum > 0)
    {
        lastDigit = cardNum % 10;
        // find the second to last digit by % of 100 then divide by 10
        //  if the number is a 2 digit number, get the last digit by % of 10 and second last by / 10
        secondToLastDigit =
            (((cardNum % 100) / 10) * 2) >= 10
                ? (((cardNum % 100) / 10) * 2) / 10 + (((cardNum % 100) / 10) * 2) % 10
                : (((cardNum % 100) / 10) * 2);
        sum = sum + lastDigit + secondToLastDigit;
        // divide by 100 as we used both last and second to last digit and added in sum
        cardNum = cardNum / 100;
    }

    return sum;
}
