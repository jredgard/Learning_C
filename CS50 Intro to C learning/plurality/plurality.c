#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];
candidate c_temp[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
int Sort(int n, int l);
void MergeArrays(int f, int l, int m);
int Swap(int n);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }


    Sort(0, candidate_count - 1);   //start recursive function;
    printf("%s  \n", candidates[candidate_count-1].name);
    print_winner();              //Display winner
}

// Update vote totals given a new vote
bool vote(string name)
{

    for (int i = 0; i < (candidate_count); i++)           //bad code, need to use recursion
    {
        string temp = candidates[i].name ;
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO //sort function, Will sort array based of votes recieves candidates.[i].votes, then linear search since it is sorted

    //Left-Right-Merge
    //step 1 Learn recursion with fact
    //step 2 Learn Merge
    //Implement

    // base case (if sorted)

    //base case is if left<right
    // n > (n+1)            (left)>(right)
    //


    //int test(int n)       //indicator of canidate [n]
    // if (n <= (n+1))      //candidates [n].votes < candidates [n+1]
    //      return 0;       //candidates [n] stays in place     --- methoid is in place
    // else
    //      return n+1;      //candidates [n] == candidates [n+1]
                                    //swap
    //int swap(int n)
        // if (test(n))
        //    {
        //        return 0;
        //    }
        //else
       //     test(n)


    return;
}


//method for checking if one value is smaller (this is without left) Need and integerer to define Middle end and start Point
//Will start giving a max as in bubble sort.(bubble sort used to break method up left right)
//sort function to do the following, input n is the number in the array, then
int Sort(int f, int l) // need to change to the number of character count
{
    if (l < 1)
    {
        return 0;
    }                     //l is candidate -1 since its an array index so starts at 0
    else if(f < l)             //if there are 2 entries in an array, then start the
    {
        int m = (f + l)/ 2;    //getting midpoint
        Sort(f, m);            //Left Side
        Sort(m + 1, l);        //Right Side
        MergeArrays(f, l, m);  //Use a function to put left and right together;
    }

    return 0;
}

void MergeArrays(int f, int l, int m)       //m start point, f first, l is last
{
   candidate c_temp1[l - f + 1];             //lenght of temp array

    int i = f;
    int j = m + 1;
    int k = f;

    while ((i <= m)  && (j <= l))
    {
        if(candidates[i].votes < candidates[j].votes)
        {
            c_temp1[k] = candidates[i];
            k++;
            i++;
        }
        else
        {
            c_temp1[k] = candidates[j];
            k++;
            j++;
        }
    }                                                                               //Swapping if number is smaller or the same

    while (i <= m)
    {
        c_temp1[k] = candidates[i];
        k++;
        i++;
    }

    while (j <= l)
    {
        c_temp1[k] = candidates[j];
        k++;
        j++;
    }

    for (i = f; i <= l; i++)
    {
        candidates[i] = c_temp1[i];     //populate array again
    }
}

//max candidates = 1
//left is sorted, and right is sorted

//Merge
//Bubble sorting next one


// Repeat n-1 times
    // For i from 0 to n–2
    //     If numbers[i] and numbers[i+1] out of order
    //         Swap them
    // If no swaps
    //     Quit