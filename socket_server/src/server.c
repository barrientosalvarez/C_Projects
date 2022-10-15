/*
 * This is my firts time triying to code and understand a socket server.
 * Code coppied from the Low Level Learning YouTube channel, check the video
 * named: "coding a socket server in C but i START OVER every time i get a compiler
 * error".
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>

int main(int argc, char **arvg)
{
    // creation of the socket info structures.
    struct sockaddr_in server_info={0};
    
    server_info.sin_family=AF_INET;
    server_info.sin-port=htons(1337);

    socklen_t server_info_len=sizeof(server_info);

    struct sockaddr client_info={0};
    socklen_t client_info_len=sizeof(client_info);

    //creating our socket
    int sfd=socket(AF_INET, SOCK_STREAM, 0);
    if(0>sfd)
    {
        perror("socket");
        return -1;
    }

    //bind
    if(0>bind(sfd, (struct sockaddr*)&server_info, server_info_len))
    {
        perror("bind");
        return -1;
    }

    //listen
    if(0>listen(sfd, 0))
    {
        perror("listen");
        return -1;
    }

    //accept
    int cfd=accept(sfd, &client_info, &client_info_len);
    if(0>cfd)
    {
        perror("accept");
        return -1;
    }


}
