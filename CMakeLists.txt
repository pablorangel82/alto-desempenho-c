cmake_minimum_required(VERSION 3.26)
project(alto_desempenho_c C)

set(CMAKE_C_STANDARD 11)
link_libraries(ws2_32 wsock32)

add_executable(aula1.0 src/aula1/aula1.0.c
        src/aula8/aula8.0_servidorUDP.c)
add_executable(aula2.0 src/aula2/aula2.0.c)
add_executable(aula2.1 src/aula2/aula2.1.c)
add_executable(aula3.0 src/aula3/aula3.0.c)
add_executable(aula4.0 src/aula4/aula4.0.c)
add_executable(aula5.0 src/aula5/aula5.0.c)
add_executable(aula6.0 src/aula6/aula6.0.c
        src/aula6/aula6.0.c
        src/aula6/aula6.1.c
        src/aula6/aula6.2.c)
#add_executable(aula7.0 src/aula7/aula7.0.c
#        src/aula7/aula7.1.c)
add_executable(aula7.0 src/aula7/aula7.1.c)
add_executable(cliente_udp src/aula8/aula8.0_clienteUDP.c)
add_executable(servidor_udp src/aula8/aula8.0_servidorUDP.c)