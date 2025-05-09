#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>&arr,int day,int m,int k){
    int cnt =0;
    int noOfB=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<=day){
            cnt++;
        }
        else{
            noOfB += (cnt/k);
            cnt =0;
        }
    }
    noOfB += (cnt/k);
    return noOfB>=m;
}
int RoseGarden(vector<int>&arr,int m,int k){
    long long val = m * 1LL * k * 1LL;
    if(val>arr.size()) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi,arr[i]);
    }
    int low = mini, high = maxi;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(arr,mid,m,k)){
            high = mid-1;
        }
        else low = mid+1;
    }
    return low;
}
int main(){
    vector<int> arr = {7,7,7,7,13,11,12,7};
    int m; // No of bouquets
    int k; // Adjacent Flowers required
    cin>>m;
    cin>>k;
    int result = RoseGarden(arr,m,k);
    cout<<result;
    return 0;
}