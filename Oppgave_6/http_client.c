#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <string.h>

int main()
{

    int client_socket;
    struct sockaddr_in remote_address;
    char *request, response[2024];

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Define remote address
    remote_address.sin_addr.s_addr = inet_addr("77.111.240.75");
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(80);

    // Connect to remote_address
    connect(client_socket, (struct sockaddr *)&remote_address, sizeof(remote_address));

    // Send hardcoded request
    request = "GET / HTTP/1.1\r\nHost: www.eastwillsecurity.com\r\n\r\n";
    send(client_socket, request, strlen(request), 0);

    // Recieve reply and printf it
    recv(client_socket, response, sizeof(response), 0);
    printf("%s\n", response);

    close(client_socket); // good practice
    return 0;
}

/* SOURCES 

    - https://www.binarytides.com/receive-full-data-with-recv-socket-function-in-c/
    
    - Videoer: 
        - https://www.youtube.com/watch?v=LtXEMwSG5-8&t=1184s (part 1)

        - https://www.youtube.com/watch?v=mStnzIEprH8&list=RDCMUCAQjmY2DJqwU3Eqz0oN83aw&index=2 (part 2)

*/