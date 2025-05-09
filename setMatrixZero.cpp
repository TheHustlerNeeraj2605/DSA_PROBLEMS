#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> setMatZero(vector<vector<int>> &matrix, int n, int m){
    int col[m] = {0};
    int row[n] = {0};
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(matrix[i][j]==0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j =0; j<m; j++){
            if(row[i]|| col[j]){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}

vector<vector<int>> Optimal(vector<vector<int>> &matrix, int n, int m){
    //int col[m] = {0}; -> matrix[i][...]
    //int row[n] = {0}; -> matrix[...][j]
    int col0 =1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] ==0){
                // mark the ith row
                matrix[i][0] = 0;
                // mark the jth column
                if(j!=0){
                    matrix[0][j] =0;
                }
                else{
                    col0 = 0;
                }
            }
        }
    }
    // i and j start from 1 because we want to exclude first row and column in the start.
    for(int i =1; i<n; i++){
        for(int j =1 ; j<m; j++){
            if(matrix[i][j] !=0){
                // check for the row and col
                if(matrix[i][0] ==0 || matrix[0][j]==0){
                    matrix[i][j] =0;
                }
            }
        }
    }
    if(matrix[0][0]==0){
        for(int j =0; j<m; j++){
            matrix[0][j]=0;
        }
    }
    if(col0 ==0){
        for(int i =0; i<n; i++){
            matrix[i][0] =0;
        }
    }
    return matrix;
}
int main(){
    int row, col;
    cin>>row>> col;
    vector<vector<int>> matrix(row,vector<int>(col));
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>> matrix[i][j];
        }
    }
    // vector<vector<int>> resultantMat = setMatZero(matrix,row,col);
    vector<vector<int>> resultantMat = Optimal(matrix,row,col);
    // Printing the resultant matrix
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << resultantMat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;

}