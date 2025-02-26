/******************************************************************************

    You are designing a Bird Sanctuary Management System where different types of birds reside. Each bird has a name, species, and sound.
    The sanctuary should allow:

    Adding new birds.
    Displaying all birds.
    Searching for a bird by species.
    Removing birds

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Bird{
    
    public:
    
    string name, species, sound;
    
    Bird(string name, string species, string sound){
        this->name = name;
        this->species = species;
        this->sound = sound;
    }
    
    void displayBird(){
        cout << "\nBird's name: " << name << endl;
        cout << "Specie's name: " << species << endl;
        cout << "Sound produce: " << sound << "\n";
    }
};

class BirdSanctuary{
    
    public:
    
    BirdSanctuary(){
        cout << "\n-------------------- Welcome to Bird Sanctuary Management System --------------------\n";
    }

    vector<Bird> sanctuary;

    // Add Birds to sanctuary
    
    void addBirds(){
        
        string name, species, sound;
        
        cin.ignore();
        
        cout << "\nEnter bird name: "; getline(cin, name);
        cout << "Enter species name: "; getline(cin, species);
        cout << "Enter bird sound: "; getline(cin, sound);
        
        Bird bird(name, species, sound);
        sanctuary.push_back(bird);
        
        cout << "\nBird added successfully\n";
    }
    
    // Search Birds in sanctuary

    void searchBirds(){
        
        string species;

        cin.ignore();
        
        cout << "\nEnter species name: "; getline(cin, species);
        
        for(auto itr : sanctuary){
            if(itr.species == species){
                cout << "\nBird with species '" << itr.species << "' present in sanctuary\n";
                break;
            }
        }
    }

    // Remove birds from sanctuary
    
    void removeBird(){
        
        string species;

        cin.ignore();
        
        cout << "\nEnter species name: "; getline(cin, species);
        
        for(auto itr = sanctuary.begin(); itr != sanctuary.end(); itr++){
            if(itr->species == species){
                cout << "\nBird with species '" << itr->species << "' removed from sanctuary\n";
                sanctuary.erase(itr);
                break;
            }
        }
    }

    // Dispaly birds present in sanctuary
    
    void displayBirds(){
        
        for(auto itr : sanctuary){
            itr.displayBird();
        }
    }
};


int main()
{
    string input;
    
    BirdSanctuary bird_sanctuary;
    
    do{
        
        cout << "\nEnter 1 to add birds" << endl;
        cout << "Enter 2 to search birds" << endl;
        cout << "Enter 3 to remove birds" << endl;
        cout << "Enter 4 to displayBirds" << endl;
        
        int choice;
        
        cout << "\nEnter your choice: "; cin >> choice;
        
        switch(choice){
            case 1:
                bird_sanctuary.addBirds();
                break;
                
            case 2:
                bird_sanctuary.searchBirds();
                break;
                
            case 3:
                bird_sanctuary.removeBird();
                break;
                
            case 4:
                bird_sanctuary.displayBirds();
                break;
                
            default:
                cout << "\nInvalid choice, please select from above choices";
        }
        
        cout << "\nDo you want to continue? (y/n) : "; cin >> input;
    }
    while(input == "y" || input == "Y");
    
    cout << "\n-------------------- Closing Bird Sanctuary Management System --------------------\n";

    return 0;
}