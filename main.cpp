#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

int main() {

  
  WSADATA wsaData;

  int res = WSAStartup(MAKEWORD(2,2), &wsaData);

  if (res != 0) {
    std::cout << "An error ocurred: " << WSAGetLastError() << std::endl;

  } else {
    std::cout << "Successful. System Status: " << std::endl << wsaData.szSystemStatus << std::endl;
  };

  SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  int port = 4000;
  sockaddr_in tcpaddr;
  tcpaddr.sin_family = AF_INET;
  tcpaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  tcpaddr.sin_port = htons(port);

  bind(ServerSocket, (SOCKADDR *)&tcpaddr, sizeof(tcpaddr));

  std::cout << "Socket successfully bound to tcp address" << std::endl;

  if ( listen(ServerSocket, 1) == SOCKET_ERROR ) {
    std::cout << "An error occured when listening to this socket." << std::endl << WSAGetLastError() << std::endl;
  } else {
    std::cout << "Socket is listening with no errors";
  }

};


// to compile run:
// g++ main.cpp -lws2_32
