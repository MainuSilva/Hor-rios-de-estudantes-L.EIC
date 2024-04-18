#include "../include/Read_file.h"
using namespace std;

Read_file::Read_file()= default;

vector<Read_line> Read_file::read(std::string file_name, bool colum_names){
    ifstream file;
    vector<Read_line> lines;
    file.open(file_name.c_str());

    string line = "";

    if (colum_names) {
        getline(file, line);
    }

    while(getline(file, line)){
        Read_line file_line;
        file_line.parse(line);
        lines.push_back(file_line);
    }

    return lines;
}
