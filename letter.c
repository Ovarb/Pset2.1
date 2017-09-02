#include <stdio.h>
#include <ctype.h>

char EncriptedLetter(char symbol, int key);
char EncriptedLetter1(char symbol, int key);

int main(void)
{
    //initialising input letter and key
    char letter = 'b';
    int flag = (int)islower(letter) + 2;
    printf("flag %i\n", flag);
    int k = 13;
    printf("%c, %i\n", letter, k);
    
    //get ASCII code
    int l = (int) letter;
    printf("%i\n", l);
    
    for (letter = 'A'; letter <= 'Z'; letter++)
    //for (k = 0; k < 27; k++)
    {
        //run function
        printf("%c ", letter);
        printf("%i ", k);
        printf("%c", EncriptedLetter1(letter, k));
        printf("\n");
    }
    
    
    
}

char EncriptedLetter(char symbol, int key)
{
    
    //get ASCII code of symbol
    int symbol_code = (int) symbol;
    
    //Add key to ASCII code
    int encripted_code = symbol_code + key;
    
    //Check out of alphabet border
    if (((symbol >= 'a' && symbol <= 'z') && encripted_code > ((int) 'z')) || ((symbol >= 'A' && symbol <= 'Z') && encripted_code > ((int) 'Z')))
    {
        //if yes decrement encripted ASCII
        encripted_code = encripted_code - (26);
    }
    
    //return encripted char
    return (char) encripted_code;
}

char EncriptedLetter1(char symbol, int key)
{
    int encripted_code;
    
    //get ASCII code of symbol
    int symbol_code = (int) symbol;
    
    //Add key to ASCII code
    if (islower(symbol)!= 0)
        {
            encripted_code = (((symbol_code - 'a') + key) % 26) + 'a';
        } else
            {
                encripted_code = (((symbol_code - 'A') + key) % 26) + 'A';
            }
    
    //return encripted char
    return (char) encripted_code;
}