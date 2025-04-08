#include<iostream>
#include<string>
#include<vector>
#include<ranges>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int L=0,R=height.size()-1;
            int ans,area = 0;
            while(L<R){
                area = min(height[L],height[R])*(R-L);
                ans = max(ans,area);
    
                if(height[L]<height[R]){
                    // height[L] 与右边的任意线段都无法组成一个比 ans 更大的面积
                    L++;
                }
                else{
                    // height[R] 与左边的任意线段都无法组成一个比 ans 更大的面积
                    R--;
                }
            }
            return ans;
        }
    };