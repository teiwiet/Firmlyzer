#include "../include/scanner.h"
#include "../include/analyzer.h"
void scan_file(const string& file){
    cout << "Scanning file : " << file << endl;
    detect_credentials(file);
    detect_private_keys(file);
    detect_dangerous_functions(file);
    detect_command_injection(file);
};
