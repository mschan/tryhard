#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(0==x) {
            return true;
        }
        
        std::vector<int> digits;
        while(x) {
            auto reminder = x%10;
            digits.push_back(reminder);
            cout << reminder;
            x = x/10;
        }
        auto num_digits = digits.size();
        cout << "num_digits:" << num_digits << endl;
        for (int i = 0 ; i < num_digits/2; i++) {
            cout << i << "\t" << digits[i] <<"\t" << digits[num_digits-i - 1] <<endl;
            if (digits[i] != digits[num_digits-i - 1]) {
                return false;
            }
        }
        return true;
    }
};
int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;
    cout<< sol.isPalindrome(121) << endl;
}