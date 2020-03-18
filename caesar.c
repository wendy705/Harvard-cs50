#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2 && isdigit(*argv[1]))

    {

        int k = atoi(argv[1]);

        //get user input for string
        string s = get_string("Text you'd like to cypher: ");

        //print out text once it has been ciphered
        printf("Ciphertext: ");


        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            //check if i is lowercase character
            if (s[i] >= 'a' && s[i] <= 'z')

            {
                printf("%c", (((s[i] - 'a') + k) % 26) + 'a');
            }

            //check if i is uppercase character
            else if (s[i] >= 'A' && s[i] <= 'Z')

            {
                printf("%c", (((s[i] - 'A') + k) % 26) + 'A');
            }

            //print same character
            else

            {
                printf("%c", s[i]);
            }
        }

        printf("\n");
        return 0;
    }

    //throw an error
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;

    }

}