#include "ConnectSocket.hpp"

HDE::ConnectSocket::ConnectSocket(int domain, int service, int protocol, int port,  u_long interface ) : SimpleSocket(domain, service, protocol, port, interface){
    set_connection(connect_to_network(get_sock(), get_address()));
    test_connetion(get_conncetion());
}

int HDE::ConnectSocket::connect_to_network(int sock, struct sockaddr_in address){
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}