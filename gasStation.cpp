#include<bits/stdc++.h>
using namespace std;
// This code will give Time Limit Error(TLE).... So we have to optimize.
long double gasStation(vector<int>& arr,int k){
    int n =arr.size();
    vector<int> howMany(n-1,0);
    for(int gasStations =0; gasStations<=k; gasStations++){
        long double maxSections = -1;
        int maxInd = -1;
        for(int i =0; i<n-1; i++){
            long double diff = arr[i+1] - arr[i];
            long double sectionLength = diff/(long double)(howMany[i]+1);
            if(sectionLength>maxSections){
                maxSections = sectionLength;
                maxInd =i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for(int i =0; i<n-1; i++){
        long double diff = arr[i+1] - arr[i];
        long double sectionLength = diff/(long double)(howMany[i]+1);
        maxAns = max(maxAns,sectionLength);
    }
    return maxAns;
}
long double BetterSol(vector<int>& arr,int k){
    int n = arr.size();
    vector<int> howMany(n-1,0);
    priority_queue<pair<long double , int>> pq;
    for(int i =0; i<n-1; i++){
        pq.push({arr[i+1]-arr[i],i});
    }
    for(int gasStations =0; gasStations<=k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double neweSecLen = iniDiff/(long double)(howMany[secInd]+1);
        pq.push({neweSecLen,secInd});
    }
    return pq.top().first;
}


int noOfGasStationsReq(vector<int>&arr,int dist){
    int cnt =0;
    for(int i=1; i<arr.size(); i++){
        int numberInBetween = ((arr[i]-arr[i-1])/dist);
        if((arr[i]-arr[i-1])/dist == numberInBetween*dist){
            numberInBetween--;
        }
        cnt = cnt + numberInBetween;
    }
    return cnt;
}
long long BinarySearch(vector<int>&arr, int k){
    int n = arr.size();
    long double low =0;
    long double high =0;
    for(int i=0; i<n-1; i++){
        high = max(high, (long double)(arr[i+1]- arr[i]));
    }
    long double diff = 1e-6;
    while(high-low>diff){
        long double mid = (low +high)/(2.0);
        int cnt = noOfGasStationsReq(arr,mid);
        if(cnt>k) low = mid;
        else high = mid;
    }
    return high;
}




int main(){
    vector<int> arr = {1,13,17,23};
    int k;
    cin>>k;
    //long double result = gasStation(arr,k);
    //long double result = BetterSol(arr,k);
    long double result = BinarySearch(arr,k);
    cout<<result;
    return 0;
}