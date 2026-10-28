Name: DINESH T
Project Name: Arbitary Precision Calculater
Date:27/09/2026
Project Description:Developed a C-based Arbitrary Precision Calculator using doubly linked lists to perform 
addition, subtraction, multiplication, and division on large integers beyond standard data-type limits.
 Implemented input validation, sign handling, and result management using modular functions.



#include "apc.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

    // Validation
	if(argc != 4)
    {
        printf("Error: argument count should be 4\n");
        return FAILURE;
    }
	if (cla_validation(argc, argv) == FAILURE)
    {
        return FAILURE;
    }
    
    int sign1=1;
    int sign2=1;
    int signR=1;
    char *num1_str=argv[1];
    char *num2_str=argv[3];

    if(num1_str[0]=='-')
    {
        sign1=-1;
        num1_str++;
    }
    else if(num1_str[0]=='+')
    {
        num1_str++;
    }

    if(num2_str[0]=='-')
    {
        sign2=-1;
        num2_str++;
    }
    else if(num2_str[0]=='+')
    {
        num2_str++;
    }

    // Create 2 lists of operands
	create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    // Remove pre zeros
    remove_pre_zeros(&head1, &tail1);
    remove_pre_zeros(&head2, &tail2);

    char oper = argv[2][0];

    switch(oper)
    {
	case '+':
        if(sign1==sign2)
        {
	        addition(tail1, tail2, &headR, &tailR);
            signR=sign1;
            printf("Result: ");
            //if(sign==-1)
            //printf("-");
            print_list(headR,signR);
        }
        else
        {
            int ret=compare_list(head1,head2);
            if(ret==OPERAND1)
            {
                subtraction(tail1,tail2,&headR,&tailR);
                signR=sign1;
                printf("Result: ");
                print_list(headR,signR);

            }
            else if(ret==OPERAND2)
            {
                subtraction(tail2,tail1,&headR,&tailR);
                signR=sign2;
                printf("Result: ");
                print_list(headR,signR);

            }
        }
	    break;

	case '-':
    
    headR=NULL;
    tailR=NULL;
    if(sign1!=sign2)
    {
        addition(tail1,tail2, &headR,&tailR);
        signR=sign1;
        printf("Result: ");
        print_list(headR,signR);
    }
    else
    {
        int ret=compare_list(head1,head2);
        if(ret==OPERAND1)
        {
            subtraction(tail1,tail2,&headR,&tailR);
            signR=sign1;
            printf("Result: ");
            print_list(headR,signR);

        }
        else if(ret==OPERAND2)
        {
            subtraction(tail2,tail1,&headR,&tailR);
            signR=-sign1;
            printf("Result: ");
            print_list(headR,signR);

        }
        else
        {
            insert_first(&headR,&tailR,0);
            signR=1;
            printf("Result: ");
            print_list(headR,signR);
        }
    }
	break;

	case 'x':
	case 'X':
        multiplication(tail1,tail2,&headR,&tailR);
        signR=sign1*sign2;
        printf("Result: ");
        print_list(headR,signR);
	    break;

	case '/':
        if(division(head1,head2,&headR,&tailR)==SUCCESS)
        {
        signR=sign1*sign2;
        printf("Result: ");
        print_list(headR,signR);
        }
	    break;
	default:
	    printf("Invalid operator\n");
    }
}