#include"iostream"
using namespace std;

void main()
{
	int a[100];
	int m,i,j,num,temp,length;
	cout<<"��������ӵ�����:";
	cin>>m;
	for(i=1;i<=m;i++)
	{
		a[i-1]=i;
	}
//	cout<<"���ӵı��Ϊ:";
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
			cout<<"ɾ��"<<num<<"�ź���"<<endl;
			for(i=1;i<length;i++)
			{
				a[i-1]=a[i];
			}
		}
		else cout<<"������"<<num<<"�ź���"<<endl;
	}
}