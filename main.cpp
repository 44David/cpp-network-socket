#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

int main() {    
    SOCKET ListenSocket;
    struct sockaddr_in saServer;

    auto host = gethostbyname("127.0.0.1");
    auto hostIP = inet_ntoa (*(struct in_addr *)*host->h_addr_list);

    std::cout << listen(ListenSocket, SOMAXCONN);

    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2,2), &wsaData);
    std::cout << ListenSocket << std::endl;

    if ( listen( ListenSocket, SOMAXCONN ) == SOCKET_ERROR ) {
        printf("Listen failed: %ld\n", WSAGetLastError() );
        printf("Result from WSAStartup: %ld\n", res );
        closesocket(ListenSocket);
        WSACleanup();
    };  


};


// to compile run:
// g++ main.cpp -lws2_32