//
//  MarkovChain.cpp
//  BabyNames
//
//  Created by Clayton Newmiller on 2/25/17.
//  Copyright © 2017 Clayton Newmiller. All rights reserved.
//

#include "MarkovChain.hpp"

//for ease of use and readability
#define string std::string

void MarkovNameGenerator::addLink(string data, char next){
    if (chain.count(data)){
        chain[data]->addProbability(next);
    }
    else{
        chain[data] = new ParentNode(data);
        chain[data]->addProbability(next);
    }
}

ParentNode* MarkovNameGenerator::getLink(string data){
    if (chain.count(data)){
        return chain[data];
    }
    else{
        printf("not here\n");
        return nullptr;
    }
}


//do this my own bad self
string& trim_right_inplace(
                                string&       s,
                                const string& delimiters = " \f\n\r\t\v" )
{
    return s.erase( s.find_last_not_of( delimiters ) + 1 );
}

string& trim_left_inplace(
                               string&       s,
                               const string& delimiters = " \f\n\r\t\v" )
{
    return s.erase( 0, s.find_first_not_of( delimiters ) );
}

string& trim_inplace(
                          string&       s,
                          const string& delimiters = " \f\n\r\t\v" )
{
    return trim_left_inplace( trim_right_inplace( s, delimiters ), delimiters );
}

void MarkovNameGenerator::makeChainFromFile(string fileName){
    std::fstream nameFile;
    nameFile.open(fileName);
    if (!nameFile.is_open()){
        printf("File could not open.\n");
        return;
    }
    //file is open
    
    string line;
    while (std::getline(nameFile, line)){
//        printf("new name\n");
        string bookends = "";
        for (int i = 0; i<order ; i++){
            bookends.append("_");
        }
        trim_inplace(line);
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
//        printf("line: %s\n",line.c_str());
        seen[line]=true;
        line = line.append(bookends);
        line = bookends.append(line);
        
        
//        printf("whole line: %s\n", line.c_str());
        for (int i=0;i<line.length()-order;i++){
            
            addLink(line.substr(i,order), tolower(line[i+order]));

        }
        
        
        
    }
    
    
}



string MarkovNameGenerator::generateName(){
    string final = "";
    string interim;
    for (int i = 0; i<order ; i++){
        interim.append("_");
    }
    //seed now starts with the requisite amount of preprocessing characters
    char addition = 'a';
    while (addition != '_'){
        string helper(interim);
        ParentNode* p = getLink(helper);
        if (p==nullptr) return "error";
        
        addition = p->getRandomFollower();
        
        if (addition == '_'){
            break;
        }
        
        final += addition;
        interim = interim.append(&addition);
        interim = interim.substr(1,order);

        
    }
    if (seen.count(final)>0){
        printf("collision\n");
        final = generateName();
        
    }
    return final;
}






