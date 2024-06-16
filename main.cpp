#include "LoadBalancer.h"
#include <iostream>

using namespace std;

int main() {
    int numServers;
    int runTime;
    const int requestsPerCycle = 5;
    
    cout << "Enter the number of web servers: ";
    cin >> numServers;
    cout << "Enter the load balancer run time (in cycles): ";
    cin >> runTime;
    
    LoadBalancer lb(numServers);
    
    for (int time = 0; time < runTime; ++time) {
        for (int i = 0; i < requestsPerCycle; ++i) {
            lb.generateRequest();
        }
        lb.distributeRequests();
        lb.monitorServers();
    }
    
    return 0;
}
