#include"iostream"
using namespace std;
int main(int argc, char* argv[ ])
{
	int n=0 , num,i,x;//n的初始值为0
	int a[100], m; //猴子的数量小于100
	n < m;
	cout << "请输入猴子总数:" << endl;
	cin >> m;
	cout << "请输入数数n:" << endl;
	cin >> x;
	num = m;//记录未退出的猴子数
	for (i = 1; i <= m; i++)
	{a[i] = 1;//每个猴子标记为1，表示该猴子未退出
	}
	while (num != 1)//当只有一猴子时，退出循环
	{
		for (i = 1; i <= m; i++)
		{
			if (a[i] == 1)
			{
				n++;
			}
			if (n==x)
			{
				a[i] = 0; 
				num--;   //退出一只猴子
				n= 0;
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (a[i] == 1)//输出最后剩下的那只猴子，猴王
		{
			cout <<"i="<<i<< endl;
			break;
		}
	}
	return 0;
}