#include<bits/stdc++.h>
using namespace std;
int search(vector<int> &arr, int target){
    int n = arr.size();
    int low =0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid] == target ) return mid;
        else if(target>arr[mid]) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int bs(vector<int>&arr, int low , int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(arr[mid]== target) return mid;
    else if(target >arr[mid]) return bs(arr, mid+1,high, target);
    else return bs(arr, low, mid-1,target);
}
int Recursion(vector<int> &arr, int target){
    return bs(arr, 0 , arr.size()-1, target);
}
int main(){
    vector<int> arr = { 3,4,6,7,9,12,16,17};
    int target;
    cin>>target;
    //int result = search(arr,target);
    int result = Recursion(arr,target);
    cout<< result;
    return  0;
}