/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
*/

#include<iostream>
#include<vector>
#include<ranges>
using namespace std;

class Solution {
    int lower_bound(vector<int>& nums, int target) {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right) { // 区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2; //防止溢出
            if (nums[mid] >= target) {
                right = mid; // 范围缩小到 (left, mid)
            } 
            else {
                left = mid; // 范围缩小到 (mid, right)
            }
        }
        // 循环结束后 left+1 = right
        // 此时 nums[left] < target 而 nums[right] >= target
        // 所以 right 就是第一个 >= target 的元素下标
        return right;
    }
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int start = lower_bound(nums,target);
            if (start == nums.size() || nums[start] !=target){
                return {-1,-1};
            }

            int end = lower_bound(nums,target+1)-1;
            return{start,end};
        }
    };


    //也可以直接使用库函数 ranges::lower_bound和ranges::upper_bound
    class Solution {
        public:
            vector<int> searchRange(vector<int>& nums, int target) {
                int start = ranges::lower_bound(nums, target) - nums.begin();
                if (start == nums.size() || nums[start] != target) {
                    return {-1, -1};
                }
                int end = ranges::upper_bound(nums, target) - nums.begin() - 1;
                return {start, end};
            }
        };
        