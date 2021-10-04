#include "solutions/463.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    auto g = Utils::getNewGrid<int>({{1, 0}});
    auto answer = Solution().islandPerimeter(g);
    Utils::print(answer);
    return 0;
}