#include "BindingSocket.hpp"


// Constructor
HDE::BindingSocket::BindingSocket(int domain, int service, int protocol, int port, u_long interface):SimpleSocket(domain, service, protocol, port, interface){
set_connection(connect_to_network(get_sock(), get_address()));
}

// implementation of connect_to_network virtual function
int HDE::BindingSocket::connect_to_network(int sock,struct sockaddr_in address){
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}