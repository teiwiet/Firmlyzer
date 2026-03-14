#include "../include/walker.h"
#include "../include/scanner.h"
#include <filesystem>

void walk_filesystem(const filesystem::path& path){
    for(auto &f : filesystem::recursive_directory_iterator(path)){
        if(!f.is_regular_file()){
            continue;
        }
        scan_file(f.path().string());
    }
};
