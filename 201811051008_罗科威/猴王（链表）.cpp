#include <iostream>
using namespace std;
struct monkey    //�ṹ���� 
{
	int num;     //���ӱ�� 
	monkey *next;   //monkey�ṹָ�� 
};
monkey *head,*tail;  //monkey�ṹָ�룬ָ������ͷ�ڵ��β�ڵ�
//creat�����������ɺ�mm���ڵ��ѭ������ 
void creat(int mm)
{
	int i;
	monkey *p,*q;    //����monkey�ṹָ��p,q 
	p=new monkey;    //��p����ռ䣬�����½ڵ� 
	p->num=1;
	p->next=NULL;
	head=p;          //��һ���ڵ�Ϊͷ�ڵ� 
	q=p;
	for(i=2;i<=mm;i=i+1) //����ѭ������ 
	{
		p=new monkey;    //�����½ڵ� 
		p->num=i;
		q->next=p;
		q=p;
		p->next=NULL;
	}
	tail=q;
	tail->next=head; //��β�����ӣ��γ�ѭ������ 
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
			cout<<"��ɾ���ĺ��Ӻ�Ϊ"<<p->num<<"��"<<endl;
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
	cout<<"��������ӵĸ�����\n";
	cin>>m;
	cout<<"����������\n";
	cin>>n;
	creat(m);
	select(n);
	cout<<"������"<<head->num<<"��"<<endl;
	delete head;
	return 0;
}
