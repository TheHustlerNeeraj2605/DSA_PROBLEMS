#include<bits/stdc++.h>
using namespace std;
int longestSuccessiveEle(vector<int> &a){
    if(a.size() ==0) return 0;
    sort(a.begin(), a.end());
    int n = a.size();
    int count =0, lastSmaller = INT_MIN;
    int longest =1;
    for(int i =0; i<n ; i++){
        if(a[i]-1 == lastSmaller){
            count +=1;
            lastSmaller = a[i];
        }
        else if(a[i] != lastSmaller){
            count =1;
            lastSmaller = a[i];
        }
        longest = max(count, longest);
    }
    return longest;
}
int optimalSol(vector<int> &a){
    int n = a.size();
    if(n==0) return 0;
    int longest =1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }
    for(auto it: st){
        if(st.find(it-1)== st.end()){
            int count =1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x+1;
                count =count + 1;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}


int main(){
    vector<int> a= {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    // int result = longestSuccessiveEle(a);
    int result = optimalSol(a);
    cout<<result;
    return 0;
}