#include <iostream>
#include <ctime>

class ElvenVillage
{
private:

public:
    ElvenVillage(int inNumberTrees)
    {

    }
};

int main()
{
    srand(time(NULL));
    
    ElvenVillage* elvenVillage = new ElvenVillage(5);












    for (int i = 0; i < 30; ++i)
    {
        std::cout << rand() % 3 + 3 << std::endl;
    }




    delete elvenVillage;
    return 0;
}