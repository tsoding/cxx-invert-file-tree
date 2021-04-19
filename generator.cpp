#include <cstdlib>
#include <ctime>

#include <ostream>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "./fruits.hpp"

namespace fs = std::filesystem;

void usage(std::ostream &os)
{
    os << "Usage: ./generator <folder-path>" << std::endl;
}

int rand_int_range(int low, int high)
{
    return low + rand() % (high - low + 1);
}

const size_t DEPTH_CAPACITY = 5;

void generate_tree(const fs::path &root, size_t depth = 0)
{
    if (depth < DEPTH_CAPACITY) {
        int n = rand_int_range(3, 5);

        for (int i = 0; i < n; ++i) {
            const auto child_path = root / (random_fruit() + "-" + std::to_string(i));

            if (rand() % 2) {
                std::cout << "Created Folder: " << child_path << std::endl;
                fs::create_directory(child_path);
                generate_tree(child_path, depth + 1);
            } else {
                std::cout << "Created File: " << child_path << std::endl;
                std::ofstream fout(child_path);

                int words_count = rand_int_range(20, 30);
                while (words_count-- > 0) {
                    fout << random_fruit() << std::endl;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(std::cerr);
        std::cerr << "ERROR: folder path is not provided" << std::endl;
        return 1;
    }

    srand(time(nullptr));

    fs::path folder_path(argv[1]);
    fs::create_directory(folder_path);
    std::cout << "Created Folder: " << folder_path << std::endl;
    generate_tree(folder_path);

    return 0;
}
