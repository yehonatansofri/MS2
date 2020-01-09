//
// Created by yehonatan on 09/01/2020.
//

#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <iosfwd>

namespace server_side {
    class ClientHandler {
        virtual void handleClient(std::istream, std::ostream) = 0;
    };
}


#endif //CLIENTHANDLER_H
