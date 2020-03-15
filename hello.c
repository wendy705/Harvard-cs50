#include <stdio.h>
#include <cs50.h>

//Get user input for name and return personalized message
int main(void)
{
    string name = get_string("What is your name?\n");
    printf("Hello, %s\n", name);
}    
