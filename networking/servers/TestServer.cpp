#include "TestServer.hpp"
#include <fcntl.h> 


HDE::TestServer::TestServer():SimpleServer(AF_INET, SOCK_STREAM, 0,8080, INADDR_ANY, 10){
launch();
}

void HDE::TestServer::accepter()
{
 struct sockaddr_in address = 
 get_socket()->get_address();
 int addrlen = sizeof(address);
 new_socket = accept (get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)sizeof(addrlen));

 read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void HDE::TestServer::responder()
{
 char *hello = "HTTP/1.1 200 OK\nGMT\nServer: Apache/2.2.14 (Win32)\nLast-Modified: Sun, 8 October 2023 0:55:56GMT\nContent-Type: text/html\nConnection: close\n\n<!DOCTYPE html><html lang='en'><head><meta charset='UTF-8'><meta name='viewport' content='width=device-width, initial-scale=1.0'><title>From Server</title></head><body><h2>Hello, Gourab please mentor me!</h2></body></html>";
 write(new_socket, hello,strlen(hello));
 close(new_socket);
}

void HDE::TestServer::launch()
{
    while(true)
    {
        std::cout << "=========== WAITING ==========" << std::endl;
        accepter();
        handler();
        responder();
        std::cout << "=========== DONE ==========" << std::endl;
    }
}