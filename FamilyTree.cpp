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


string Tree::find(string rel){
    string temp;
    if(rel=="me"){
        return name;
    }
    if(rel=="father"){
        if(father!=nullptr){
            return father->name;
        }
        else{
             throw out_of_range("Given wrong relation");
        }
    }
    if(rel="mother"){
        if(mother!=nullptr){
            return mother->name;
        }
        else{
             throw out_of_range("Given wrong relation");
        }
    }
    if(rel.at(0)=='g'){
        try{
            string temp2=rel.substr(0,5);
            if(temp2!="great" && temp2!="grand"){
                goto THROW;
            }
            temp=rel.substr(5);
            if(temp.at(0)=="-"){
                temp.earse(0,1);
            }
        } catch(out_of_range& ex){
            goto THROW;
        }
    if(father!= nullptr){
        try{
            return father->find(temp);
        } catch(out_of_range &ex){}
        if(mother != nullptr){
            return mother->find(temp);
        }
    }
    throw out_of_range("Requested relation dosn't exist");
    }
    THROW:
    throw runtime_error("wrong relation given");
}


void Tree::display(){
    return;
}


bool Tree::remove(string fname){
    if(fname ==name){
        throw invalid_argument("cant remove the root");
    }
    if(father!=nullptr &&father->name==fname){
        delete father;
        father=nullptr;
        return true;
    }
    if(mother!=nullptr &&mother->name==fname){
        delete mother;
        mother=nullptr;
        return true;
    }
    bool ans=(father!=nullptr && father->remove(fname)) || (mother!=nullptr && mother->remove(fname));
    if(ans == false){
        throw invalid_argument("cant find this ancestor");
    }
    return ans;
}