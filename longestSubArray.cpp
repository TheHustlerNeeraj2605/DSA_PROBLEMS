#include<bits/stdc++.h>
using namespace std;
int longestSubArr(vector<int> &arr , long long k){
    map<long long, int> preSumMap;
    long long sum =0;
    int maxLen =0;
    for(int i=0; i<arr.size(); i++){
        sum = sum+arr[i];
        if(sum ==k){
           maxLen = max(maxLen,i+1); 
        }
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){ // We are finding the rem in the preSumMap 
            int len = i-preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum)== preSumMap.end()){
            preSumMap[sum] =i;
        }
    }
    return maxLen;
}
int optimalSol(vector<int> &arr , long long k){
    int left = 0; int right = 0;
    long long sum =arr[0];
    int maxLen =0;
    int n =arr.size();
    while(right<n){
        while(left<=right && sum>k){
            sum -= arr[left];
            left++;
        }
        if(sum ==k) {
            maxLen = max(maxLen, right-left +1);
        }
        right++;
        if(right<n) sum += arr[right]; 
    }
    return maxLen;
}

int main(){
    int k;// Desired sum of the Subarray
    cin>>k;
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int result = longestSubArr(arr,k);
    cout<< result;
}