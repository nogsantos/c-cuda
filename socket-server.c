/**
 * ./socket-server 8080
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    int newsockfd;
    int portno;
    int n;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    
    if (argc < 2) {
        fprintf(stderr, "ERRO, porta n�o foi requistada\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        error("ERRO ao abrir socket");
    }
    
    bzero((char *) &serv_addr, sizeof (serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0){
        error("ERRO no binding");
    }
    
    listen(sockfd, 5);
    clilen = sizeof (cli_addr);
    
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    
    if (newsockfd < 0){
        error("ERRO no accept");
    }
    
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    
    if (n < 0){
        error("ERRO ao ler do socket");
    }
    
    printf("A mensagem recebida foi: %s\n", buffer);
    n = write(newsockfd, "Recebi sua mensagem", 18);
    
    if (n < 0){
        error("ERRO ao escrever no socket");
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}