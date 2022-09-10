#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int c=a;
    int d=b;
    vector<int> v;
    int cnt=0;
    while (b!=a && b>a)
    {
        if(b%10==1){
            b=(b-1)/10;
            v.push_back(b);
            cnt++;
        }
        else if(b%2==0){
            b=b/2;
            v.push_back(b);
            cnt++;
            
        }
        else{
            break;
        }
    }
    if(a==b){
        cout<<"YES"<<endl;
        cout<<cnt+1<<endl;
        //cout<<c<<" ";
        for (int i = v.size()-1; i>=0; i--)
        {
            cout<<v[i]<<" ";
        }
        cout<<d<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}