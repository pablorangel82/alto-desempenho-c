/*
 * Cliente UDP
 */

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32)

#include <winsock2.h>
#include <io.h>

#else
#include <netdb.h>
#include <poll.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <unistd.h>
#endif /* _WIN32 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    WSADATA wsaData;
    int porta_servidor = 2000;
    char ip_servidor[50];
    unsigned char *mensagem;
    int sock, retorno;
    struct sockaddr_in endereco_cliente, endereco_servidor;

    sprintf(ip_servidor, "127.0.0.1");
    mensagem = (unsigned char *) malloc(7);
    *mensagem = 6;
    sprintf(mensagem+1, "Pablo");

    endereco_servidor.sin_family =  AF_INET;
    endereco_servidor.sin_addr.s_addr = inet_addr(ip_servidor);
    endereco_servidor.sin_port = htons(porta_servidor);

    if( WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
        WSACleanup();
        return -1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("%s: não foi possível abrir socket \n", ip_servidor);
        exit(1);
    }

    endereco_cliente.sin_family = AF_INET;
    endereco_cliente.sin_addr.s_addr = htonl(INADDR_ANY);
    endereco_cliente.sin_port = htons(0);

    retorno = bind(sock, (struct sockaddr *) &endereco_cliente, sizeof(endereco_cliente));
    if (retorno < 0) {
        printf("%s: não foi possível fazer bind\n", ip_servidor);
        exit(1);
    }

    retorno = sendto(sock, mensagem, 7, 0,
                     (struct sockaddr *) &endereco_servidor,
                     sizeof(endereco_servidor));

    if (retorno < 0) {
        printf("Não foi possível enviar mensagem \n");
        close(sock);
        exit(1);
    }


    return 1;

}