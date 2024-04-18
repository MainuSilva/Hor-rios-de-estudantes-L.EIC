#ifndef UNTITLED_READ_LINE_H
#define UNTITLED_READ_LINE_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/**
 * @brief Classe Para manipular e aceder os dados armazenados no vetor que leu os ficheiros
 */


class Read_line {

private:

    /// Vetor contendo as linhas de um determinado ficheiro
    vector<string> values;

public:

    /**
     * @brief Default Constructor
     */
    Read_line();

    /**
     * @brief Contructor da Classe
     * Complexidade Temporal: O(1)
     * @param other
     */
    Read_line(const Read_line& other);

    /**
     * @brief Organiza as colunas
     * Complexidade Temporal: O(n) sendo n o comprimento da linha
     * @param line : 1 linha do ficheiro
     * @param end_line : fim da linha
     */
    void parse(string line, char end_line = ',');

    /**
     * @brief Função para obter 1 dos dados que a linha contém (string)
     * Complexidade Temporal: O(1)
     * @param column: qual a posição do dado a recolher
     * @return O dado que se pretendia aceder
     */
    string getString(int column);

    /**
     * @brief Função para obter 1 dos dados que a linha contém (decimal)
     * Complexidade Temporal: O(1)
     * @param column: qual a posição do dado a recolher
     * @return O dado que se pretendia aceder
     */
    double getDouble(int column);

    /**
     * @brief Função que permite mudar um valor
     * Complexidade Temporal: O(1)
     * @param new_value : novo valor
     * @param column : posição do valor a mudar
     */
    void change_Value(string new_value, int column);

    /**
     * @brief Função para obter 1 dos dados que a linha contém (inteiro)
     * Complexidade Temporal: O(1)
     * @param column: qual a posição do dado a recolher
     * @return O dado que se pretendia aceder
     */
    int getInt(int column);
};


#endif //UNTITLED_READ_LINE_H
