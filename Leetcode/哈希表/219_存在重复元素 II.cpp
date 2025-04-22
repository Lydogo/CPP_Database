/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 使用哈希表存储元素值及其最近出现的索引
        unordered_map<int, int> mp; // key: 元素值, value: 最近出现的索引
        int n = nums.size(); // 数组长度

        // 遍历数组中的每个元素
        for(int i = 0; i < n; i++){
            // 检查当前元素是否已经在哈希表中存在
            if(mp.find(nums[i]) != mp.end()) {
                // 如果存在，说明之前有相同的元素，且它们的索引差一定 <= k（因为超过k的已经被移除）
                return true;
            }
            // 将当前元素及其索引存入哈希表
            mp[nums[i]] = i;

            // 维护哈希表的大小不超过k，确保只保留最近k个元素的索引
            if(mp.size() > k){
                // 移除最早加入的元素（即当前窗口之外的元素）
                mp.erase(nums[i - k]);
            }
        }
        // 遍历结束，没有找到满足条件的索引对，返回false
        return false;
    }
};