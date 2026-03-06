#include<iostream>
#include "../include/extractor.h"
using namespace std;

int main(int argc,char* argv[]){
    if(argc!=2){
        cout << "Usage : aforge <firmware>";
        return 1;
    }
    string firmware = argv[1];
    cout << "[+] Extracting firmware...\n";
    extract_firmware(firmware);
    return 0;
}
