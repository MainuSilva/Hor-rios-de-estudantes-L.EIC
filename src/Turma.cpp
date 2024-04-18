#include "../include/Turma.h"
#include <iomanip>
#include <iostream>

using namespace std;

Turma::Turma(string classCode) {
    classCode_ = classCode;
}

Turma::Turma(string classCode, string ucCode) {
    classCode_ = classCode;
    ucCode_ = ucCode;
}

const string &Turma::getClassCode() const {
    return classCode_;
}

//obtemos o horário de uma turma - file classes.csv
vector<Aula> Turma::get_horario_turma(std::vector<Read_line> lines) {
    vector<Aula> horario_turma;

    for (auto line : lines) {
        if(line.getString(0) == classCode_){
            Aula aula(line);
            horario_turma.push_back(aula);
        }
    }
    return horario_turma;

}

//número de estudantes de uma turma por UC - ficheiro students_classes.csv
int Turma::getStudentNumber(vector<Read_line> lines) {

    int total = 0;

    for (auto line:lines) {

        if (line.getString(2)== ucCode_ && line.getString(3) == classCode_) {

            total++;
        }
    }
    return total;
}



//imprimir o horario de uma turma
 void Turma::print_horario_class_code( vector<Aula> horario){
    cout << "______________________________________________________________________________________________________" <<endl;
    cout << "|                                        SCHEDULE OF " << classCode_ << "                                         |" <<endl;
    cout << "|____________________________________________________________________________________________________|" <<endl;
    cout << "|    Weekday   |     UcCode    |      Type      |    StartHour    |     EndHour     |    Duration    |" <<endl;
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    int i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Monday" && i == 0){
            i++;
            cout << "|Monday        |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Monday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Tuesday" && i == 0){
            i++;
            cout << "|Tuesday       |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Tuesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Wednesday" && i == 0){
            i++;
            cout << "|Wednesday     |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Wednesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if(aula.get_weekDay() == "Thursday" && i == 0){
            i++;
            cout << "|Thursday      |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Thursday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario) {
        if (aula.get_weekDay() == "Friday" && i == 0) {
            i++;
            cout << "|Friday        |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        } else if (aula.get_weekDay() == "Friday" && i != 0) {
            cout << "|              |_______________|________________|_________________|_________________|________________|" << endl;
            cout << "|              |" << left << setw(15) << aula.get_ucCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        }
    }
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
}


