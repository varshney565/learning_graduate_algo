#include<iostream>
#include<vector>
using namespace std;

int unbounded_knapsack(vector<int>& values,vector<int>& weights,int capacity,vector<int> &dp) {
    int final = 0;
    for(int i = 0 ;  i < values.size() ; i++) {
        if(weights[i] <= capacity) {
            int smallAns = unbounded_knapsack(values,weights,capacity - weights[i],dp);
            int ans = smallAns + values[i];
            final = max(final,ans);
        }
    }
    return final;
}

int main() {
    int cap;
    cin>>cap;
    int n;
    cin>>n;
    vector<int> values(n),weights(n);
    for(int i = 0 ; i < n ; i++) {
        cin>>values[i];
    }
    for(int i = 0 ; i < n ; i++) {
        cin>>weights[i];
    }


    int ans = unbounded_knapsack(values,weights,cap);
    cout<<ans<<"\n";
}