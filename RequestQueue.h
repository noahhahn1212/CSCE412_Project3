#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include "Request.h"
#include <queue>

using namespace std;

class RequestQueue {
public:
    void addRequest(const Request& req);
    Request getNextRequest();
    bool isEmpty() const;
    int size() const;
    
private:
    queue<Request> queue;
};

#endif // REQUESTQUEUE_H
