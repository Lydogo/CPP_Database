/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
你可以按任意顺序返回答案。
*/

#include<iostream>
#include<vector>
#include<ranges>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> prevNums;

            for (int i = 0; i < nums.size(); i++) {
                int curNum = nums[i];
                int targetNum = target - curNum;
                
                /*
                在 C++ 中，prevNums.end() 返回的是 指向哈希表（unordered_map）末尾的迭代器，
                它表示的是一个 “超出末尾”的位置（类似于 nullptr 的概念），并不指向任何有效元素。
                */

                if (prevNums.find(targetNum) != prevNums.end()) { // 检查目标数字是否存在
                    return {prevNums[targetNum], i}; // 返回找到的索引对
                } else {
                    prevNums[curNum] = i; // 记录当前数字和索引
                }
            }
        
            return {}; // 如果没有解，返回空向量（根据题目假设总是有解，这行不会执行）
        }
    };