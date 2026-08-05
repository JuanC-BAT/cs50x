#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int CONST_AMEX = 15;
const int CONST_MAST = 16;
const int CONST_VISA_MAX = 13;
const int CONST_VISA_MIN = 16;

int check_num(long n, int m)
// n = card_num, m = digits
/*
    Function made to count the digits of the number given.
*/
{
    do
    {
        m++;
        n = n / 10;
    }
    while (n > 0);
    return m;
}

bool check_sum(long p, int q)
// p == card_num, q == digits
/*
    This function multiply the odd numbers by 2 and if the number is greater than 10 it will
   separate the 1 from the unit then both will be added to the counter "sum". If the number is even
   it will be added to the counter "sum"
*/

{
    long div = 1;
    int count = 0;
    int sum = 0;

    for (int i = 0; i < (q); i++)
    {
        div = div * 10;
        if ((i % 2) != 0)
        {
            count = (((p % div) * 10) / div) * 2;
            if (count >= 10)
            {
                count = (count % 10) + 1;
            }
            sum = sum + count;
        }
        else
        {
            count = (((p % div) * 10) / div);
            sum = sum + count;
        }
    }
    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string card_type(long r, int s)
// r == card_num, s == digits
/*
    This function scan for the first digits and then return the card type (AMEX, MASTERCARD, VISA)
*/
{
    long mod = 1;
    int num = 0;
    string type;

    for (int i = 0; i < (s - 2); i++)
    {
        mod = mod * 10;
    }
    num = r / mod;
    if (num >= 51 && num <= 55 && s == CONST_MAST)
    {
        type = "MASTERCARD\n";
        return type;
    }
    else if ((num == 34 || num == 37) && s == CONST_AMEX)
    {
        type = "AMEX\n";
        return type;
    }
    else if (num >= 40 && num <= 49 && (s == CONST_VISA_MIN || s == CONST_VISA_MAX))
    {
        type = "VISA\n";
        return type;
    }
    else
    {
        type = "INVALID\n";
        return type;
    }
}

int main(void)
{
    long card_num;
    int digits = 0;
    card_num = get_long("ingrese el numero: ");
    digits = check_num(card_num, digits);
    if (digits != CONST_VISA_MAX && digits != CONST_VISA_MIN && digits != CONST_AMEX)
    {
        printf("INVALID\n");
    }
    else
    {
        string check = card_type(card_num, digits);
        if (strcmp(check, "INVALID\n") == 0)
        {
            printf("%s", check);
        }
        else
        {
            bool flag = check_sum(card_num, digits);
            if (flag == false)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("%s", check);
            }
        }
    }
}
