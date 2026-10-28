#include "apc.h"


int division(node *head1, node *head2, node **headR, node **tailR)
{
    node *divisor=NULL;
    node *divisor_tail=NULL;
    node *remainder=NULL;
    node *remainder_tail=NULL;
    node *temp=NULL;

    if(head1==NULL || head2==NULL)
    {
        
        printf("Error: Division failed-one or both operands are NULL\n");
        return FAILURE;
    }
    /*if(head1->data==0 && head1->next==NULL)
    {
        insert_first(headR,tailR,0);
        return SUCCESS;
    }*/
    for(temp=head2;temp!=NULL;temp=temp->next)
    {
        insert_last(&divisor,&divisor_tail,temp->data);
    }
    remove_pre_zeros(&divisor,&divisor_tail);
    if(divisor==NULL || (divisor->data==0 && divisor->next==NULL))
    {
        
        printf("Division by zero is not allowed\n");
        delete_list(&divisor,&divisor_tail);
        return FAILURE;
    }
    *headR=NULL;
    *tailR=NULL;

    for(temp=head1;temp!=NULL;temp=temp->next)
    {
        int quotient_digit=0;
        insert_last(&remainder,&remainder_tail,temp->data);
        remove_pre_zeros(&remainder,&remainder_tail);
        while(remainder!=NULL && compare_list(remainder,divisor)!=OPERAND2)
        {
            node *new_remainder=NULL;
            node *new_remainder_tail=NULL;
            subtraction(remainder_tail,divisor_tail,&new_remainder,&new_remainder_tail);
            delete_list(&remainder,&remainder_tail);
            remainder=new_remainder;
            remainder_tail=new_remainder_tail;
            remove_pre_zeros(&remainder,&remainder_tail);
            quotient_digit++;
        }
        insert_last(headR,tailR,quotient_digit);
    }
    remove_pre_zeros(headR,tailR);
    delete_list(&divisor,&divisor_tail);
    delete_list(&remainder,&remainder_tail);
    return SUCCESS;
}
