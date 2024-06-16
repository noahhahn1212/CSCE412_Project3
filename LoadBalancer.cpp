#include "LoadBalancer.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

// Constructor
LoadBalancer::LoadBalancer(int numServers) : currentTime(0), rng(random_device{}()), timeDist(1, 10), ipDist(1, 255) {
    for (int i = 0; i < numServers; ++i) {
        webServers.emplace_back(i);
    }
    logFile.open("load_balancer_log.txt");
    if (!logFile.is_open()) {
        cerr << "Failed to open log file." << endl;
    }
    // Logging the task time range
    log("Task time range: " + to_string(timeDist.min()) + " to " + to_string(timeDist.max()) + " seconds", true);
}

// Log closer
LoadBalancer::~LoadBalancer() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Generate request
void LoadBalancer::generateRequest() {
    string ipIn = generateRandomIP();
    string ipOut = generateRandomIP();
    int time = timeDist(rng);
    Request req(ipIn, ipOut, time);
    requestQueue.addRequest(req);
    
    log("Adding new request: " + ipIn + " time to process " + to_string(time) + " sec");
    log("Adding " + ipIn + " to the Queue");
}

// Distribute request
void LoadBalancer::distributeRequests() {
    log("Starting queue size: " + to_string(requestQueue.size()));
    for (auto& server : webServers) {
        if (server.isIdle() && !requestQueue.isEmpty()) {
            Request req = requestQueue.getNextRequest();
            server.processRequest(req);
            log("Adding " + req.getIpIn() + " to server " + to_string(server.getId()) + " (" + req.getIpOut() + ")");
        }
    }
    log("Ending queue size: " + to_string(requestQueue.size()));
}

// Monitor servers
void LoadBalancer::monitorServers() {
    for (auto& server : webServers) {
        server.update();
        if (server.hasCompletedRequest()) {
            log("Server " + to_string(server.getId()) + ": " + server.getCurrentRequest().getIpIn() + " finished.");
            server.resetCurrentRequest();
        }
    }
}

// Logger
void LoadBalancer::log(const string& message, bool timestamp) {
    if (logFile.is_open()) {
        if (timestamp) {
            auto now = chrono::system_clock::now();
            auto in_time_t = chrono::system_clock::to_time_t(now);
            logFile << ctime(&in_time_t);
        }
        logFile << message << endl;
    }
}

// Generate random IP
string LoadBalancer::generateRandomIP() {
    return to_string(ipDist(rng)) + "." + to_string(ipDist(rng)) + "." + to_string(ipDist(rng)) + "." + to_string(ipDist(rng));
}
