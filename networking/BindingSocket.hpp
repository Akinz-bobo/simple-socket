#ifndef BindingSockect_hpp
#define BindingSockect_hpp

#include "SimpleSocket.hpp"
#include <stdio.h>

namespace HDE {
    class BindingSocket: public SimpleSocket 
    {
        public:
            BindingSocket(int domain, int service,int protocol, int port, 
            u_long interface);
            int connet_to_network( int sock, struct sockaddr_in address);
    };
    
}

#endif // BindingSockect_hpp
