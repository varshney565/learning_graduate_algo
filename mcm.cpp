#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int> &arr,int start,int end,vector<vector<int>> &dp) {
    if(start + 1 == end) {
        return dp[start][end] = 0;
    }
    if(dp[start][end] != -1) return dp[start][end];
    int ans = INFINITY;
    for(int cut = start + 1 ; cut < end ; cut++) {
        int value_left = helper(arr,start,cut,dp);
        int value_right = helper(arr,cut,end,dp);
        int value = arr[start]*arr[cut]*arr[end] + value_left + value_right; 
        if (value < ans) {
            ans = value;
        }
    }
    return dp[start][end] = ans;
}

int mcm(vector<int> &arr) {
    vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
    return helper(arr,0,arr.size()-1,dp);
}

int main() {
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++) cin>>arr[i];

   int ans = mcm(arr);
   cout<<ans<<"\n";
}