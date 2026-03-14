#include "../include/extract.h"
#include <filesystem>
string extract_firmware(const filesystem::path& path){
    string cmd = "binwalk -e " + path.string();
    int ret = system(cmd.c_str());
    if(ret!=0){
        cerr << "Extraction failed";
    }
    filesystem::path extracted = path.parent_path() / ("_" + path.filename().string() + ".extracted");
    return extracted.string();
};
