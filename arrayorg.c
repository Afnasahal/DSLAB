#include <stdio.h>
#include <stdlib.h>

int main ()
{
int a[100], n, j, i;
char choice;
int k, H,temp;
temp=0;


//INSERTION OF AN ARRAY

printf("enter the array limit ");
scanf("\n %d",&n);

printf("enter the array elements");

for(i=0; i<n; i++)
{
scanf("%d",&a[i]);

}
printf("entered array elements are");

for(i=0; i<n; i++)
{
printf("\n%d\n",a[i]);

}

//section of an operation



printf("A is for insertion \n B is for deletion\n C is for display\n");
 printf("please choose among the given operation\n");
 scanf(" %c",&choice);

switch(choice)
{
//Insertion into existing array
 case 'A':
  printf("Enter the position on to which insertion is intended to ");
  scanf("%d",&H);
  printf("Enter value :\n ");
  scanf("%d",&k);
  H=H-1;
  for(i=0; i<n; i++)
{

if(i==H)
{ 
a[i]=k;
}
}
printf("you have inserted into position %d with %d \n ",i,k);
  break;
 
 //deletion from an exising array
            
case 'B':
 
  printf("Enter the value :\n ");
  scanf("%d",&k);
  
  for(i=0; i<n; i++)
{

if(a[i]==k)
{ 
temp=a[i+1];
a[i+1]= a[i];
a[i] = temp;
}
if(a[n]-1==k)
{
n=n-1;
printf("youre updated array is");
}

}

for(i=0; i<n; i++)
{
printf("%d\n",a[i]);

}

break;

//for display
case 'C':
for(i=0; i<n; i++)
{
printf("%d\n",a[i]);

}

default: 
printf("please check your entry");
}



return 0;

}
