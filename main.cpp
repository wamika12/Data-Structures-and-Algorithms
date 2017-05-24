//
//  main.cpp
//  Data Structures
//
//  Created by Wamika Bansal on 5/21/17.
//  Copyright © 2017 Wamika Bansal. All rights reserved.
//
/*
    In this code, I make adjacency list using vectors
 */
#include <iostream>
#include <vector>
using namespace std;

//adjacency matrix
vector<vector<char>> adj;


class Vertex{
    public:
        char src;
        char dest;
        int len;
        Vertex(char,char,int);
        void insertNodes(char,char);
};

Vertex::Vertex(char src, char dest, int len){
    
    this->src = src;
    this->dest = dest;
    this->len = len;
    insertNodes(src,dest);
}

void
Vertex::insertNodes(char src, char dest){
    
    int flag1 = 0, flag2 = 0;
    for(int i = 0; i < adj.size(); ++i){
        if(adj[i][0] == src){
            adj[i].push_back(dest);
            flag1 = 1;
        }
        if(adj[0][i] == dest){
            adj[i].push_back(src);
            flag2 = 1;
        }
    }
    
    if(flag1 == 0){
        
        vector<char> temp;
        temp.push_back(src);
        temp.push_back(dest);
        adj.push_back(temp);
    }
    
    if(flag2 == 0){
        
        vector<char> temp;
        temp.push_back(dest);
        temp.push_back(src);
        adj.push_back(temp);
    }

}

void
printall(){

    for(int i = 0; i < adj.size(); ++i){
        cout<<adj[i][0]<<" - ";
        for(int j = 1; j < adj[i].size(); ++j){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
   
    
    Vertex v1('A','B',1);
    Vertex v2('B','C',2);
    Vertex v3('A','C',3);
  
   printall();

    return 0;
}
