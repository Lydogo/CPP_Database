/*
给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int n = s.length(),ans = 0,left = 0,right = 0;
            unordered_map<char , int > cnt; //记录当前窗口中每个字符的出现次数

            for(right;right<n;right++){
                cnt[s[right]]++; //将字符c再哈希表中对应的值加1

                while(cnt[s[right]]>1){  //如果 cnt[s[right]] > 1，说明 s[right] 重复了，需要收缩窗口：
                    cnt[s[left]]--;
                    left ++;
                }
                ans = max(ans,right-left+1);
            }
            return ans;
        }
    };
/*
整体的思路是：
先右端点向右移动窗口，然后再左端点向右移动使数组尽量最小

维护一个不包含重复字符的窗口，并在遍历字符串时动态调整窗口的左右边界。
*/