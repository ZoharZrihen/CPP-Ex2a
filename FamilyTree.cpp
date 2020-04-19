/*Author: Zohar Zrihen */
#include "FamilyTree.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace family;

Tree *Tree::findSon(string fname){
    if(name==fname){
        return this;
    }
    Tree *ans=nullptr;
    if(father!=nullptr){
        ans=father->findSon(fname);
    }
    if(ans==nullptr &&mother!=nullptr){
        ans=mother->findSon(fname);
    }
    return ans;
}

Tree &Tree::addFather(string son,string dad){
    Tree *node=findSon(son);
    if(node==nullptr){
        throw out_of_range(son+"does not exsit");
    }
    if(node->father!=nullptr){
         throw runtime_error(son+"has a father aleardy");
    }
    node->father=new Tree(dad);
    return *this;
}

Tree &Tree::addMother(string son, string mom){
    Tree *node=findSon(son);
    if(node==nullptr){
        throw out_of_range(son+"does not exsit");
    }
    if(node->mother!=nullptr){
         throw runtime_error(son+"has a mother aleardy");
    }
    node->mother=new Tree(mom);
    return *this;
}


string Tree::relation(string n){
    if(n==name){
        return "me";
    }
    string ans="unrelated";
    if(father!=nullptr){
        ans=father->relation(n);
        if(ans!="unrelated"){
            if(ans="me"){
                ans="father";
            }
            else if(ans=="father" || ans=="mother"){
                ans="grand"+ans;
            }
            else{
                ans="great-"+ans
            }
        }
    }
    
    if(ans=="unrelated" && mother!=nullptr){
       ans=mother->relation(n);
       if(ans != "unrelated"){
           if(ans=="me"){
               ans="mother";
           }
           else if(ans =="father" || ans =="mother"){
               ans = "grand"+ans;
           }
           else{
               ans="great-"+ans;
           }
       }
    }
    return ans;
}


string Tree::find(string relation){
    return "temp";
}
void Tree::display(){
    return;
}
bool Tree::remove(string name){
    return true;
}