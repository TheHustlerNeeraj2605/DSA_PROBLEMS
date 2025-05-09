#include<bits/stdc++.h>
using namespace std;
vector<int> findUnion(vector<int> arr1, vector<int > arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    set<int> st;
    for(int i=0; i<n1; i++){
        st.insert(arr1[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(arr2[i]);
    }
    vector<int> temp;
    for(auto it: st ){
        temp.push_back(it);
    }
    return temp;
}
vector<int> optimalAppro(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i =0;
    int j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            if(unionArr.size()==0 || unionArr.back() != arr1[i]){
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionArr.size()==0 || unionArr.back() != arr2[j]){
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(j<n2){

        if(unionArr.size()==0 || unionArr.back() != arr2[j]){
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    while(i<n1){
            
        if(unionArr.size()==0 || unionArr.back() != arr1[i]){
            
            unionArr.push_back(arr1[i]);
            
        }
            
        i++;  
    }
    return unionArr;
}

int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {2,3,4,4,5,6};
    // vector<int> res = findUnion(arr1, arr2);
    vector<int> res = optimalAppro(arr1, arr2);
    cout<< "The union of the two arrays is: ";
    for(auto val: res){
        cout<< val<< " ";
    }
    cout<< endl;
    return 0;
}