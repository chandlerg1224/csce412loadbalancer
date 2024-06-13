#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @class Request
 * @brief Class to represent a network request with input and output IP addresses and a processing time.
 */
class Request {
public:
    string IpIn; ///< The input IP address of the request
    string IpOut; ///< The output IP address of the request
    int requestTime; ///< The time required to process the request

    /**
     * @brief Constructs a new Request object with specified IP addresses and time.
     * @param IpIn The input IP address
     * @param IpOut The output IP address
     * @param time The time required to process the request
     */
    Request(string IpIn, string IpOut, int time) {
        this->IpIn = IpIn;
        this->IpOut = IpOut;
        this->requestTime = time;
    }

    /**
     * @brief Constructs a new Request object with randomly generated IP addresses and a random processing time.
     */
    Request() {
        this->IpIn = this->GenerateIp();
        this->IpOut = this->GenerateIp();
        this->requestTime = 3 + rand() % 98;
    }

    /**
     * @brief Generates a random IP address.
     * @return string A randomly generated IP address
     */
    string GenerateIp() {
        int octet1 = rand() % 255;
        int octet2 = rand() % 255;
        int octet3 = rand() % 255;
        int octet4 = rand() % 255;
        return to_string(octet1) + "." + to_string(octet2) + "." + to_string(octet3) + "." + to_string(octet4);
    }
};
