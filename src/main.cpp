#include <iostream>
#include "../include/extract.h"
#include "../include/walker.h"
#include "../include/scanner.h"

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << "Usage: fwscan <firmware.bin>\n";
        return 1;
    }

    std::string firmware = argv[1];

    std::cout << "[*] Extracting firmware...\n";
    std::string extracted_path = extract_firmware(firmware);

    std::cout << "[*] Walking filesystem...\n";
    walk_filesystem(extracted_path);

    return 0;
}
