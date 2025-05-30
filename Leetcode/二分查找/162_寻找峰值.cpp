/*
峰值元素是指其值严格大于左右相邻值的元素。

给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
*/

#include<iostream>
#include<vector>
#include<ranges>
using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int n = nums.size();
            int left = -1;
            int right = n-1;

            while(left+1<right){
                int mid = left + (right - left)/2; //防溢出

                if(nums[mid]>nums[mid-1]){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            return right;
        }
    };
        