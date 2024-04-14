#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr, int n);
pair<string, int>find_element(vector<int> &arr, int n, int k);
pair<bool, int> find_(vector<int>&arr, int start, int end, int K);

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i <n; ++i) {
        cin >> x[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        pair<string, int>p=find_element(x, n, y);
        cout<<p.first<<' '<<p.second<<endl;
    }
    return 0;
}
//find pivot in the given array
int pivot(vector<int> &arr, int n){
    int s=0;
    int e=n;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[s])
            s=mid+1;
        else
            e=mid;
    }
    return s;
}
//find a element in a given array
pair<string, int>find_element(vector<int> &arr, int n, int k){
    int pivot_=pivot(arr, n-1);
    if(k>=arr[pivot_] && k<=arr[n-1]){
            pair<bool, int>p=find_(arr, pivot_, n-1, k);
            if(p.first)
            return {"Yes", p.second};
            else
            return {"No", p.second};
    }
    else{
        pair<bool, int>p=find_(arr, 0, pivot_-1, k);
            if(p.first)
            return {"Yes", p.second};
            else
            return {"No", p.second};
    }
}
//element is present or not
pair<bool, int> find_(vector<int>&arr, int start, int end, int K){
    int s=start;
    int e=end;
    int mid=s+(e-s)/2;
    while(s<=e){
        
        if(arr[mid]>K)
        e=mid-1;
        else if(arr[mid]==K)
        return {true, mid+1};
        else
        s=mid+1;
        mid=s+(e-s)/2;
    }
    return {false, mid+1};
}
