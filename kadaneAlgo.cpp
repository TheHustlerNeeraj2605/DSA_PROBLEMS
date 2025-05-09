#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int a[] , int n){
    long long maxi = INT_MIN;
    long long sum=0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum>maxi){
            maxi = sum;
        }
        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum =0;
        }
    }
    // To consider the sum of the empty subarray
    // uncomment the following check:
    //if (maxi < 0) maxi = 0;
    return maxi;
    
}
long long followUp(int a[], int n){
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int start =0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += a[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }
    //printing the subarray:
    cout<< "The subarray is [ ";
    for(int i = ansStart ; i<=ansEnd; i++){
        cout<<a[i]<< " ";
    }
    cout<<"]n";
    cout<< endl;

    return maxi;

}
int main(){
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(a)/ sizeof(a[0]);
    // long long maxSum = maxSubarraySum(a, n);
    long long maxSum = followUp(a, n);
    cout<<"The maximum subarray sum is: " << maxSum;
    return 0;
}