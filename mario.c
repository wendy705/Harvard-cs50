#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    int i = get_positive_int ("Please, enter a number between one and eight: ");
    printf ("%i\n", i);

}

// Prompt user for positive integer between one and eight
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    //return n;
//Print hashes iteration
    for (int i = 1; i <= n; i++)
        {
            for (int j = (n - i); j >= 1; j--)
                {
                    printf(".");
                }
            for (int k = 1; k < (i + 1); k++)
                {
                    printf("#"); 
                }
            printf("\n");
        }
        return n;
}
