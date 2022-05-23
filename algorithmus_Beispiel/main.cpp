#include <iostream>
#include <vector>
#include <cmath>
#include "utils.hpp"

double max_subarray_naive(const std::vector<double>& data){
  double max = data[0];
  for (unsigned i = 0; i<data.size(); ++i){
    for (unsigned j = i; j<data.size();++j){
      double sum = 0;
      for (unsigned k = i; k <=j; ++k){
        sum += data[k];
      }
      if (sum > max)
        max = sum;
    }
  }
  return max;
}

std::vector<double> get_table(const std::vector<double>& data){
  std::vector<double> sum(data.size()+1);
  sum[0] = 0;
  for (unsigned i = 0; i<data.size(); ++i){
    sum[i+1] = sum[i]+data[i];
  }
  return sum;  
}

double max_subarray_table(const std::vector<double>& data){
  auto sum = get_table(data);
  double max = data[0];
  for (unsigned i = 1; i<sum.size(); ++i){
    for (unsigned j = i; j<sum.size();++j){
      if (sum[j] - sum[i-1] > max)
        max = sum[j] - sum[i-1];
    }
  }
  return max;
}

double max_subarray_recursive(const std::vector<double>& sum, unsigned l, unsigned r){
  if (r == l){
    return sum[r]-sum[l-1];
  } else {
    unsigned m=(r+l)/2;
    double bestL = max_subarray_recursive(sum, l, m);
    double bestR = max_subarray_recursive(sum, m+1, r);
    double maxL = sum[m]-sum[m-1];
    for (unsigned i = l; i <= m; ++i){
      if (sum[m]-sum[i-1] > maxL){
        maxL = sum[m]-sum[i-1];
      }
    }
    double maxR = 0;
    for (unsigned i = m+1; i<=r; ++i){
      if (sum[i]-sum[m] > maxR){
        maxR = sum[i]-sum[m];
      }
    }
    double bestM = maxL + maxR;
    if (bestL > bestR)
      bestR = bestL;
    if (bestR > bestM)
      bestM = bestR;
    return bestM;
  }
}

double max_subarray_recursive(const std::vector<double>& data){
  return max_subarray_recursive(get_table(data), 1, data.size());
}

double max_subarray_inductive(const std::vector<double>& data){
  auto sum = get_table(data);
  unsigned int n = data.size();
  
  double max = data[0];
  unsigned int left = 0;
  for (unsigned int right=1; right<=n; ++right){
    double current = sum[right]-sum[left];
    if (current > max){
      max = current;
    }
    if (current <= 0){
      left = right;
    }
  }
  return max;
}


std::vector<double> random_vector(unsigned n){
  std::vector<double> ran(n);
  for (unsigned i= 0; i<=n; ++i){
    ran[i] = std::sin(i*25.0/n);
  }
  return ran;
}

int main(){
  timer t;
  unsigned int start = 0;
  unsigned int end = 0;
  std::string features;
  std::cout << "n(Anfang), n(Ende) und Merkmale (Teilmenge von ntri) bereitstellen" << std::endl;
  std::cout << "z.B. Versuch 100 1000 ntri" << std::endl;
  std::cin >> start;
  std::cin >> end;
  std::cin >> features;
  if (start <= 0) 
    start= 100;
  if (end <= 0) 
    end = 1000000;
  for (unsigned N = start; N <= end; N*=10){
    for (unsigned n=N; n<10*N && n <= end; n+= N){
      std::vector<double> a = random_vector(n);
      std::cout << "n = " << n;
      if (features.find('n') != std::string::npos){
        t.tick();
        max_subarray_naive(a);
        t.tock();
        std::cout << t.elapsed("naive");
      }
      if (features.find('t') != std::string::npos){
        t.tick();
        max_subarray_table(a);
        t.tock();
        std::cout << t.elapsed("Tabelle");
      }
      if (features.find('r') != std::string::npos){
        t.tick();
        max_subarray_recursive(a);
        t.tock();
        std::cout << t.elapsed("d & c");
      }
      if (features.find('i') != std::string::npos){
        t.tick();
        max_subarray_inductive(a);
        t.tock();
        std::cout << t.elapsed("induktiv");
      }
      std::cout << std::endl;
    }
  }
  return 0;
}

/* inputs
100 1000 n
100 1000 ntri
100 30000 t
100 30000 tr
10000 10000000 r
10000 10000000 ri
100000 100000000 i
*/
