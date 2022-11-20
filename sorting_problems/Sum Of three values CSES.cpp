#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int arr[n],arr1[n];
    int arr2[3]={0};

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    bool flag=0;
    sort(arr,arr+n);
    int a,j,k;
    for (int i = 0; i < n; i++)
    {
        a=i;
        j=i+1;
        k=n-1;
        while(j<k){
            
            if(arr[j]+arr[k]<(x-arr[i])){
               j++;
            }
            else if(arr[j]+arr[k]>(x-arr[i])){
               k--;
            }
            else{
                flag=1;
                for (int i = 0; i < n; i++)
                {
                    if(arr1[i]==arr[a] && arr2[0]==0){
                        arr2[0]=i+1;
                    }
                    else if(arr1[i]==arr[j] && arr2[1]==0){
                        arr2[1]=i+1;
                    }
                   else if(arr1[i]==arr[k] && arr2[2]==0){
                        arr2[2]=i+1;
                    }
                }
                sort(arr2,arr2+3);

                cout<<arr2[0]<<" "<<arr2[1]<<" "<<arr2[2]<<endl;
                return 0;
            }
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    return 0;
}
