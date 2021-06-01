#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//Server includes
#include <sys/socket.h>
#include <netinet/in.h>

//HTML parsing library
//#include "gumbo.h" 
#include <sys/stat.h>

//connection port
#define PORT 8080
#define IP "127.0.0.1"

static void read_file(FILE *fp, char **output, int *length);

int main(void) {

    int serverSocket = 0;

    //Creating a socket, AF_INET is for IPv4
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error in socket");
        exit(EXIT_FAILURE);
    }

    //setting address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT); //htons() is for converting TCP/IP network byte order.
    address.sin_addr.s_addr = INADDR_ANY;//inet_addr(IP); //possible to use INADDR_ANY in order to access any incoming connections
    memset(&address.sin_zero, 0, sizeof(address.sin_zero)); //IMPORTANT to clear sin_zero because of unexpected behavior!
    
    //binding server
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Error in bind");
        exit(EXIT_FAILURE);
    }

    //setting listen
    if (listen(serverSocket, 10) < 0) {
        perror("Error in listen");
        exit(EXIT_FAILURE);
    }

    long valRead = 0;
    int newSocket = 0;
    int addrLen = sizeof(address);


    //getHTML
    const char *filename = "index.html";
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (!fp) {
        perror("Error in file opening");
        exit(EXIT_FAILURE);
    }

    char *input;
    int input_length;
    read_file(fp, &input, &input_length);
    
    size_t size = 0;
    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);

    char *sizeStr = (char *)malloc(1000 * sizeof(char));
    sprintf(sizeStr, "%ld", size);
    printf("%s\n", sizeStr);

    char *send = malloc(1000 * sizeof(char));
    
    stpcpy(send, "HTTP/1.1 200 OK\nContent-Type: text/html;charset=UTF-8\nContent-Length: ");
    strcat(send, sizeStr);
    strcat(send, "\n\n");
    strcat(send, input);

    while(1) {
        printf("Waiting for a connection.\n");
        if ((newSocket = accept(serverSocket, (struct sockaddr*)&address, (socklen_t*)&addrLen)) < 0) {
            perror("Error in accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted.\n");
        
        char buffer[30000] = {0};
        valRead = read(newSocket, buffer , sizeof(buffer));
        printf("%s\n", buffer);
        write(newSocket, send, strlen(send));
        printf("Sent\n");
        if (close(newSocket) < 0) {
            perror("Error in close");
            exit(EXIT_FAILURE);
        }
        
        printf("Connection closed.\n");
        exit(EXIT_SUCCESS);
    }
    return 0;
}

static void read_file(FILE *fp, char **output, int *length) {
    struct stat filestats;
    int fd = fileno(fp);
    fstat(fd, &filestats);
    *length = filestats.st_size;
    *output = malloc((*length) + 1);
    int start = 0;
    int bytes_read;
    while ((bytes_read = fread(*output + start, 1, *length - start, fp))) {
        start += bytes_read;
    }
    
}