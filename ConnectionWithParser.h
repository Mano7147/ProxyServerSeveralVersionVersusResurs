//
// Created by mano on 10.12.16.
//

#ifndef PORTFORWARDERREDEAWROFTROP_CONNECTIONWITHPARSER_H
#define PORTFORWARDERREDEAWROFTROP_CONNECTIONWITHPARSER_H

#include "Connection.h"

class ConnectionWithParser : public Connection {
    Cache * cache;

    bool flag_data_cached;

public:
    ConnectionWithParser() : Connction() {}

    ConnectionWithParser(Cache * cache) : Connection() {
        this->cache = cache;

        flag_data_cached = false;
    }

    // NULL if it have not
    char * get_end_first_line();

    void change_input_buffer();
};


#endif //PORTFORWARDERREDEAWROFTROP_CONNECTIONWITHPARSER_H
