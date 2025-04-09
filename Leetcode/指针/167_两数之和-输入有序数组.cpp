#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            int i = 0;
            int j = numbers.size()-1;
            while(numbers[i]+numbers[j] != target)
            {
                if(numbers[i]+numbers[j] < target)
                {   
                    i++;
                }
                else if(numbers[i]+numbers[j] > target)
                {
                    j--;
                }
                else
                {
                    continue;
                }
            }
    
            return {i+1,j+1};
            
        }
    };



/*
利用有序排列这个特性

最小的数和最大的数相加：
如果大于target
那么最大的数和数组中其他数相加肯定都大于target
那么可以删掉最大的数（右指针向左移动）

如果小于target
那么最小的数和数组其他数相加肯定都小于target
那么可以删掉最小的数（左指针向有移动）
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
            
        while(i < j) {
            int s = numbers[i]+numbers[j];
            if(s == target){   
                return {i+1,j+1};
            }
            s > target ? j-- :i++;
        }
        return {};
    }
};