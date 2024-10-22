 #include<stdio.h>
 #include<stdlib.h>
 
 struct Node {
               
               int data;
               struct Node* link;
               
               };
               
 struct Node* start = NULL;
 
 struct Node* getnode()
 
         {
            int item;
            printf("enter the value to insert:\n");
            scanf("%d",&item);
            
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = item;
            new_node->link = NULL;
            return new_node;
            
            }
            
           void push()
           {
             struct Node* new_node = getnode();
              if(start == NULL)
                 
                           {
                              start =  new_node;
                           }
                           
              else
                  {
                     new_node->link = start;
                     start = new_node;
                     
                  }
                  
                  printf("%d is pushed\n",new_node->data);
                  
                  }
             
             
             int pop()
             {
                    if(start == NULL)
                      {
                        printf("stack is empty\n");
                        return 0;
                        }
                        
                     else
                         {
                            struct Node* ptr =  start;
                            start = start->link;
                            free(ptr);
                            return 1;
                            
                          }
                     }
                     
                     
                void traverse()
                     {
                     
                        if(start == NULL)
                           {
                             printf("stack is empty\n");
                             
                             }
                             
                             else
                                 {
                                     printf("stack elements are:\n");
                                     
                                     struct Node* ptr = start;
                                     while(ptr != NULL)
                                     {
                                    printf("-> %d",ptr->data);
                                    
                                    ptr= ptr->link;
                                    
                                   }
                      
                      }
                      
                      
               }
               
              void freeList()
                
                {
                  while(start != NULL)
                {   
                   pop();
                   
                  }
                
               }
                     

int main()
{
 int ch;
   
   while(1)
   {
       printf("\n----Stack Menu---\n");
       printf("1.Push\n");
       printf("2.Pop\n");
       printf("3.Travesre\n");
       printf("4.Exit \n");
       printf("enter your choice\n");
       scanf("%d",&ch);
       
       switch(ch)
       {
         case 1 : push();
                  break;
               
         case 2 : pop();
                  break;
                  
         case 3 : traverse();
                  break;
                  
         case 4 : 
                     printf("exiting program\n");
                     freeList();
                     exit(0);
         
         default : printf("invalid entry");
                   
                   }
                 }
                 
                 return 0;
                 
                }
       
    
