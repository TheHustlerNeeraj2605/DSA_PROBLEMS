#include<bits/stdc++.h>
using namespace std;
int numApperOnes(vector<int> &arr){
    int xorr =0;
    for(int i=0; i<arr.size(); i++){
        xorr = xorr^ arr[i];
    }
    return xorr;
}
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5};
    int result = numApperOnes(arr);
    cout<<result;
}