#include "stdio.h"
int fun(int &a,int &b)
{
	int a1,a2,b1,b2,c;
	a1=a%10;
	a1=a1*1000;
	a2=a%100;
	a2=a2/10;
	a2=a2*10;
	b1=b%10;
	b1=b1*100;
	b2=b%100;
	b2=b2/10;
	c=a1+a2+b1+b2;
	return c;
}
main()
{
	int a,b,c;
	printf("请输入数值a,b:");
	scanf("%d%d",&a,&b);
	c=fun(a,b);
	printf("合并后的数值c:%d\n",c);

}