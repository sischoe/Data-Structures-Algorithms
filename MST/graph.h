#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <memory>
#include <unordered_map>


struct Node{
  unsigned id; // unique
  double x;
  double y;
  
  Node(unsigned ID, double X, double Y):
    id(ID), x(X), y(Y) {};
    
  double dist(const Node& other){
    double dx = (x-other.x);
    double dy = (y-other.y);
    return std::sqrt(dx*dx+dy*dy);
  }
};

using NodeP = std::shared_ptr<Node>;

struct Edge {
  double length;
  NodeP source;
  NodeP target;

  Edge(NodeP src, NodeP tgt):
    length(src->dist(*tgt)), source(src), target(tgt){}
};

using EdgeP = std::shared_ptr<Edge>;


class Graph {
public:
  
  Graph(){}; 
  
  void add_node(NodeP n){ 
    nodes.push_back(n); 
  }
  
  void add_edge(NodeP src, NodeP dest){
    edges.emplace_back(src,dest);
  }
  
  std::vector<NodeP> get_nodes(){
    return nodes;
  }
  
  std::vector<Edge> Kruskal();
  
private:
  std::vector<NodeP> nodes;
  std::vector<Edge> edges;
};

#endif