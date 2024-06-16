#include "WebServer.h"

// Constructor
WebServer::WebServer(int id) : id(id), idle(true), currentRequest(Request("0.0.0.0", "0.0.0.0", 0)), remainingTime(0), completedRequest(false) {}

// Is idle
bool WebServer::isIdle() const { return idle; }

// Process request
void WebServer::processRequest(const Request& req) {
    currentRequest = req;
    remainingTime = req.getTime();
    idle = false;
    completedRequest = false;
}

// Update
void WebServer::update() {
    if (!idle) {
        --remainingTime;
        if (remainingTime <= 0) {
            idle = true;
            completedRequest = true;
        }
    }
}

// Has completed request
bool WebServer::hasCompletedRequest() const {
    return completedRequest;
}

// Reset current request
void WebServer::resetCurrentRequest() {
    completedRequest = false;
}

// Get ID
int WebServer::getId() const { return id; }

// Get current request
Request WebServer::getCurrentRequest() const { return currentRequest; }
