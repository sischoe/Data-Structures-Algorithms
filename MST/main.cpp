#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <sstream>

#include "graph.h"

std::vector<Node> read_csv(){
  std::ifstream fin("swiss-towns.csv");
  std::string row;
  std::string column;
  
  std::vector<std::string> header;
  std::getline(fin,row,'\n');
  std::stringstream ss(row);
  
  // Extract column names
  while(std::getline(ss, column, ';')){
    header.push_back(column);
  }
  std::vector<Node> result;
  double east = 0, north = 0;
  unsigned id = 0;
  while (!fin.eof()){
    std::getline(fin,row,'\n');
    std::stringstream ss(row);
    std::string column;
    for(auto head = header.begin(); std::getline(ss, column, ';');++head){
      if (*head == "E"){
        east = std::stod(column)-2600000;
      } else if (*head == "N"){
        north = std::stod(column)-1200000;
      }
    }
    result.push_back(Node(id++,east,north));
  }
  return result;
}

int main(){
  unsigned n_nodes;
  std::cout << "Enter the number of towns: " << std::endl;
  std::cin >> n_nodes;
  std::cout << "reading in data" << std::endl;
  std::vector<Node> all_nodes = read_csv();
  std::vector<NodeP> selected_nodes;
  std::mt19937 gen(n_nodes);
  if (n_nodes >= all_nodes.size()){
    n_nodes = all_nodes.size();
  } else {
    std::cout << "shuffling data" << std::endl;
    for (unsigned i=0; i<n_nodes; ++i){
      std::uniform_int_distribution<> distrib(i, all_nodes.size()-1);
      unsigned pos = distrib(gen);
      std::swap(all_nodes[i],all_nodes[pos]);
    }
  }
  std::cout << "creating nodes" << std::endl;
  for (unsigned i=0; i<n_nodes; ++i){
    selected_nodes.push_back(std::make_shared<Node>(all_nodes[i]));
  }
  
  std::cout << "creating edges" << std::endl;
  Graph g;
  for (auto left = selected_nodes.begin(); left != selected_nodes.end(); left ++){
    g.add_node(*left);
    for (auto right = left+1; right != selected_nodes.end(); ++right){
      g.add_edge(*left,*right);
    }
  }
  std::cout << "running mst algorithm" << std::endl;
  std::vector<Edge> mst = g.Kruskal();
  
  std::cout << "writing nodes and edges to file" << std::endl;
  
  std::ofstream ofn("out_nodes.txt");
  for (auto n: g.get_nodes()){
    ofn << n->id << "," << n->x << "," << n->y << std::endl;
  }
  std::ofstream ofe("out_edges.txt");
  double sum = 0;
  for (auto e: mst){
    ofe << e.source->id << "," << e.target->id << "," << e.length << std::endl;
    sum += e.length;
  }
  std::cout << "MST weight = " << unsigned(sum+0.5) << std::endl;
  return 0;
}
