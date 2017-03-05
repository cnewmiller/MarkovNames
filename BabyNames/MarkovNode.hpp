//
//  MarkovNode.hpp
//  BabyNames
//
//  Created by Clayton Newmiller on 2/24/17.
//  Copyright © 2017 Clayton Newmiller. All rights reserved.
//

#ifndef MarkovNode_hpp
#define MarkovNode_hpp

#include <stdio.h>
//#include <__hash_table>
#include <map>
#include <string>
#include <random>
#include <list>
#include <time.h>


class ChildNode{
protected:
    char data;
    int probability;
    
    
public:
    ChildNode(char c){data=c; probability = 0;};
    int getProbability(){return probability;};
    char getData(){return data;};
    void incrementProbability(){probability++;};
    
    
};

class ParentNode{
private:
    
    std::string info; //the value of the node, eg "th"/"ar"/etc
    std::default_random_engine generator;
    std::map<char, ChildNode*> children;
    
    
public:
    
    ParentNode(std::string data){info = data;generator.seed(time(NULL));};
    
    void addProbability(char child);
    char getRandomFollower();
    
    
};





#endif /* MarkovNode_hpp */
