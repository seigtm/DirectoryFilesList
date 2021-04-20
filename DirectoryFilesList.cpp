#include <iostream>
#include <string>
#include <filesystem> // Don't forget about -std=c++17 flag.

namespace fs = std::filesystem;

// Returns a vector of file name strings in some directory with some extension.
std::vector<std::string> getDirectoryFiles(const fs::path &directory = fs::current_path(),
                                           const std::vector<std::string> extension = {})
{
    // List of file names.
    std::vector<std::string> files{};

    for (const auto &file : fs::recursive_directory_iterator(directory))
    {
        if (fs::is_regular_file(file))
        {
            if (extension.empty() ||
                std::find(extension.begin(), extension.end(), file.path().extension().string()) != (extension.end()))
            {
                files.push_back(file.path().filename().string());
            }
        }
    }
    return files;
}

int main()
{
    auto fileList = getDirectoryFiles(fs::current_path(), {".exe"});

    std::cout << "List of files in the current directory:" << std::endl;
    for (const auto &fileName : fileList)
    {
        std::cout << '\t' << fileName << std::endl;
    }
    std::cout << "The number of files in the current directory: " << fileList.size() << std::endl;
}
