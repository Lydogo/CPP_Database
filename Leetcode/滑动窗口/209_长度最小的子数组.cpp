/*
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其总和大于等于 target 的长度最小的子数组
[numsl, numsl+1, ..., numsr-1, numsr]，并返回其长度。
如果不存在符合条件的子数组，返回 0 。
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int sum = 0, left = 0,right = 0,n = nums.size();
            int ans = n+1;

            for(right = 0;right<n;right++){
                sum += nums[right];
                while(sum - nums[left]>=target){
                    sum -=nums[left];
                    left++;
                }

                if (sum >=target){
                    ans = min(ans,right-left+1); 
                    /*
                    这里之所以要加1，可以举特殊例子，比如当数组长度只有1时，left=right
                    应该输出1，因此return：right-letf+1
                    */
                }

                return ans<=n ? ans : 0;
            }
        }
    };
/*
整体的思路是：
先右端点向右移动窗口，然后再左端点向右移动使数组尽量最小
*/