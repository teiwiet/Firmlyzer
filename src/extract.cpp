#include "../include/extract.h"
#include<iostream>
std::string extract_firmware(filesystem::path & firmware){
    std::string cmd = "binwalk -e " + firmware.string();
    int ret = system(cmd.c_str());
    if(ret!=0){
        cerr << "Extraction failed\n";
    }
    filesystem::path extracted =
    firmware.parent_path() /
    ("_" + firmware.filename().string() + ".extracted");
    return extracted.string();
};
void detect_architecture(std::string file);
