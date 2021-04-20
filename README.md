# List files in a directory C++ function.
Implementation of the C++ function that returns a list of files in a certain directory by a given mask (file extension).  
``` cpp
// Returns a vector of file name strings in some directory with some extension.
std::vector<std::string> getDirectoryFiles(const fs::path &directory = fs::current_path(),
                                           const std::vector<std::string> extensions = {})
```
It's my homework task on the subject "Information security".   
## Usage examples:
> Returns the list of the names of all files in the current directory.
``` cpp
auto fileList = getDirectoryFiles();
```
> Returns the list of the names of all files in the current directory with the "*.exe" extension.
``` cpp
auto fileList = getDirectoryFiles(fs::current_path(), {".exe"});
```
> Returns the list of the names of all files in the current directory with the "*.png", "*.bmp" or "*.jpg" extension.
``` cpp
auto fileList = getDirectoryFiles(fs::current_path(), {".png", ".bmp", ".jpg"});
```
