#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void towers(int,char,char,char);

int i,top;
float op1,op2,res;
char symbol,postfix[20];
float s[30];
float value[20];

float compute()
{
	switch(symbol)
	{
 	  case'+':return op1+op2;
	  case'-':return op1-op2;
	  case'*':return op1*op2;
	  case'%':return((int)op1%(int)op2);
	  case'/':
		   if(op2==0)
	 {
	 	printf("operation cannot be performed because dividing by zero\n\n");
		exit(0);
	 }
    	}
}
void main()
{
	int choice,num;
	while(1)
	{
	  i=0;
	  printf("\n STACK APPLICATIONS\n");
	  printf("\n1.Evaluation of suffix expression");
	  printf("\n2.solving Towers of Hanoi problems with n disks");
	  printf("\n3.exit");
	  printf("\nEnter your choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
	      case 1:printf("Enter the suffix expression\n\n\n");
	      	     scanf("%s",postfix);
			top=-1;
			while(postfix[i]!='\0')
			{
				if(isalpha(postfix[i]))
				{
					printf("Enter the value for %c\n",postfix[i]);
					scanf("%f",&value[i]);
				}
				i++;
			}
			for(i=0;i<strlen(postfix);i++)
			{
				symbol=postfix[i];
				if(isalpha(postfix[i]))
				{
					s[++top]=value[i];
 				}
				else
				{
					op2=s[top--];
					op1=s[top--];
					res=compute();
					s[++top]=res;
				}
			}
				printf("The value after solving postfix expression is %f\n",res);
				break;

			case 2:printf("Enter the number of disks:");
				scanf("%d",&num);
			      printf("The sequence of moves inv1oved in the Tower of Hanoi are:\n");
			      towers(num,'A','C','B');
				break;

			case 3:return;
			default:printf("\nEnter a valid choice\n");
			}
		}
}
void towers(int num,char frompeg,char topeg,char auxpeg)
{
	if(num==1)
	{
		printf("\n Move disk 1 frompeg%c topeg%c",frompeg,topeg);
		return;
	}
	towers(num-1,frompeg,auxpeg,topeg);
	printf("\nMove disks %d frompeg%c topeg%c",num,frompeg,topeg);
	towers(num-1,auxpeg,topeg,frompeg);
}




	    
	  
