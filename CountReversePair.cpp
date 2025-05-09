#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr ,int low, int mid , int high){
    int right = mid+1;
    int count =0;
    for(int i = low; i<= mid; i++){
        while(right <=high && arr[i] > 2* arr[right]) right++;
        count += (right - (mid+1)); 
    }
    return count;
}
int mergeSort(vector<int> &arr , int low , int high){
    int count = 0;
    if(low>= high) return count;
    int mid = (low + high)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}
int Reversepairs(vector<int> arr,int n) {
    return mergeSort(arr, 0 , n-1);
}
int main(){
    vector<int> arr = {40 , 25 , 19 , 12 , 9 , 6 , 2};
    int n = arr.size();
    int count = Reversepairs(arr,n);
    cout<<"The number of Reverse Pairs is: "<< count;
    return 0;
}