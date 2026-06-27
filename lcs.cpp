#include<iostream>
using namespace std;
void display(vector<vector<int>> &dp) {
    for(int i = 0 ; i < dp.size() ; i++) {
        for(int j = 0 ; j < dp[i].size() ; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

// int lcs_tabulation(string &a,string &b) {
//     vector<vector<int>> dp(a.size() + 1,vector<int>(b.size() + 1,-1));
//     for(int i = 0 ; i <= a.size() ; i++) {
//         for(int j = 0 ; j <= b.size() ; j++) {
//             if(i == 0 || j == 0) dp[i][j] = 0;
//             //dp[i][j] = ? we have to find
//             if(a[i-1] == b[j-1]) {
//                 dp[i][j] = 1 + dp[i-1][j-1];
//             }else {
//                 int op1 = dp[i-1][j];
//                 int op2 = dp[i][j-1];
//                 int op3 = dp[i-1][j-1];
//                 dp[i][j] = max({op1,op2,op3});
//             }
//         }
//     }
//     return dp[a.size()][b.size()];
// }

//Time complexity = O(m*n)
//Space Complexity = O(m*n)
int lcs_tabulation(string &a,string &b,int A,int B,vector<vector<int>> &dp) {
    for(int a_len = 0 ; a_len <= A ; a_len++) {
        for(int b_len = 0 ; b_len <= B ; b_len++) {
            if(a_len == 0 || b_len == 0) {
                dp[a_len][b_len] = 0;
                continue;
            }

            if(a[a_len-1] == b[b_len-1]) {
                return dp[a_len][b_len] = 1 + lcs(a,b,a_len-1,b_len-1,dp);
            }
            // int l1 = lcs(a,b,a_len-1,b_len,dp);
            int l1 = dp[a_len-1][b_len];
            // int l2 = lcs(a,b,a_len,b_len-1,dp);
            int l2 = dp[a_len][b_len-1];
            // int l3 = lcs(a,b,a_len-1,b_len-1,dp);
            int l3 = dp[a_len-1][b_len-1];
            dp[a_len][b_len] = max({l1,l2,l3});
        }
    }
    dp[A][B];
}


int lcs(string &a,string &b,int a_len,int b_len,vector<vector<int>> &dp) {
    //Base Case
    if(a_len == 0 || b_len == 0) {
        return dp[a_len][b_len] = 0;
    }

    if(dp[a_len][b_len] != -1) {
        return dp[a_len][b_len];
    }

    if(a[a_len-1] == b[b_len-1]) {
        return dp[a_len][b_len] = 1 + lcs(a,b,a_len-1,b_len-1,dp);
    }
    int l1 = lcs(a,b,a_len-1,b_len,dp);
    int l2 = lcs(a,b,a_len,b_len-1,dp);
    int l3 = lcs(a,b,a_len-1,b_len-1,dp);
    return dp[a_len][b_len] = max({l1,l2,l3});
}

int main() {
    string a = "abdefg",b = "aefpl";
    vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
    lcs(a,b,a.size(),b.size(),dp);
    display(dp);
}