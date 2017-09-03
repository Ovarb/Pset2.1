//GIT test commit 01

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#define N 26

char EncriptedLetter(char symbol, int key);

int main(int argc, string argv[])
{
    //check existence of key in command line
    if (argc != 2)
        {
            printf("There is no valid cipher key in command line!\n");
            return 1;
        }

    // if the command line contains a valid key then request a plaintext
    string plain_txt = GetString();

    //calculate the key
    int cipher_key = atoi(argv[1]) % N;

    //encript plain text symbol by symbol
    for (int i = 0, n = strlen(plain_txt); i < n; i++)
    {
    //if symbol is a lowercase or capitalized letter then encript it
        if (isalpha(plain_txt[i]) != 0)
            {
                printf("%c", EncriptedLetter(plain_txt[i], cipher_key));
            }   else

    //if symbol is any other than letter then keep it unencripted
                printf("%c", plain_txt[i]);
    }

    printf("\n");
    return 0;
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