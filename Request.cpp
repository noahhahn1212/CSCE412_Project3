#include "Request.h"

using namespace std;

// Default Constructor
Request::Request() : ipIn("0.0.0.0"), ipOut("0.0.0.0"), time(0) {}

// Constructor
Request::Request(const string& ipIn, const string& ipOut, int time)
    : ipIn(ipIn), ipOut(ipOut), time(time) {}

// Getters
string Request::getIpIn() const { return ipIn; }
string Request::getIpOut() const { return ipOut; }
int Request::getTime() const { return time; }
