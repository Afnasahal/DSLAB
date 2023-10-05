#include<stdio.h>
int a[10][10],b[10][10],c[10][10],d[10][10],t[10][10],i,j,row,col,choice;
void add();
void multiply();
void transpose();
int main(){
printf("Enter the no of rows: ");
scanf("%d",&row);
printf("Enter the no of columns: ");
scanf("%d",&col);
printf("Enter the elements of first matrix:\n ");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("a[%d][%d]: ",i,j);
	scanf("%d",&a[i][j]);
	}}
printf("Enter the elements of second matrix:\n ");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("b[%d][%d]: ",i,j);
	scanf("%d",&b[i][j]);
	}}

printf("\nFirst Matrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("%d\t",a[i][j]);
	}
	printf("\n");
	}	
	
printf("\nSecond Matrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("%d\t",b[i][j]);
	}
	printf("\n");
	}

while(choice!=4){
	printf("\nEnter the choice (1.Add 2.Multiply 3.Transpose 4.Exit): ");
	scanf("%d",&choice);
	switch(choice){
	case 1:{
	add();
	break;
	}
	case 2:{
	multiply();
	break;
	}
	case 3:{
	transpose();
	break;
	}
	case 4:{
	printf("\nExit\n");
	break;
	}
	
	default:{
	printf("Enter the invalid option");
	}}}
return 0;
}

void add(){
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	c[i][j]=a[i][j]+b[i][j];
	}}
printf("\nMatrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("%d\t",c[i][j]);
	}
	printf("\n");
	}
}

void multiply(){
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	d[i][j]=a[i][j]*b[i][j];
	}}
printf("\nMatrix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("%d\t",d[i][j]);
	}
	printf("\n");
	}
}


void transpose(){
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	t[j][i]=a[i][j];
	}}
printf("transpose of First Matix: \n");
for(i=0;i<row;i++){
	for(j=0;j<col;j++){
	printf("%d\t",t[i][j]);
	}
	printf("\n");
	}
}

