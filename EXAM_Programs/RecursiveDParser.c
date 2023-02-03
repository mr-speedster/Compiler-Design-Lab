#include <stdio.h>
#include <string.h>
#include <ctype.h>
char input[10];
int i, flag;
void E();
void T();
void Edash();
void Tdash();
void F();
int main()
{
    i = 0;
    flag = 0;
    printf("Enter the expression to evaluate \n");
    gets(input);
    E();
    if (strlen(input) == i && flag == 0)
        printf("\nAccepted\n");
    else
        printf("\nRejected\n");
    return 0;
}
void E()
{
    T();
    Edash();
}
void Edash()
{
    if (input[i] == '+')
    {
        i++;
        T();
        Edash();
    }
}
void T()
{
    F();
    Tdash();
}
void Tdash()
{
    if (input[i] == '*')
    {
        i++;
        F();
        Tdash();
    }
}
void F()
{
    if (input[i] == 'a')
        i++;
    else if (input[i] == '(')
    {
        i++;
        E();
        if (input[i] == ')')
            i++;
        else
            flag = 1;
    }
    else
        flag = 1;
}
