#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>
#include <map>

using namespace std;
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
        cout << boolalpha <<  s.substr(start, len);
        if (len == 2) {
            cout << boolalpha << "\t" << (s[start] == s[start + 1]) << endl;
            return (s[start] == s[start + 1]);
        } else  if (len == 3) {
            cout << boolalpha << "\t" << (s[start] == s[start + 2]) << endl;
            return s[start] == s[start + 2];
        }
        if (palindromeMap.end() != palindromeMap.find({start + 1, len - 2})) {
            if (s[start] == s[start + len]) {
                cout << boolalpha << "\t" << true << endl;
                return true;
            }
        }
        
        cout << boolalpha << "\t" << false << endl;
        return false;
    }
    
    int countSubstrings(string s) {
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
        return c + palindromeMap.size();
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    // cout << std::numeric_limits<int>::max() << endl;
    cout<< sol.countSubstrings("abc") << endl;
}