#include"iostream"
using namespace std;
void main()
{
	int M,N,i,j,C,k;
	char map[100][100];
	char temp[100][100];
	cout<<"�������Ⱦ��ͼ�ĳ��Ϳ�:";
	cin>>N>>M;
	cout<<"�������Ⱦ����:";
	cin>>C;
	cout<<"�������Ⱦ�����ͼ:"<<endl;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cin>>map[i][j];
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			temp[i][j]=map[i][j];
		}
	}
	for(k=0;k<C;k++)
	{
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				if(map[i][j]=='X')
				{			
					if(map[i-1][j]!='P'&&i>0) temp[i-1][j]='X';			
					if(map[i+1][j]!='P'&&i<M-1) temp[i+1][j]='X';				
					if(map[i][j-1]!='P'&&j>0) temp[i][j-1]='X';				
					if(map[i][j+1]!='P'&&j<N-1) temp[i][j+1]='X';			
				}		
			}
		}
	}
	cout<<"����"<<C<<"����Ⱦ���ں󣬸�Ⱦ�����ͼΪ:"<<endl;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<temp[i][j];	
		}
		cout<<endl;
	}	
}