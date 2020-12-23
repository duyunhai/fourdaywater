#include"iostream"
using namespace std;

int fun(int a,int b)
{
	int c;
    c=b/10+a/10*10+b%10*100+a%10*1000;
    return c;
}
void main()
{
	int m,n,obj;
	cout<<"Please input two integer numbers:";
    cin>>m>>n;
	obj=fun(m,n);
	cout<<"The new number after synthesis is:"<<obj<<endl;
}