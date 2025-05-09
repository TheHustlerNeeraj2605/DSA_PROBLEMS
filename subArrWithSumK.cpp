#include<bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int> &a, int k){
    map<int,int> mpp;
    mpp[0] =1;
    int preSum =0, count =0;
    for(int i=0; i<a.size(); i++){
        preSum +=a[i];
        int remove = preSum - k;
        count +=mpp[remove];
        mpp[preSum] += 1;

    }
    return count;
}
int main(){
    int k;
    cin>>k;
    vector<int> a= {1,2,3,-3,1,1,1,4,2,-3};
    int result = findAllSubarraysWithGivenSum(a,k);
    cout<< result;
    return 0;
}