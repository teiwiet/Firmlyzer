#include "../include/scanner.h"
#include "analyzer.h"

#include <iostream>

void scan_file(const std::string& path)
{
    std::cout << "[*] Scanning: " << path << "\n";

    detect_credentials(path);
    detect_private_keys(path);
    detect_dangerous_functions(path);
    detect_command_injection(path);
}
