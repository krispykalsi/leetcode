#include "solutions/639.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    auto s = "1*";
    auto answer = Solution().numDecodings(s);
    Utils::print(answer);
    return 0;
}