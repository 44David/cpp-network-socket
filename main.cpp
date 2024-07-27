#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

int main(int argc, char** argv) {

    
  WSADATA wsaData;


  // initialize socket
  int res = WSAStartup(MAKEWORD(2,2), &wsaData);

  if (res != 0) {
    std::cout << "An error ocurred: " << WSAGetLastError() << std::endl;

  } else {
    std::cout << "Successful. System Status: " << std::endl << wsaData.szSystemStatus << std::endl;
  };


  // CLI::App app{"C++ Packet Analyzer"};
  // argv = app.ensure_utf8(argv);
  // std::string user_defined_addr = "127.0.0.1";

  // add.option("-a --address", user_defined_addr);

  // CLI11_PARSE(app, argc, argv);
  
  // create a socket, and bind it to an address and port
  SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  int port = 3000;
  sockaddr_in tcpaddr;
  tcpaddr.sin_family = AF_INET;
  tcpaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  tcpaddr.sin_port = htons(port);

  bind(ServerSocket, (SOCKADDR *)&tcpaddr, sizeof(tcpaddr));

  std::cout << "Socket successfully bound to tcp address" << std::endl;


  // make the socket listen to the address
  if ( listen(ServerSocket, 1) == SOCKET_ERROR ) {
    std::cout << "An error occured when listening to this socket." << std::endl << WSAGetLastError() << std::endl;
  } else {
    std::cout << "Socket is listening with no errors" << std::endl;
  }

  // accept connections with the socket
  while(true) {
    SOCKET acceptSocket = (ServerSocket, (SOCKADDR *)&tcpaddr, sizeof(tcpaddr));

    char buffer[4096];

    if (recv(acceptSocket, buffer *, 4096, 0) == SOCKET_ERROR) {
      std::cout << "Socket failed to fetch bytes";
      break;
    } else {
      std::cout << buffer;
    };




  }
  
  return 0;
};

void getHTTPResponseData(int argc, char** argv) {
  
}


// to compile run:
// g++ main.cpp -lws2_32
