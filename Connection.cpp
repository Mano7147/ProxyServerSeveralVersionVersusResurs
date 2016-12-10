//
// Created by mano on 10.12.16.
//

#include "Connection.h"

Connection::Connection(int socket_read, int socket_write, bool flag_from_client) {
    this->socket_read = socket_read;
    this->socket_write = socket_write;

    flag_closed = false;

    buffer = new Buffer(DEFAULT_BUFFER_SIZE);

    this->flag_from_client = flag_from_client;
    this->flag_handled_first_line = false;
}

int Connection::get_read_socket() {
    return socket_read;
}

int Connection::get_write_socket() {
    return socket_write;
}

void Connection::set_close() {
    flag_closed = true;
}

bool Connection::is_closed() {
    return flag_closed;
}

bool Connection::is_buffer_have_data() {
    return buffer->is_have_data();
}

int Connection::do_receive() {
    ssize_t received = recv(socket_read, buffer->get_end(), buffer->get_empty_space_size(), 0);

    if (-1 == received) {
        perror("recv");
        set_close();

        return RESULT_INCORRECT;
    }
    else if (0 == received) {
        fprintf(stderr, "Receive done\n");
        set_close();
        pair->set_close();

        return RESULT_CORRECT;
    }
    else {
        fprintf(stderr, "Successfully received %ld\n", received);
        buffer->do_move_end(received);

        return RESULT_CORRECT;
    }
}

int Connection::do_send() {
    ssize_t sent = send(socket_write, buffer->get_start(), buffer->get_data_size(), 0);

    if (-1 == sent) {
        perror("sent");
        set_close();

        return RESULT_INCORRECT;
    }
    else if (0 == sent) {
        fprintf(stderr, "Send done\n");
        set_close();
        pair->set_close();

        return RESULT_CORRECT;
    }
    else {
        fprintf(stderr, "Successfully sent %ld\n", sent);
        buffer->do_move_start(sent);

        return RESULT_CORRECT;
    }
}

void Connection::set_pair(Connection * pair) {
    this->pair = pair;
}

void Connection::set_buffer_data(char * data, size_t data_size) {
    delete buffer;

    buffer = new Buffer(data_size);

    memcpy(buffer->get_start(), data, data_size);
    buffer->do_move_end(data_size);
}

void Connection::set_buffer(Buffer * buffer) {
    delete this->buffer;
    this->buffer = buffer;
}

bool Connection::is_handled_first_line() {
    return flag_handled_first_line;
}

void Connection::set_handled_first_line() {
    flag_handled_first_line = true;
}

char * Connection::get_p_new_line() {
    if (!flag_from_client) {
        return NULL;
    }

    char * pos = strchr(buffer->get_start(), '\n');
    return pos;
}

char * Connection::get_buffer_start() {
    return buffer->get_start();
}

Connection::~Connection() {
    fprintf(stderr, "Connection destructor\n");

    delete buffer;

    if (close(socket_read)) {
        perror("close");
    }

    if (close(socket_write)) {
        perror("close");
    }
}