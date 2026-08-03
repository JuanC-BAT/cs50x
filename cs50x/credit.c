#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnum;
    long check;
    int digits;
    do
    {
        cardnum = get_long("ingrese el numero: ");
        check = cardnum;
        digits= 0;
        do
        {
            digits++;
            check = check/10;
        }
        while(check>0);
    }
    while (digits != 13 && digits != 15 && digits != 16);
}
