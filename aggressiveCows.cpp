#include<bits/stdc++.h>
using namespace std;
bool canWePlace(vector<int>&arr,int dist,int cows){
    int cntCows =1, last = arr[0];
    for(int i =0; i<arr.size(); i++){
        if(arr[i]-last>= dist){
            cntCows++;
            last = arr[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}
int aggresiveCows(vector<int>&arr,int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low =0, high = arr[n-1]-arr[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(arr,mid,k)==true){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}
int main(){
    vector<int> arr = {0,3,4,7,9,10};
    int k;
    cin>>k;
    int result = aggresiveCows(arr,k);
    cout<<result;
    return 0;
}