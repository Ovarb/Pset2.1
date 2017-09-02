#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
// request a full name    
    string s = GetString();
    
//  print upperized 1st initial  
    if (isalpha(s[0]) != 0)
        {
             printf("%c", toupper(s[0]));
        }

    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (((int) s[i] == 32) && (isalpha(s[i+1]) != 0))
        {
            printf("%c", toupper(s[i + 1]));
        }
    }


    printf("\n");
}