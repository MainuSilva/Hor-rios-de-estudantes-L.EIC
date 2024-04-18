cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled src/main.cpp src/Turma.cpp include/Turma.h src/Estudante.cpp include/Estudante.h src/Aula.cpp include/Aula.h src/Read_file.cpp include/Read_file.h src/Read_line.cpp include/Read_line.h src/Uc.cpp include/Uc.h include/Interface.h src/Interface.cpp include/Pedido_troca.h src/Pedido_troca.cpp)
