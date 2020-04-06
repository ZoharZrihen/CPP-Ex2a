#ifndef FamilyTree_HPP
#define FamilyTree_HPP

#include <iostream>
#include <string>


using namespace std;
namespace family{
    class Tree{
        string name;
        Tree *father, *mother;
    public:
        Tree(string n): 
            name(n), 
            father(nullptr), 
            mother(nullptr)
    {};    
        
        Tree &addFather(string son, string dad);
        Tree &addMother(string son, string mom);
        string relation(string n);
        string find(string relation);
        void display();
        bool remove(string name);
         ~Tree(){
            if(father!=nullptr)
                delete father;
            if(mother!=nullptr)
                delete mother;
        };
    };
};

#endif