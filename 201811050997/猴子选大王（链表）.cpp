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