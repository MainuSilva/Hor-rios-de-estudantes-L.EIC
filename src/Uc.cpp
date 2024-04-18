#include "../include/Uc.h"
#include "../include/Turma.h"
#include <iomanip>
#include <iostream>
#include <set>

using namespace std;

Uc::Uc(std::string ucCode){
    ucCode_ = ucCode;
}

vector<Aula> Uc::get_horario_uc(vector<Read_line> lines){
    vector <Aula> horario_uc;
    vector <Read_line> aulas = find_uc(lines, 1);

    for (auto line : aulas) {
        Aula aula(line);
        horario_uc.push_back(aula);
    }
    return horario_uc;
}

//obtemos o horário da uc de determinada turma
vector<Aula> Uc::get_horarios_uc_turma( string classCode, vector<Read_line> lines) {
    vector<Aula> new_horario;
    vector <Aula> horario_uc = get_horario_uc(lines);

    for(int i = 0; i < horario_uc.size(); i++ ){

        if(horario_uc[i].get_classCode() == classCode){

            new_horario.push_back(horario_uc[i]);
        }
    }
    return new_horario;
};


// obter o horário da uc de determinada turma sem aulas teóricas
vector<Aula> Uc::get_horarios_turma_without_T( string classCode, vector<Read_line> lines) {
    vector<Aula> new_horario;
    vector <Aula> horario_uc = get_horario_uc(lines);

    for(int i = 0; i < horario_uc.size(); i++ ){

        if(horario_uc[i].get_classCode() == classCode && horario_uc[i].get_type() != "T"){

            new_horario.push_back(horario_uc[i]);
        }
    }
    return new_horario;
};



//fazer a lista de todas as turmas a cada uc
vector <Turma> Uc::classList(vector<Read_line> lines) {
    vector <Turma> classList;

    vector<Read_line> turmas = find_uc(lines, 0); // procurar no ficheiro classes per uc a lista de todas as classes de uc

    for (auto line: turmas) {

            Turma new_turma = Turma(line.getString(1), line.getString(0));

            classList.push_back(new_turma);

    }
    return classList;
}



// obter o número de estudantes de uma UC - students
int Uc::get_number_students(vector<Read_line> lines){
    int num = 0;
    set<string> students;

    for(auto line: lines){

        auto i = students.find(line.getString(0));

        //verificar se o ucCode é igual e o up não se encontra no set

        if(line.getString(2) == ucCode_ && i == students.end()){
            num++;
            students.insert(line.getString(0));
        }
    }

return num;
}



int Uc::defineCap(vector<Read_line> lines, vector<Turma> classlist ) {

    int cap = 0;

    for (auto turma: classlist) {

        if (turma.getStudentNumber(lines) > cap) {

            cap = turma.getStudentNumber(lines);

        }
    }
    return cap;
}


int Uc::lowStudentIndex( vector<Read_line> classes, int index) {
    string uc = ucCode_;
    int lower = 0,
            higher = classes.size()-1;

    while(higher > lower){
        int medium = lower + (higher-lower)/2;

        if(classes[medium].getString(index) >= uc) higher = medium;

        else  lower = medium +1;

    }
    return lower;
}



int Uc::highStudentIndex(vector<Read_line> classes, int ind){
    int index;
    string uc = ucCode_;
    int low = 0;
    int high= classes.size()-1;

    while(high > low){
        int medium = low + (high-low)/2;

        if(classes[medium].getString(ind) > uc) high = medium;

        else  low = medium +1;
    }
    if(classes[low].getString(ind) > uc) index = low-1;

    else index = low;

    return index;

}



vector<Read_line> Uc::find_uc(vector <Read_line> classes, int index){

    vector<Read_line> aux;
    int resultA = lowStudentIndex(classes, index);

    int resultB = highStudentIndex(classes, index);

    for(int i = resultA; i <= resultB; i++){
        aux.push_back(classes[i]);
    }
    return aux;

}


void Uc::print_horario_uc_code(vector<Read_line> lines){
    vector <Aula> horario_uc = get_horario_uc(lines);
    cout << endl;


    cout << "______________________________________________________________________________________________________" <<endl;
    cout << "|                                        SCHEDULE OF " << ucCode_ << "                                        |" <<endl;
    cout << "|____________________________________________________________________________________________________|" <<endl;
    cout << "|    Weekday   |   classCode   |      Type      |    StartHour    |     EndHour     |    Duration    |" <<endl;
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    int i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Monday" && i == 0){
            i++;
            cout << "|Monday        |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Monday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Tuesday" && i == 0){
            i++;
            cout << "|Tuesday       |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        } else if (aula.get_weekDay() == "Tuesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Wednesday" && i == 0){
            i++;
            cout << "|Wednesday     |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Wednesday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if(aula.get_weekDay() == "Thursday" && i == 0){
            i++;
            cout << "|Thursday      |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }else if (aula.get_weekDay() == "Thursday" && i != 0){
            cout << "|              |_______________|________________|_________________|_________________|________________|" <<endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" <<endl;
        }
    }

    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
    i = 0;
    for(Aula aula : horario_uc) {
        if (aula.get_weekDay() == "Friday" && i == 0) {
            i++;
            cout << "|Friday        |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        } else if (aula.get_weekDay() == "Friday" && i != 0) {
            cout << "|              |_______________|________________|_________________|_________________|________________|" << endl;
            cout << "|              |" << left << setw(15) << aula.get_classCode() << "|" << left << setw(16) << aula.get_type() << "|" << left << setw(17) << aula.get_startHour() << "|" << left << setw(17) << aula.get_endingTime() << "|" << left << setw(16) << aula.get_duration() << "|" << endl;
        }
    }
    cout << "|______________|_______________|________________|_________________|_________________|________________|" <<endl;
};



