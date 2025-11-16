#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            int c = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == nums[j])
                    c++;
                else
                    break;
            }
            nums.erase(nums.begin() + i + 1, nums.begin() + c);
        }
        return nums.size();
    }
};