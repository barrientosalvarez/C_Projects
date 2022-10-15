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

    //creating our socket
    int sfd=socket(AF_INET, SOCK_STREAM, 0);
    if(0>sfd)
    {
        perror("socket");
        return -1;
    }

}
