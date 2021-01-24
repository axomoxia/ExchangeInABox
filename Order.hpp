// class to represent an order. This should be validated
#pragma once
#include <string>
class Order
{
    public:

    enum OrderSide { Buy, Sell};
private:
    std::string orderID_;            /// unique identifier for the order - as created when the order is accepted onto the book
    std::string clientOrderID_;      /// the order supplied by the client 
    std::string instrument_;              /// instrument id
    std::string principle_;                  /// the originator of the order
    unsigned long initialVolume_ = 0;       /// volume of the order 
    unsigned long remainingVolume = 0;      /// order volume remaining on the book
    unsigned int price_ = 0.0;             /// price of the order () - rebalanced to integer. Note we will keep this as an int rather
                                           /// than unsigned int since there are negative prices (crack spreads etc)
    unsigned int multiplier_ = 0;           /// factor applied to the price_ to convert from integer to floating point (we will keep
                                           /// as int to prevent floating point issues - its a lots simpler than using binary coded decimal)
                                           /// also note its a signed integer - price may be less than 1.0 e.g. 0.143
    OrderSide orderSide_;
public:
    Order() = delete;
    Order(const std::string& clientOrderID, 
          const std::string& instrument, 
          const std::string& principle,
          const unsigned long volume, 
          const int price, 
          const int multiplier, 
          const OrderSide orderSide);

    bool IsBuy() const;
};

