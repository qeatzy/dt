#include "utility.h"
// Maximum path sum I
// https://projecteuler.net/problem=18
// https://projecteuler.net/problem=67
// wget https://projecteuler.net/project/resources/p067_triangle.txt

int max_path_sum(std::vector<std::vector<int>> triangle) {
    std::vector<int> prev {triangle[0]};
    for (size_t i = 1; i < triangle.size(); ++i) {
        // print(prev);
        // wait();
        auto curr{triangle[i]};
        curr[0] += prev[0];
        for (size_t j = 1; j < i; ++j) {
            curr[j] += std::max(prev[j-1], prev[j]);
        }
        curr.back() += prev.back();
        curr.swap(prev);
    }
    return *std::max_element(prev.begin(), prev.end());
}

std::vector<std::vector<int>> read_triangle(std::string filename) {
    std::ifstream ifs {filename};
    std::vector<std::vector<int>> triangle;
    for (std::string line; std::getline(ifs, line); ) {
        std::istringstream iss {line};
        std::vector<int> row;
        for (int x; iss >> x; ) {
            row.push_back(x);
        }
        triangle.push_back(row);
    }
    return triangle;
}


int main() {
std::vector<std::vector<int>> triangle = {{75},
{95,64},
{17,47,82},
{18,35,87,10},
{20,04,82,47,65},
{19,01,23,75,03,34},
{88,02,77,73,07,63,67},
{99,65,04,28,06,16,70,92},
{41,41,26,56,83,40,80,70,33},
{41,48,72,33,47,32,37,16,94,29},
{53,71,44,65,25,43,91,52,97,51,14},
{70,11,33,28,77,73,17,78,39,68,17,57},
{91,71,52,38,17,14,91,43,58,50,27,29,48},
{63,66,04,68,89,53,67,30,73,16,69,87,40,31},
{04,62,98,27,23,9,70,98,73,93,38,53,60,04,23}};
// auto triangle2 = read_triangle("p067_triangle.txt");
// int res = max_path_sum(triangle2);
int res = max_path_sum(triangle);
// int res = max_path_sum(vector<iVec>{{3},{7,4},{2,4,6},{8,5,9,3}});
cout << res;
}
