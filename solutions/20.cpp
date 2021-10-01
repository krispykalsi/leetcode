//
// Created by Ikroop Singh Kalsi on 10/1/2021.
//
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        for (auto &bracket: s) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                brackets.push(bracket);
            } else {
                if (brackets.empty()) {
                    return false;
                }
                auto openingBracket = brackets.top();
                brackets.pop();
                if (bracket == ')' && openingBracket != '(' ||
                    bracket == ']' && openingBracket != '[' ||
                    bracket == '}' && openingBracket != '{')
                {
                    return false;
                }
            }
        }

        if (!brackets.empty())
            return false;
        else
            return true;
    }
};