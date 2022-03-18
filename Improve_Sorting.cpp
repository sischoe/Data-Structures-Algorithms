// selection sort with improvement: less swaps
void improved_selection_sort(std::vector<Value>& a){
  std::size_t n = a.size();
  for (std::size_t i = 0; i<n ; ++i){
    auto min = i;
    for (std::size_t j = i+1; j<n; ++j){
      if (a[j] < a[min]){
        min = j;
      }
    }
    if (i != min){
      swap(a[i],a[min]);
    }
  }
}

// insertion sort with swaps and comparisons
void insertion_sort(std::vector<Value>& a){
  std::size_t n = a.size();
  for (std::size_t i = 1; i<n ; ++i){
    for (auto j = i; j>0 && a[j]<a[j-1];--j){
      swap(a[j],a[j-1]);
    }
  }
}

// binary search for insertion position
std::size_t find(std::vector<Value>& a, Value value, std::size_t left, std::size_t right){
  while (left != right){
    auto m = (left + right) / 2;
    if (value < a[m]) right = m;
    else if (value > a[m]) left = m+1;
    else return m;
  }
  return left;
}

// insertion sort using binary search 
void insertion_sort_x(std::vector<Value>& a){
  std::size_t n = a.size();
  for (std::size_t i = 1; i<n ; ++i){
    auto pos = find(a,a[i],0,i);
    for (auto j = i; j>pos;--j){
      swap(a[j],a[j-1]);
    }
  }
}


// pre: arbitrary vector of data a
// post: return sorted vector
std::vector<Value> your_sort1(std::vector<Value> a){
  improved_selection_sort(a);
  return a;
}

// pre: arbitrary vector of data a
// post: return sorted vector
std::vector<Value> your_sort2(std::vector<Value> a){
  insertion_sort(a);
  return a;
}

// pre: arbitrary vector of data a
// post: return sorted vector
std::vector<Value> your_sort3(std::vector<Value> a){
  insertion_sort_x(a);
  return a;
}


