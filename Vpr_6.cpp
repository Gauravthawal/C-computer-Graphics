#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class student
{
public:
int rollno;
string name; 
char mob[20];
bool operator==(const student &student1)
{
return (rollno==student1.rollno);
}
friend ostream& operator << (ostream &out, const student &);
friend istream& operator >> (istream &in, student &k);
};
ostream & operator << (ostream &out, const student &k)
{
out<<"\n\t\t"<<k.rollno<<"\t\t"<<k.name<<"\t\t"<<k.mob;
return out;
}
istream & operator >> (istream &in, student &k)
{
cout<<"\n Enter Roll no: "; 
in>>k.rollno;
cout<<"\n Enter Name: ";
in>>k.name;
cout<<"\n Enter mob: ";
in>>k.mob;
return in;
}
vector<student>read()
{
int n;
student k;
vector<student> j;
cout<<"\n Enter total no. of students: ";
cin>>n;
for(int i=0;i<n;i++) 
{
cin>>k;
j.push_back(k);
}
return j;
}
void printfunction(const student &k)
{
cout<<k;
}
void print(const vector<student> &j)
{
cout<<"\n\t\tROLL NO\t\tNAME\t\tMobile Number";
for_each(j.begin(),j.end(),printfunction);
}
void search(vector<student> &j)
{
student k;
cout<<"\nEnter Student Roll No To search: ";
cin>>k.rollno;
cout<<"\n\n\t\tROLL NO\t\tNAME\t\tDATE OF BIRTH";
vector<student>::iterator p;
p=find(j.begin(),j.end(),k);
if(p!=j.end())
cout<<*p;
else
cout<<"\nNot found ";
}
bool sort_func(const student &x, const student &y)
{
return(x.rollno<y.rollno);
}
void sort(vector<student> &j)
{
sort(j.begin(),j.end(),sort_func);
}
int main()
{
vector<student> s;
int ch;
do
{
cout<<"\n\n\t\t***Personal Record Database***";
cout<<"\n\t\t1.Create Record";
cout<<"\n\t\t2.Display Record";
cout<<"\n\t\t3.Search Record";
cout<<"\n\t\t4.Sort Record";
cout<<"\n\t\t5.Quit Menu";
cout<<"\n\t\t-----------------------------------";
cout<<"\n\t\tEnter your choice: ";
cin>>ch;
switch (ch)
{
case 1:
s=read();
break;
case 2:
print(s);
break;
case 3:
search(s);
break;
case 4:
sort(s);
print(s);
break;
}
} while (ch != 5);
}
