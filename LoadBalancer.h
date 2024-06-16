#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>
#include <random>
#include <fstream>
#include <string>

using namespace std;

class LoadBalancer {
public:
    LoadBalancer(int numServers);
    ~LoadBalancer();
    void generateRequest();
    void distributeRequests();
    void monitorServers();
    void log(const string& message, bool timestamp = false);

private:
    vector<WebServer> webServers;
    RequestQueue requestQueue;
    int currentTime;
    mt19937 rng;
    uniform_int_distribution<int> timeDist;
    uniform_int_distribution<int> ipDist;
    ofstream logFile;

    string generateRandomIP();
};

#endif // LOADBALANCER_H
