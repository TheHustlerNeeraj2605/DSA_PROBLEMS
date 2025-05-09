#include<bits/stdc++.h>
using namespace std;
vector<int> spiralMat(vector<vector<int>>&matrix){
    int n = matrix.size();
    int m= matrix[0].size();
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;
    // We are checking these while because if we have only one row
    while(top<= bottom && left<=right){
        // right
        for(int i=left ; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main(){
    int row, col;
    cin>> row>> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for(int i =0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>> matrix[i][j];
        }
    }
    vector<int> resultantMat = spiralMat(matrix);
    for(auto it: resultantMat){
        cout<< it<<" ";
    }
    return 0;

}