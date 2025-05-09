#include<bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row){
    long long ans =1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++){
        ans = ans * (row-col);
        ans = ans/(col);
        ansRow.push_back(ans);
    }
    return ansRow;

}
vector<vector<int>> pascal(int N){
    vector<vector<int>> ans;
    for(int i=1; i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    vector<vector<int>> triangle = pascal(N);
    for(auto row : triangle){
        for(auto num : row){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Fully optimized code for pascal triangle

#include <iostream>
#include <vector>
using namespace std;

// Function to generate and print Pascal's Triangle
void printPascal(int N) {
    for (int row = 0; row < N; ++row) {
        long long val = 1;
        for (int space = 0; space < N - row - 1; ++space) {
            cout << "  "; // for alignment (optional)
        }
        for (int col = 0; col <= row; ++col) {
            cout << val << "   ";
            val = val * (row - col) / (col + 1);
        }
        cout << "\n";
    }
}

int main() {
    int N;
    cin >> N;
    printPascal(N);
    return 0;
}

*/