#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letter;
int word;
int sentence;

int main (void)

{
    //ask user input for text
    string text = get_string("What is the text you would like to analyze?: ");

    //define lenght of text
    int n = strlen(text);

    count words
    if (isalnum(text[0]))
    {
        word = 1;
    }

    for (int i = 0; i < n;  i++)
    {
        //count letters

        if (isalnum(text[i]))
        {
            letter++;
        }

        //count words

        if (i < n - 1 && isspace(text[i]) && isalnum(text[i + 1]))
        {
            word++;
        }

        //count sentences

        if (i > 0 && (text[i] == '.' || text[i] == '?' || text[i] == '!') && isalnum(text[i - 1]))
        {
            sentence++;
        }

    }

//apply algorithm for Coleman-Liau index

    float grade = ((0.0588 * (100 * letter / word)) - (0.296 * (100 * sentence / word)) - 15.8);
    int roundgrade = round (grade);

//debugger

    //print f("Letters: %i\n Words: %i\n Sentences: %i\n", letter, word, sentence);


//print result for index
    if (roundgrade <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundgrade < 16)
    {
        printf("Grade %i\n", roundgrade);
    }
    else
    {
        printf("Grade 16+\n");
    }
    

}
