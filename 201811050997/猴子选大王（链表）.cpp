#include <iostream>
using namespace std;
struct monkey
{
int num;
monkey *next;
};
monkey *head,*tail;
void creat(int mm)
{
int i;
monkey *p,*q;
p=new monkey;
p->num=1;
p->next=NULL;
head=p;
q=p;
for(i=2;i<=mm;i=i+1)
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