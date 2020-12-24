#include"iostream"
#include"algorithm"
using namespace std;
struct grade
{
	int Chinese,Math,English;
	int num,sum;
}student[100];
int cmp(grade x,grade y)   //自定义排序方法
{
    if(x.sum!=y.sum) return x.sum>y.sum;
    if(x.Chinese!=y.Chinese) return x.Chinese>y.Chinese;
    if(x.num!=y.num) return x.num<y.num;
}
void main()
{
	int i,m,n;
	cout<<"请输入学生的个数:";
	cin>>m;
	cout<<"请输入每个学生的成绩:"<<endl;
	for(i=0;i<m;i++)
	{
      cin>>student[i].Chinese>>student[i].Math>>student[i].English;
      student[i].num=i+1;
      student[i].sum=student[i].Chinese+student[i].Math+student[i].English;
	}
	sort(student,student+m,cmp);  //第三个参数为sort的排序方法
	cout<<"学生成绩排名为:"<<endl;
	for(i=0;i<5;i++)
	{
		cout<<student[i].num<<"  "<<student[i].sum<<endl;
	}

}

