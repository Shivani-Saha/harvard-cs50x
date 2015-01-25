#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<string.h>

int main(int argc, string argv[])
{
    if(argc!=2)
    {
        printf("Single argument required!\n");
        return 1;
    }
    int len1, i;
    for(i=0, len1=strlen(argv[1]); i<len1; i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Only alphabets required in the parameter!\n");
            return 1;
        }
    }
    char text[40];
    gets(text);
    for(int j=0, k=0, len2=strlen(text); j<len2; j++)
    {
            if(isalpha(text[j]))
            {
                if(k==len1)
                    k=0;
                if((argv[1][k]>='a')&&(argv[1][k]<='z'))
                {
                    if((text[j]>='a')&&(text[j]<='z'))
                    {
                        text[j]=(((text[j]-97)+(argv[1][k]-97))%26)+97;
                        k++;
                    }
                    else
                    {
                        text[j]=(((text[j]-65)+(argv[1][k]-97))%26)+65;
                        k++;
                    }
                }
                else
                {
                    if((text[j]>='a')&&(text[j]<='z'))
                    {
                        text[j]=(((text[j]-97)+(argv[1][k]-65))%26)+97;
                        k++;
                    }
                    else
                    {
                        text[j]=(((text[j]-65)+(argv[1][k]-65))%26)+65;
                        k++; 
                    }
                }
            }
    }
    puts(text);

    return 0;
}
