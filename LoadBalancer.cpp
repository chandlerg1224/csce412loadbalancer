#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h> 

#include "WebServer.cpp"
using namespace std;

/**
 * @class LoadBalancer
 * @brief Class to simulate a load balancer that manages web server requests.
 */
class LoadBalancer {
    public:
    queue<Request> RequestQueue; ///< Queue to hold incoming requests
    vector<WebServer> WebServers; ///< Vector to hold available web servers
    int Time; ///< Total run time for the load balancer
    int NumberOfServers; ///< Initial number of servers
    int QueueCapacity; ///< Maximum capacity of the request queue
    int NumberOfRejections; ///< Number of rejected requests
    int NumberOfUniqueServers; ///< Unique server count
    int NumberOfRequestsProcessed; ///< Number of processed requests

    /**
     * @brief Constructor to initialize the load balancer with given number of servers and time.
     * @param NumberOfServers Number of initial servers
     * @param Time Total run time for the load balancer
     */
    LoadBalancer(int NumberOfServers, int Time) {
        cout << "Creating Load Balancer..." << endl;
        this->RequestQueue = queue<Request>();
        this->WebServers = vector<WebServer>();
        this->Time = Time;
        this->NumberOfServers = NumberOfServers;
        this->QueueCapacity = NumberOfServers * 100;
        this->NumberOfRejections = 0;
        this->NumberOfUniqueServers = 0;
        this->NumberOfRequestsProcessed = 0;
        freopen("log.txt", "w", stdout);
    }

    /**
     * @brief Runs the load balancer simulation.
     */
    void RunLoadBalancer() {
        cout << "Running Load Balancer..." << endl;

        // Initialize web servers
        for (int i = 0; i < this->NumberOfServers; i++) {
            cout << "Server " << this->NumberOfUniqueServers << " added." << endl;
            WebServer Server = WebServer(this->NumberOfUniqueServers++);
            this->WebServers.push_back(Server);
        }

        // Populate the request queue
        for (int i = 0; i < this->QueueCapacity; i++) {
            Request r = Request();
            this->RequestQueue.push(r);
        }

        cout << "Starting Queue Size: " << this->RequestQueue.size() << endl;

        // Main simulation loop
        while (Time > 0) {
            // Add a new server if the queue is almost full
            if (this->RequestQueue.size() >= this->QueueCapacity - 5) {
                cout << "Server " << this->NumberOfUniqueServers << " added." << endl;
                WebServer ws = WebServer(this->NumberOfUniqueServers++);
                this->WebServers.push_back(ws);
            }
            // Remove a server if the queue is less than half full
            else if (this->RequestQueue.size() <= this->QueueCapacity / 2 + 5 && !this->RequestQueue.empty()) { 
                cout << "Server " << this->WebServers.back().Id << " removed." << endl;
                this->WebServers.pop_back();
            }

            // Process requests on each server
            for (int i = 0; i < this->WebServers.size(); i++) {
                if (this->WebServers.at(i).CountDown == 0 && !this->RequestQueue.empty()) {
                    // Assign a new request to the server
                    this->WebServers.at(i).CurrentRequest = this->RequestQueue.front();
                    this->WebServers.at(i).CountDown = this->WebServers.at(i).CurrentRequest.requestTime;
                    this->RequestQueue.pop();
                } else {
                    // Decrease the server's countdown
                    this->WebServers.at(i).CountDown--;
                    if (this->WebServers.at(i).CountDown == 0) {
                        cout << "A request from IP " << this->WebServers.at(i).CurrentRequest.IpIn << " has been processed by server " << this->WebServers.at(i).Id << endl;
                        this->NumberOfRequestsProcessed++;
                    }
                }
            }

            Time--;

            // Generate new requests
            int NumberOfNewRequests = rand() % 3;
            for (int i = 0; i < NumberOfNewRequests; i++) {
                if (this->RequestQueue.size() == this->QueueCapacity) {
                    cout << "A new request has been trashed." << endl;
                    this->NumberOfRejections++;
                    continue;
                } else {
                    Request r = Request();
                    this->RequestQueue.push(r);
                }
            }
        }

        // Print summary
        cout << endl << endl;
        cout << "Summary of Task:" << endl;
        cout << "Current servers: " << this->WebServers.size() << endl;
        cout << "Requests in queue: " << this->RequestQueue.size() << endl;
        cout << "Trashed Requests: " << this->NumberOfRejections << endl;
        cout << "Number of Processed Requests: " << this->NumberOfRequestsProcessed << endl;
        cout << "Starting Queue Size: " << this->QueueCapacity << endl;
        cout << "Ending Queue Size: " << this->RequestQueue.size() << endl;
        cout << "Task time range: 3 - 10000 cycles" << endl;
    }
};
