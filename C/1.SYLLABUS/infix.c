#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 100
typedef struct Stackint
{
    int top1;
    int a[max];
}stackint;

void createStackint(stackint* s1)
{
    s1->top1=-1;
}

void pushint(stackint* s1,int item)
{
    s1->top1++;
    s1->a[s1->top1]=item;
}

int popint(stackint* s1)
{
    int item=s1->a[s1->top1];
    s1->top1--;
    return item;
}

typedef struct Stackchar
{
    int top2;
    char b[max];
}stackchar;

void createStackchar(stackchar* s2)
{
    s2->top2=-1;
}

void pushchar(stackchar* s2,char item)
{
    s2->top2++;
    s2->b[s2->top2]=item;
}

char popchar(stackchar* s2)
{
    char item=s2->b[s2->top2];
    s2->top2--;
    return item;
}

int ISoperand(char ch)
{
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

int ISoperator(char ch)
{
    return (ch=='+'||ch=='*'||ch=='/'||ch=='-'||ch=='^');
}

int precedence(char ch)
{
    switch(ch)
    {
        case '(':case ')':return 0;
        case '+':case '-':return 1;
        case '*':case '/':return 2;
        case '^':return 3;
        default: return -1;
    }
}

void infixtopostfix(char infix[],char postfix[],stackchar* s2)
{
    int i=0,j=0;
    char ch;
    while(infix[i]!='\0')
    {
        ch=infix[i];
        if(ISoperand(ch))
        {
            postfix[j]=ch;
            j++;
        }
        else if(ch=='(')
        {
            pushchar(s2,ch);
        }
        else if(ch==')')
        {
            while(s2->top2 != -1 && s2->b[s2->top2] != '(')// Fixed while condition to check the top of stack
            {
                postfix[j]=popchar(s2);
                j++;
            }
            popchar(s2);
        }
        else
        {
            while(s2->top2!=-1&&precedence(s2->b[s2->top2])>=precedence(ch))
            {
                postfix[j]=popchar(s2);
                j++;
            }
            pushchar(s2, ch);
        }
        i++;
       
    }
    while(s2->top2!=-1)
    {
        postfix[j]=popchar(s2);
        j++;
    }
    postfix[j] = '\0';
}

int postfix_evaluation(char postfix[],stackint* s1,int op_values[256])
{
    int j=0,op1,op2,result;
    char ch;
    while(postfix[j]!='\0')
    {
        ch=postfix[j];
        if(ISoperand(ch))
        {
            pushint(s1,op_values[ch]);
        }
        else
        {
            op1=popint(s1);
            op2=popint(s1);
            switch(ch)
            {
                case '+':result=op2+op1;break;
                case '-':result=op2-op1;break;
                case '*':result=op2*op1;break;
                case '/':result=op2/op1;break;
                case '^':result=pow(op2,op1);break;
            }
            pushint(s1,result);
        }
        j++;
    }
    return result;
}

void main()
{   
    stackchar s2;
    stackint s1;
    createStackchar(&s2);
    createStackint(&s1);
    char postfix[max],infix[max],ch;
    int j,op_values[256];
    printf("\nEnter infix expression:");
    fgets(infix,max,stdin);
    
    infixtopostfix(infix,postfix,&s2);
    printf("\nPostfix expression:%s",postfix);
    
    for(j=0;postfix[j]!='\0';j++)
    {
        ch=postfix[j];
        if(ISoperand(ch))
        {
            printf("\nEnter the value of %c:",ch);
            scanf("%d",&op_values[ch]);
        }
    }
    
    int result=postfix_evaluation(postfix,&s1,op_values);
    printf("\nResult: %d",result);
}