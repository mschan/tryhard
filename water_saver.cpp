/// https://leetcode.com/problems/trapping-rain-water/
#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

using namespace std;

#define Debug(x) x

class Solution {
public:
    int trap(vector<int>& height) {
        int big_height = height[0];
        int big_height_pos = 0;
        int total_water = 0;
        int current_water = 0;
        for (size_t i = 1; i < height.size(); i++) {
            if (height[i] > big_height) {
                total_water += current_water;
                big_height = height[i];
                big_height_pos = i;
                current_water = 0;
            } else {
                current_water += big_height - height[i];
            }
            Debug( cout << i << ": " << current_water << ", " << total_water << ", " << height[i] << endl);

        }

        if (current_water) {
            Debug(cout << "some water left from " << big_height_pos << " running reverse" << endl);
            big_height = height[height.size() - 1];
            current_water = 0;
            for (size_t i = height.size() - 2; i > big_height_pos; i--) {
                if (height[i] > big_height) {
                    
                    total_water += current_water;
                    big_height = height[i];
                    current_water = 0;
                } else {
                    current_water += big_height - height[i];
                }
                Debug( cout << i << ": " << current_water << ", " << total_water << ", " << height[i] << endl);
            }
            total_water += current_water;
        }
        return total_water;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;
    std::vector<int> inputs{0,1,0,2,1,0,1,3,2,1,2,1};

    cout << sol.trap(inputs) << endl;
}