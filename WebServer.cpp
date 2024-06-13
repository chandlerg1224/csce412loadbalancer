#include "Request.cpp"

/**
 * @class WebServer
 * @brief Class to represent a web server that processes network requests.
 */
class WebServer {
public:
    int Id; ///< Unique identifier for the web server
    int CountDown; ///< Countdown timer for processing the current request
    Request CurrentRequest; ///< The current request being processed by the server

    /**
     * @brief Constructs a new WebServer object with the specified ID.
     * @param Id The unique identifier for the web server
     */
    WebServer(int Id) {
        this->Id = Id;
        this->CountDown = 0;
    }
};
