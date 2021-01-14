// class to represent an order
#prama once
#include <string>
class Order
{
private:
    string orderId_;                 /// unique identifier for the order
    string instrument_;              /// instrument id
    unsigned long volume_ = 0;       /// volume in the order
    double price_ = 0.0;             /// price of the order
public:
    Order() = delete;
    Order(const std::string& orderID, const std::string& instrument, const unsigned long volume, const double price)
     Order();
};

