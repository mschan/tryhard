#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>
#include <map>

#define LOGEnable(x) x
// #define LOGEnable(x) 

using namespace std;

#if 0
class Solution {
public:
    using Pos = pair<size_t, size_t>;
    map<Pos, bool> palindromeMap;
    
    bool isPalindrome(string s) {
        for(int i = 0; i < s.size()/2 - 1; i++) {
            if (s[i] != s[s.size() - 1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome_cached(string s, size_t start, size_t len) {
       LOGEnable(cout << boolalpha <<  s.substr(start, len)) << " " << start << " " << len;
        if (len == 2) {
       LOGEnable(cout << boolalpha << "\t" << (s[start] == s[start + 1]) << endl);
            return (s[start] == s[start + 1]);
        } else  if (len == 3) {
       LOGEnable(cout << boolalpha << "\t" << (s[start] == s[start + 2]) << endl);
            return s[start] == s[start + 2];
        }
        if (palindromeMap.end() != palindromeMap.find({start + 1, len - 2})) {
            if (s[start] == s[start + len - 1]) {
                LOGEnable(cout << boolalpha << "\t" << true << endl);
                return true;
            }
        } else {
            cout << s.substr(start + 1, len - 2) << "is not palindrome";
        }
        
       LOGEnable(cout << boolalpha << "\t" << false << endl);
        return false;
    }
    
    int countSubstrings(string s) {
        palindromeMap.clear();
        size_t c = s.size(); // Single letters are always palindrome.
        size_t letterCount = 2;
        const size_t size = s.size();
        // Generate all palindromes and check
        for (letterCount = 2; letterCount <= size; letterCount++) {
            for (size_t i = 0; i <= size - letterCount ; i++) {
                if (isPalindrome_cached(s, i, letterCount)) {
                    Pos pos{i, letterCount};
                    palindromeMap[pos] = true;
                }
            }
        }
        auto total = c + palindromeMap.size();
        palindromeMap.clear();
        assert(0 == palindromeMap.size());
        return total;
    }
};
#else
class Solution {
    public:
     int countSubstrings(string s) {
        const size_t size = s.size();
        bool dp[size][size] = {0};
        size_t count = 0;

        // dp[i][j] represents if s.substr(i, j-i) is palindrome
        dp[0][0] = true;
        for (int i=1; i<size; i++) {
            dp[i][i] = true;
            dp[i-1][i] =  (s[i-1] == s[i]);
        }

        for (size_t letterCount = 3; letterCount <= size; letterCount++) {
            for (size_t i = 0; i <= size - letterCount; i++) {
                dp[i][i+letterCount] = dp[]
            }
        }

        return count;
     }
};
#endif
int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;
    // std::vector<string> inputs{"abc", "aaa", "baas", "abc", "aaaaa"};
    std::vector<string> inputs{"aaaaa"};

    for (auto& s : inputs) {
        cout << s << " : " << sol.countSubstrings(s) << endl;
    }
}