//88.合并两个有序数组
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = nums1.size() - 1;
            int a = m-1;
            int b = n-1;
            while(b>=0)
            {
                if (a>=0 && nums1[a]>nums2[b])
                {
                    nums1[i--] = nums1[a--]; // 如果 nums1[a] 更大，将其放到 nums1[i]
                }
                else
                {
                    nums1[i--] = nums2[b--]; // 否则将 nums2[b] 放到 nums1[i]
                }
            }
        }
    };

int main()
{
    std::vector<int> v1 = {1, 2, 3, 0, 0, 0}; // 初始化v1
    std::vector<int> v2 = {2, 5, 6};          // 初始化v2
    
    Solution solution; // 创建 Solution 类的对象
    solution.merge(v1, 3, v2, 3); // 调用 merge 方法，合并 v1 和 v2

    // 输出合并后的 v1
    for (int num : v1)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
    

    