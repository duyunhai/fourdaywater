#include"iostream"
#include"algorithm"
using namespace std;
struct grade
{
	int Chinese,Math,English;
	int num,sum;
}student[100];
int cmp(grade x,grade y)   //�Զ������򷽷�
{
    if(x.sum!=y.sum) return x.sum>y.sum;
    if(x.Chinese!=y.Chinese) return x.Chinese>y.Chinese;
    if(x.num!=y.num) return x.num<y.num;
}
void main()
{
	int i,m,n;
	cout<<"������ѧ���ĸ���:";
	cin>>m;
	cout<<"������ÿ��ѧ���ĳɼ�:"<<endl;
	for(i=0;i<m;i++)
	{
      cin>>student[i].Chinese>>student[i].Math>>student[i].English;
      student[i].num=i+1;
      student[i].sum=student[i].Chinese+student[i].Math+student[i].English;
	}
	sort(student,student+m,cmp);  //����������Ϊsort�����򷽷�
	cout<<"ѧ���ɼ�����Ϊ:"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<student[i].num<<"  "<<student[i].sum<<endl;
	}

}

