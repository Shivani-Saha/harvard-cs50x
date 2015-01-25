#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("A non negative integer required!");
        return 1;
    }
    int k = atoi(argv[1]);
    char text[20];
    gets(text);
    for(int i=0, len=strlen(text); i<len; i++)
    {
        if(isalpha(text[i]))
        {
            if(text[i]>='a' && text[i]<='z')
            {
                text[i] = ((text[i]-97+k)%26)+97;
            }
            else
            {
                text[i] = ((text[i]-65+k)%26)+65;   
            }
        }
    }
    puts(text);
    return 0;
}
