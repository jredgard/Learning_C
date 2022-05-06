#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2)
    {
        printf("Tie!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    string s = word;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            while (islower(s[i]))
            {
                s[i] = toupper(s[i]);       //While loop to change any lower case
            }
            int value = s[i] - 65;          //Using base values of a letter and -65 to get point in array
            score += POINTS[value];
        }
        else
        {
            score += 0;                     //No added score if it is not part of the alphabet
        }
    }
    return score;
}
