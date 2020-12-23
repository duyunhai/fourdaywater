#include"iostream"
using namespace std;

void main()
{
	int a[100];
	int m,i,j,num,temp,length;
	cout<<"请输入猴子的数量:";
	cin>>m;
	for(i=1;i<=m;i++)
	{
		a[i-1]=i;
	}
//	cout<<"猴子的编号为:";
//	for(i=0;i<m;i++)
//	{
//		cout<<a[i]<<endl;
//	}
	for(j=0;j<m;j++)
	{
		length=m-j;
		num=a[0];
		if(length>1)
		{
			cout<<"删除"<<num<<"号猴子"<<endl;
			for(i=1;i<length;i++)
			{
				a[i-1]=a[i];
			}
		}
		else cout<<"猴王是"<<num<<"号猴子"<<endl;
	}
}