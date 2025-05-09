#include<bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target){
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int more = target- arr[i];
        if(mpp.find(more) != mpp.end()){
            return "YES";
        }
        mpp[a] = i;
    }
    return "NO";
}
string optimalAppro(int n, vector<int> &arr, int target){
    int left = 0; int right = n-1;
    sort(arr.begin(), arr.end());
    while(left<right){
        int sum = arr[left] + arr[right];
        if(sum==target){
            return "YES";
        }
        else if(sum<target) left++;
        else right--;
    }
    return "NO";
}

int main(){
    int target;
    cin>>target;
    vector<int> arr= {2,6,5,8,11};
    int n = arr.size();

    string result = optimalAppro(n,arr,target);
    cout<<result;
}