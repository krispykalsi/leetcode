#include "solutions/887.cpp"
#include "utils.cpp"

using namespace std;

int main() {
    auto g = Utils::getNewGrid<int>({{1, 0}});
    auto answer = Solution().superEggDrop(2, 6);
    Utils::print(answer);
    return 0;
}