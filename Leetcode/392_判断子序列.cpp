#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t)
        {
            int i =0;
            int j =0;

            while(i < s.size() && j < t.size())
            {
                if(s[i]==t[j])
                {
                    i++;
                }
                j++;
            }
            return i == s.size();  //这里的判断条件不是i==size()-1
        }
    };

/*
你可能把 i 想象成数组索引（从0开始），但实际上：

i 的初始值是0（尚未匹配任何字符）

每次成功匹配后 i++

所以 i 的值实际上是"已匹配的字符数"
*/
