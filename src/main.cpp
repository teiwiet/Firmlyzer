#include <iostream>
#include <filesystem>
#include "../include/extract.h"
#include "../include/walker.h"

namespace fs = filesystem;

int main(int argc, char* argv[])
{
    if(argc != 2){
        std::cout << "Usage: aforge <firmware.bin>\n";
        return 1;
    }
    fs::path firmware = fs::absolute(argv[1]);
    if(!fs::exists(firmware)){
        cout << "Firmware not found";
        return 1;
    }
    
    cout << "Extracting firmware " << firmware;
    string extracted = extract_firmware(firmware);
    if(!fs::exists(extracted)){
        cout << "Cannot extract firmware";
        return 1;
    }
    cout << "Walking filesystem";
    walk_filesystem(extracted);
    return 0;
}
