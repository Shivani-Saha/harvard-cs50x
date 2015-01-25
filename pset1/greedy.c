#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    float amt;
    int cents=0, count=0;
    printf("O hai! ");
    //Getting amount from the user
    do
    {
        printf("How much change is owed?\n");
        amt = GetFloat();
    }while(amt<0.00);
    
    //Rounding off amount
    cents= roundf(amt*100);
    
    //Counting minimum number of coins required
    while(cents>0)
    {
        if(cents>=25)
        {    
            count++;
            cents=cents-25;
        }     
        else if(cents>=10)
        {
            count++;
            cents=cents-10;
        }
        else if(cents>=5)
        {
            count++;
            cents=cents-5;
        }
        else
        {
            count++;
            cents=cents-1;
        }
    }
    printf("%d\n",count);
    return 0; 
}
