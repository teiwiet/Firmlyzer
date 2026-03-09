#include "../include/walker.h"
#include"../include/scanner.h"
#include<filesystem>
#include<iostream>
namespace fs = std::filesystem;
void walk_filesystem(std::string& path){
    for(auto& p : fs::recursive_directory_iterator(path)){
        if(!fs::is_regular_file(p)){
            continue;
        }
        scan_file(p.path().string());
    }
};
