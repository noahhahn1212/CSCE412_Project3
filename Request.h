#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using namespace std;

class Request {
public:
    Request();
    Request(const string& ipIn, const string& ipOut, int time);
    string getIpIn() const;
    string getIpOut() const;
    int getTime() const;

private:
    string ipIn;
    string ipOut;
    int time;
};

#endif // REQUEST_H