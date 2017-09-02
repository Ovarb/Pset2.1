#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
// request a full name    
    string s = GetString();
    
//  print upperized 1st initial  
    printf("%c", toupper(s[0]));

// print upperized symbols following every blank space    
    for (int i = 1, length = strlen(s); i < length; i++)
    {
        if (s[i] == ' ')
        {
            printf("%c", toupper(s[i + 1]));
        }
    }
    printf("\n");
}