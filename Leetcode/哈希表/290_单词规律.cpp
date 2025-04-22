/*
给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
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
        bool wordPattern(string pattern, string s) {
            vector<string> words;
            stringstream ss(s);
            string word;
            while (ss >> word) { //每次读取一个单词（以空格分隔）
                words.push_back(word);
            }
            
            if (words.size() != pattern.length()) {
                return false;
            }
            unordered_map<char, string> c2s;
            unordered_map<string, char> s2c;

            for (int i = 0; i < words.size(); i++) {
                char c = pattern[i];   // 当前字符（如 'a'）
                string w = words[i];   // 当前单词（如 "dog"）
                
                // 检查字符 c 是否已经映射到另一个单词
                if (c2s.count(c)) {    // 如果 c 已经存在于 c2s
                    if (c2s[c] != w) { // 但它的映射不是当前单词 w
                        return false;  // 违反规则，返回 false
                    }
                }
                
                // 检查单词 w 是否已经映射到另一个字符
                if (s2c.count(w)) {    // 如果 w 已经存在于 s2c
                    if (s2c[w] != c) { // 但它的映射不是当前字符 c
                        return false;  // 违反规则，返回 false
                    }
                }
                
                // 如果没有冲突，建立双向映射
                c2s[c] = w;  // 记录 c → w
                s2c[w] = c;  // 记录 w → c
            }
            return true;

        }
    };