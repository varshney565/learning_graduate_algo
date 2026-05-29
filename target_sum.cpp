//Target Sum

// arr = [10,20,21,24,29]


// arr = [10,20,21,24,29]
// target = 29

//10,20,21,24,29 ===> 10,20,21,24

// target = 80

//Q : Given an array and target => tell target achievable or not ??

// answer = yes


//0-1 Knapsack
//bounded
//unbounded

//MCM

//array target can be neagitive 
//array elements are positive

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


//neagitive target => return false
//target zero => 
#include<vector>
#include<iostream>
using namespace std;
bool target_sum(vector<int> &arr,int target,int len) {
    //target = 80
    //Base Case
    if(target == 0) return true;
    if(len == 0) return false;

    //pick
    if(arr[len-1] <= target) {
        int new_target = target - arr[len-1]; //80 => 51
        int new_len = len-1;
        bool res = target_sum(arr,new_target,new_len); //pick
        if (res == true) {
           return true; 
        }
    }
    return target_sum(arr,target,len-1);
}


//1 2 3 4 5
//target = 0


// weights = [110,20,30,23,25] 
// val = [1,2,3,4,50]

// max_cap = 90