#include "LoadBalancer.cpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/**
 * @brief Main function to run the Load Balancer simulation.
 * 
 * This function prompts the user to enter the number of servers and the total run time
 * for the load balancer simulation. It then creates a LoadBalancer object and runs the simulation.
 * 
 * @return int Returns 0 upon successful completion.
 */
int main() {
    int NumServers;
    cout << "Enter the number of servers: ";
    cin >> NumServers;

    int Time;
    cout << "Enter the total run time: ";
    cin >> Time;

    LoadBalancer lb = LoadBalancer(NumServers, Time);

    lb.RunLoadBalancer();

    return 0;
}
