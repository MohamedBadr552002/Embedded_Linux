#include <iostream>
#include <string>
#include <array>

using namespace std;

#define MAX_RECOREDS    100


class USER
{
    private:
        string name {"user"};
        int age = 0;
    

    public:

        USER() = default;

        USER(string name , int age){
            this->name = name ;
            this->age = age ;
           std::cout << "USer record added successfully.\n";;
        }

        int getage()
        {
             return this->age;
        }

        string getname()
        {
            return this->name ;
        }

        void setage(int age){
            this->age = age ;
        }

        void setname(string name){
            this->name = name;
        }

        void display(){
            std::cout << "User name: "<< this->name <<"\n";
            std::cout << "USer age: "<< this->age <<"\n";
        }

};


int main()
{
    int option {0};
    int counter {0};
    string tempName {} ;
    int tempAge{};

    std::array<USER , MAX_RECOREDS > Recoreds ={} ;

    while(true){

          std::cout << "Please Select an Option: \n";
          std::cout <<"1: Add Record \n2: Fetch Record \n3: Quit \n ";

            std::cin >> option ;

           if(option == 1){

                cout << "Add Record, Please enter User name and  age \n";
                cout << "name: ";
                cin >> tempName ;
                cout <<"age: ";
                cin >> tempAge ;

                Recoreds[counter].setname(tempName);
                Recoreds[counter].setage(tempAge);

                cout << "User Added Successfully \n \n";

            }
             else if(option == 2 )
            {
                cout << "Please Enter User ID : ";
                cin >> tempAge ;

                cout << "User Name: " << Recoreds[tempAge].getname() <<"\n";

                cout << "User Age: " << Recoreds[tempAge].getage() << "\n";


            }
            else if (option == 3){
                break;
            }
            else
            {
                cout << "Not Valid Option, Try Again :( \n";
            }

            if(counter == 100){
                cout << "Max Number of records, Program Quit ...  \n";
            }
            

    }

    return 0;
}
