#include<iostream>
#include<vector>
using namespace std;

//HW1 : LDS
//HW2 : number of Longest Increasing subsequences.
//HW3 : print all Longest Increasing subsequences.
//HW4 : Longest Bitonic subsequnece
//HW5 : 354. Russian Doll Envelopes

// int lis(vector<int>& arr,int end,vector<int> &dp) {
//     int ans = 1;
//     if(dp[end] != -1) return dp[end];
//     for(int ind = end-1 ; ind >= 0 ; ind--) {
//         if(arr[ind] < arr[end]) {
//             ans = max(ans,1+lis(arr,ind,dp));
//         }
//     }
//     return dp[end] = ans;
// }

// Time Complexity = O(n*n)
// Space Complexity = O(n)
int lis(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n,-1);
    int len1 = 0;
    for(int i = 0 ; i < n ; i++) {
        int len2 = 0;
        for(int end = i - 1 ; end >= 0 ; end--) {
            if(arr[end] < arr[i]) {
                len2 = max(dp[end]+1,len2); 
            }
        }
        //......[i] 
        dp[i] = len2;
        len1 = max(len1,dp[i]);
    }
}

int main() {

}

// int main() {
//     vector<int> arr = {1,2,3,4,10,2};
//     int ans = 0;
//     vector<int> dp(arr.size(),-1);
//     for(int i = 0 ; i < arr.size() ; i++) {
//         ans = max(ans,lis(arr,i,dp));
//     }
// }