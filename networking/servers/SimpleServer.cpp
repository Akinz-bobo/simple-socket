#include "SimpleServer.hpp"

HDE::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int kblg){
socket = new ListeningSocket(domain, service, protocol, port, interface, kblg);
}

HDE::ListeningSocket *HDE::SimpleServer::get_socket(){
    return socket;
}