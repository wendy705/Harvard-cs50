#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
//get user input for change owed
    float change_owed;
    do
    {
        change_owed = get_float("What's the change you are owed?\n$");
    }
    while (change_owed < 0);
    int cents_owed = round(change_owed * 100);
   

//get remainder for every coin
    int quarters = cents_owed / 25;
    int dimes = (cents_owed % 25) / 10;
    int nickels = ((cents_owed % 25) % 10) / 5;
    int pennies = ((cents_owed % 25) % 10) % 5;

//print result    
    printf("%i\n", quarters + dimes + nickels + pennies);
}
