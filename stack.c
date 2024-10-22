#include<stdio.h>
#include <stdlib.h>

#define max 50 

int stack[max],top=-1;

void push()
{
 int elem;
 if(top==max-1)
 {
 printf("stack overflow\n");
 return;
 }
printf("enter the elements to be pushed:");
scanf("%d",&elem);
top++;
stack[top]=elem;
printf("%d pushed to the stack",elem);
 }

void pop()
{
if(top==-1)
{
printf("stack underflow\n");
return;
}
top--;
printf("popped elements:%d\n",stack[top]);
 }
 void display()
 {
 int i;
 if (top == -1) 
 {
 printf("Stack is empty.\n");
 return;
 }
 printf("Stack elements are:\n");
 for (i = top; i >= 0; i--) {
 printf("%d\n", stack[i]);
  }
}
int main()
{
int ch;
while(1){
printf("\n----stack menu-----\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Display\n");
printf("4.Exit\n");
printf("enter your choice:\n");
scanf("%d",&ch);
switch(ch){
case 1:
        push();
        break;
        
case 2:pop();
       break;

case 3:display();
       break;
       
case 4:exit(0);
default:  
         printf("invalid choice,try again:\n");
}
}
return 0;
}
