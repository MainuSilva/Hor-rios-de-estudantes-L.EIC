#ifndef UNTITLED_TURMA_H
#define UNTITLED_TURMA_H

#include <ostream>
#include <string>
#include <list>
#include "Aula.h"

/**
 * @brief Classe que representa uma Turma
 */

class Turma {

private:

    /// Código da Turma
    std::string classCode_;

    /// Código da UC
    std::string ucCode_;


public:

    /**
     * @brief Constructor da classe
     * Complexidade Temporal: O(1)
     * @param classCode : Código da turma
     * @param ucCode : código da UC
     */
    Turma(string classCode, string ucCode);

    /**
     * @brief Outro Contructor da Classe
     * Complexidade Temporal: O(1)
     * @param classCode : Código da turma
     */
    Turma(std::string classCode);

    /**
     * @brief Getter para o horário da turma em causa
     * Complexidade Temporal: O(1)
     * @param lines : vetor com as linhas do ficheiro classes.csv
     * @return um vetor com as várias aulas que compõem o horário da turma
     */
    vector<Aula> get_horario_turma(std::vector<Read_line> lines);

    /**
     * @brief Função que permite criar uma interface para o Horário de uma turma
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor horario
     * @param classCode : Código da turma
     * @param horario : Horário da turma
     */
    void print_horario_class_code( vector<Aula> horario);

    /**
     * @brief Função que calcula o número de estudantes existentes numa determinada turma de uma determinada UC
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor lines
     * @param lines : vetor com as linhas do ficheiro studentes_classes.csv
     * @return Número de estudantes da turma
     */
    int getStudentNumber(vector<Read_line> lines);

    /**
     * @brief Getter para código da turma em causa
     * Complexidade Temporal: O(1)
     * @return Código da turma
     */
    const string &getClassCode() const;


};


#endif //UNTITLED_TURMA_H
