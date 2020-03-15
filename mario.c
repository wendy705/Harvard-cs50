#include <cs50.h>
#include <stdio.h>

int pyramid(int n);

//getting user input for pyramid height
int main(void)
{
    int height;

    do 
    {
        height = get_int("Please enter a number between one and eight: ");
    } 
    //setting limits for pyramid height
    while (height < 1 || height > 8);
    
    return pyramid(height);
}

int pyramid(int n)
{
//Print hashes iteration
    for (int i = 1; i <= n; i++)
    {
        for (int j = (n - i); j >= 1; j--)
        {
            printf(" ");
        }

        for (int k = 1; k < (i + 1); k++)
        {    
            printf("#"); 
        }
        printf("\n");
    }
    //in case of error, you could throw error
    return 0;
}
