#include<bits/stdc++.h>
using namespace std;
int findDays(vector<int>&weight,int cap){
    int day =1;
    int load =0;
    for(int i=0; i<weight.size(); i++){
        if(weight[i]+load >cap){
            day +=1;
            load= weight[i];
        }
        else {
            load += weight[i];
        }
    }
    return day;
}
int leastWeightCapacity(vector<int>&weight,int d){
    int low = *max_element(weight.begin(),weight.end()); // For finding the max element in the array.
    int high = accumulate(weight.begin(),weight.end(),0); // Direct do sum of array element.
    while(low<=high){
        int mid = (low+high)/2;
        int numberOfDays = findDays(weight,mid);
        if(numberOfDays<=d){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> weight = {1,2,3,4,5,6,7,8,9,10};
    int d;
    cin>>d;
    int result = leastWeightCapacity(weight,d);
    cout<<result;
    return 0;
}