#include "ListeningSocket.hpp"

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg): BindingSocket(domain, service, protocol, port, interface){
    backlog = bklg;
    start_listening();
    std::cout <<"listening on port: " << port << std::endl;
    test_connetion(listening);
};
void HDE::ListeningSocket::start_listening()
{
   listening =  listen(get_sock(), backlog);
}