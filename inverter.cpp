#include <cstdio>
#include <iostream>
#include <ostream>
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

void usage(std::ostream &os)
{
    os << "Usage: ./inverter <folder-path>" << std::endl;
}

fs::path free_file_name(const fs::path &root)
{
    std::string prefix = "_";
    int counter = 0;

    while (fs::exists(root / (prefix + std::to_string(counter)))) {
        counter++;
    }

    return root / (prefix + std::to_string(counter));
}

void invert_folder(const fs::path &root)
{
    std::vector<fs::path> children;
    for (auto &child : fs::directory_iterator(root)) {
        children.push_back(child);
    }
    std::sort(children.begin(), children.end());

    for (const auto &child: children) {
        if (fs::is_directory(child)) {
            invert_folder(child);
        }
    }

    const fs::path tmp = free_file_name(root);

    for (size_t i = 0; i < children.size() / 2; ++i) {
        const auto a = children[i];
        const auto b = children[children.size() - i - 1];
        std::cout << a << " <-> " << b << std::endl;
        fs::rename(a, tmp);
        fs::rename(b, a);
        fs::rename(tmp, b);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        usage(std::cerr);
        std::cerr << "ERROR: folder path is not provided" << std::endl;
        return 1;
    }

    fs::path folder_path(argv[1]);
    invert_folder(folder_path);

    return 0;
}
