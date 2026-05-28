#include<iostream>
#include<vector>
using namespace std;

void display(vector<int> &v) {
    for(auto x : v) cout<<x<<" ";
    cout<<"\n";
}
//Time Complexity = O(n)
//Space complexity = O(n)
int fibonacci(int n,vector<int>& dp) {
    if(n <= 1) return dp[n] = n; //Base Case
    if(dp[n] != -1) return dp[n];
    int ans = fibonacci(n-1,dp) + fibonacci(n-2,dp);
    return dp[n] = ans;
}


//Time Complexity = O(n)
//Space complexity = O(n)
int fibonacci_tab(int N,vector<int>& dp) {
    //===> n 
    for(int n = 0 ; n <= N ; n++) {
        if(n <= 1)  {
            dp[n] = n;
            continue;
        }
        // if(dp[n] != -1) return dp[n];
        int ans = dp[n-1] + dp[n-2];
        dp[n] = ans;
    }
}


//Optimization
//Time complexity = O(n)
//Space complexity = O(1)



//Matrix Exponantiation = O(logn) 

int main() {
    int n = 10;
    vector<int> dp(n+1,-1);
    int ans = fibonacci(n,dp);
    display(dp);
    std::cout<<ans<<"\n";
}