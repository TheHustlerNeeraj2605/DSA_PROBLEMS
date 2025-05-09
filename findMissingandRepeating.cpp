#include<bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> arr){
    int n = arr.size();
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }
    int repeating = -1; 
    int missing =-1;
    for(int i=1; i<=n ; i++){
        if(hash[i]==0){
            missing = i;
        }
        else if(hash[i]==2){
            repeating = i;
        }
        if(repeating !=-1 && missing != -1)
            break;
    }
    return {repeating, missing};
}
vector<int> Optimal1(vector<int> arr){
    long long n = arr.size();
    long long SN = (n*(n+1))/2;
    long long S2N = (n*(n+1)*(2*n+1))/6;
    long long S =0, S2 =0;
    for(int i=0; i<n; i++){
        S +=arr[i];
        S2 += (long long) arr[i] * (long long) arr[i];
    }
    long long val1 = S-SN; // X-Y
    long long val2 = S2 - S2N;
    val2 = val2/val1; // X+Y
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return {(int)x,(int)y};
}
vector<int> Optimal2(vector<int> arr){
    long long n = arr.size();
    int xr =0;
    for(int i =0; i<n ; i++){
        xr  = xr^ arr[i];
        xr = xr ^ (i+1);
    }
    int number = xr & (xr-1);// By this we can easily generate differentiating bit.
    // Grouping the numbers
    int zero =0;
    int one =0;
    for(int i =0; i<n ; i++){
        // part of 1 club
        if((arr[i] & number) !=0){
            one = one ^ arr[i];
        }
        else{
            // Zeroth club
            zero = zero ^ arr[i];
        }
    }
    for(int i =1; i<=n ; i++){
        // part of 1 club
        if((i & number) !=0){
            one = one ^ i;
        }
        else{
            zero = zero ^ i;
        }
    }
    int cnt =0;
    for(int i =0; i<n; i++){
        if(arr[i] ==0) cnt++;
    }
    if (cnt == 2) return {zero, one};
    return {one, zero};
}
int main(){
    vector<int> arr = {4,3,6,2,1,1};
    // vector<int> ans = findMissingRepeatingNumbers(arr);
    //vector<int> ans = Optimal1(arr);
    vector<int> ans = Optimal2(arr);
    cout<<"The missing and repeating numbers are {" << ans[0] << " , "<< ans[1]<< "}";
    return 0;
}