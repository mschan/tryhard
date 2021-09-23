#include <ios>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(std::string s) {
        size_t size = s.size();
        
        for (size_t i=0, j=size-1; i < size/2; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;

    }
    
    string longestPalindrome(string s) {
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;
    cout<< boolalpha << sol.isPalindrome("ABCBA") << endl;
}