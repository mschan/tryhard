#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int negitive = x<0 ? -1 : 1;
        x = x * negitive;
        std::vector<int> digits;     
        uint32_t ret = 0;
        uint32_t position = 1;
        while (x) {
            int reminder = x % 10;
            x = x/10;
            // ret += reminder * position;

            // position *= 10;
            digits.push_back(reminder);
        }
        if(digits.empty()) {
            return 0;
        }

        auto size = digits.size();
        constexpr const uint32_t maxby10 = std::numeric_limits<decltype(x)>::max() / 10;

        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            uint32_t val = position * (*it);
            if (std::numeric_limits<int>::max() < val || ) {
                return 0;
            }
            if (std::numeric_limits<int>::max() - ret < val) {
                
            }
            if(maxby10 < val) {
                cout << maxby10 << "\t is less than \t" << position << "returning \n";
                return 0;
            }
            cout << val << "\t" << position << "\t";
            ret += position * (*it);
            position *= 10;
            cout << ret << "\n";

        }

        return ret * negitive;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << std::numeric_limits<int>::max() << endl;
    cout<< sol.reverse(-2147483412);
}