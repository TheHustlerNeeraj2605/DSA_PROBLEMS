#include<bits/stdc++.h>
using namespace std;
double medianOfTwoSortedArr(vector<int>&a,vector<int>&b){
    vector<int> arr3;
    int n1 = a.size();
    int n2 = b.size();
    int i =0, j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }
    while(i<n1) arr3.push_back(a[i++]);
    while(j<n2) arr3.push_back(b[j++]);
    int n = (n1+n2);
    if(n%2 ==1){
       return arr3[n/2];
    }
    else {
        return (double) ((double)arr3[n/2]+ (double)(arr3[n/2 - 1])) / 2.0;
    }
}
double Better(vector<int>&a,vector<int>&b){
    int n1 = a.size();
    int n2 = b.size();
    int i =0, j=0;
    int n = (n1+n2);
    int ind2 = n/2;
    int ind1 = ind2 -1;
    int count = 0;
    int ind1el = INT_MIN, ind2el = INT_MIN;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            if(count == ind1) ind1el = a[i];
            if(count == ind2) ind2el = a[i];
            count++;
            i++;
        }
        else{
            if(count == ind1) ind1el = b[j];
            if(count == ind2) ind2el = b[j];
            count++;
            j++;
        }
    }
    while(i<n1){
        if(count == ind1) ind1el = a[i];
        if(count == ind2) ind2el = a[i];
        count++;
        i++;
    }
    while(j<n2){
        if(count == ind1) ind1el = b[j];
        if(count == ind2) ind2el = b[j];
        count++;
        j++;
    }
    if(n%2 ==1){
        return ind2el;
    }
    else {
        return (double) ((double)(ind1el+ ind2el)) / 2.0;
    }
}

double Optimal(vector<int>&a,vector<int>&b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1>n2) return Optimal(b,a);
    int low =0, high = n1;
    int left = (n1+n2+1)/2;
    int n = n1+n2;
    while(low<=high){
        int mid1 = (low+high)>>1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX , r2 = INT_MAX;
        if(mid1<n1) r1 = a[mid1];
        if(mid2<n2) r2 = b[mid2];
        if(mid1-1 >=0) l1 = a[mid1-1];
        if(mid2-1 >=0) l2 = b[mid2-1];
        if(l1<=r2 && l2<=r1){
            if(n% 2 ==1) return max(l1,l2);
            else return ((double)(max(l1,l2)+ min(r1,r2))) / 2.0;
        }
        else if(l1>l2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}
int main(){
    vector<int> a = {1,3,4,7,10,12};
    vector<int> b = {2,3,6,15};
    //double result = medianOfTwoSortedArr(a,b);
    //double result = Better(a,b);
    double result = Optimal(a,b);
    cout<<result;
    return 0;
}