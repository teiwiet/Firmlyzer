#include "../include/extract.h"
#include<iostream>
string extract_firmware(std::string& firmware){
    std::string cmd = "binwalk -e " + firmware;
    int ret = system(cmd.c_str());
    if(!ret){
        cerr << "Extraction failed\n";
    }
    return "_" + firmware + "extrected";
};
void detect_architecture(std::string file);
