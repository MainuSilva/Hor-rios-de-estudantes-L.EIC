#include <string>
#include <vector>
#include <set>
#include "../include/Pedido_troca.h"


Pedido_troca::Pedido_troca(Estudante student, std::string atual_classCode, std::string ucCode, std::string new_classCode){
    student_ = student;
    atual_classCode_ = atual_classCode;
    ucCode_ = ucCode;
    new_classCode_ = new_classCode;
}

const string &Pedido_troca::getUcCode() const {
    return ucCode_;
}

const string &Pedido_troca::getNewClassCode() const {
    return new_classCode_;
}

string Pedido_troca::getStudentCode(){
    return student_.get_studentCode();
}


string Pedido_troca::getStudentName(vector<Read_line> lines) {
    return student_.get_studentName(lines);
}


bool Pedido_troca::can_student_switch_without_sobreposing_TP_PL( vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_){
    set<string> uc_codes;

    vector <Aula> horario_without_uc = student_.get_horario_Student(student_classes_lines_, classesCsv_lines_);

    for(int i = 0; i < horario_without_uc.size(); i++){

        if(horario_without_uc[i].get_ucCode() == ucCode_ || horario_without_uc[i].get_type() == "T"){

            horario_without_uc.erase(horario_without_uc.begin() + i);
        }
    }

    // descobrir o horário da uc nova
    Uc new_uc(ucCode_);
    vector<Aula> horario_novo_da_uc = new_uc.get_horarios_turma_without_T( new_classCode_, classesCsv_lines_);

    //verificar se estão overlaped

    for(auto new_aula: horario_novo_da_uc){

        for(auto aula : horario_without_uc){

            if(aula.is_overlaped(new_aula)){
                return false;
            }
        }
    }

    return true;
}

bool Pedido_troca::can_student_switch_without_passing_cap(vector<Read_line> student_classes_lines_, vector <Read_line> classes, vector<Read_line> classes_per_uc) {

    Turma turma(new_classCode_, ucCode_);
    Uc uc(ucCode_);
    vector <Turma> list_classes_uc = uc.classList(classes_per_uc);

    int value_1 = turma.getStudentNumber(student_classes_lines_) + 1;
    int value_2 = uc.defineCap(student_classes_lines_, list_classes_uc);

    if (value_1 > value_2) {
        return false;
    }
    return true;
}

bool Pedido_troca::can_student_switch_without_causing_uc( vector<Read_line> student_classes_lines_){
    Turma turma_atual(atual_classCode_, ucCode_);
    Turma turma_nova(new_classCode_, ucCode_);

    int turma_atual_fv = turma_atual.getStudentNumber(student_classes_lines_) - 1;
    int turma_nova_fv = turma_nova.getStudentNumber( student_classes_lines_) + 1;

    if(turma_nova_fv - turma_atual_fv >= 4) {
        return false;
    }

    return true;
}

bool Pedido_troca::can_student_switch( vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_, vector<Read_line> classes_per_uc){

    return (can_student_switch_without_sobreposing_TP_PL(student_classes_lines_, classesCsv_lines_)) &&
           can_student_switch_without_causing_uc(student_classes_lines_) &&
           can_student_switch_without_passing_cap(student_classes_lines_ , classesCsv_lines_, classes_per_uc);

}
