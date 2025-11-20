#include <stdio.h>
#define SIZE 10
int main()
{
int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
int *pa;
int i;
pa = a;
printf("%d\n", *pa);
printf("%d\n", *(a + 1));
printf("[");
for(i = 0;i < SIZE;i += 2)
{
if(i > 0)
{
printf(", ");
}
pa = a + i;
printf("%d", *pa);
}
printf("]\n");
return 0;
}