#include <iostream>
#include <vector>

// Flavors
enum Flavor{

    UNKNOWN = -1,
    CHOCOLATE,
    VANILLA,
    CREAM,
    STRAWBERRY,
    FLAVOR_COUNT = 4 


};
// Flavor Names
const char* flavor_names[FLAVOR_COUNT] = {"Chocolate", "Vanilla", "Cream", "Strawberry"};

// Ice Cream
struct IceCream
{
    Flavor flavor;
    int weight_grams;
    double price;

    // create an ice cream
    void makeIceCream(){
        int flavor, weight_grams;
        double price;

        std::cout << "Enter flavor (1-4):\n";
        std::cin >> flavor;
        std::cout << "Enter weight in grams:\n";
        std::cin >> weight_grams;
        std::cout << "Enter price:\n";
        std::cin >> price;

        this->flavor = (Flavor)(flavor-1);
        this->price = price;
        this->weight_grams = weight_grams;
    };

    // print Ice cream vars
    void print(){
        std::cout << "Flavor: " << flavor_names[flavor] << std::endl;
        std::cout << "Weight: " << weight_grams << std::endl;
        std::cout << "Price: " << price << std::endl;
    };
};

// Ice Cream Array
const int iceCreams_count = 4;
struct IceCreamFactory
{
    IceCream iceCreams[iceCreams_count];

    void getCheapest(){
        
        int cheapest_IceCream_index = 0;
        int cheapest_price = iceCreams[0].price;

        for(int i = 1; i < iceCreams_count; i++)
        {
            if(iceCreams[i].price < cheapest_price){
                cheapest_IceCream_index = i;
            }
        }

        iceCreams[cheapest_IceCream_index].print();
    }
};


int main()
{
    IceCreamFactory iceCreamShop;

    for(int i = 0; i < iceCreams_count; i++)
    {
        iceCreamShop.iceCreams[i].makeIceCream();
    }
    
    iceCreamShop.getCheapest();

    return 0;
}