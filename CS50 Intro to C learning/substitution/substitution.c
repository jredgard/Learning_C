#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int CheckLenght(string argv);
int TestDouble(string argv, string l_used2);
void InputS(string code);

//used a char with alphabet values since it will be constant
char alpha[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        if (CheckLenght(argv[1]) != 0)          //I used a lot of functions to break up code. This was a problem with the check50
        {
            return 1;
        }
    }
}

int CheckLenght(string argv)
{
    char l_used[27];                           //making sure the input it  26
    int l_string = strlen(argv);
    if (l_string != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < l_string; i++)      //changing the key to uppercase and error if there is anything else than the alphabet
        {
            if (isalpha(argv[i]))
            {
                if (islower(argv[i]))
                {
                    argv[i] = toupper(argv[i]);
                }
                else
                {
                    l_used[i] = argv[i];
                }
            }
            else
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
        l_used[26] = '\0';                              //removing excess to end on a null
        if (TestDouble(argv, l_used) != 0)
        {
            return 1;
        }
        return 0;
    }
}

int TestDouble(string argv, string l_used2)
{
    int lenght = strlen(argv);
    //testing double by populating a second array and comparing each number+1 of the second array
    for (int i = 0; i < lenght; i++)
    {
        for (int j = i + 1; j < lenght; j++)
        {
            if (argv[i] == l_used2[j])
            {
                printf("Usage: ./substitution key\n");          //same thing happened with the check50
                return 1;
            }
        }
    }
    InputS(argv);
    return 0;
}

void InputS(string code)
{
    string input = get_string("plaintext:  ");              //used several methods to make it easier for me to break down logic blocks
    int i_lenght = strlen(input);
    char output[i_lenght + 1];

    for (int i = 0; i < i_lenght; i++)
    {
        if (isalpha(input[i]))                              //making sure there can be spaces or anything else than chars
        {
            for (int j = 0; j < 26; j++)
            {
                if (islower(input[i]))
                {
                    if (alpha[j] == (input[i] - 32))        //comparing the lower case to that of the upper case using the ASCII
                    {
                        output[i] = code[j];
                        output[i] = tolower(output[i]);
                        break;
                    }
                }
                else if (isupper(input[i]))
                {
                    if (alpha[j] == input[i])
                    {
                        output[i] = code[j];
                        break;
                    }
                }
            }
        }
        else
        {
            output[i] = input[i];                       //adding non alphabetical letters to the ouput
        }
    }

    output[i_lenght] = '\0';                        //removing excess inputs from the char array
    printf("ciphertext: %s\n", output);
}


