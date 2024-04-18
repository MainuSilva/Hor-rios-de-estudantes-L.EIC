#include "../include/Interface.h"
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

Interface::Interface(vector<Read_line> classesCsv_lines, vector<Read_line> classes_per_uc_lines, vector<Read_line> student_classes_lines){
    classesCsv_lines_ = classesCsv_lines;
    classes_per_uc_lines_ = classes_per_uc_lines;
    student_classes_lines_ = student_classes_lines;
    login = false;
    end_prog = false;
}


string Interface::find_Up(){
    string up;
    bool stop_While = false;

    // verificar se up existe
    do {
        cin >> up;

        auto i = all_students.find(up);

        if (i == all_students.end())
            cout << "\nStudent doesn't exist, please try again";

        else
            stop_While = true;

    } while (!stop_While);

    return up;


}


string Interface::find_UC(){
    string ucCode;
    bool stop_While = false;

    do {
        cin >> ucCode;

        auto i = all_UCs.find(ucCode);

        if (i == all_UCs.end())
            cout << "\nUC doesn't exist, please try again";

        else
            stop_While = true;
    }
    while(!stop_While);

    return ucCode;

}


string Interface::find_Class(){

    string classCode;
    bool stop_While = false;

    do {
        cin >> classCode;

        auto i = all_classes.find(classCode);

        if (i == all_classes.end())
            cout << "\nClass doesn't exist, please try again";

        else
            stop_While = true;
    }
    while(!stop_While);

    return  classCode;

}


//colocar o utilizador e a palavra passe, colocar mudanças de turmas;
void Interface::showMenu(){
    char choice;

    // armazenar os sets no início do programa, para utilizar ao longo do programa
    if (all_students.empty()) {
        for (auto line: student_classes_lines_) {
            all_students.insert(line.getString(0));
        }
    }
    if (all_UCs.empty()) {
        for (auto line: classes_per_uc_lines_) {
            all_UCs.insert(line.getString(0));
        }
    }
    if (all_classes.empty()) {
        for (auto line: classes_per_uc_lines_) {
            all_classes.insert(line.getString(1));
        }
    }

    do {
        cout << "************* SIGARRA 2.0 *************" << endl;
        cout << endl;
        cout << "________________________________________" << endl;
        cout << "|      What are you looking for?       |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|        [1] Class Information         |" << endl;
        cout << "|         [2] UC Information           |" << endl;
        cout << "|       [3] Student Information        |" << endl;
        cout << "|          [4] Class Permute           |" << endl;
        cout << "|______________________________________|" << endl;
        cout << "|              [E] Exit                |" << endl;
        cout << "|______________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << "\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                class_Info();
                break;

            case '2':
                uc_Info();
                break;

            case '3':
                student_Info();
                break;

            case '4':
                class_Permute();
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!end_prog);
}



bool Interface:: verifyExit(){
    char check;

    cout << "\nAre you sure you want to exit? Y or N: ";

    do {
        cin >> check;

         switch(check){

             case 'Y': case 'y':
                return true;
                break;

             case'N': case'n':
                return false;
                break;

             default:
                 cout << "\nInvalid Input, please try again" << endl;

        }

    }
    while(true);
}



// para esperar que o b seja pressionado
void wait_B(){

    char button;
    bool stop_While = false;

    cout << "\n[B] Go Back\n" << endl;

    while(!stop_While){
        cin >> button;
        if(button == 'b' || button == 'B') {
            stop_While = true;
        }
    }
}



//////////////////// Class Permute //////////////////////

void Interface::class_Permute() {
    char choice;
    bool stop_While = false;

    do {
        if(end_prog) break;

        cout << endl;
        cout << "____________________________________________" << endl;
        cout << "|              Class Permute               |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|          [1] Only one student            |" << endl;
        cout << "|         [2] Between two students         |" << endl;
        cout << "|__________________________________________|" << endl;
        cout<<  "|          [3] Process changes             |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|              [B] Go Back                 |" << endl;
        cout << "|                [E] Exit                  |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "********************************************" << endl;
        cout <<"\nEnter Your Choice : ";
        cin >> choice;
        cin.ignore(INT16_MAX, '\n'); // dúvida em relação a este passo

        switch (choice) {
            case '1':
                only_One_Std();
                break;

            case '2':
                bet_Two_Std();
                break;

            case '3':
                process_Changes();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);
}


void Interface:: process_Changes() {

    if (!login) {
        string password;

        cout << "\n-------- To access this section you need a login and password - Only teachers can access this section --------"<< endl;
        cout << endl;

        cout << "Username (choose an username): ";
        cin >> username;
        cout << endl;
        cout << "Password (any password works): ";
        cin >> password;

        login = true;
    }

    if (double_request.empty() && one_request.empty())
        cout << "\nNo changes need to be made" << endl;

    else {
        cout << "\nChanges are being made...\n" << endl;

// efetuar alteração mútua de estudantes
        for (vector<Pedido_troca> change: double_request) {

            vector<Pedido_troca> two_requests {change[0], change[1]};

            //se true - fazemos as mudanças
            if (change[0].can_student_switch_without_sobreposing_TP_PL(student_classes_lines_, classesCsv_lines_) &&
                change[1].can_student_switch_without_sobreposing_TP_PL(student_classes_lines_, classesCsv_lines_)) {

                string ucCode = change[0].getUcCode();

                string up1 = change[0].getStudentCode();
                string up2 = change[1].getStudentCode();

                Estudante student1(up1);
                Estudante student2(up2);

                int low_index1 = student1.lowerStudentIndex(student_classes_lines_);
                int high_index1 = student1.highStudentIndex(student_classes_lines_);

                int low_index2 = student2.lowerStudentIndex(student_classes_lines_);
                int high_index2 = student2.highStudentIndex(student_classes_lines_);

                string studentName1 = change[0].getStudentName(student_classes_lines_);
                string studentName2 = change[1].getStudentName(student_classes_lines_);

                for(int i = low_index1; i <= high_index1; i++) {

                    Read_line line =  student_classes_lines_[i];

                    if (ucCode == line.getString(2)) {

                        line.change_Value(up2, 0);
                        line.change_Value(studentName2, 1);
                    }
                }

                for(int i = low_index2; i <= high_index2; i++) {

                    Read_line line =  student_classes_lines_[i];

                    if (ucCode == line.getString(2)) {

                        line.change_Value(up1, 0);
                        line.change_Value(studentName1, 1);

                    }
                }

                // colocar os valores na lista de pedidos aceites
                accepted_two_students.push_back(two_requests);

            }
            else {

                refused_two_students.push_back(two_requests); // guardar as requests que não são aceites

            }

        }

    double_request.clear();


// alteração de um único estudante

        for (Pedido_troca change: one_request) {

            string up = change.getStudentCode();
            Estudante student(up);
            string ucCode = change.getUcCode();
            string new_classCode = change.getNewClassCode();

            int low_index = student.lowerStudentIndex(student_classes_lines_);
            int high_index = student.highStudentIndex(student_classes_lines_);

            if (change.can_student_switch(student_classes_lines_, classesCsv_lines_, classes_per_uc_lines_)) {

                accepted_one_student.push_back(change);

                for (int i = low_index; i <= high_index; i++) {

                    Read_line line = student_classes_lines_[i];

                    if (ucCode == line.getString(2)) {

                        line.change_Value(new_classCode, 3);

                    }
                }
            }
            else{

                refused_requests.push_back(change);
            }
        }

        cout << "\nChanges were successfully saved" << endl;

        //esvaziar o vetor
        one_request.clear();
    }

    //colocar sorted outra vez os estudantes
    sort(student_classes_lines_.begin(),student_classes_lines_.end(), [](Read_line a, Read_line &b){ return b.getInt(0) > a.getInt(0); });

    wait_B();
}

void Interface:: only_One_Std(){

    string up,ucCode,classCode;

    cout << "\n--------------- Permute one student ------------------" << endl;
    cout<< endl;
    cout << "Introduce the up of the student (only the number): ";

    up = find_Up();

    cout << endl;
    cout << "Introduce the UC to switch: ";

    ucCode = find_UC();


    cout << endl;
    cout << "Introduce to which class the switch is to be made: ";

    classCode = find_Class();

    Estudante student(up);
    string class_before = student.get_Classcode_in_UC(student_classes_lines_, ucCode);

    Pedido_troca change(up,class_before,ucCode,classCode);

    one_request.push_back(change);

    cout << "\nYour request has been sent and will be processed at the end of the day" << endl;

    wait_B();
}

void Interface::bet_Two_Std() {
    string up1, up2, ucCode;

    cout << "\n--------------- Permute between two student ------------------" << endl;
    cout << endl;
    cout << "Introduce the up of the first student (only the number): " ;

    up1 = find_Up();

    cout << "\nIntroduce the up of the second student (only the number): " ;

    up2 = find_Up();

    cout << "\nIntroduce the UC to swap students: " ;

   ucCode = find_UC();

   Estudante first_up(up1);
   Estudante sec_up(up2);

   string up1_before = first_up.get_Classcode_in_UC(student_classes_lines_, ucCode) ,
   up1_after = sec_up.get_Classcode_in_UC(student_classes_lines_, ucCode);

   Pedido_troca change_up1(first_up, up1_before, ucCode, up1_after );
   Pedido_troca change_up2(sec_up, up1_after, ucCode, up1_before);
   vector <Pedido_troca> change_two {change_up1, change_up2};

   double_request.push_back(change_two);

   cout << "\nYour request has been sent and will be processed at the end of the day" << endl;

   wait_B();

}

////////////////// Class Information /////////////////

void Interface::class_Info(){
    char choice;
    bool stop_While = false;

    do {
        if(end_prog) break;

        cout << "____________________________________________" << endl;
        cout << "|             Class Information            |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|             [1] List Classes             |" << endl;
        cout << "|         [2] Show Class Schedule          |" << endl;
        cout << "|   [3] Show number of students in Class   |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|              [B] Go Back                 |" << endl;
        cout << "|                [E] Exit                  |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "********************************************" << endl;
        cout << endl;
        cout <<"Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
            case '1':
                list_Classes();
                break;

            case '2':
                class_Schedule();
                break;

            case '3':
                number_Students_Class();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);
}

void Interface::list_Classes(){
    char choice;
    bool stop_While = false;

    do{
        cout << "____________________________________________" << endl;
        cout << "|               List Classes               |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [1] Show all               |" << endl;
        cout << "|         [2] Show classes by UC           |" << endl;
        cout << "|         [3] Show Classes by year         |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|              [B] Go Back                 |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << endl;
        cout <<"Enter Your Choice : ";
        
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                show_All_Classes();
                break;

            case '2':
                show_Classes_UC();
                break;

            case '3':
                show_Classes_Year();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;
        }
    }
    while(!stop_While);
}

void Interface::show_Classes_Year(){

    char year;
    bool digit = false;
    set <string> classes_year;

    cout << "\n---------- List Classes by Year ----------" << endl;
    cout << endl;
    cout << "What academic year are you looking for: ";

    // verificar se o input existe
    while(!digit) {

        cin >> year;

        if(isdigit(year))
            digit = true;

        else
            cout << "\nInvalid Input, please try again" << endl;

    }

    cout << "\n-------------- Classes in year "<< year << " ---------------";
    cout << endl;


    for (auto turma: all_classes) {
        if(turma.at(0) == year)
            classes_year.insert(turma);
    }

    for(auto turma : classes_year){
        cout << turma << endl;
    }

    if(classes_year.empty()){
        cout << "\nThere are no students in that year" << endl;
    }

    wait_B();

}

void Interface::show_All_Classes() {

    cout << "\n---------- ALL Classes ----------" << endl;
    cout << endl;


    for (auto classCode : all_classes){
        cout << classCode << endl;
    }

    wait_B(); // esperar para pressionar B

}

void Interface::show_Classes_UC() {
    string ucCode;
    set<string> classes_Uc_;

    cout << "\n---------- List Classes by UC ----------" << endl;
    cout << endl;
    cout << "Introduce the UC Code: ";

    //verificar se o Uc Code existe
    ucCode = find_UC();

    Uc uc(ucCode);


    cout << "\n---------- Classes of " << ucCode << " ----------" << endl;
    cout << endl;

    // imprimir a lista das classes naquela UC

    for (auto line: uc.classList(classes_per_uc_lines_)) {
        cout << line.getClassCode() << endl;

    }

    wait_B();

}

void Interface::class_Schedule() {
    string classCode;

    cout << "\n---------- Class Schedule ----------" << endl;
    cout << endl;
    cout << "Introduce the Class Code: ";

    classCode = find_Class();

    // pegar no horário de uma turma
    Turma turma(classCode);
    vector<Aula> horario = turma.get_horario_turma(classesCsv_lines_);

    cout<< endl;
    // apresentar o horário de uma turma
    turma.print_horario_class_code( horario);

    wait_B();

}

void Interface::number_Students_Class() {
    string classCode;
    string ucCode;

    cout << "\n---------- Number of Students ----------" << endl;
    cout << endl;
    cout << "Introduce the Class Code: ";

    classCode = find_Class();

    cout << "\nIntroduce the UC Code: ";

    ucCode = find_UC();

    // obter o número de estudantes numa turma por uc
    int num_students;
    Turma turma_uc(classCode, ucCode);
    num_students = turma_uc.getStudentNumber(student_classes_lines_);

    cout << "\n---------- Number of Students ----------" << endl;
    cout << endl;
    cout << "The number of students in the class "<< classCode << " on the UC " << ucCode << " is " << num_students << endl;


    wait_B();

}

//////////////////// UCs Information /////////////////////

void Interface::uc_Info(){
    char choice;
    bool stop_While = false;

    do {
        if(end_prog) break;
       
        cout << "____________________________________________" << endl;
        cout << "|             Curricular Units             |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [1] List UCs               |" << endl;
        cout << "|          [2] Show UC Schedule            |" << endl;
        cout << "|     [3] Show number of students in UC    |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|              [B] Go Back                 |" << endl;
        cout << "|                [E] Exit                  |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << endl;
        cout <<"Enter Your Choice : ";
        
        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                list_Ucs();
                break;

            case '2':
                get_UcSchedule();
                break;

            case '3':
                number_Students_Uc();
                break;

            case 'B': case 'b':
                stop_While = true;
                break;

            case 'E': case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    }
    while(!stop_While);
}

void Interface::list_Ucs(){
    char choice;
    bool stop_While = false;

    do{
        
        cout << "____________________________________________" << endl;
        cout << "|                 List UCs                 |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|                 [1] All                  |" << endl;
        cout << "|          [2] By Academic Year            |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|              [B] Go Back                 |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << endl;
        cout <<"Enter Your Choice : ";
        
        cin >> choice;

        switch (choice) {
            case '1':
                list_All_Ucs();
                break;

            case '2':
                list_By_Year_UC();
                break;

            case 'B':case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;
        }
    }
    while(!stop_While);
}

void Interface::list_All_Ucs() {

    cout << "\n----------- ALL UCs -----------";
    cout << endl;

    for (auto uc: all_UCs) {
        cout << uc << endl;
    }

    wait_B();

}

void Interface::list_By_Year_UC() {
    char year;
    bool digit = false;
    set <string> ucs_year;


    cout << "\n--------------- List UCs ----------------" << endl;
    cout << endl;
    cout << "What academic year are you looking for: ";

    // verificar se o input existe
    while(!digit) {
        cin >> year;

        if(isdigit(year))
            digit = true;

        else
            cout << "Invalid Input, please try again \n";

    }

    cout << "\n-------------- "<< year << " year UCs ---------------" << endl;
    cout << endl;

    //criar um set das ucs por ano para evitar repetições
    for(auto line : classes_per_uc_lines_) {

        if (line.getString(1).at(0) == year) {

            ucs_year.insert(line.getString(0));
        }
    }

    //fazer cout das ucs
    for(string uc : ucs_year){
        cout << uc << endl;
    }

    wait_B();

}

void Interface::get_UcSchedule() {
    string ucCode;


    cout << "\n---------- UC Schedule ----------" << endl;
    cout << endl;
    cout << "Introduce the UC Code : ";

    // verificar se o UcCode existe
    ucCode = find_UC();

    // se existir
    cout << "\n--------- Schedule of " << ucCode << " ----------" << endl;
    cout << endl;

    // pegar no horário de uma UC
    Uc single_UC(ucCode);
    single_UC.print_horario_uc_code(classesCsv_lines_);// faz print do horário de uma uc

    wait_B();

}


void Interface::number_Students_Uc() {
    string ucCode;

    cout << "\n--------- Number of Students in UC ----------"<< endl;
    cout << endl;
    cout << "Introduce the UC Code: ";

    //para verificar que existe UC
    ucCode = find_UC();

    cout << "\n--------- Number of Students in " << ucCode << " ----------"<< endl;
    cout << endl;

    Uc single_UC(ucCode);
    cout << "The number of Students in "<< ucCode << " is " << single_UC.get_number_students(student_classes_lines_) << endl;

    wait_B(); // espera que o B seja pressionado


}

///////////////// Students Information ///////////////////

void Interface::student_Info() {
    char choice;
    bool stop_While = false;

    do {
        if (end_prog) break;

        cout << "____________________________________________" << endl;
        cout << "|            Student Information           |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|             [1] List Students            |" << endl;
        cout << "|        [2] Show student Schedule         |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [B] Go Back                |" << endl;
        cout << "|                [E] Exit                  |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "********************************************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                list_Students();
                break;

            case '2':
                get_StudentSchedule();
                break;

            case 'B':
            case 'b':
                stop_While = true;
                break;

            case 'E':
            case 'e':
                end_prog = verifyExit();
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    } while (!stop_While);
}

void Interface::get_StudentSchedule() {
    string studentCode;
    string classCode;
    string ucCode;

    cout << "\n-------------- UP Schedule ---------------"<< endl;
    cout << endl;
    cout << "Introduce the number of the student UP code: ";

    studentCode = find_Up();

    Estudante student_(studentCode);

    // pegar no horário da turma por cada uc do estudante
    vector<Aula> horario = student_.get_horario_Student(student_classes_lines_, classesCsv_lines_);

    // apresentar o horário de um estudante
    student_.print_horario_class_uc(horario);

    wait_B();

}

void Interface::list_Students() {
    char choice;
    bool stop_While = false;

    do {

        cout << "____________________________________________" << endl;
        cout << "|               List Students              |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|                 [1] All                  |" << endl;
        cout << "|                [2] By Uc                 |" << endl;
        cout << "|               [3] By class               |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [B] Go Back                |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "********************************************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;
        string input;
        cin.ignore(INT16_MAX, '\n');

        switch (choice) {
            case '1':
                input = "all";
                list_All_Students(input);
                break;

            case '2':
                list_UcStudents();
                break;

            case '3':
                list_Class_Students();
                break;


            case 'B':
            case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    } while (!stop_While);

}
void Interface::list_All_Students(string input, string value_1, string value_2) {
    bool stop_While = false;
    char choice;

    do {

        cout << "----------------- Students -----------------";
        cout << endl;
        cout << "____________________________________________" << endl;
        cout << "|         HOW DO YOU WANT TO ORDER?        |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|           [1] Alphabetic order           |" << endl;
        cout << "|           [2] By number of Ucs           |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [B] Go Back                |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "********************************************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch (choice) {
            case '1':
                alphabetic_Order(input);
                break;

            case '2':
                number_Of_Ucs();
                break;

            case 'B':
            case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    } while (!stop_While);
}

void Interface::number_Of_Ucs() {
    string value_1;
    string input = "number_uc";
    bool stop_While = false;
    char choice;

    cout << "\n--------- You want to see students who have more than how many ucs? ----------"<< endl;
    cout << endl;
    cout << "Introduce the number of UCs: ";

    while(!stop_While) {
        cin >> choice;

        if(isdigit(choice))
            stop_While = true;

        else
            cout << "\nInvalid Input, please try again" << endl;

    }

    string s(1, choice);
    alphabetic_Order(input, s);

}

void Interface::alphabetic_Order(string input, string value_1, string value_2) {
    bool stop_While = false;
    char choice;

    do {


        cout << "------------- Alphabetic order -------------";
        cout << endl;
        cout << "____________________________________________" << endl;
        cout << "|               IN WHICH ORDER?            |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|           [1] Ascending order            |" << endl;
        cout << "|           [2] Descending order           |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << "|               [B] Go Back                |" << endl;
        cout << "|__________________________________________|" << endl;
        cout << endl;
        cout << "****************************************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch (choice) {
            case '1':
                ascending_Order(input, value_1, value_2);
                break;

            case '2':
                descending_Order(input, value_1, value_2);
                break;

            case 'B':
            case 'b':
                stop_While = true;
                break;

            default:
                cout << "\nInvalid Input, please try again" << endl;

        }
    } while (!stop_While);
}

void Interface::ascending_Order(string input, string value_1, string value_2) {

    set<vector<string>> alunos;

    if (input == "all") {
        for (auto line: student_classes_lines_) {
            alunos.insert({line.getString(1), line.getString(0)});
        }

        cout << "\n--------- All Students in ascending order ----------";
        cout << endl;
    }

    if (input == "uc") {
        for (auto line: student_classes_lines_) {
            if (line.getString(2) == value_1) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }

        cout << "\n--------- Students in " << value_1 << " in ascending order ----------";
        cout << endl;
    }

    if (input == "uc_class") {
        for (auto line: student_classes_lines_) {
            if ((line.getString(3) == value_2) && (line.getString(2) == value_1)) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }

        cout << endl;
        cout << "Students of the class " << value_2 << " in the " << value_1 << " UC in ascending order:" << endl;

    }

    if(input == "number_uc"){
        for (auto line: student_classes_lines_) {
            Estudante student(line.getString(0));
            int numeroUcs = student.get_number_of_ucs(student_classes_lines_);
            int number = stoi(value_1);
            if (numeroUcs > number) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }


        cout << "\n-------- Students with more than " << value_1 << " UCs, in ascending order ---------" << endl;
        cout <<endl;

        if(alunos.empty()){
            cout << "\nThere is no student with more than "<< value_1 <<" UCs" << endl;
        }
    }


    for (auto aluno: alunos) {
        cout << "up" << aluno[1] << ": "<< aluno[0] << endl;
    }
    // função que faz cout dos estudantes por ordem crescente de nome

    wait_B();
}

void Interface::descending_Order(string input, string value_1, string value_2) {

    set<vector<string>, greater<>> alunos;

    if (input == "all") {
        for (auto line: student_classes_lines_) {
            alunos.insert({line.getString(1), line.getString(0)});
        }

        cout << "\n--------- All Students in descending order ----------";
        cout << endl;
    }

    if (input == "uc") {
        for (auto line: student_classes_lines_) {
            if (line.getString(2) == value_1) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }

        cout << "\n--------- Students in " << value_1 << " in ascending order ----------";
        cout << endl;
    }

    if (input == "uc_class") {
        for (auto line: student_classes_lines_) {
            if ((line.getString(3) == value_2) && (line.getString(2) == value_1)) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }

        cout << "\n-------- Students of the class " << value_2 << " in the " << value_1 << " UC in ascending order ---------" << endl;
        cout <<endl;

    }

    if(input == "number_uc"){
        for (auto line: student_classes_lines_) {
            Estudante student(line.getString(0));
            int numeroUcs = student.get_number_of_ucs(student_classes_lines_);
            int number = stoi(value_1);
            if (numeroUcs > number) {
                alunos.insert({line.getString(1), line.getString(0)});
            }
        }


        cout << "\n-------- Students with more than " << value_1 << " UCs, in ascending order ---------" << endl;
        cout <<endl;

        if(alunos.empty()){
            cout << "\nThere is no student with more than "<< value_1 <<" UCs" << endl;
        }
    }


    for (auto aluno: alunos) {
        cout << "up" << aluno[1] << ": "<< aluno[0] << endl;
    }
    // função que faz cout dos estudantes por ordem decrescente de nome

    wait_B();
}

void Interface::list_UcStudents() {
    string ucCode;

    cout << "--------- Students in UC ----------";
    cout << endl;
    cout << "Introduce the UC Code: ";

    ucCode = find_UC();

    string input = "uc";
    alphabetic_Order(input, ucCode);

}

void Interface::list_Class_Students() {
    string classCode;
    string ucCode;

    cout << "\n--------- Students in Class on a UC ----------";
    cout << endl;
    cout << "Introduce the Class Code : ";

    classCode = find_Class();

    cout << "\nIntroduce the UC Code: ";

    ucCode = find_UC();

    string input = "uc_class";
    alphabetic_Order(input, ucCode, classCode);

}