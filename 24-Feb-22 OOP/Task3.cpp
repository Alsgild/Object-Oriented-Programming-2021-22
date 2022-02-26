#include <iostream>
#include <vector>

struct Prisoner{
    char name[36];
    char ID[50];
    int remaining_time_days;

    void enterPrisonerDetails(){
        std::cout << "Enter prisoner name:\n";
        std::cin.ignore();
        std::cin.getline(this->name, 36);
        std::cout << "Enter prisoner ID:\n";
        std::cin.ignore();
        std::cin.getline(this->ID, 50);
        std::cout << "Enter prisoner days remaining:\n";
        std::cin >> this->remaining_time_days;
    }

    void printPrisonerDetails(){
        std::cout << "Prisoner name: " << this -> name << std::endl;
        std::cout << "Prisoner ID: " << this -> ID << std::endl;
        std::cout << "Days remaining: " << this -> remaining_time_days << std::endl;
    };
};

const int prisoners_count = 4;
struct Prison
{
    char name[36];
    Prisoner prisoners[prisoners_count];

    void printPrisonInfo(){
        std::cout << "Prison name: " << name << std::endl;

        for(int i = 0; i < prisoners_count; i ++)
        {
            std::cout << "Prisoner " << i+1 << " name:" << prisoners[i].name << std::endl;
            std::cout << "Prisoner " << i+1 << " ID:" << prisoners[i].ID << std::endl;
            std::cout << "Prisoner " << i+1 << " Days:" << prisoners[i].remaining_time_days << std::endl; 
        }
    };

    void sortByDays()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = i + 1; j < 4; ++j) 
            {
                if (prisoners[i].remaining_time_days > prisoners[j].remaining_time_days)
                {
                    std::swap(prisoners[i], prisoners[j]);
                }
            }
        }
    };
};


int main()
{
    Prison prison;

    std::cout << "Enter prison name:\n"; 
    std::cin.getline(prison.name, 36);

    for(int i = 0; i < prisoners_count; i ++){
        prison.prisoners[i].enterPrisonerDetails();
    }

    prison.printPrisonInfo();
    std::cout << "========\n\nSorted results:\n";
    prison.sortByDays();
    prison.printPrisonInfo();

    
    return 0;
}