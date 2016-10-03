using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(int i=0;i<(N);i++)
int main()
{
    string str,t;
    int len;
    bool j,c;
    while(cin>>str)
    {
        j=c=true;
        len=str.length();
        if(!islower(str[0]))
        j=c=false;
        for(int i=1;i<len;i++)
        {
            if(!isalpha(str[i]))
            j=false;
            if(str[i]=='_')
            {
                if(!islower(str[i+1])) c=false;
            }
            else if(!islower(str[i]))c=false;
        }
//        cout<<j<<" "<<c<<endl;
        if(!j and !c)
        {
            cout<<"Error!\n";
            continue;
        }
        else if(j and c)
        {
            cout<<str<<endl;
            continue;
        }
        if(j)
        {
            cout<<str[0];
            for(int i=1;i<len;i++)
                if(str[i]>='A' && str[i]<='Z')
                    cout<<"_"<<char(str[i]-'A'+'a');
                else cout<<str[i];
        }
        else
        {
            t="";
            t.push_back(str[0]);
            for(int i=1;i<len;i++)
            {
                if(islower(str[i]))
                {
                    if(str[i-1]=='_')
                    {
                        t.push_back(toupper(str[i]));
                    }
                    else
                    {
                        t.push_back(str[i]);
                    }
                }
            }
            cout<<t;
        }
        cout<<endl;
    }
}
