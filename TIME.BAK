#include<iostream.h>
#include<conio.h>
#include<stdio.h>
class time
{
public:
int h,m,s;
void read()
{
cout<<"enter hour:"<<endl;
cin>>h;
cout<<"enter minutes:"<<endl;
cin>>m;
cout<<"enter second:"<<endl;
cin>>s;
}
void display()
{
cout<<"TIME : "<<h<<":"<<m<<":"<<s<<endl;
}
void correction()
{
if(s<0)
{
s=s+60;
m--;
}
if(m<0)
{
m=m+60;
h--;
}
if(s>60)
{
m=m+s/60;
s=s%60;
}
if(m>60)
{
h=h+m/60;
m=m%60;
}
}
};
time diff(time time1,time time2)
{
time temp;
temp.h = time1.h - time2.h;
temp.m = time1.m - time2.m;
temp.s = time1.s - time2.s;
temp.correction();
return temp;
}
time add(time time1,time time2)
{
time temp;
temp.h = time1.h + time2.h;
temp.m = time1.m + time2.m;
temp.s = time1.s + time2.s;
temp.correction();
return temp;
}
void main()
{
clrscr();
time t1,t2,t3;
cout<<"enter first time:"<<endl;
t1.read();
cout<<"enter second time:"<<endl;
t2.read();

t3 = add(t1 , t2);
cout<<"addition is : "<<endl;
t3.display();
t3=diff(t1,t2);
cout<<"difference is:"<<endl;
t3.display();
cout<<"sec ";
getch();
}
