#include <iostream>
#include "graph.h"

class UnionFind {
  public:
    void MakeSet(NodeP n){
      parent[n] = n;
      depth[n] = 0;
    }
    
    NodeP Find(NodeP n){
      while (parent[n] != n){
        n = parent[n];
      }
      return n;
    }
    
    bool Union(NodeP l, NodeP r){
      l = Find(l);
      r = Find(r);
      if (l == r){
        return false;
      } else {
        if (depth[l] < depth[r]){
          std::swap(l,r);
        }
        parent[r] = l;
        if (depth[l] == depth[r]){
          depth[l]++;
        }
        return true;
      }
    }

  private:
    std::unordered_map<NodeP,NodeP> parent;
    std::unordered_map<NodeP,unsigned> depth;
};


std::vector<Edge> Graph::Kruskal(){
  std::vector<Edge> result;
  std::cout << "sorting edges" << std::endl; 
  std::sort(edges.begin(),edges.end(),[](const Edge& l, const Edge& r) {return l.length < r.length;});

  std::cout << "creating uf" << std::endl; 
  UnionFind uf;
  for (auto n: nodes){
    uf.MakeSet(n);
  }
  std::cout << "adding edges" << std::endl; 
  for (const auto& e: edges){
    if (uf.Union(e.source, e.target)){
      result.push_back(e);
    }
  }
  return result;
}
  