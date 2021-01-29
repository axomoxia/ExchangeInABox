#include "order.hpp"

  Order::Order(const std::string& clientOrderID, 
          const std::string& instrument, 
          const std::string& principle,
          const unsigned long volume, 
          const int price, 
          const int multiplier, 
          const OrderSide orderSide) : 
        
        clientOrderID_(clientOrderID),
        instrument_(instrument),
       principle_(principle),
        initialVolume_(volume),
        price_(price),
        multiplier_(multiplier),
        orderSide_(orderSide)
    
{
}
