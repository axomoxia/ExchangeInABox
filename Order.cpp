#include "Order.hpp"

 Order::Order(const std::string& orderID, const std::string& instrument, const unsigned long volume, const double price,OrderSide orderSide) :
        orderID_(orderID),
        instrument_(instrument),
        volume_(volume),
        price_(price),
        orderSide_(orderSide)
    
{
}
