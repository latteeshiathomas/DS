#include<stdio.h>
#include<stdlib.h>

#define max 50
int queue[max],front=-1,rear=-1;
 
  void enqueue()
  {
    int elem;
    if(rear==max-1)
    {
    printf("Queue overflow!\n");
    return;
    }
    
   printf("enter the elements to be enqueued:\n");
   scanf("%d",&elem);
   if(front==-1)
   {
   front=0;
    }
    rear++;
    queue[rear]=elem;
    printf("%d is enqueued into the queue\n",elem);
   }
  void dequeue()
  { 
    if(front==-1||front>rear)
    {
    printf("Queue underflow!\n");
    return;
    }
 
    printf("Dequeued elements:%d\n",queue[front]);
    front++;
    if(front>rear) 
    {
     front=rear=-1;
       }
   }
   
   
   void display()
   { 
     int i;
     if(front==-1)
     {
       printf("Queue is empty!\n");
       return;
       }
     printf("Queue elements are:\n");
     for(i=front;i<=rear;i++)
    {
      printf("%d",queue[i]);
      }
   printf("\n");
   }
   
   
int main()
{
int ch;

  while(1){
     printf("\n-----ENTER CHOICE----\n");
     printf("1.Enqueue\n");
     printf("2.Dequeue\n");
     printf("3.Display\n");
     printf("4.Exit\n");
     printf("Enter your choice:\n");
     scanf("%d",&ch);
    
  switch(ch){
        case 1: enqueue();
                break;
        case 2: dequeue();
                break;
        case 3: display();
                break;
        case 4: exit(0);
        
        default: 
                printf("invalid entry,try Again:\n");
              }
         }               
                
  return 0;            
}                   
