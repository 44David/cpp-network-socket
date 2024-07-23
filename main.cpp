#include <iostream>
#include <winsock2.h>

auto host = gethostbyname("");
auto hostIP = inet_ntoa (*(struct in_addr *)*host->h_addr_list);

int main() {
    std::cout << hostIP;
};
