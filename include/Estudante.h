#ifndef UNTITLED_ESTUDANTE_H
#define UNTITLED_ESTUDANTE_H

#include <string>
#include <vector>

#include "Aula.h"
#include "Uc.h"
#include "Turma.h"

/**
 * @brief Classe que representa um estudante
 */
class Estudante {
private:

    /// Código do estudante (no formato upXXXXXXXXX)
    std::string studentCode_;

    /// Nome do estudante
    std::string studentName_;

public:

    /**
     * @brief Default Constructor da classe
     */
    Estudante();

    /**
     * @brief Constructor da classe
     * @param studentCode: Código do estudante
     */
    Estudante(std::string studentCode);

    /**
     * @brief Getter para studentCode
     * Complexidade temporal: O(1)
     * @return O código do estudante
     */
    std::string get_studentCode() const;

    /**
   * @brief Getter para studentName
   * Complexidade temporal: O(1)
   * @param lines: 1 linha do ficheiro students_classes.csv
   * @return O nome do estudante
   */
    std::string get_studentName(vector<Read_line> lines) ;

    /**
     * @brief Getter para o código da turma do estudante a uma determinada UC
     * Complexidade temporal: O(1)
     * @param lines : 1 linha do ficheiro students_classes.csv
     * @param ucCode: código da UC
     * @return O código da turma do estudante a uma determinada UC
     */
    std::string get_Classcode_in_UC(vector<Read_line> lines, std::string ucCode);

    /**
     * @brief Função que imprime uma interface para a visualização do horário de um estudante
     * @param horario : vetor com as várias aulas que o estudante frequenta
     */
    void print_horario_class_uc(vector<Aula> horario);

    /**
    * @brief Função para guardar toda a informação relativa a um estudante que conste em students_classes.csv
    * Complexidade temporal: O(log(n)), sendo n o número de linhas de students_classes.csv
    * @param students: vetor com todas as linhas do ficheiro students_classes.csv
    * @return retorna um vetor com todas as linhas em que o código do estudante em causa aparece
    */
    vector<struct Read_line> find(vector<Read_line> students);

    /**
     * @brief Função auxiliar da função anterior
     * Complexidade temporal: O(log(n)), sendo n o número de linhas de students_classes.csv
     * @param students: vetor com todas as linhas do ficheiro students_classes.csv
     * @return retorna o primeiro indíce onde o código do estudante em causa aparece
     */
    int lowerStudentIndex(vector<Read_line> students);

    int highStudentIndex(vector<Read_line> students);

    int get_number_of_ucs(vector<Read_line> students);

    vector<Aula> get_horario_Student(vector<Read_line> students, vector<Read_line> classes);
};



#endif //UNTITLED_ESTUDANTE_H

