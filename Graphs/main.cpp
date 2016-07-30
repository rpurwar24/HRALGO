//
//  main.cpp
//  Graphs
//
//  Created by Rishabh Purwar on 11/05/16.
//  Copyright © 2016 Rustyman. All rights reserved.
//
#define INF 1e9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;
class Node{
    int data,dist;
    bool isVisited;
    Node *next,*par;
    
public:
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->isVisited = false;
        this->dist = INF;
    }
    //getters.....
    Node * getNext(){
        return this->next;
    }
    int getData(){
        return this->data;
    }
    bool getVisited(){
        return this->isVisited;
    }
    // Setters
    void setData(int data){
        this->data = data;
    }
    void setVisited(bool val){
        this->isVisited = val;
    }
    void setNext(Node *n){
        this->next = n;
    }
    void setDist(int d){
        this->dist = d;
    }
};

class Graph{
    int nodes,edges;
    bool isDirected;
    unordered_set<int> unVisited;
    vector<Node*> list;
    map<int,int> hash;
public:
    void initialize();
    Graph(int nodes, int edges, bool isDirected);
    void createEdge(int source, int destination);
    void removeEdge(int source, int destination);
    int findNode(int nData);
    void bfTraversal(int src);
    void print();
    
};

void Graph::initialize(){
    this->list = vector<Node *>(this->nodes);
    for(int i=0;i<this->nodes;i++){
        Node *temp = new Node(i+1);
        this->list[i] = temp;
        this->hash[i+1] = i;
        this->unVisited.insert(i+1);
    }
    cout<<"after initialization"<<endl;
    this->print();
}

void Graph::print(){
    for(int i=0;i<this->nodes;i++){
        Node * temp;
        temp = this->list[i];
        while(temp->getNext()){
            cout<<temp->getData()<<" -> ";
            temp = temp->getNext();
        }
        cout<<temp->getData()<<" -X ";
        cout<<endl;
    }
}

int Graph::findNode(int nData){
    map<int,int>::iterator it;
    it = this->hash.find(nData);
    if(it!=this->hash.end())
        return hash[nData];
    return -1;
}

Graph::Graph(int nodes, int edges, bool isDirected){
    this->nodes = nodes;
    this->edges = edges;
    this->isDirected = isDirected;
    this->initialize();
}

void Graph::createEdge(int source,int destination){
    int sIndex = this->findNode(source);
    if(sIndex != -1){
        Node *temp = new Node(destination);
        temp->setNext( this->list[sIndex]->getNext());
        this->list[sIndex]->setNext(temp);
    }
}

void Graph::bfTraversal(int src){
    int index = this->findNode(src);
    Node *head = this->list[index];
    head->setDist(0);
    queue<Node *> myQ;
    myQ.push(head);
    while(!myQ.empty()){
        Node *temp = myQ.front();
        temp->setVisited(true);
        myQ.pop();
        temp = temp->getNext();
        while(temp){
            if(!temp->getVisited())
                myQ.push(temp);
            temp = temp->getNext();
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout<<"Enter TestCases "<<endl;
    int T;
    cin>>T;
    cout<<"entered"<<endl;
    while(T--){
        int N,M;
        cin>>N>>M;
        Graph g = Graph(N,M,false);
        for(int i=0;i<M;i++){
            int src,dst;
            cin>>src>>dst;
            g.createEdge(src,dst);
            g.createEdge(dst,src);
        }
        g.print();
        int sNode;
        cin>>sNode;
        g.bfTraversal(sNode);
    }
    return 0;
}