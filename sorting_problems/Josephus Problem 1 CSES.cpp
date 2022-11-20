#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
//vector<long long>ans;
//vector<int> arr(N);
//void josephus(vector<long long> arr,int index){
    // if(arr.size()==1){
    //     ans.push_back(arr[0]);
    //     return;
    // }
    // while(arr.size()>=1){
    // //auto it= arr.begin()+index;
    // index=(index+1)%arr.size();
    // cout<<arr[index]<<" ";
    // arr.erase(arr.begin()+index);
    // for(auto it:arr){
    //     cout<<it<<" ";
    // }
    //josephus(arr,index);
    //}
//}
int main(){
    int n;
    cin>>n;
    //arr.resize(n);
    //ans.resize(n);
    vector<int> arr(n);
    for (int i = 0; i <n; i++)
    {
        arr[i]=i+1;
    }
    //josephus(arr,0);
    //int index=0;
    while(arr.size()>1){
        vector<int>survivors;
        for (int i = 0; i < arr.size(); i++)
        {
            if(i%2==1){
               cout<<arr[i]<<" ";
            }
            else{
                survivors.push_back(arr[i]);
            }
        }
        if(arr.size()%2==0){
            arr=survivors;
        }
        else{
            int last=survivors.back();
            survivors.pop_back();
            arr.clear();
            arr.push_back(last);
            for (int i:survivors)
            {
                arr.push_back(i);
            }
        }
    }
    cout<<arr[0]<<" ";
    // while(arr.size()>=1){
    // //auto it= arr.begin()+index;
    // index=(index+1)%arr.size();
    // cout<<arr[index]<<" ";
    // arr.erase(arr.begin()+index);
    // }
    // for(auto it:ans){
    // // if(it==0){
    // //     continue;
    // // }
    // cout<<it<<" ";
    // }
    
   // cout<<arr[josephus(n,2)];

    return 0;
}
