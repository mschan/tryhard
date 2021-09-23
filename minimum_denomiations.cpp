/**
Q. Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
 */

 /// Status : complete

#include <ios>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDemoninations(const std::vector<int>& denominations, unsigned target) {
        // Assuming given denominations is in increasing order.
        auto original = target;
        using Den = std::pair<unsigned, unsigned>;
        std::vector<Den> sum;
        for (int i = denominations.size()-1; i >= 0; i--) {
            int currentDonomination = denominations[i];
            if (target < currentDonomination) {
                continue;
            }
            int c = target / denominations[i];
            target = target % denominations[i];
            sum.emplace_back(currentDonomination, c);
        }

        unsigned s = 0;
        unsigned total_denominations = 0;
        for (auto& d: sum) {
            s += d.first * d.second;
            total_denominations += d.second;
            cout << "[" << d.first << "," << d.second /*<< "," << s */ << "], ";
        }

        cout << endl;
        assert (s == original);

        return total_denominations;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;

    std::vector<int> denominaions {1, 5, 10, 25};
    cout<< boolalpha << sol.minDemoninations(denominaions, 17) << endl;
}