
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

// defining a function like the caeser cypher
char old(char token, int key);



//single character input processing no check
char old(char token, int key)
{
    if(islower(token))
    {
        return ((((token - 97)+key)%26)+97);
    }
    else
    {
        return ((((token - 65)  +key)%26)+65);
    }
}

int main(int argc, string argv[]) {

    // Initialization section
    int K_counter = 0;
    bool keypassed = false;
    string v_word = "";
    int keylength = 0;
    string user_text = "";
    int input_length;
    

    do
    {
        // most probably they didn't enter a word 
        if(argc != 2)
        {
            printf("nope, I need a v_word - try again.\n");
            return 1;
        }
        else if(argv[1])
        {
            int length = strlen(argv[1]);
            for(int i = 0; i < length; i++)
            {   //this loop sorts out anything that isn't a letter  
                if(!isalpha(argv[1][i]))
                {
                    
                    printf("Letters only bro/sis.\n");
                    return 1;
                }
                else
                {
                    // User input is all good passing argv to variable
                    keypassed = true;
                    v_word = argv[1];
                }
            }
        }
        /*keeping a do while format, even although not not necessary
        if this was a website, we would keep it all in one session */
    } while(!keypassed);
    
    // get the lenght of v_word
    keylength = strlen(v_word);
    int K_num[keylength];
    // vword letters converted to numbers ignoring caps, 0 - 25

    for(int i = 0; i < keylength;i++)
    {
        K_num[i] = toupper(v_word[i]) - 65;
    }

    // process the input of text to be cyphered
    user_text = GetString();
    input_length = strlen(user_text);

    for (int i = 0; i < input_length; i++)
    {
        // print out and ignore if not a letter
        if(!isalpha(user_text[i]))
        {
            printf("%c", user_text[i]);
        }
        // encoding 
        else
        {
            printf("%c", old(user_text[i], K_num[K_counter]));

            // move throught the array 
            if(K_counter < keylength - 1)
            {
                K_counter++;
            }
            else
            {
                K_counter = 0;
            }
        }
    }

    // all is fine if we got here
    printf("\n");
    return 0;
}

