#include<stdio.h>
int main()

{
  int n,i,list[30],flag=-1,item;
  printf("enter the length of the list:");
  scanf("%d",&n);
  printf("enter elements:\n");
  for(i=0;i<n;i++)
  {
     scanf("%d",&list[i]);
     
    }
    
  printf("enter the item:");
  scanf("%d",&item);
  
  for(i=0;i<n;i++)
  
  {
  
    if(list[i]== item)
    {
      printf("%d is present at index %d \n",item,i);
      flag = -1;
      break;
      }
      }
      if (flag == -1)
      {
        printf("item not found \n");
        }
        
        return 0;
        }

