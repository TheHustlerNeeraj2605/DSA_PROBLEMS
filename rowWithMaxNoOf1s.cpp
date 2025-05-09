#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>&arr, int n , int x){
    int low =0, high = n-1;
    int ans = n; 
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>>&matrix, int n, int m){
    int count_max =0;
    int index = -1;
    for(int i =0; i<n; i++){
        int count_ones = m- lowerBound(matrix[i], m, 1);
        if(count_ones>count_max){
            count_max = count_ones;
            index = i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> matrix = {{0,0,1,1,1},
                                  {0,0,0,0,0},
                                  {0,1,1,1,1},
                                  {0,0,0,0,0},
                                  {0,0,0,0,0}};


    int n = matrix.size();
    int m = matrix[0].size();
    int result = rowWithMax1s(matrix, n, m);  
    cout<< "Row with maximum 1s: " << result << endl;
    return 0;                        
}