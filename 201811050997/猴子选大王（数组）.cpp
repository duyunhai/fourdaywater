#include"iostream"
using namespace std;
int main(int argc, char* argv[ ])
{
	int n=0 , num,i,x;//n�ĳ�ʼֵΪ0
	int a[100], m; //���ӵ�����С��100
	n < m;
	cout << "�������������:" << endl;
	cin >> m;
	cout << "����������n:" << endl;
	cin >> x;
	num = m;//��¼δ�˳��ĺ�����
	for (i = 1; i <= m; i++)
	{a[i] = 1;//ÿ�����ӱ��Ϊ1����ʾ�ú���δ�˳�
	}
	while (num != 1)//��ֻ��һ����ʱ���˳�ѭ��
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
				num--;   //�˳�һֻ����
				n= 0;
			}
		}
	}
	for (i = 1; i <= m; i++)
	{
		if (a[i] == 1)//������ʣ�µ���ֻ���ӣ�����
		{
			cout <<"i="<<i<< endl;
			break;
		}
	}
	return 0;
}