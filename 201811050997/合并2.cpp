//通过引用参数将新数传给主函数：
#include "stdio.h"
int fun(int &a,int &b)
{
	int c;
	c=a%100/10 *10+a%10 *1000+ b%100/10+b%10 *100;
	return c;
}
int main()
{
   int m,n;
   printf("please input two const number\n");
   scanf("%d%d",&m,&n);
   printf("%d\n",fun(m,n));
}