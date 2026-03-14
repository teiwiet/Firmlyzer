#include<iostream>
#include<filesystem>
#include "../include/all.h"
using namespace std;

namespace fs = filesystem;
int main(int argc,char* argv[]){
    if(argc!=2){
        cout << "Usage : aforge <firmware>";
        return 1;
    }
    fs::path firmware = fs::absolute(argv[1]);
    if(!fs::exists(firmware)){
        cout << "Cannot find firmware";
        return 1;
    }
    cout << "Extracting firmware" << firmware;
    fs::path extracted_path = extract_firmware(firmware);
    if(!fs::exists(extracted_path)){
        cout << "Cannot find extracted" << endl;
        return 1;
    }
    cout << "Walking filesystem";
    walk_filesystem(extracted_path);
    return 0;
}
