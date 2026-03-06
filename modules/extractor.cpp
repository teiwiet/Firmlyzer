#include "../include/extractor.h"

void extract_firmware(std::string& firmware){
    std::string cmd = "binwalk -e " + firmware;
    system(cmd.c_str());
};
void detect_architecture(std::string file);
