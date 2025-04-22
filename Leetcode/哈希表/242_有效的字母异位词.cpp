/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。
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
        bool isAnagram(string s, string t) {
            if(s.length() != t.length()){
                return false;
            }

            unordered_map <char,int> hash;

            for(char c:s){
                hash[c] += 1;
            }

            for(char c:t){
                hash[c] -=1;
            }

            for (auto k : hash) {
                if (k.second != 0)
                    return false;
            }
            return true;
        }
    };

    class Solution {
        public:
            bool isAnagram(string s, string t) {
                // 如果两个字符串长度不同，直接返回false
                if (s.size() != t.size()) {
                    return false;
                }
        
                // 使用数组代替哈希表，因为字母只有26个小写字母
                // 初始化为0，用于统计每个字母出现的次数
                int count[26] = {0};
        
                // 统计字符串s中每个字母的出现次数
                for (char c : s) {
                    count[c - 'a']++; // 'a'对应0，'b'对应1，...，'z'对应25
                }
        
                // 检查字符串t中的字母
                for (char c : t) {
                    count[c - 'a']--; // 对应字母的计数减1
                    // 如果某个字母的计数变为负数，说明t中该字母比s中多
                    if (count[c - 'a'] < 0) {
                        return false;
                    }
                }
        
                // 如果所有字母的计数都为0，返回true
                return true;
            }
        };