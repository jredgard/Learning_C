#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int compute_Score(string letters);

int main(void)
{
    string sent = get_string("Test: \n");
    int scoreS = compute_Score(sent);

    if (scoreS < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (scoreS >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", scoreS);
    }
}

int compute_Score(string letters)
{
    int w_count = 1;
    int l_count = 0;
    int s_count = 0;
    float l = 0;
    float s = 0;
    float f_score = 0;
    int lenght = strlen(letters);
    for (int i = 0; i < lenght; i++)        //getting lenght of string
    {
        if (isalpha(letters[i]))
        {
            l_count++;                      //getting letters
        }

        if (isspace(letters[i]))
        {
            w_count++;                      //word count
        }

        if (letters[i] == 33 || letters[i] == 46 || letters[i] == 63)       //checking for end of sentences
        {
            s_count++;
        }
    }

    s = s_count / (w_count / 100.00);       //converting to floats while dividing
    l = l_count / (w_count / 100.00);

    f_score = round(((0.0588 * l) - (0.296 * s) - 15.8));
    return f_score;
}

