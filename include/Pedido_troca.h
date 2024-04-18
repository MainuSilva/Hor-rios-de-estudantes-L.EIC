#ifndef UNTITLED_PEDIDO_TROCA_H
#define UNTITLED_PEDIDO_TROCA_H
#include <ostream>
#include <string>

#include "Read_line.h"
#include "Turma.h"
#include "Estudante.h"

using namespace std;

/**
 * @brief Classe que representa os pedidos de alteração de horário
 */

class Pedido_troca {

private:

    /// Estudante
    Estudante student_;

    /// Código da turma atual
    string atual_classCode_;

    /// Código da UC
    string ucCode_;

    /// Código da turma destino
    string new_classCode_;

public:

    /**
     * @brief Contructor da Classe
     * Complexidade Temporal: O(1)
     * @param student : estudante
     * @param atual_classCode : código da turma atual
     * @param ucCode: código da UC
     * @param new_classCode : código da turma destino
     */
    Pedido_troca(Estudante student, string atual_classCode, string ucCode, string new_classCode);

    /**
     * @brief Getter para o código da UC
     * Complexidade Temporal: O(1)
     * @return Código da UC
     */
    const string &getUcCode() const;

    /**
     * @brief Getter para o código da turma destino
     * Complexidade Temporal: O(1)
     * @return Código da turma destino
     */
    const string &getNewClassCode() const;

    /**
     * @brief Getter para o nome do Estudante
     * Complexidade Temporal: O(1)
     * @return Nome do estudante
     */
    string getStudentName(vector<Read_line> lines);

    /**
     * @brief Getter para o código do estudante
     * Complexidade Temporal: O(1)
     * @return Código do estudante
     */
    string getStudentCode();

    /**
     * @brief Função que avalia se a alteração pode ser efetuada sem sobreposição de aulas TP e PL
     * @param student_classes_lines_ : vetor contendo as linhas do ficheiro students_classes_lines_
     * @param classesCsv_lines_ : vetor contendo as linhas do ficheiro classes.csv
     * @return true se a alteração puder ser feita, false caso contrário
     */
    bool can_student_switch_without_sobreposing_TP_PL(vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_);

    /**
     * @brief Função que avalia se a alteração pode ser efetuada sem ultrapassar o Cap
     * @param student_classes_lines_ : vetor contendo as linhas do ficheiro students_classes_lines_
     * @return true se a alteração puder ser feita, false caso contrário
     */
    bool can_student_switch_without_passing_cap(vector<Read_line> student_classes_lines_, vector <Read_line> classes, vector<Read_line> classes_per_uc);

    /**
     * @brief Função que avalia se a alteração pode ser efetuada sem causar desquilíbrio nas turmas
     * @param student_classes_lines_ : vetor contendo as linhas do ficheiro students_classes_lines_
     * @return true se a alteração puder ser feita, false caso contrário
     */
    bool can_student_switch_without_causing_uc( vector<Read_line> student_classes_lines_);

    /**
     * @brief Função que avalia se se reunem todas as condições para a alteração ser feita
     * @param student_classes_lines_ : vetor contendo as linhas do ficheiro students_classes_lines_
     * @param classesCsv_lines_ : vetor contendo as linhas do ficheiro classes.csv
     * @return true se a alteração puder ser feita (se as 3 funções anteriores dão true), false caso contrário
     */
    bool can_student_switch(vector<Read_line> student_classes_lines_, vector<Read_line> classesCsv_lines_,  vector<Read_line> classes_per_uc);


};

#endif //UNTITLED_PEDIDO_TROCA_H
