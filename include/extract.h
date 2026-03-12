#pragma once 
#include <filesystem>
#include<string>
using namespace std;
std::string extract_firmware(filesystem::path & firmware);
void detect_architecture(std::string file);
