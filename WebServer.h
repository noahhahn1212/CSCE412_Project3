#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

class WebServer {
public:
    WebServer(int id);
    bool isIdle() const;
    void processRequest(const Request& req);
    void update();
    bool hasCompletedRequest() const;
    void resetCurrentRequest();
    int getId() const;
    Request getCurrentRequest() const;

private:
    int id;
    bool idle;
    Request currentRequest;
    int remainingTime;
    bool completedRequest;
};

#endif // WEBSERVER_H
