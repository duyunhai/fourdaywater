#include"iostream"
using namespace std;

void fun(int *a,int *b)
{
	int c;
    c=*b/10+*a/10*10+*b%10*100+*a%10*1000;
    cout<<"The new number after synthesis is:"<<c<<endl;
}
void main()
{
	int m,n;
	cout<<"Please input two integer numbers:";
    cin>>m>>n;
	fun(&m,&n);
}