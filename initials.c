#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// could 
int main(void)
{
    
    
    // store string to name 
    string name = GetString();
    
    // takes the first letter and puts to upper case
    printf("%c", toupper(name[0]));
   
    // increments through string places, use 'n' to keep tidy
    for ( int i = 0, n = strlen(name); i < n; i++)
    {
        // if a value in the string has a space...and not end of text
        if ( name[i] == ' ' && name[i + 1] != '\0') 
        {
            // make the next one a capital
            printf("%c",toupper(name[i + 1])); 
            i++;
      
        }
       
    }
    
    // after end print out new line 
    printf("\n"); 
}