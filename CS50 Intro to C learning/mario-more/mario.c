#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int n;

    do
    {
        n = get_int("Input Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)             //Starting loop that will divide the rows
    {

        for (int j = (n-1); j > i; j--)         //making a loop to make spaces, max is n-1 spaces
        {
            printf(" ");
        }

        for (int k = 0; k < i + 1; k++)    //loop to print the first set of # in a row
        {
            printf("#");
        }

        for (int l = 0; l < 2; l++)        //Printing a gap
        {
            printf(" ");
        }

        for (int m = 0; m < i + 1; m++)    //printing the second set of # to finish a row
        {
            printf("#");
        }

        printf("\n");
    }
}


