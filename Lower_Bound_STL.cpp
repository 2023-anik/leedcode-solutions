#include <bits/stdc++.h> 
using namespace std;

pair<string,int>find_element(vector<int> &arr, int n, int k){
    int low=0;
    int high=n-1;
    int mini_index;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]<k)
            low=mid+1;
        else if(arr[mid]==k){
            mini_index=mid;
        }
        else
            high=mid-1;
    }
    if(arr[mini_index]==k)
        return {"Yes", mini_index+1};
    else
        return {"No", mini_index+1};
}

int main() 
{ 
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; ++i){
        cin>>arr[i];
    }
    int q;
    cin>>q;
    while(q--){
        int y;
        cin>>y;
        pair<string, int>p=find_element(arr, n, y);
        cout<<p.first<<' '<<p.second<<endl;
    }
    return 0; 
}
