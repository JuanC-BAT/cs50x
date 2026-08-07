#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int LETTERS = 0;
const int WORDS = 1;
const int SENTENCES = 2;

// index = 0.0588 * L - 0.296 * S - 15.8
//  L = avg number of letters per 100 words.
//  S = avg number of sentences per 100 words.

// Words are separated by a space (spaces + 1 = words).
// Sentences, any period, exclamation point, or question mark indacates the end of the sentence.

void check_text(string text[]);
void check_level(int c[]);

int main(void)
{
    string text[] = {""};
    text[0] = get_string("Text: ");
    check_text(text);
}

void check_text(string t[])
{
    int counts[] = {0, 0, 0};
    int len = strlen(t[0]);
    for (int i = 0; i < len; i++)
    {
        if (isalnum(t[0][i]) != 0)
        {
            counts[LETTERS]++;
        }
        else if (isspace(t[0][i]) != 0)
        {
            counts[WORDS]++;
        }
        else if (t[0][i] == '.' || t[0][i] == '!' || t[0][i] == '?')
        {
            counts[SENTENCES]++;
        }
    }
    counts[WORDS]++;
    check_level(counts);
}

void check_level(int c[])
{
    float index = 0.0588 * (((float) c[LETTERS] / c[WORDS]) * 100) -
                  0.296 * (((float) c[SENTENCES] / c[WORDS]) * 100) - 15.8;
    index = round(index);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
