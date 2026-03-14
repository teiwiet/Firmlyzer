#pragma once 
#include<iostream>
#include<filesystem>
#include<fstream>
#include<regex>
using namespace std;
void log_finding(const string& log);
void detect_credentials(const filesystem::path& file);
void detect_private_keys(const filesystem::path& file);
void detect_dangerous_functions(const filesystem::path& file);
void detect_command_injection(const filesystem::path& file);

