// this is the class representing the order book. This is a limit order book. 

#include <vector>
#include <mutex>
#include <optional>

#include "Order.hpp"

// a boo

class OrderBook{

public:
    // a list of error codes. There will be other at some point!
    enum OrderPlacementErrorCodes { AllOK };


    // Adds an order to the order book - returns a grab bag of things
    // if succesful 
    // 1. Any executions for any orders crossed.
    // 2. New market data (since the book has changed)
    // 3. A exchange specific order ID to confirm that the order has been placed on the book
    struct OrderResult
    {
        OrderPlacementErrorCodes errorCode_;

        bool IsOK() const
        {
            return (errorCode_ == AllOK);
        }

        // todo: MarketData
        // todo: Order Executions (may be none!)
        std::string OrderID_;
        
    };

    OrderBook::OrderResult Add(const Order& order);

private:
    // An order book is two series of orders, sorted by price.
    // one for buy, one for sell
    using bookside = std::vector<Order>;
    bookside bidSide_;
    bookside askSize_;

    std::mutex mutex_;
};