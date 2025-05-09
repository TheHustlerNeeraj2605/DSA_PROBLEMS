#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i =0; i<n ;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int>&v,int hourly){
    long long totalH =0;
    int n = v.size();
    for(int i=0; i<n; i++){
        totalH += ceil((v[i]+ hourly - 1LL)/hourly);
    }
    return totalH;
}
int minimumRateToEatBanana(vector<int>&v,int h){
    int low =1, high = findMax(v);
    int ans = high; // Initializing with maximum
    while(low<=high){
        int mid = (low+high)/2;
        long long totalH = calculateTotalHours(v,mid);
        if(totalH<=h){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v = {3,6,7,11};
    int h;
    cin>>h;
    int result = minimumRateToEatBanana(v,h);
    cout<<result;
    return 0;
}