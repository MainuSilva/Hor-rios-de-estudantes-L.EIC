#ifndef UNTITLED_AULA_H
#define UNTITLED_AULA_H

#include <ostream>
#include <string>
#include "Read_line.h"

using namespace std;

/**
 * @brief Classe que representa uma aula
 */

class Aula {
private:

    /// Código da turma (no formato "XLEICXX")
    std::string classCode_;

    /// Código da Unidade Curricular (no formato "L.EICXXX")
    std::string ucCode_;

    /// Dia da semana
    std::string weekDay_;

    /// Hora do início da aula
    double startHour_;

    /// Duração da aula
    double duration_;

    /// Tipo de aula
    std::string type_;



public:

    /**
     * @brief Constructor da classe
     * Complexidade Temporal: O(1)
     * @param classCode : Código da turma
     * @param ucCode : Código da UC
     * @param weekDay : Dia da semana
     * @param startHour : Hora de início
     * @param duration : Duração
     * @param type : Tipo de aula (Teórica, Teórico-Prática, ou Prática Laboratorial)
     */
    Aula(string classCode, string ucCode, string weekDay, double startHour, double duration, string type);

    /**
     * @brief Outro Contructor da classe
     * Retira os parâmetros usados no constructor anterior interpretando 1 linha do ficheiro
     * @param 1 linha do ficheiro classes.csv
     */
    Aula(Read_line);

    /**
     * @brief Getter para classCode
     * Complexidade temporal O(1)
     * @return O código da turma
     */
    string get_classCode() const;

    /**
     * @brief Getter para ucCode
     * Complexidade temporal O(1)
     * @return O código da UC
     */

    string get_ucCode() const;

    /**
     * @brief Getter para weekDay
     * Complexidade temporal O(1)
     * @return O dia da semana
     */

    string get_weekDay() const;

    /**
    * @brief Getter para weekDay
    * Complexidade temporal O(1)
    * @return A hora
    */
    double get_startHour() const;

    /**
     * @brief Getter para duration
     * Complexidade temporal O(1)
     * @return A duração
     */
    double get_duration() const;

    /**
     * @brief Getter para type
     * Complexidade temporal O(1)
     * @return O tipo de aula
     */
    string get_type() const;

    /**
     * @brief Getter para a hora do fim da aula, calculada com startHour e duration
     * Complexidade temporal O(1)
     * @return A hora do fim da aula
     */
    double get_endingTime() const; // determinar o valor double da aula final

    /**
    * @brief Função para avaliar se duas aulas estão sobrepostas, em cenário de alteração de horários
    * Complexidade temporal O(1)
    * @param new_aula: aula destino, a que o aluno frequentará se a alteração se concretizar
    * @return true se estiverem sobrepostas, false caso contrário
    */
    bool is_overlaped(Aula new_aula);

};

#endif //UNTITLED_AULA_H
