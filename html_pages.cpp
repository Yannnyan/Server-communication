#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>



#define PORT 55013
#define ADDRESS "8.8.8.8"
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

    

}





