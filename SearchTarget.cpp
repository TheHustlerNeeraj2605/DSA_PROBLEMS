#include<bits/stdc++.h>
using namespace std;
bool SearchTarget(vector<vector<int>>&matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();
    int low =0, high = (n*m-1); // Interpreting it as 1d array.
    while(low<=high){
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(matrix[row][col]== target) return true;
        else if(matrix[row][col] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {{3,4,7,9},
                                  {12,13,16,18},
                                  {20,21,23,29}};

    int target;
    cin>>target;
    bool result = SearchTarget(matrix,target);  
    cout<< result << endl;
    return 0;                        
}