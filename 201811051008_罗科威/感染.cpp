#include <iostream>
#include "stdio.h"
using namespace std;
void ganran(char* map,char* maptemp,int N,int M)
{
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(*(map+i*N+j)=='X')
			{
				if(*(map+(i-1)*N+j)!='P'&&i-1>=0) *(maptemp+(i-1)*N+j)='X';
				if(*(map+(i+1)*N+j)!='P'&&i+1<M) *(maptemp+(i+1)*N+j)='X';
				if(*(map+i*N+j-1)!='P'&&j-1>=0) *(maptemp+i*N+j-1)='X';
				if(*(map+i*N+j+1)!='P'&&j+1<N) *(maptemp+i*N+j+1)='X';
			}
		}
	};
}
int main()
{
	int M,N,C;
	int i,j,k;
	cin>>N>>M;
	char map[M][N];
	char maptemp[M][N];
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cin>>map[i][j];
		}
	};
    for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
	   {
	   	maptemp[i][j]=map[i][j];
	    }
	};
	cin>>C;
	for(k=1;k<=C;k++)
	{
	ganran(*map,*maptemp,N,M);
	  for(i=0;i<M;i++)
	  {
		  for(j=0;j<N;j++)
	     {
	   	  map[i][j]=maptemp[i][j];
	      }
	  }
	};
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	};
	return 0;
 } 
