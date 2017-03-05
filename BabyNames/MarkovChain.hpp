//
//  MarkovChain.hpp
//  BabyNames
//
//  Created by Clayton Newmiller on 2/25/17.
//  Copyright © 2017 Clayton Newmiller. All rights reserved.
//

#ifndef MarkovChain_hpp
#define MarkovChain_hpp

#include <stdio.h>
#include <fstream>
#include <map>
#include "MarkovNode.hpp"


//for ease of use and readability
#define string std::string


class MarkovNameGenerator{
    
private:
    std::map<string, ParentNode*> chain;
    std::map<string, bool> seen;
    int order=2;
//    void trim(string);
    
public:
    MarkovNameGenerator(){};
    MarkovNameGenerator(int n){order = n;};
    void addLink(string, char);
    ParentNode* getLink(string);
    void makeChainFromFile(string);
    
    string generateName();
    
    
};


#endif /* MarkovChain_hpp */
