/*
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。
*/

#include<iostream>
#include<vector>
#include<ranges>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> charCount;

            for(char x:magazine){
                charCount[x]++;
            }

            for(char x:ransomNote){
                int a = charCount[x]--;
                if (a<=0){
                    return false;
                }
            }
            return true;
        }
    };