#ifndef hdelibc_hpp
#define hdelibc_hpp

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE 
{
    class SimpleSocket
    {
         private:
            struct sockaddr_in address;
            int sock;
            int connection;
        public:
            SimpleSocket(int domain, int service, int protocol, int port,  u_long inteface); 
            virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;
            void test_connetion(int);
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection();
            //Setter function 
            void set_connection(int conn);
    };
}

#endif /* hdelibc_hpp */