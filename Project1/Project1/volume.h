#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include"convert.h"
#include<windows.h>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

void create_file_default(const char* path, int size,ofstream &fin);

void jump_code(const char* path, ofstream &fin);
void num_cluster_start(const char* path, ofstream& fin);
bool createvolume(const char* path, int size,ofstream &fin);
//int seek_num_entry_empty(const char* path, ofstream& fin);
int seekentryempty(char*&vol,int &size,ifstream &fin);
void writefile(char*&vol,const char* path,int &size,ofstream &fout);
bool import_file_to_volume(char*&vol,const char* path,int &cur,ofstream &fout,ifstream &fin, uint64_t pass);
int firstFreeCluster(ifstream& fin);

//string WcharToString(wchar_t* wchar_str);
//wchar_t* StringToWchar(string str);
//vector<string> ListFileInVolume(string path_folder);

uint64_t hashtables(string temp);
string inputPassword();
void writePass(const char*vol, uint64_t pass, ofstream &fout);

bool exportfile(char*&vol,const char*file, ifstream &fin);
void printListFile(const char*vol,ifstream &fin);