#include <iostream>
#include <vector>

// Genders
enum Gender{
    UNKNOWN = -1,
    MALE,
    FEMALE,
    GENDERS_COUNT = 2
};
const char* genders[GENDERS_COUNT] = {"Male", "Female"};

struct Doctor{
    char family_name[36];
    int years_of_service;
    char hospital_workplace_name[36];
    Gender gender;

    void printDoctorInfo(){ 
        std::cout << "Family name: " << family_name << std::endl;
        std::cout << "Years of service: " << years_of_service << std::endl;
        std::cout << "Hospital name: " << hospital_workplace_name << std::endl;
    };

    void changeHospitalWorkplace(){
        std::cout << "Select new hospital name:\n";
        std::cin.ignore();
        std::cin.getline(this->hospital_workplace_name, 36);
    }
    void changeFamilyName(){
        std::cout << "Select new family name:\n";
        std::cin.ignore();
        std::cin.getline(this->family_name, 36);
    }

};

const int doctors_count = 3;
void sortDoctorsByService(Doctor doctors[]){
    for(int i = 0; i < doctors_count; ++i){
        for(int j = i + 1; j < doctors_count; ++j){
            if(doctors[i].years_of_service < doctors[j].years_of_service){
                std::swap(doctors[i], doctors[j]);
            }
        }
    }
}



int main()
{
    
    Doctor doctors[doctors_count];

    for(int i = 0; i < doctors_count; i++)
    {
        std::cout << "Enter doctor " << i+1 << " family name:\n";
        std::cin.ignore();
        std::cin.getline(doctors[i].family_name, 36);
        std::cout << "Enter doctor " << i+1 << " years of service:\n";
        std::cin >> doctors[i].years_of_service;
        std::cout << "Enter doctor " << i+1 << " hospital workplace name:\n";
        std::cin.ignore();
        std::cin.getline(doctors[i].hospital_workplace_name, 36);
        std::cout << "Enter doctor " << i+1 << " gender (1-2):\n";
        int gender;
        std::cin >> gender;
        doctors[i].gender = (Gender)(gender-1);
    }
    
    std::cout << "Sorting doctors by years...\n";
    sortDoctorsByService(doctors);

    for(int i = 0; i < doctors_count; i++){
        doctors[i].printDoctorInfo();
    }
    return 0;
}