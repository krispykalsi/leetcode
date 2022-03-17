#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, int> memo;
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 1;
        }
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        if (s[0] != '0') {          
            auto ans = numDecodings(s.substr(1));
            if (s.size() > 1 && stoi(s.substr(0, 2)) < 27) {
                ans += numDecodings(s.substr(2));
            }
            memo[s] = ans;
            return ans;
        } else {
            memo[s] = 0;
            return 0;
        }
    }
};