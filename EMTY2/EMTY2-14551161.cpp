#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class stack
{
public:
 char st[200000];
 int top;
 void push(char a){
  st[++top]=a;
 }
 void del(int pos)
 {
  for(int i=pos;i<top;i++)
   st[i]=st[i+1];
  st[top]==NULL;
  top--;
 }
};
int main()
{
 int t;
 scanf("%d  ",&t);
 for(int k=1;k<=t;k++)
 {
  stack d;
  d.top=-1;
  char s[200000];
  scanf("%s",s);
  int i=0,size;
  while(s[i]!='\0')
  {
   d.push(s[i]);
   if(d.top>=2){
    size=d.top;
    if(d.st[size-2]==49 && d.st[size-1]==48 && d.st[size]==48){
     d.del(size);
     d.del(size-1);
     d.del(size-2);
    }
   }
   i++;
  }
  if(d.top==-1)
   printf("Case %d: yes\n",k);
  else
   printf("Case %d: no\n",k);
 }
 return 0;
}