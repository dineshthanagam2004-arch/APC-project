#include "apc.h"

// Function definitions
int cla_validation(int argc,char *argv[])
{
    //check argument count
    if(argc!=4)
    {
        printf("Error:argument count should be 4\n");
        return FAILURE;
    }
    //validate first operand
    int i=0;
    if(argv[1][0]=='+' || argv[1][0]=='-')
    {
        i=1;
    }
    for(int i=1;argv[1][i]!='\0';i++)
	{
		if(argv[1][i]<'0' || argv[1][i]>'9')
		{
			printf("Invalid first operand\n");
			return FAILURE;
		}
	}
    //validate operator
    if(strlen(argv[2])!=1)
    {
        printf("Invalid operator\n");
        return FAILURE;
    }
    if(argv[2][0]!='+' && argv[2][0]!='-' && argv[2][0]!='X' && argv[2][0]!='x' && argv[2][0]!='/')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }
    //validate second operand
     i=0;
    if(argv[3][0]=='+' || argv[3][0]=='-')
    {
        i=1;
    }
	for(int i=1;argv[3][i]!='\0';i++)
	{
		if(argv[3][i]<'0' || argv[3][i]>'9')
		{
			printf("Invalid second operand\n");
			return FAILURE;
		}
	}
    return SUCCESS;
}
void create_list(char *opr,node **head,node **tail)
{
    int i=0;
    if(opr[0]=='+' || opr[0]=='-')
    {
        i=1;
    }
    for(;opr[i]!='\0';i++)
    {
        insert_last(head,tail,opr[i]-'0');
    }
}
int insert_last(node **head, node **tail, int data)
{
    node *new=malloc(sizeof(node));
        if(new==NULL)
        {
            return FAILURE;
        }
        new->data=data;
        new->prev=NULL;
        new->next=NULL;
        if(*head==NULL)
        {
            *head=new;
            *tail=new;
        }
        else
        {
            new->prev=*tail;
            (*tail)->next=new;
            *tail=new;
        }
        return SUCCESS;
}

int insert_first(node **head,node **tail,int data)
{
    node *new=malloc(sizeof(node));
    if(new==NULL)
    {
        return FAILURE;
    }
    new->data=data;
    new->prev=NULL;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
        *tail=new;
    }
    else
    {
        new->next=*head;
        (*head)->prev=new;
        *head=new;
    }
    return SUCCESS;
}
//remove pre zeros

void remove_pre_zeros(node **head,node **tail)
{
    while(*head!=NULL && (*head)->data==0 && (*head)->next!=NULL)
    {
        node *temp=*head;
        *head=(*head)->next;
        if(*head!=NULL)
        {
            (*head)->prev=NULL;
        }
        else
        {
            *tail=NULL; // If the list becomes empty, set tail to NULL
        }
        free(temp);
    }
}

void print_list(node *head,int sign)
{
    if(sign==-1 && !(head->data==0 && head->next==NULL))
    {
        printf("-");
    }
    while(head)
    {
        printf("%d",head->data);
        head=head->next;
    }
    printf("\n");
}

int compare_list(node *head1,node *head2)
{
    int list1_len=list_len(head1);
    int list2_len=list_len(head2);
    if(list1_len>list2_len)
    {
        return OPERAND1;
    }
    else if(list1_len<list2_len)
    {
        return OPERAND2;
    }
    else
    {
        node *temp1=head1;
        node *temp2=head2;
        while(temp1!=NULL)
        {
            if(temp1->data > temp2->data)
            {
                return OPERAND1;
            }
            if(temp1->data < temp2->data)
            {
                return OPERAND2;
            }
            else
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        return SAME;
    }
}

int list_len(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}

int delete_list(node **head, node **tail)
{
    if(*head==NULL)
    {
        return FAILURE;
    }
    node *temp=*head;
    while(*head!=NULL)
    {
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    *tail=NULL;
    return SUCCESS;

}
