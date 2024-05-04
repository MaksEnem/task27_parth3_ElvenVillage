#include <iostream>
#include <ctime>
class Trees
{
public:
    int topBranch = 0;
    int middleBranch = 0;
    std::string name = "Unknow";
    
    void setNumberMiddleBranch(int &inMiddleBranch)
    {
        middleBranch = inMiddleBranch;
    }

    int getMiddleBranch()
    {
        return middleBranch;
    }
};

class ElvenVillage: public Trees
{
private:
    
   
    Trees** branches = nullptr;

public:
    ElvenVillage()
    {
        topBranch = rand() % 3 + 3;       
       
        branches = new Trees*[topBranch];
        for (int i = 0; i < topBranch; ++i)
        {
            middleBranch = rand() % 2 + 2;
            branches[i] = new Trees[middleBranch];
            branches[i]->setNumberMiddleBranch(middleBranch);
        }
    }

    void setName()
    {
        for (int i = 0; i < topBranch; ++i)
        {
            for (int j = 0; j < branches[i]->getMiddleBranch(); ++j)
            {
                std::cout << "Enter the elf's name: ";
                //std::cin >> branches[i][j].name;
                if (i == 0 && j==0)
                {
                    branches[i][j].name = "elf";
                }
                else if (i == 0)
                {
                    branches[i][j].name = "None";
                }
                else
                {
                    branches[i][j].name = 'a' + i + j;
                }
                
                
            }
        }        
    }

    void printName()
    {
        for (int i = 0; i < topBranch; ++i)
        {
            for (int j = 0; j < branches[i]->getMiddleBranch(); ++j)
            {
                std::cout << "Elf's name: " << branches[i][j].name << std::endl;
            }
        }
    }

    void searchName(std::string & elvenName)
    {
        for (int i = 0; i < topBranch; ++i)
        {
            for (int j = 0; j < branches[i]->getMiddleBranch(); ++j)
            {
                if (elvenName == branches[i][j].name) 
                {                    
                    for (int k = 0; k < branches[i]->getMiddleBranch(); ++k)
                    {
                        if (branches[i][k].name != "None")
                        {
                            std::cout << "Elf's name: " << branches[i][k].name << std::endl;
                        }
                    }
                    break;
                }                
            }
        }
    }
};

int main()
{
    srand(time(NULL));
    int trees = 2;
    std::string elvenName;
    
    ElvenVillage* elvenVillage = new ElvenVillage[trees];

    for (int i = 0; i < trees; ++i)
    {
        elvenVillage[i].setName();
    }

    std::cout << std::endl;

    for (int i = 0; i < trees; ++i)
    {
        elvenVillage[i].printName();
    }
    std::cout << "Enter the name of the elf you want to find: ";
    std::cin >> elvenName;

    for (int i = 0; i < trees; ++i)
    {
        elvenVillage[i].searchName(elvenName);
    }

    delete[] elvenVillage;
    return 0;
}