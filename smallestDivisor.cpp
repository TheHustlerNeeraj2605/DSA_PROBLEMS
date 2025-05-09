#include<bits/stdc++.h>
using namespace std;
int SumByD(vector<int>&arr, int div){
    int sum =0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        sum = sum + ceil((double)arr[i]/ (double)div);
    }
    return sum;
}
int smallestDivisor(vector<int>& arr,int threshold){
    int n = arr.size(); 
    if(n>threshold) return -1; // Min sum which is n and that is exceeding the threshold
    int low =1;
    int high = *max_element(arr.begin(), arr.end());
    while(low<=high){
        int mid = (low+high)/2;
        if(SumByD(arr,mid)<=threshold){
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr = {1,2, 5, 9};
    int threshold;
    cin>>threshold;
    int result = smallestDivisor(arr,threshold);
    cout<<result;
    return 0;
}