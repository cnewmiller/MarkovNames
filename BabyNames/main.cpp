//
//  main.cpp
//  BabyNames
//
//  Created by Clayton Newmiller on 2/24/17.
//  Copyright © 2017 Clayton Newmiller. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#include "MarkovNode.hpp"
#include "MarkovChain.hpp"

int main(int argc, const char * argv[]) {

    int order;
    printf("What do you want the order of this Markov model to be?\n");
    std::cin>>order;
    MarkovNameGenerator g(order);
    printf("Do you want (1) girls, (2) boys, (3) orcs, or (4) a new word?: ");
    std::cin>>order;
    string choice;
    switch(order){
        case 1:
            choice = "/Users/Clay/ownCloud/Coding/BabyNames/namesGirls.txt";
            break;
        case 2:
            choice = "/Users/Clay/ownCloud/Coding/BabyNames/namesBoys.txt";
            break;
        case 3:
            choice = "/Users/Clay/ownCloud/Coding/BabyNames/namesOrcs.txt";
            break;
        case 4:
            choice = "/Users/Clay/ownCloud/Coding/BabyNames/words.txt";
            break;
        default:
            printf("Bad choice, mister...");
            return 0;
            break;
    }
    g.makeChainFromFile(choice);
    bool flag=true;
    do{
        printf("Input a minimum length: ");
        int min;
        std::cin>>min;
        printf("Input a maximum length: ");
        int max;
        std::cin>>max;
        
        string name = g.generateName();
        while (name.length() < min || name.length() >max)
            name = g.generateName();
        
        
        printf("the generated name/word is %s\n",name.c_str());
        int retry;
        printf("Do you want another result? 1: yes, 2: no\n");
        std::cin>>retry;
        if (retry!=1) flag=false;

        
        
        
    }while(flag);
    
    
//    g.addLink("th", 'e');
//    g.addLink("th", 'e');
//    g.addLink("th", 'a');
//    g.addLink("th", 'e');
//    g.addLink("th", 'r');
//    g.addLink("th", 'r');
    
//    for (int i=0;i<10;i++)
//        printf("d: %d\n", g.getLink("th")->getRandomFollower());
    
//    g.makeChainFromFile("/Users/Clay/ownCloud/Coding/BabyNames/namesOrcs.txt"); //
//    g.makeChainFromFile("/Users/Clay/ownCloud/Coding/BabyNames/words.txt");
//    printf("th: %c\n", g.getLink("ath")->getRandomFollower());
//    printf("ar: %c\n", g.getLink("rar")->getRandomFollower());
//    printf("__: %c\n", g.getLink("___")->getRandomFollower());
    
    
}
