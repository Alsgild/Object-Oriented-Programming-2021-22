#include <iostream>

struct Destination {
	char city[32]; // град
	int kilometers; // километри

    void print()
    {
        std::cout << "Name: " << city << std::endl << "Distance: " << kilometers << std::endl;
    }
};

int main()
{
    // a
    Destination city1, city2;

    std::cout << "Input City 1 name:" << std::endl;
    std::cin >> city1.city;
    std::cout << "Input City 1 range from Sofia:" << std::endl;
    std::cin >> city1.kilometers;

    std::cout << "Input City 2 name:" << std::endl;
    std::cin >> city2.city;
    std::cout << "Input City 2 range from Sofia:" << std::endl;
    std::cin >> city2.kilometers;

    // b
    std::cout << "City 1 Name: " << city1.city << std::endl << "City 1 Distance from Sofia: " << city1.kilometers << std::endl;
    std::cout << "City 2 Name: " << city2.city << std::endl << "City 2 Distance from Sofia: " << city2.kilometers << std::endl;

    // c
    const int arr_size = 3;
    Destination cities[arr_size];

    //d
    for(int i = 0; i < arr_size; i++)
    {
        std::cout << "Input City name:" << std::endl;
        std::cin >> cities[i].city;
        std::cout << "Input City range from Sofia:" << std::endl;
        std::cin >> cities[i].kilometers;
    }

    for(int i = 0; i < arr_size; i++)
    {
        cities[i].print();
    }

    return 0;
}