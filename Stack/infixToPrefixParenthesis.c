//infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack
{
    int item[STACKSIZE];
    int top;
};
void initialise(struct stack *ptr)
{
    ptr->top=-1;
}
int Isempty(struct stack *ptr)
{
    if (ptr->top==-1)
        return 1;
    else
        return 0;
}
void push(struct stack *ptr,int x)
{
    if (ptr->top==(STACKSIZE-1))
    {
        printf("Stack Overflow");
        exit(1);
    }
    ptr->top++;
    ptr->item[ptr->top]=x;
}
char pop(struct stack *ptr)
{
    char x;
    if(Isempty(ptr))
    {
        printf("Stack Underflow");
        exit(1);
    }
    x=ptr->item[ptr->top];
    ptr->top--;
    return x;
}
char Stacktop(struct stack *ptr)
{
    char x;
    if(Isempty(ptr))
    {
        printf("Stack is UnderFlow");
        exit(1);
    }
    else
    {
        x=ptr->item[ptr->top];
        return x;
    }
}
int prc(char op1,char op2)
{
    if(op1 =='(')
        return FALSE;
    else
    {
        if(op2=='(')
        return FALSE;
        else if(op2==')')
        return TRUE;
        else
        {

            if(op1=='$'||op1=='*'||op1=='/'||op1=='%')
            {
                if(op2=='$')
                    return FALSE;
                else
                    return TRUE;
            }
            else
            {
                if(op1=='+'||op1=='-')
                {
                    if(op2=='+'||op2=='-')
                    return TRUE;
                    else
                    return FALSE;
                }
            }
        }
    }
}
void main()
{
    struct stack s;
    initialise(&s);
    char a[20];
    char p[20];
    char rev[20];
    int i=0;
    int j=0;
    char symbol;
    int k=0;
    gets(a);
    //strrev(a);
    while(a[i]!='\0')
    {
        i++;
    }
    for( k=(i-1);k>=0;k--)
    {   if(a[k]=='(')
    {
            rev[j]=')';
            j++;
    }
        else if(a[k]==')')
        {
             rev[j]='(';
            j++;
        }
        else
        {
            rev[j]=a[k];
            j++;
        }
    }
    rev[k]='\0';
    i=0;
    j=0;
    k=0;
    while(rev[i]!='\0')
    {
        symbol=rev[i++];
        if((symbol>='0'&& symbol<='9')||(symbol>='a'&&symbol<='z')||(symbol>='A'&&symbol<='Z'))
        {
            p[j]=symbol;
            j++;
        }
        else
        {
            while(!(Isempty(&s))&&!prc(symbol,Stacktop(&s)))
            {
                char x=pop(&s);
                p[j]=x;
                j++;
            }
            push(&s,symbol);
        }

    }
    while(!Isempty(&s))
    {
        p[j]=pop(&s);
        j++;
    }
    p[j]='\0';
    //strrev(p);
    i=0;
    j=0;
    k=0;
    while(p[i]!='\0')
    {
        i++;
    }
    for( k=(i-1);k>=0;k--)
    {   
        rev[j]=p[k];
        j++;
    }
    rev[j]='\0';
    printf("%s",rev);

    }