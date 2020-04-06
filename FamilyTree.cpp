#include "FamilyTree.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace family;

Tree &Tree::addFather(string son,string dad){
    return *this;
}
Tree &Tree::addMother(string son, string mom){
    return *this;
}
string Tree::relation(string n){
    return "temp";
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