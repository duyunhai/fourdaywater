#include "stdio.h"
//ͨ������ֵ������c����������
int fun1(int a,int b)
{
    int c;
    c=a%100/10 *10+a%10 *1000+ b%100/10+b%10 *100;
    return c;
}
//ͨ�����ò�������������������
int &fun2(int a,int b)
{
    int c;
    c=a%100/10 *10+a%10 *1000+ b%100/10+b%10 *100;
    return &c;
}
//ͨ��ָ���Ͳ�������������������
int *fun3(int a,int b)
{
    int *p=c;
    c=a%100/10 *10+a%10 *1000+ b%100/10+b%10 *100;
    return p;
}
int main()
{
   int m,n;
   scanf("%d%d",&m,&n);
   printf("%d\n",fun2(m,n));
}
