#include <bits\stdc++.h>
using namespace std; 
class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());  // step 1
            int n = nums.size();
            int ans = 1;
    
            for (int i = 0; i < n; i++) {
                int target = nums[i];
                long long cost = 0;
                int count = 1; // at least nums[i] itself
    
                // try to make previous numbers equal to target
                for (int j = i - 1; j >= 0; j--) {
                    cost += target - nums[j];
                    if (cost <= k) {
                        count++;
                    } else break; // too costly, stop
                }
    
                ans = max(ans, count);
            }
    
            return ans;
        }
    };