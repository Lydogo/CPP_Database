#include<iostream>
#include<string>
#include<vector>
#include<ranges>
using namespace std;

//三元组的顺序并不重要，那么就转化为有序数组，再转化为两数之和
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            ranges::sort(nums);
            vector<vector<int>> ans;
            /*
            4. 为什么需要这样定义
            因为题目要求返回所有不重复的三元组，每个三元组包含3个整数，所以需要：
            一个容器存储所有三元组（外层 vector）
            每个三元组本身也是一个容器（内层 vector<int>）
            */
            int n = nums.size();

            for(int i=0;i<n-2;i++){
                int x = nums[i];
                if(i>0 && x == nums[i-1]) continue;
                if(x+nums[i+1]+nums[i+2]>0) break;  //优化1：如果x和最小的两个数加起来大于0，没有比这还小的了，后面的肯定都大于0，可以直接跳出循环
                if(x+nums[n-2]+nums[n-1]<0) continue;//优化2：如果x和最大的两个数加起来小于0，那么可以直接右移，去检查下一个x

                int j=i+1,k=n-1;
                while(j<k){
                    int s =x+nums[j]+nums[k];
                    if (s>0){
                        k--;
                    }
                    else if(s<0){
                        j++;
                    }
                    else{
                        ans.push_back({x,nums[j],nums[k]}); //c++中使用push_back 将三元组存入结果中
                        for (j++;j < k && nums[j] == nums[j - 1];j++);
                        for (k--;k > j && nums[k] == nums[k + 1];k--);
                        /*等效于以下这段
                        j++;  // 先移动
                        while (j < k && nums[j] == nums[j - 1]) { 
                            j++;  // 跳过重复
                        }

                        k--;  // 先移动
                        while (k > j && nums[k] == nums[k + 1]) {
                            k--;  // 跳过重复
                        }
                        */
                    }
                }
            }
            return ans;

        }
    };