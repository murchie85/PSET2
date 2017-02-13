#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
                        
int main(int argc, string argv[])
{
    // initialization 
    bool keypassed = false;
    int key = 0;
    int text_length = 0;
    string text = "";
    
    // get and process input
    do
    {
        // 
        if(argc != 2)
        {
            printf("doh, fail! Try again.\n");
            return 1;
        }
        else
        {
            // Key needs to be converted from string to int
            key = atoi(argv[1]);
            keypassed = true;
        }
    } while(!keypassed);
    
    // get the text to be inciphered
    text = GetString();
    text_length = strlen(text);
    for(int i = 0; i < text_length; i++)
    {
        // Process characters as per advice from Zamyla in cs50
        if(isalpha(text[i]))
        {
            // deals with small letters key is parameterised 
            if(islower(text[i]))
            {
                printf("%c", ((((text[i] - 97)+key)%26)+97));
            }
            // deals with big letters
            else
            {
                printf("%c", ((((text[i] - 65)+key)%26)+65));
            }
        }
        // leave anything that doesn't fit the cypher criteria
        else
        {
            printf("%c", text[i]);
        }
    }
    // if it gets here, then its a success 
    printf("\n");
    return 0;  
}