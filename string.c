#include <stdio.h>
#include <string.h>
int main()
{
 char str1[100], str2[100];
 int choice=0;
 printf("Enter the first string: ");
 scanf("%s", str1);
 printf("Enter the second string: ");
 scanf("%s", str2);
 while (choice != 4)
 {
 printf("\nSelect a String Operation\n1.Search\n2.Concatenate\n3.Substring\n4.Exit\n");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 if (strstr(str1, str2) != NULL)
 {
 printf("%s found in %s \n", str2, str1);
 }
 else
 {
 printf("%s not found in %s \n", str2, str1);
 }
 break;
 case 2:
 strcat(str1, str2);
 printf("Concatenated string: %s\n", str1);
 break;
 case 3:
 if (strstr(str1, str2) != NULL)
 {
 printf("%s is a substring of %s \n", str2, str1);
 }
 else
 {
 printf("%s is not a substring of %s \n", str2, str1);
 }
 break;
 case 4:
 printf("Exiting the program.\n");
 break;
 default:
 printf("Invalid choice.\n");
 }
 }
 return 0;
}

