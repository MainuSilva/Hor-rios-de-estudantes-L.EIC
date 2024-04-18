#include "../include/Aula.h"
using namespace std;

Aula::Aula(string classCode, string ucCode, string weekDay, double startHour, double duration, string type){
    classCode_= classCode;
    ucCode_ = ucCode;
    weekDay_ = weekDay;
    startHour_ = startHour;
    duration_ = duration;
    type_ = type;
}

Aula::Aula(Read_line line){
    classCode_ = line.getString(0);
    ucCode_ = line.getString(1);
    weekDay_ = line.getString(2);
    startHour_ = line.getDouble(3);
    duration_ = line.getDouble(4);
    type_ = line.getString(5);
}

//Getters
string Aula::get_classCode() const { return classCode_; }

string Aula::get_ucCode() const { return ucCode_; }

string Aula::get_weekDay() const {return weekDay_;}

double Aula::get_startHour() const { return startHour_; }

double Aula::get_duration() const { return duration_; }

string Aula::get_type() const { return type_; }

double Aula::get_endingTime() const {
    // saber o tempo final em double
    double endingTime_ = startHour_ + duration_;
    return  endingTime_;
}

bool Aula::is_overlaped(Aula new_aula){

    if(weekDay_ == new_aula.get_weekDay() &&

    ((startHour_ >= new_aula.get_startHour() && startHour_ < new_aula.get_endingTime()) ||

    (get_endingTime() > new_aula.get_startHour() &&  get_endingTime() <= new_aula.get_endingTime()))) {

        return true;
    }
    else
        return false;

}



