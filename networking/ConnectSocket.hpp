#ifndef ConnectSocket_hpp
#define ConnectSocket_hpp

#include "SimpleSocket.hpp"
#include <stdio.h>

namespace HDE{
    class ConnectSocket :public SimpleSocket
    {
        public:
            ConnectSocket(int domain, int service, int protocol, int port, u_long interface);
            int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif // ConnectSocket_hpp