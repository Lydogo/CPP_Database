#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s)
        {
            int left = 0;
            int right = s.size()-1;
            while(left < right)
            {
                if (!isalnum((s[left])))
                {
                    left++;
                }
                else if (!isalnum((s[right])))
                {
                    right--;
                }
                else if (towlower((s[left])) == towlower((s[right])))
                {
                    left++;
                    right--;
                }
                else
                {
                    return false;
                }
            } 
        return true;
        }
    };