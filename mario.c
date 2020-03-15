#include <cs50.h>
#include <stdio.h>

int pyramid(int n);

int main(void){
    int height;

    do {
        height = get_int("Please enter a number between one and eight: ");
    } while(height < 1 || height > 8);
    
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
    return 0;
}
