#include <cs50.h>
#include <stdio.h>

void pyramid(int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height? ");
    }
    while (height < 1 || height > 8);
    pyramid(height);
}

void pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = (height - 1); j > i; j--)
        {
            printf(" ");
        }

        for (int k = -1; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int m = -1; m < i; m++)
        {
            printf("#");
        }

        printf("\n");
    }
}
