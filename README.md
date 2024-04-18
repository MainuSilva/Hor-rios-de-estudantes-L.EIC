# Projeto-AED

## Tarefas a implementar
Na implementação do trabalho, deve usar as estruturas de dados lista, vetor, fila e árvore binária de pesquisa
(pode usar ainda outras estruturas, se considerar necessário). Essas estruturas servirão de base para as
seguintes tarefas e nos seguintes contextos:
  1. Leitura dos dados fornecidos e criação das estruturas de dados que representam o cenário
  referido. Deve usar as estruturas de dados lineares mais apropriadas em cada contexto, sendo,
  no entanto, sugerido e valorizado o uso da estrutura árvore binária de pesquisa1
  (estrutura de
  dados hierárquica) no armazenamento dos estudantes.
  2. Listagens várias, totais e parciais, com critérios a definir pelo utilizador. Podem também ter
  ordenações distintas a definir pelo utilizador. Exemplos:
  − Ocupação de turmas/ano/UC (ordenação por UC, ordenação crescente, ordenação
  decrescente, …)
  − Horário de determinado estudante
  − Estudantes em determinada turma/UC/ano
  − Estudantes com mais de n UCs (implica uso de BST) (ordem alfabética, ordem nºs
  UCs,…)
  − …
  3. Os pedidos de alteração de horários são guardados numa fila, sendo processados no final do
  dia. Os pedidos que não puderem ser satisfeitos, são guardados para arquivo em outra
  estrutura de dados à sua escolha. Os pedidos a tratar incluem:
    i. Remover estudante de turma/UC.
    ii. Adicionar estudante a uma turma/UC:
  a) Só é possível se o horário é compatível e a turma possui vaga. Considerar a
  capacidade de uma turma igual a um valor máximo Cap.
  b) Só é possível se o horário é compatível e não provoca desequilíbrio nas turmas
  dessa UC. Considerar que existe desequilíbrio nas turmas de uma UC se a
  diferença entre o nº de estudantes em duas quaisquer turmas dessa UC é >=4.
    iii. Alterar a turma/UC de um estudante. Considerar as alternativas a), b) do caso ii.
    iv. Alterar um conjunto de turmas/UCs de um estudante. Considerar as alternativas a) e
  b) do caso ii.
  
Implemente também outras funcionalidades que considere relevantes, para além dos requisitos globais enunciados.

Outros requisitos:
  ● O sistema deverá ter um menu que dispõe, de forma amigável, as funcionalidades implementadas.
  ● Deve incluir documentação do código implementado, usando Doxygen, e indicando a respetiva
  complexidade.

## Resultados esperados
A aplicação a desenvolver deve permitir registar e gerir entidades e relações entre elas, fazendo uso das
estruturas lineares vetor, lista e fila e da estrutura hierárquica árvore binária de pesquisa.
A aplicação a desenvolver deve:
  ● Utilizar classes adequadas para representação das entidades envolvidas
  ● Utilizar estruturas lineares (vetores, listas e filas) e a estrutura hierárquica árvore binária de
  pesquisa (esta última é um fator de valorização)
  ● Guardar informação em ficheiros para uso futuro
  ● Incluir documentação das funções implementadas, usando Doxygen, e indicando a sua
  complexidade.
  A aplicação deve também permitir listagens várias:
  ● As listagens podem ser totais ou parciais com critérios a definir pelo utilizador
  ● Podem também ter ordenações distintas definidas pelo utilizador
  ● Devem ser usados algoritmos de pesquisa e ordenação para este efeito
  Sobre a demonstração do trabalho:
  ● Preparação adequada para demonstrar as funcionalidades do trabalho
  ● Elaboração de uma apresentação (diapositivos) para suporte à demonstração
