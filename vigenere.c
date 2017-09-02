#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 26

int CheckArgQuantity(int needed_quantity, int real_quantity);
int CheckIsArgAlpha(string argument);
string StringToLower(string s);
char EncriptedLetter(char symbol, int key);
void UsagePrompt(void);
void DummyStep (string StepName);

int main(int argc, string argv[])
{
    if ((CheckArgQuantity(2, argc) != 0 ) || (CheckIsArgAlpha(argv[1]) != 0))
    {
        UsagePrompt();
        return 1;
    }
    
    //request plain text
    string plain_text = GetString();
    //string plain_text = "Meet me at the park at eleven am";
  
    //key to lowercase
    string key = StringToLower(argv[1]);
    int key_length = strlen(key);
    
    for (int i = 0, n = strlen(plain_text), j = 0; i < n; i++)
    {
    //start encripting loop    
        if (isalpha(plain_text[i]) != 0)
        {
            printf("%c", EncriptedLetter(plain_text[i], (int) (key[j % key_length] - 'a')));
            j++;
        }   else
            {
                printf("%c", plain_text[i]);
            }
    //end encripting loop    
    }
    printf("\n");
    return 0;
}

int CheckArgQuantity(int needed_quantity, int real_quantity)
{
    if (real_quantity == needed_quantity)
    {
        return 0;
    }   else
        return 1;
}
int CheckIsArgAlpha(string argument)
{
    int check = 0;
    for (int i = 0, n = strlen(argument); i < n; i++ )
    {
        if (isalpha(argument[i]) == 0)
        {
            check = 1;
        }
    }
    return check;
}

string StringToLower(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

char EncriptedLetter(char symbol, int key)
{
    //initialise case beginning letter
    char start_point = 'A';
    if (islower(symbol)!= 0)
        {
            start_point = 'a';
        } 
        
    return (((symbol - start_point) + key) % N) + start_point;
}

void UsagePrompt(void)
{
    printf("Usage is: ./viginere [alphabetical symbols only key] !!\n");
}

void DummyStep (string StepName)
{
    printf("Step \"%s\" is completed\n", StepName);
}
