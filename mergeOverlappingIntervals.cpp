#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> a){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || a[i][0] > ans.back()[1]){
            ans.push_back(a[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1] , a[i][1]);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> a = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(a);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;

}