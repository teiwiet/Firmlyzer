#include "../include/analyzer.h"

void log_finding(const string& log){
    static ofstream of("report.txt",ios::app);
    if(of){
        of << log << endl;
    }
};

void detect_credentials(const filesystem::path& file){
    ifstream f(file.string());
    if(!f){
        cout << "Cannot open : " << file << endl;
        return;
    }
    string line;
    regex cred("(root|admin|passwd)\\s*[:=]\\s*[^\\s]{1,20}", regex::icase);
    smatch match;
    while(getline(f,line)){
        if(regex_search(line,match,cred)){
            string msg = "[!] Credentials found in : " + file.string() + "->" + match.str();
            cout << msg << endl;
            log_finding(msg);
            break;
        };
    }
};
void detect_private_keys(const filesystem::path& file){
    ifstream f(file);
    if(!f){
        cout << "Cannot open : " << file << endl;
        return ;
    }
    string line;
    while(getline(f,line)){
        if(
            line.find("PRIVATE KEY") != string::npos || 
            line.find("RSA PRIVATE KEY") != string::npos || 
            line.find("CERTIFICATE") != string::npos
        )
        {
            string msg = "[!] Private key or certificate found in : " + file.string();
            cout << msg << endl;
            log_finding(msg);
            break;
        }
    }
};
void detect_dangerous_functions(const filesystem::path& file){
    ifstream f(file);
    if(!f) return;

    string line;

    while(getline(f,line)){
        if(line.find("system(") != string::npos){
            string msg = "[!] Dangerous function system() in " + file.string();
            cout << msg << endl;
            log_finding(msg);
            break;
        }
    }
}

void detect_command_injection(const filesystem::path& file){
    ifstream f(file);
    if(!f) return;

    string line;

    while(getline(f,line)){
        if(line.find("QUERY_STRING") != string::npos &&
           line.find("system(") != string::npos){

            string msg = "[!] Possible command injection in " + file.string();
            cout << msg << endl;
            log_finding(msg);
            break;
        }
    }
}



