#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_array[MAX];
int rear=-1;
int front=-1;
void main()
{
int choice;
while(1)
{
printf("1. insert element to queue\n");
printf("2. delete element from queue\n");
printf("3. display all elements of queue \n");
printf("4.display the value of front \n");
printf("5.display the value of rear\n");
printf("6.Quit \n");
printf("enter your choice :");
scanf("%d",&choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
delete();
break;
case 3:
display();
break;
case 4:
printf("the value of front is %d \n",queue_array[front]);
break;
case 5:
printf("the value of rear is %d \n",queue_array[rear]);
break;
case 6:
exit(1);
default:
printf("wrong choice \n");
}
}
}
void insert()
{
int add_item;
if(rear==MAX -1)
printf("Queue overflow \n");
else
{
if(front==-1)
front =0;
printf("insert the element in queue :");
scanf("%d",&add_item);
rear= rear+1;
queue_array[rear]=add_item;
}
}
void delete()
{
if(front==-1|| front>rear)
{
printf("queue underflow \n");
return;
}
else
{
printf("element deleted from queue is:%d \n",queue_array[front]);
front =front +1;
}
}
void display()
{
int i;
if(front ==-1)
printf("Queue is empty \n");
else
{
printf("queue is:\n");
for(i=front;i<=rear;i++)
printf("%d ",queue_array[i]);
printf("\n");
}
}
