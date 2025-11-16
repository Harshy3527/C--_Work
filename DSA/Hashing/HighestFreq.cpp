#include <bits\stdc++.h>
using namespace std; 

class Solution {
    public:
        int mostFrequentElement(vector<int>& nums) {
            map<int, int> freq;  // element -> frequency
    
            // Count frequencies
            for (int x : nums) {
                freq[x]++;
            }
    
            int maxFreq = 0;
            int ans = INT_MAX; // store smallest element in case of tie
    
            // Loop over map
            for (auto &entry : freq) {
                if (entry.second > maxFreq) {
                    maxFreq = entry.second;
                    ans = entry.first;
                } else if (entry.second == maxFreq && entry.first < ans) {
                    ans = entry.first;
                }
            }
    
            return ans;
        }
    };
    