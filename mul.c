#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry,count=0;
    if((tail1->data==0 && tail1->prev==NULL) || (tail2->data==0 && tail2->prev==NULL))
    {
        insert_first(headR,tailR,0);
        return;
    }
    node *temp1;
    node *temp2;

    node *headR2=NULL,*tailR2=NULL;
    node *headAR=NULL,*tailAR=NULL;

    temp2=tail2;

    while(temp2!=NULL)
    {
        carry=0;
        temp1=tail1;

        /*multiply one digit of second number
        with all digits of first number*/
        while(temp1!=NULL)
        {
            int mul=(temp2->data * temp1->data)+carry;
            carry=mul/10;
            mul=mul%10;

            insert_first(&headR2,&tailR2,mul);
            temp1=temp1->prev;
        }
        if(carry!=0) //insert remaining carry
        {
            insert_first(&headR2,&tailR2,carry);
        }
        for(int i=0;i<count;i++)
        {
            insert_last(&headR2,&tailR2,0);
        }
        if(*headR==NULL)
        {
            *headR=headR2;
            *tailR=tailR2;

            headR2=NULL;
            tailR2=NULL;
        }
        else
        {
            addition(*tailR,tailR2,&headAR,&tailAR); //Add partial result with final result

            delete_list(headR,tailR);

            *headR=headAR;
            *tailR=tailAR;

            headAR=NULL;
            tailAR=NULL;

            delete_list(&headR2,&tailR2);
        }
        count++;
        temp2=temp2->prev;
    }

}