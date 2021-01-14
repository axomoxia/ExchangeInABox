// class to represent an order
#pragma once
#include <string>
class Order
{
    public:

    enum OrderSide { Buy, Sell};
private:
    std::string orderID_;                 /// unique identifier for the order
    std::string instrument_;              /// instrument id
    unsigned long volume_ = 0;       /// volume in the order
    double price_ = 0.0;             /// price of the order
    OrderSide orderSide_;
public:
    Order() = delete;
    Order(const std::string& orderID, const std::string& instrument, const unsigned long volume, const double price, OrderSide orderSide);
};

