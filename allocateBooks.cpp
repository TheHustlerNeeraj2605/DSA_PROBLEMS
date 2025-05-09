// The Painter's Problem and Split array-largest Sum
#include<bits/stdc++.h>
using namespace std;
int countStudent(vector<int>&arr,int pages){
    int students =1;
    long long pagesStudent = 0;
    for(int i =0; i<arr.size(); i++){
        if(pagesStudent+arr[i]<=pages){
            pagesStudent +=arr[i];
        }
        else{
            students +=1;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int allocateBooks(vector<int>&arr,int s){
    int n = arr.size();
    if(s>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(),0);
    while(low<=high){
        int mid= (low+high)/2;
        int students = countStudent(arr,mid);
        if(students>s) low = mid+1;
        else high = mid-1;
    }
    return low;
}
int main(){
    vector<int> arr = {25,46,28,49,24};
    int s;
    cin>>s;
    int result = allocateBooks(arr,s);
    cout<<result;
    return 0;
}