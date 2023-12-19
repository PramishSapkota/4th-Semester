#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int precedencecheck(char);
int main()
{
int i, otos = -1, ptos = -1, l, len;
char infix[100], poststack[100], opstack[100];
printf("Enter a valid infix expression\n");
fgets(infix, sizeof(infix), stdin);
l = strlen(infix);
len = l;
for (i = 0; i < l; i++)
{
if (infix[i] == '(' )
{
opstack[++otos] = infix[i];
len++;
}
else if (isalpha(infix[i]))
{
poststack[++ptos] = infix[i];
}
else if (infix[i] == ')')
{
len++;
while (otos >= 0 && opstack[otos] != '(')
{
poststack[++ptos] = opstack[otos];
otos--;
}
if (otos >= 0 && opstack[otos] == '(')
{
otos--;
}
else
{
printf("Invalid expression\n");
return 1;
}
}
else
{
while (otos >= 0 && precedencecheck(opstack[otos]) >= precedencecheck(infix[i]))
{
poststack[++ptos] = opstack[otos--];
}



opstack[++otos] = infix[i];
}
}
while (otos >= 0)
{
poststack[++ptos] = opstack[otos--];
}
printf("Postfix expression: ");
for (i = 0; i <= ptos; i++)
{
printf("%c", poststack[i]);
}
printf("\n");
return 0;
}
int precedencecheck(char ch)
{
switch (ch)
{
case '$':
return 4;
case '*':
case '/':
return 3;
case '+':
case '-':
return 2;
default:
    return -1;
}
}