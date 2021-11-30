#include <bits/stdc++.h>
using namespace std;

class Bigint
{
    private:
    string str;
    public:
    Bigint(string str)
    {
        this->str=str;
    }
    string toString()
    {
        return str;
    }
};
 string add(string, string);
 string subtract(string, string);
 string multiply(string, string);
 string divide(string, string);
 string mod(string, string);
 string factorial(int);
 string gcd(string, string);
 bool greaterThan(string, string);
 bool equalto0(string);
 string divideby2(string);
 bool equalto0(string);
 string power(string, int);

int main()
{
    return 0;
}

string power(string s, int n)
{
    string res(3000,'0');
    res[2999]='1';
    int l=s.length();
    while (n>0)
    {
        if (n&1)
            res=multiply(res,s);
        s=multiply(s,s);
        n>>=1;
    }
    int i=0;
    while(res[i++]=='0');
    res=res.substr(i-1,2999);
    return res;
}
string factorial(int n)
{
    string f1(3000,'0');
    f1[2999]='1';
    int count=floor(log10(n) + 1);
    string f2(count,'0');
    f2[count-1]='2';
    for(int i=1; i<n; i++)
    {
        f1=multiply(f1,f2);
        f2=add(f2,"1");
    }
    int i=0;
    while(f1[i++]=='0');
    f1=f1.substr(i-1,2999);
    return f1;
}
string gcd(string s1, string s2)
{
    if (equalto0(s2))
        return s1;
    else
        return gcd (s2, mod(s1,s2));
}
string mod(string s1, string s2)
{
    int l1=s1.length(), l2=s2.length();
    string q="",remainder="",divisor;
    for(int i=l2-1; i<l1; i++)
    {
        string quotient="",dividend;
        divisor=s2;
        if(i==l2-1)
            dividend=s1.substr(0,l2);
        else 
            dividend=remainder+s1[i];
        int times=0;
        while(!greaterThan(multiply(s2,to_string(++times)),dividend));
        times--;
        quotient=multiply(s2,to_string(times));
        remainder=subtract(dividend,quotient);
        q+=to_string(times);
    }
    return remainder;
}
string divide(string s1, string s2)
{
    int l1=s1.length(), l2=s2.length();
    string q="",remainder="",divisor;
    for(int i=l2-1; i<l1; i++)
    {
        string quotient="",dividend;
        divisor=s2;
        if(i==l2-1)
            dividend=s1.substr(0,l2);
        else 
            dividend=remainder+s1[i];
        int times=0;
        while(!greaterThan(multiply(s2,to_string(++times)),dividend));
        times--;
        quotient=multiply(s2,to_string(times));
        remainder=subtract(dividend,quotient);
        q+=to_string(times);
    }
    return q;
}

bool equalto0(string s)
{
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i]!='0')
            return false;
    }
    return true;
}
string subtract(string s1, string s2)
{
    string str="";
    int l1=s1.length(), l2=s2.length();
    int i,j,borrow=0;
    for(i=l1-1,j=l2-1; j>=0; i--, j--)
    {
        int d1=(s1[i]-'0'), d2=(s2[j]-'0');
        if(borrow>0)
        {
            if(d1>0)
            {
                d1--;
                borrow--;
            }
            else
                d1=9;
        }
        int diff=d1-d2;
        if(diff<0)
        {
            diff=d1+10-d2;
            borrow++;
        }
        str+=(char)(diff+'0');
    }
    while(i>=0)
    {
        int d1=(s1[i--]-'0');
        if(borrow>0)
        {
            if(d1>0)
            {
                d1--;
                borrow--;
            }
            else
                d1=9;
        }
        str+=(char)(d1+'0');
    }
    reverse(str.begin(),str.end());
    i=0;
    while(str[i++]=='0');
    str=str.substr(i-1,l1+l2);
    return str;
}
string add(string s1, string s2)
{
    string str="";
    int l1=s1.length(), l2=s2.length();
    int i,j,carry=0;
    for(i=l1-1,j=l2-1; i>=0 && j>=0; i--, j--)
    {
        int sum=(s1[i]-'0')+(s2[j]-'0')+carry;
        carry=sum/10;
        str+=(char)(sum%10+'0');
    }
    while(j>=0)
    {
        int sum=(s2[j--]-'0')+carry;
        carry=sum/10;
        str+=(sum%10+'0');
    }
    while(i>=0)
    {
        int sum=(s1[i--]-'0')+carry;
        carry=sum/10;
        str+=(sum%10+'0');
    }
    reverse(str.begin(),str.end());
    return str;
}
bool greaterThan(string s1, string s2)
{
    int l1=s1.length(), l2=s2.length();
    int i=0;
    while(s1[i++]=='0');
    s1=s1.substr(i-1,l1);
    i=0;
    while(s2[i++]=='0');
    s2=s2.substr(i-1,l2);
    l1=s1.length();
    l2=s2.length();
    if(l1!=l2)
        return l1>l2;
    else
    {
        for(int i=0; i<l1; i++)
        {
            if(s1[i]==s2[i])
                continue;
            else
                return s1[i]>s2[i];
        }
    }
    return false;
}
string multiply(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length(); 
    if (l1 == 0 || l2 == 0) 
        return "0"; 
    string res(l1+l2, '0');
    int carry=0;
    for (int i=l1-1; i>=0; i--)
    {
        int d1=s1[i]-'0';
        for(int j=l2-1; j>=0; j--)
        {
            int d2=s2[j]-'0';
            int prev=res[i+j+1]-'0';
            int prod=d1*d2+prev;
            res[i+j]=((res[i+j]-'0')+prod/10)+'0';
            res[i+j+1]=(prod%10)+'0';
        }
    }
    int i=0;
    while(res[i++]=='0');
    res=res.substr(i-1,l1+l2);
    return res;
}
string divideby2(string s)
{
    int l=s.length();
    int remainder=0;
    for(int i=0; i<l; i++)
    {
        int n=(s[i]-'0');
        s[i]=(remainder==0)?(n/2)+'0':((n+10)/2)+'0';
        remainder=n%2==0?0:1;        
    }
    return s;
}