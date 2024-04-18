#ifndef UNTITLED_READ_FILE_H
#define UNTITLED_READ_FILE_H

#include "Read_line.h"
#include <vector>
#include <fstream>

/**
 * @brief Classe para ler os ficheiros
 */

class Read_file {
public:

    /**
     * @brief Default Constructor da Classe
     */
    Read_file();

    /**
     * @brief Função para armazenar os dados de um determinado ficheiro
     * Complexidade Temporal: O(n) sendo n o comprimento do ficheiro
     * @param fileName : Nome do ficheiro
     * @param hasHeader : Se o ficheiro possuir um header, salta o header
     * @return vetor contendo as linhas todas do ficheiro
     */
    std::vector<Read_line> read(std::string fileName, bool hasHeader = false);
};


#endif //UNTITLED_READ_FILE_H
