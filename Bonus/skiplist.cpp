#include "skiplist.h"
#include <random>
#include <iostream>

// you can use stderr for debugging
// (it does not interfere with the grading)
// example: cerr << "inserting number " << value << endl;

std::random_device r;
// default random generator
std::default_random_engine e(r());
// uniform distribution on {0,1}
std::uniform_int_distribution<int> rando(0, 1);


SkipList::~SkipList() 
{
    Node* h;
    while (head != nullptr)
    {
      h = head;
      head = head->forward[0];
      delete h;
    }
}

SkipList::Node* progress(SkipList::Node* start, int value, size_t level)
{
  if (start->forward.size() <= level) return start;
  
  while (start->forward[level] != nullptr && start->forward[level]->value < value)
    start = start->forward[level];
  return start;
}

void SkipList::insert(int value) 
{
  size_t l = 1;
  while (l < max_level_ && rando(e)) l++;

  Node* insertion = new Node(value, l);
  Node* curr = head;
  
  for (size_t level = max_level_; level > 0; level--)
  {
    curr = progress(curr, value, level-1);

    if (insertion->forward.size() >= level)
    {
      insertion->forward[level - 1] = curr->forward[level-1];
      curr->forward[level-1] = insertion;
    }
  }
}

void SkipList::erase(int value) 
{
  Node* curr = head;
  Node* backward[16];
  
  for (size_t level = max_level_; level > 0; level--)
  {
    curr = progress(curr, value, level-1);
    backward[level - 1] = curr;
  }
  
  while(curr->forward[0] != nullptr && curr->forward[0]->value == value)
  {
    Node* a = curr->forward[0];
    for (size_t i = 0; i < a->forward.size(); i++)
      backward[i]->forward[i] = a->forward[i];
    
    delete a;
  }
  
}
