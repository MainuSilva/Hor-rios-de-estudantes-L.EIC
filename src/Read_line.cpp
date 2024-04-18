#include "../include/Read_line.h"

using namespace std;

Read_line::Read_line()= default;;

Read_line::Read_line(const Read_line& other){
    values = other.values;
}

void Read_line::parse(std::string line, char end_line){

    stringstream values_in_line(line);

    string column;
    while (getline(values_in_line, column, end_line)){
        values.push_back(column);
    }
}

string Read_line::getString(int column){
    return values[column];
}

double Read_line::getDouble(int column){
    return atof(values[column].c_str());
}

int Read_line::getInt(int column){
    return stoi(values[column].c_str());
}

void Read_line::change_Value(string new_value, int column){
    values[column] = new_value;
}


