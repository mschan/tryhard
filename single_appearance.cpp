/**

Q. Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.
**/
/// Status: complete.

#include <ios>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    pair<int, int> findNoDups(const std::vector<int>& l) {
        std::set<int> noDups;
        for (auto e : l) {
            bool inserted;
            tie(ignore, inserted) = noDups.insert(e);
            if (!inserted) {
                noDups.erase(e);
            }
        }
        assert(2 == noDups.size());
        return {*noDups.begin(), *(++noDups.begin())};
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;

    std::vector<int> dups {2, 4, 6, 8, 10, 2, 6, 10};
    auto nodupPair = sol.findNoDups(dups);
    cout<< boolalpha << nodupPair.first << " " << nodupPair.second << endl;
}