#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry=0;
    while(tail1 != NULL || tail2 !=NULL)
    {
        int sum=carry;
        if(tail1 != NULL)
        {
            sum=sum+tail1->data;
            tail1=tail1->prev;
        }
        if(tail2 != NULL)
        {
            sum=sum+tail2->data;
            tail2=tail2->prev;
        }
        int digit=sum%10;
        carry=sum/10;
        insert_first(headR,tailR,digit);
    }
    if(carry!=0)
    {
        insert_first(headR,tailR,carry);
    }
    //return SUCCESS;

}
