//
// Created by mano on 10.12.16.
//

#ifndef PORTFORWARDERREDEAWROFTROP_CONNECTION_H
#define PORTFORWARDERREDEAWROFTROP_CONNECTION_H

#include "Buffer.h"

class Connection {
    int socket_read;
    int socket_write;

    bool flag_closed;

    bool flag_from_client;
    bool flag_handled_first_line;

    Buffer * buffer;

    Connection * pair;

public:
    Connection(int socket_read, int socket_write, bool flag_from_client);

    int get_read_socket();

    int get_write_socket();

    void set_close();

    bool is_closed();

    int do_receive();

    int do_send();

    bool is_buffer_have_data();

    void set_pair(Connection * pair);

    void set_buffer_data(char * data, size_t data_size);

    void set_buffer(Buffer * buffer);

    bool is_handled_first_line();

    void set_handled_first_line();

    char * get_p_new_line();

    char * get_buffer_start();

    ~Connection();
};


#endif //PORTFORWARDERREDEAWROFTROP_CONNECTION_H
