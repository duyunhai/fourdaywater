#include <iostream>
using namespace std;
struct monkey
{
	int num;
	monkey *next;
};
monkey *head,*tail;
void ergodic(int k)
{
	int i;
	monkey *p,*q;
	p=new monkey;
	p->num=1;
	p->next=NULL;
	head=p;
	q=p;
	for(i=2;i<=k;i=i+1)
	{
		p=new monkey;
		p->num=i;
		q->next=p;
		q=p;
		p->next=NULL;
	}
	tail=q;
	tail->next=head;
}
void select()
{
	monkey *p,*q;
	q=tail;
	do
	{
		p=q->next;
		cout<<"ɾ��"<<p->num<<"�ź���"<<endl;
		q->next=p->next;
		delete p;
		p=NULL; 
	}while(q!=q->next);
	head=q;
}
void main()
{
	int m;
	cout<<"��������ӵĸ���:";
	cin>>m;
	ergodic(m);
	select();
	cout<<"������"<<head->num<<"��"<<endl;
}