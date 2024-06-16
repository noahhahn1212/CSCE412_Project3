#include "RequestQueue.h"

// Add request
void RequestQueue::addRequest(const Request& req) { queue.push(req); }

// Get next request
Request RequestQueue::getNextRequest() {
    Request req = queue.front();
    queue.pop();
    return req;
}

// Is empty
bool RequestQueue::isEmpty() const { return queue.empty(); }

// Returns size
int RequestQueue::size() const { return queue.size(); }