#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief The following code has no unit testing yet therefore im adding a safery pig.
 * . 
                         _ 
 _._ _..._ .-',     _.._(`)) 
'-. `     '  /-._.-'    ',/ 
   )         \            '. 
  / _    _    |             \ 
 |  a    a    /              | 
 \   .-.                     ;   
  '-('' ).-'       ,'       ; 
     '-;           |      .' 
        \           \    / 
        | 7  .__  _.-\   \ 
        | |  |  ``/  /`  / 
       /,_|  |   /,_/   / 
          /,_/      '`-' 
 */

#define PORT 55013
#define ADDRESS "8.8.8.8"

#define MESSAGE_SIZE 1024



int main()
{   
    /**
     * @brief The purpose of this main program is to send a proper GET request for the html page of Google.
     * 
     * 
     */

    //
    struct sockaddr_in address;

    int creator = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_port = htons(PORT);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ADDRESS);
    int sock = connect(creator, (struct sockaddr *) &address, sizeof(address));
    char get_message[MESSAGE_SIZE + 1], res_message[MESSAGE_SIZE + 1];
    // bzero
    memset(get_message, 0, MESSAGE_SIZE + 1); memset(res_message, 0 , MESSAGE_SIZE + 1);
    // set variables xml req, host
    char * xml_request = (char *)"https://www.google.com";  char * host = (char *)"google.com";
    // http 1.1 header
    snprintf(get_message, MESSAGE_SIZE, 
            "GET %s HTTP/1.1\r\n"
            "HOST: %s\r\n"
            , xml_request, host);
    
    int s = send(sock, get_message, MESSAGE_SIZE, 0);
    if(s == -1)
    {
        perror("send failed.");
        exit(1);
    }
    int r = recv(sock, res_message, MESSAGE_SIZE, 0);
    if(r <= 0)
    {
        perror("recv failed");
        exit(1);
    }
    printf("%s\n", res_message);
}





