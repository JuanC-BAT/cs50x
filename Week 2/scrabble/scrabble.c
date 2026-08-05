#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_points(string w[], int p[], char l[]);
void check_winner(int p1, int p2);

int main(void)
{
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    char letters[26];
    int n = 0;
    string word_player1[] = {""};
    string word_player2[] = {""};
    for (int i = 65; i <= 90; i++)
    {
        letters[n] = i;
        n++;
    }
    word_player1[0] = get_string("Player 1: ");
    word_player2[0] = get_string("Player 2: ");
    int score_player1 = check_points(word_player1, points, letters);
    int score_player2 = check_points(word_player2, points, letters);
    check_winner(score_player1, score_player2);
}

int check_points(string w[], int p[], char l[])
{
    int score = 0;
    int word_len = strlen(w[0]);
    for (int i = 0; i < word_len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (toupper(w[0][i]) == l[j])
            {
                if (w[0][i] == '\0')
                {
                    break;
                }
                score = score + p[j];
                break;
            }
        }
    }
    return score;
}

void check_winner(int p1, int p2)
{
    if (p1 > p2)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1 < p2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
