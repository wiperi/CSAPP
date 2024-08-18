/**
 * HTTP Request - Request for index.html from a server
 */
#include "csapp.h"

int main(int argc, char** argv) {
    int clientfd;
    char *host, *port, buf[MAXLINE];
    rio_t rio;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(0);
    }
    host = argv[1];
    port = argv[2];

    // Connect to server
    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);

    char request_header[] =
        "GET /index.html HTTP/1.1\r\nHost: localhost:7890\r\n\r\n";

    // Send header to server
    Rio_writen(clientfd, request_header, strlen(request_header));

    // Read response from server
    Rio_readlineb(&rio, buf, MAXLINE);
    char prev_line[MAXLINE];
    strcpy(prev_line, buf);
    int i = 0;
    while (1) {
        Fputs(buf, stdout);
        Rio_readlineb(&rio, buf, MAXLINE);

        if (strcmp(prev_line, buf) == 0) {
            break;
        } else {
            strcpy(prev_line, buf);
        }
    }

    Close(clientfd); // line:netp:echoclient:close
    exit(0);
}
/* $end echoclientmain */