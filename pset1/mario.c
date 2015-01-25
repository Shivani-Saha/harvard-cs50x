#include<stdio.h>
#include<cs50.h>

int main(void)
{
    //Get height from the user
    int h;
    do
    {
        printf("Height: ");
        h=GetInt();
    }while(h<0 || h>23);
    
    //Printing the pyramid
    for(int i=1; i<=h; i++)
    {
        for(int j=h-1; j>=i; j--)
        {
            printf(" ");
        }
        for(int k=0; k<=i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
