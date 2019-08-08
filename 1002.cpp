#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,p,q,w;
    char x[1010],y[1010],z[1010];
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        if(i != 1)  puts("");
        memset(x,0,1010*sizeof(char));
        memset(y,0,1010*sizeof(char));
        memset(z,0,1010*sizeof(char));//这是对三个字符串进行初始化 且每次循环都要进行一次（这是我犯错误的地方）
        cin>>x>>y;
        int a,b;
        /* a = x.length();
        b = y.length();*/
        a = strlen(x);
        b = strlen(y);//不同的类型对应不同的计算长度的函数
        /* reverse(x.begin(),x.end());
        reverse(y.begin(),y.end());*/
        //不同的类型有不同的反转函数
        strrev(x);
        strrev(y);//反转字符串（可反可不反 只是这样有利于我下面的循环）
        if(a==b)//第一种情况
        {
            int flag = 0;//设置进位
            for(int i = 0;i<a;i++)
            {
                p = x[i]-'0';//把字符转化为数字
                q = y[i]-'0';//同上
                w = (p+q+flag)%10;//计算每一位上的数字
                flag = (p+q+flag)/10;//计算进位
                z[i] = w+'0';//数字转化为字符串 保存到答案字符串里
            }
            if(flag!=0)
                z[a] = flag+'0';//如果最高位进位不为0 那么它就是最高位
            //reverse(z.begin(),z.end());
            strrev(x);
            strrev(y);
            strrev(z);//反转字符串
            cout<<"Case "<<i<<":"<<endl;
            cout<<x<<" + "<<y<<" = "<<z<<endl;
        } 
        if(a>b)//第二种情况 
        {
            int flag = 0;
            for(int i = 0;i<b;i++)//先按照第一种情况把位数小的这一部分相加 算完 保存
            {
                p = x[i]-'0';
                q = y[i]-'0';
                w = (p+q+flag)%10;
                flag = (p+q+flag)/10;
                z[i] = w+'0';
            }
            for(int i = b;i<a;i++)//从b到a 相当于a（位数大的字符串）的每一位加0
            {
                p = x[i]-'0';
                w = (p+flag)%10;
                flag = (p+flag)/10;
                z[i] = w+'0';
            }
            if(flag!=0)
                z[b+1] = x[b+1]+flag+'0';
            strrev(x);
            strrev(y);
            strrev(z);
            cout<<"Case "<<i<<":"<<endl;
            cout<<x<<" + "<<y<<" = "<<z<<endl;
        }
        if(a<b)//第三种情况
        {
            int flag = 0;
            for(int i = 0;i<a;i++)
            {
                p = x[i]-'0';
                q = y[i]-'0';
                w = (p+q+flag)%10;
                flag = (p+q+flag)/10;
                z[i] = w+'0';
            }
            for(int i = a;i<b;i++)
            {
                q = y[i]-'0';
                w = (q+flag)%10;
                flag = (q+flag)/10;
                z[i] = w+'0';
            }
            if(flag!=0)
                z[a+1] = x[a+1]+flag+'0';
            strrev(x);
            strrev(y);
            strrev(z);
            cout<<"Case "<<i<<":"<<endl;
            cout<<x<<" + "<<y<<" = "<<z<<endl;
        }
    }
    return 0;
}