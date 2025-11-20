//Infix to postfix

#include<stdio.h>

#define MAX 20

int isopd (char c) 
{
  if(c >= 'a' && c <= 'z') 
  {
    return 1;
  }
  else 
    return 0;
}

int isopr (char c) 
{
  if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
  {
    return 1;
  }
  else
    return 0;
}

int priority(char c) 
{
  if(c=='^')
    return 3;
  else if (c == '/' || c=='*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return 0;
} 

int main() 
{
  char infix[30] , postfix[30];
  char stk[MAX],ch;
  int top=-1, i=0, j=0;

  printf("Enter the infix experation:");
  scanf("%s", infix);

  while (infix[i]!='\0')
  {
    ch = infix[i];
    printf("\n Char at position %d is %c", i,ch);
    if(ch == '(') 
    {
       stk[++top]=ch;
    }

    else if (isopd(ch))
    {
      postfix[j++] = ch;
    }

    else if (isopr(ch)) 
    {
      while(top != -1 && isopr(stk[top]) && priority(stk[top]) >= priority(ch) ) 
      {
         postfix[j++] = stk[top--];
       
      }
      stk[++top] = ch;
    }
    

    else 
    {
      while (stk[top] != '(')
      {
        postfix[j] = stk[top];
        top--;
        j++;
      }
      if(top!=-1)
      top--;
    }
    i++;
  }

  while (top!= -1) 
  {
    postfix[j++] = stk[top--];
  }

  postfix[j] = '\0';

  printf("\n Postfix Expression %s", postfix);

  return 0;
}