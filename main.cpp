#include "solutions/1444.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    auto g = Utils::getNewVector<string>({"A..","AAA","..."});
    auto answer = Solution().ways(g, 3);
    Utils::print(answer);
    return 0;
}