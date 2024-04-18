#ifndef UNTITLED_INTERFACE_H
#define UNTITLED_INTERFACE_H

#include "Read_line.h"
#include <vector>
#include <set>
#include "Turma.h"
#include "Uc.h"
#include "Read_line.h"
#include "Read_file.h"
#include "Aula.h"
#include "Pedido_troca.h"

/**
 * @brief Classe que funciona como interface
 */

class Interface{

private:

    /// vetor contendo todas as linhas do ficheiro classes.csv
    vector<Read_line> classesCsv_lines_;

    /// vetor contendo todas as linhas do ficheiro classes_per_uc.csv
    vector<Read_line> classes_per_uc_lines_;

    /// vetor contendo todas as linhas do ficheiro students_classes.csv
    vector<Read_line> student_classes_lines_;

    /// Termina a execução do programa quando for true
    bool end_prog; // para terminar o programa se estiver true;

    /// Permite saber se já foi feito o login na área de permutação de estudantes
    bool login;
    string username;

    ///set com o código de todas as Unidades Curriculares
    set<string> all_UCs; // saber o set de cada (útil)

    /// set com o código de todos os estudantes
    set<string> all_students;

    /// set com o código de todas as turmas
    set<string> all_classes;

    /// vetor que armazena os pedidos de troca entre dois estudantes
    vector<vector<Pedido_troca>> double_request; //vetor analisado no final

    /// vetor que armazena os pedidos de troca individuais
    vector<Pedido_troca> one_request;

    /// vetor que armazena as trocas entre dois estudantes efetuadas
    vector<vector<Pedido_troca>> accepted_two_students;

    /// vetor que armazena as trocas individuais efetuadas
    vector<Pedido_troca> accepted_one_student;

    /// vetor que armazena as trocas individuais rejeitadas
    vector<Pedido_troca> refused_requests;

    /// vetor que armazena as trocas entre dois estudantes rejeitadas
    vector<vector<Pedido_troca>> refused_two_students;



public:

    /**
     * @brief Constructor da Classe
     * Complexidade Temporal: O(1)
     * @param classesCsv_lines : vetor com as linhas de classes.csv
     * @param classes_per_uc_lines : vetor com as linhas de classes_per_uc.csv
     * @param student_classes_lines : vetor com as linhas de students_classes.csv
     */
    Interface (vector<Read_line> classesCsv_lines, vector<Read_line> classes_per_uc_lines, vector<Read_line> student_classes_lines);

    /**
    * @brief Função que verifica se o código de estudante introduzido existe/é válido
    * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador insere um input inválido
    * @return o código de estudante
    */
    string find_Up();

    /**
     * Função que verifica se o código da UC introduzido existe/é válido
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador insere um input inválido
     * @return o código da UC
     */
    string find_UC();

    /**
     * Função que verifica se o código da turma introduzido existe/é válido
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador insere um input inválido
     * @return o código da turma
     */
    string find_Class();

    /**
     * @brief Função que verifica se o utilizador quer de facto sair após ter pressionado "E"
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     * @return true se o utilizador pretender sair (pressionando Y) ou false se o utilizador pretender continuar a utilizar o programa (pressionando N)
     */
    static bool verifyExit();

    /**
     * @brief Função que cria uma interface para o menu inicial, com todas as opções de navegação associadas
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void showMenu();

    /**
     * @brief Função que cria uma interface para o menu da informação das UCs
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void uc_Info();

    /**
     * @brief Função que cria uma interface para o menu da lista de todas as UCs
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void list_Ucs();

    /**
     * @brief Getter para o horário de uma única UC às várias turmas
     * Imprime o horário usando a função print_horario_uc_code da classe Uc
     * Complexidade Temporal: O(1)
     */
    void get_UcSchedule();

    /**
     * @brief Função que imprime o número total de estudantes a frequentar uma determinada Uc
     * Complexidade Temporal: O(1)
     */
    void number_Students_Uc();

    /**
     * @brief Função que imprime os códigos de todas as UCs
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor all_UCs
     */
    void list_All_Ucs();

    /**
     * @brief Função que imprime os códigos de todas as UCs de um determinado ano
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor classes_per_uc_lines_
     */
    void list_By_Year_UC();

    /**
     * @brief Função que cria uma interface para o menu da informação das turmas
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void class_Info();

    /**
     * @brief Função que cria uma interface para as listas de turmas
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void list_Classes();

    /**
     * @brief Função que imprime o horário de uma turma
     * Complexidade Temporal: O(1)
     */
    void class_Schedule();

    /**
     * @brief Função que imprime o número de estudantes numa turma por uc
     * Complexidade Temporal: O(1)
     */
    void number_Students_Class();

    /**
     * @brief Função que imprime os códigos de todas as turmas de uma UC
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor  classes_per_uc_lines_
     */
    void show_Classes_UC();

    /**
     * @brief Função que imprime os códigos de todas as turmas
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor all_classes
     */
    void show_All_Classes();

    /**
     * @brief Função que imprime os códigos de todas as turmas de um ano
     * Complexidade Temporal: O(n) sendo n o comprimento do vetor all_classes
     */
    void show_Classes_Year();

    /**
     * @brief Função que cria uma interface para o menu informação do estudante
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void student_Info();

    /**
     * @brief Função que cria uma interface para se introduzir a UC da qual se quer a lista de estudantes
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void list_UcStudents();

    /**
     * @brief Função que imprime o Horário de um estudante
     * Complexidade temporal: O(n) sendo n o número de linhas de students_classes.csv
     */
    void get_StudentSchedule();

    /**
     * @brief Função que cria uma interface para o menu das listas de estudantes
     * Complexidade temporal: O(1)
     */
    void list_Students();

    /**
     * @brief Função que cria uma interface para se introduzir a UC e turma da qual se quer a lista de estudantes
     * Complexidade temporal: O(1)
     */
    void list_Class_Students();

    /**
     * @brief Função que cria uma interface para o menu onde o utilizador decide de que maneira pretende ver os dados organizados
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     * @param input : Especificação da listagem a apresentar
     * @param value_1 : Código da Uc
     * @param value_2 : Código da turma
     */
    void list_All_Students(string input, string value_1 = "", string value_2 = "");

    /**
     * @brief Função que cria uma interface para o menu onde o utilizador decide de que forma, dentro da ordem alfabética, pretende ver os dados organizados
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     * @param input : Especificação da listagem a apresentar
     * @param value_1 : Código da Uc
     * @param value_2 : Código da turma
     */
    void alphabetic_Order(string input, string value_1 = "", string value_2 = "");

    /**
     * @brief Função que imprime os estudantes por ordem crescente de nome
     * Complexidade Temporal: O(n) sendo n o comprimento do set alunos
     * @param input : Especificação da listagem a apresentar
     * @param value_1 : Código da Uc
     * @param value_2 : Código da turma
     */
    void ascending_Order(string input, string value_1 = "", string value_2 = "");

    /**
     * @brief Função que imprime os estudantes por ordem decrescente de nome
     * Complexidade Temporal: O(n) sendo n o comprimento do set alunos
     * @param input : Especificação da listagem a apresentar
     * @param value_1 : Código da Uc
     * @param value_2 : Código da turma
     */
    void descending_Order(string input, string value_1 = "", string value_2 = "");

    /**
     * @brief Função que imprime a lista de estudantes com mais de x UCs
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador insere um input inválido
     */
    void number_Of_Ucs();

    /**
     * @brief Função que cria uma interface para o menu de trocas de turma/horário
     * Complexidade Temporal: O(n) sendo n o número de vezes que o utilizador navega no menu
     */
    void class_Permute();

    /**
     * @brief Função que processa os pedidos de alteração individuais e os guarda num vetor
     * Complexidade Temporal: O(1)
     */
    void only_One_Std();

    /**
     * @brief Função que processa os pedidos de alteração entre dois estudantes e os guarda num vetor
     * Complexidade Temporal: O(1)
     */
    void bet_Two_Std();

    /**
     * @brief Função que avalia todos os pedidos de alteração e efetua as mudanças que cumprem os critérios de alteração
     * Complexidade temporal: O(log(n)) sendo n o comprimento do vetor que guarda os pedidos de alteração
     */
    void process_Changes();

};
#endif //UNTITLED_INTERFACE_H
