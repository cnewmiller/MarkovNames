//
//  MarkovNode.cpp
//  BabyNames
//
//  Created by Clayton Newmiller on 2/24/17.
//  Copyright © 2017 Clayton Newmiller. All rights reserved.
//

#include "MarkovNode.hpp"



/*
 Each node has data, e.g. "this node is for 'th'"
    each node then has children
    and each child represents the next link in the chain
    and each child has to have a probability associated with it
 
    so the list of children should be a (map? array?)
 
 
 
 
    the final model will be held in a Chain class
    which will have a model in a hashmap of all the letter combos
    and each letter combo will have the probabilities of the next letter
        in the chain
 
    the children structure needs to keep track of:
        -the letter the of the addition
        -the probability of it's use
    and it should be indexed by...?
        -the letter or the probability? neither?
 
 
 
    parent node holds:
        string info: the data value of the parent node
        map of children: each possible follower of this parent data
            can be reached by its data, or iterated through to make the distribution
 
 
 */


char ParentNode::getRandomFollower(){
    
    
    
    std::list<int> probs;
    std::map<char, ChildNode*>::iterator index = children.begin();
    std::map<char, ChildNode*>::iterator end = children.end();
    
    while (index!=end){
        
//        if (index != nullptr)
        probs.push_back((*index).second->getProbability());
        index++;
    }

    std::discrete_distribution<int> distribution(probs.begin(), probs.end());
    
//    printf("size is %ld", children.size());
    
    int n = distribution(generator);
    index = children.begin();
    for (int i = 0; i<n;i++){
        index++;
    }
    
    return (index)->second->getData();
    
}

void ParentNode::addProbability(char child){
    if (children.count(child)){
        children[child]->incrementProbability();
    }
    else{
        children[child] = new ChildNode(child);
        children[child]->incrementProbability();
    }
        
    
    //children[child]

}
























