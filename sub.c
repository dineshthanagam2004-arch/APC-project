#include "apc.h"
    void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow=0;
    while(tail1 != NULL || tail2 != NULL)
    {
        int d1=0;
        int d2=0;
        if(tail1 != NULL)
        {
            d1=tail1->data;
            tail1=tail1->prev;
        }
        if(tail2 != NULL)
        {
            d2=tail2->data;
            tail2=tail2->prev;
        }
        d1=d1-borrow;
        if(d1<d2)
        {
            d1=d1+10;
            borrow=1;
        }
        else
        {
            borrow=0;
        }
        insert_first(headR,tailR,d1-d2);
    }
    remove_pre_zeros(headR, tailR);
}
