#include "solutions/1143.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    auto answer = Solution().longestCommonSubsequence("oxcpqrsvwf", "shmtulqrypy");
    Utils::print(answer);
    return 0;
}