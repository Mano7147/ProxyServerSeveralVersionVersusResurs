//
// Created by mano on 10.12.16.
//

#ifndef PORTFORWARDERREDEAWROFTROP_INCLUDES_H
#define PORTFORWARDERREDEAWROFTROP_INCLUDES_H

#include <cstdlib> //exit, atoi
#include <cstdio> //perror
#include <netdb.h> //gethostbyname
#include <cstring> //memcpy
#include <sys/socket.h> //sockaddr_in, AF_INET, socket, bind, listen, connect
#include <poll.h> //poll
#include <unistd.h> //read, write, close
#include <arpa/inet.h> //htonl, htons
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <fstream>
#include <signal.h>
#include <chrono>

#include "Constants.h"


#endif //PORTFORWARDERREDEAWROFTROP_INCLUDES_H
