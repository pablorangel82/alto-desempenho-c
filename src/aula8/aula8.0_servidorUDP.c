/*
 * Servidor UDP
 */

#if defined(_WIN32) || defined(_WIN64) || defined(WIN32)
#include <winsock2.h>

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
#include <errno.h>
#include <io.h>

int main(int argc, char *argv[]) {
    WSADATA wsaData;
    int porta_servidor = 2000;
    char ip_servidor[50];
    unsigned char *mensagem;
    int sock, retorno;
    struct sockaddr_in endereco_cliente, endereco_servidor;

    sprintf(ip_servidor, "127.0.0.1");


    // Iniciar a biblioteca winsock...
    if( WSAStartup(MAKEWORD(2,2), &wsaData) != 0){
          return -1;
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("%s: nao foi possivel abrir socket\n", ip_servidor);
        exit(1);
    }

    endereco_servidor.sin_family = AF_INET;
    endereco_servidor.sin_addr.s_addr = htonl(INADDR_ANY);
    endereco_servidor.sin_port = htons(porta_servidor);

    retorno = bind(sock, (SOCKADDR *)&endereco_servidor, sizeof(endereco_servidor));
    if ( retorno == SOCKET_ERROR){
        close(sock);
        WSACleanup();
        return -1;
    }

    printf("aguardando mensagens da porta UDP");

    while(1) {
        int len = sizeof (endereco_cliente);
        mensagem = (unsigned char *) malloc(7);
        memset(mensagem,0,7);
        retorno = recvfrom(sock, mensagem, 7, 0,
                           (struct sockaddr *) &endereco_cliente, &len);
        printf("Quantidade de bytes: %d", *(mensagem));

        if(retorno<0) {
            printf("problema com o recebimento de dados\n");
            continue;
        }

        printf(mensagem+1);

    }
    return 1;

}