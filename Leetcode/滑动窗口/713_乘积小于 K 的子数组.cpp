/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if(k <= 1){
                return 0;
            }
            int mul = 1, left = 0,right = 0,n = nums.size();
            int ans = 0;

            for(right = 0;right<n;right++){
                mul *= nums[right];

                while(mul>=k){ //不满足要求，将左端点右移
                    mul /= nums[left];
                    left++;
                }
                ans += right-left+1 ; //依旧举例，带入特殊值。
            }
            return ans;
        }
    };
/*
整体的思路是：
先右端点向右移动窗口，然后再左端点向右移动使数组尽量最小
*/