#include "SimpleSocket.hpp"

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface){
    // Define address structure
address.sin_family = domain;
address.sin_port = htons(port);
address.sin_addr.s_addr = htonl(interface);

// Establish socket
sock = socket(domain, service, protocol);
test_connetion(sock);


}

void HDE::SimpleSocket::test_connetion(int item_to_test)
{
    // confirm if socket or connection is established successfully
    if(item_to_test <0){
        perror("Failed to connect!");
        exit(EXIT_FAILURE);
    }
}

// Getter functions
struct sockaddr_in HDE::SimpleSocket::get_address()
{
  return address;
};

int HDE::SimpleSocket::get_sock()
{
    return sock;
}

int HDE::SimpleSocket::get_conncetion()
{
    return connection;
}

// Setter function
void HDE::SimpleSocket::set_connection(int conn)
{
    connection = conn;
}