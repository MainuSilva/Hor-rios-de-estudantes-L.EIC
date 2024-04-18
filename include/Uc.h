#ifndef UNTITLED_UC_H
#define UNTITLED_UC_H

#include <string>
#include <iostream>
#include "Aula.h"
#include "Turma.h"

using namespace std;

class Uc {

private:

    /// Código da UC
    std::string ucCode_;

public:
    /**
     * @brief Constructor da Classe
     * Complexidade Temporal: O(1)
     * @param ucCode : Código da UC
     */
    Uc(string ucCode);

    /**
     * @brief Getter para o Horário da Uc de uma determinada turma
     * Complexidade Temporal: O(n) sendo n
     * @param classCode : Código da turma
     * @param lines : vetor contendo as linhas de um ficheiro
     * @return o horário da uc de determinada turma
     */
    vector<Aula> get_horarios_uc_turma(std :: string classCode, vector<Read_line> lines);

    /**
     * @brief Getter para o horário de uma UC
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor aulas
     * @param lines: vetor contendo as linhas de um ficheiro
     * @return o horário da uc de determinada turma
     */
    vector<Aula> get_horario_uc(vector<Read_line> lines);

    /**
     * @brief Função para obter o número de estudantes a uma determinada UC
     * Complexidade Temporal: O(n) sendo n o comprimento de lines
     * @param lines : vetor contendo as linhas de um ficheiro
     * @return o número de estudantes a uma UC
     */
    int get_number_students(vector<Read_line> lines);

     /**
      * @brief Função para obter o horário da uc de determinada turma sem aulas teóricas
      * Complexidade Temporal: O(n) sendo n o comprimento do vetor horario_uc
      * @param classCode : Código da turma
      * @param lines : vetor contendo as linhas de um ficheiro
      * @return o horário
      */
    vector<Aula> get_horarios_turma_without_T(std:: string classCode, vector<Read_line> lines);

     /**
      * @brief Função que permite criar uma interface para a visualização do horário de uma UC
      * Complexidade Temporal: O(n) sendo n o comprimento do vetor horário
      * @param lines: vetor contendo as linhas de um ficheiro
      */
    void print_horario_uc_code(vector<Read_line> lines);

     /**
      * @brief Função para definir qual o cap
      * Complexidade Temporal:  O(n) sendo n o comprimento do vetor classList
      * @param lines : vetor contendo as linhas do ficheiro students_classes.csv
      * @param classlist : vetor que contém todas as turmas
      * @return
      */
    int defineCap(vector<Read_line> lines, vector<Turma> classlist );

     /**
      * @brief Função que organiza num vetor todas as turmas existentes
      * Complexidade Temporal:  O(n) sendo n
      * @param lines : vetor contendo as linhas do ficheiro classes_per_uc.csv
      * @return vetor contendo todas as turmas existentes
      */
    vector<Turma> classList(vector<Read_line> lines);

      /** @brief Função que determina o maior índice onde o estudante consta
       * Complexidade Temporal: O(log(n)) sendo n o comprimento do vetor classes
       * @param classes : vetor com as turmas
       * @param index : índice
       * @return índice
       */
    int highStudentIndex(vector<Read_line> classes, int index);

      /**
       * @brief Função que determina o menor índice onde o estudante consta
       * Complexidade Temporal:  O(log(n)) sendo n o comprimento do vetor classes
       * @param classes : vetor com as turmas
       * @param index : índice
       * @return índice
       */
    int lowStudentIndex(vector<Read_line> classes, int index);

      /**
       * @brief Função que encontra o grupo de UCs da lista
       * Complexidade Temporal:  O(log(n))
       * @param classes : vetor com as turmas
       * @param index : índice
       * @return um vetor com o grupo de UCs
       */
    vector<Read_line> find_uc(vector<Read_line> classes, int index);
};



#endif //UNTITLED_UC_H
