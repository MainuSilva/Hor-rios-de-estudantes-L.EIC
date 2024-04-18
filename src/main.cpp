#include <vector>
#include <algorithm>
#include "../include/Read_file.h"
#include "../include/Aula.h"
#include "../include/Interface.h"
#include "../include/Estudante.h"

using namespace std;

int main() {

    Read_file reader;
    vector<Read_line> classesCsv_lines = reader.read("/Users/manue/OneDrive/Ambiente de Trabalho/Projeto/classes.csv", true);
    vector<Read_line> classes_per_uc_lines = reader.read("/Users/manue/OneDrive/Ambiente de Trabalho/Projeto/classes_per_uc.csv", true);
    vector<Read_line> student_classes_lines = reader.read("/Users/manue/OneDrive/Ambiente de Trabalho/Projeto/students_classes.csv", true);

    //sort by up
    sort(student_classes_lines.begin(),student_classes_lines.end(), [](Read_line a, Read_line &b){ return b.getInt(0) > a.getInt(0); });
    //sort by uc
    sort(classesCsv_lines.begin(),classesCsv_lines.end(), [](Read_line a, Read_line &b){ return b.getString(1) > a.getString(1); });
    // sort by uc
    sort(classes_per_uc_lines.begin(),classes_per_uc_lines.end(), [](Read_line a, Read_line &b){ return b.getString(0) > a.getString(0); });

    Interface i(classesCsv_lines, classes_per_uc_lines, student_classes_lines);
    i.showMenu();

    return 0;
}
