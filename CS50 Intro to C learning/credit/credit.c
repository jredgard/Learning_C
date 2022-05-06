#include <stdio.h>
#include <cs50.h>


void Invalid();
void Valid(string card);
void Test(int n, long num, string cardtype);
void addFirstSum(int inum);
void addSecondSum(int inum2);
void DoubleCheck(bool sum, bool start);

int main(void)
{
    int ilenght = 0;

    long _num = get_long("Number: ");
    long numb = _num;
    string cardType;

    while (_num > 0)        //first getting the max lenght of the card
    {
        ilenght++;
        _num = _num / 10;
    }

    switch (ilenght)        //using switch since I only need 3 values and can incorporate the number check
    {
        case 15:
        {
            int n = numb / 10000000000000;      //checking for starting numbers for later validation
            if (n == 34 || n == 37)
            {
                cardType = "AMEX";
                Test(15, numb, cardType);
                break;
            }
            else
            {
                Invalid();
                break;
            }
        }
        case 16:
        {
            int n = numb / 100000000000000;
            if (n >= 51 && n <= 55)
            {
                cardType = "MASTERCARD";
                Test(16, numb, cardType);
                break;
            }
            else if (n / 10 == 4)
            {
                cardType = "VISA";
                Test(16, numb, cardType);
                break;
            }
            else
            {
                Invalid();
                break;
            }
        }
        case 13:
        {
            int n = numb / 1000000000000;
            if (n == 4)
            {
                cardType = "VISA";
                Test(13, numb, cardType);
                break;
            }
            else
            {
                Invalid();
                break;
            }
        }
        default:
        {
            Invalid();
            break;
        }
    }


}

void Valid(string card)
{
    printf("%s\n", card);
}

void Invalid()
{
    printf("INVALID\n");
}

void Test(int n, long num, string cardType)
{
    int totalFirstSum = 0;
    int totalSecondSum = 0;
    int totalSum = 0;

    int tempNum;
    int lastLenght = n;

    while (lastLenght > 0)
    {

        for (int i = 1; i < (n + 1); i++)
        {
            if (i % 2 == 0)
            {
                tempNum = (num % 10) * 2;           //breaking up any multiplication that results in a larget value than 1 digit
                if (tempNum > 9)                    // in hindsite I could've used a digit rather than an int
                {
                    int j = tempNum % 10;
                    int k = tempNum / 10;
                    totalFirstSum += (j + k);
                    num = num / 10;
                }
                else
                {
                    totalFirstSum += (tempNum);
                    num = num / 10;
                }
            }
            else
            {
                tempNum = num % 10;
                totalSecondSum += tempNum;
                num = num / 10;
            }
            lastLenght--;
        }
    }

    totalSum = totalFirstSum + totalSecondSum;
    if ((totalSum % 10) == 0)
    {
        Valid(cardType);
    }
    else
    {
        Invalid();
    }
}
