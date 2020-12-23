#include <iostream>
using namespace std;
struct monkey    //结构声明 
{
	int num;     //猴子编号 
	monkey *next;   //monkey结构指针 
};
monkey *head,*tail;  //monkey结构指针，指向链表头节点和尾节点
//creat函数用于生成韩mm个节点的循环链表 
void creat(int mm)
{
	int i;
	monkey *p,*q;    //声明monkey结构指针p,q 
	p=new monkey;    //给p分配空间，生成新节点 
	p->num=1;
	p->next=NULL;
	head=p;          //第一个节点为头节点 
	q=p;
	for(i=2;i<=mm;i=i+1) //构造循环链表 
	{
		p=new monkey;    //生成新节点 
		p->num=i;
		q->next=p;
		q=p;
		p->next=NULL;
	}
	tail=q;
	tail->next=head; //首尾相连接，形成循环链表 
}
void select(int nn)
{
	int x=0;
	monkey *p,*q;
	q=tail;
	do
	{
		p=q->next;
		x=x+1;
		if(x%nn==0)
		{
			cout<<"被删除的猴子号为"<<p->num<<"号"<<endl;
			q->next=p->next;
			delete p;
			p=NULL; 
		}
		else
		    q=p;
	}while(q!=q->next);
	head=q;
}
int main()
{
	int m,n;
	head=NULL;
	cout<<"请输入猴子的个数：\n";
	cin>>m;
	cout<<"请输入间隔：\n";
	cin>>n;
	creat(m);
	select(n);
	cout<<"猴王是"<<head->num<<"号"<<endl;
	delete head;
	return 0;
}
