#ifndef LEVELDB_SERVER_HPP
#define LEVELDB_SERVER_HPP

#include <netdb.h>

#include "http_server.hpp"
#include "lib/leveldb/db.h"

namespace mongols {

    class leveldb_server {
    public:
        leveldb_server() = delete;
        leveldb_server(const std::string& host, int port
                , int timeout = 5000
                , size_t buffer_size = 1024
                , size_t thread_size = 0
                , size_t max_body_size = 1024
                , int max_event_size = 64);
        virtual~leveldb_server();
        void set_max_open_files(int);
        void set_write_buffer_size(size_t);
        void set_max_file_size(size_t);
        void run(const std::string&);
    private:
        http_server* server;
        leveldb::DB *db;
        leveldb::Options options;
        bool ready;
    protected:
       virtual void work(const mongols::request& req,mongols::response& res);
       virtual bool filter(const mongols::request& req);

    };
}


#endif /* LEVELDB_SERVER_HPP */

