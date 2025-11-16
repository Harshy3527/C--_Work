#include <bits/stdc++.h>
using namespace std; 
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            set<int> st(nums.begin(), nums.end());
            nums.assign(st.begin(), st.end());
            return nums.size();
        }
    };
    