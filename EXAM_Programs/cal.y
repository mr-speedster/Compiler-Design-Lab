%{
	#include<stdio.h>
%}
%token number
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
A:E
{
	printf("\nResult=%d\n", $$);
	return 0;
}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| number {$$=$1;}
;
%%
void main()
{
	printf("\nEnter Any Arithmetic Expression:\n");
	yyparse();
}
void yyerror()
{
	printf("\nInvalid\n");
}
