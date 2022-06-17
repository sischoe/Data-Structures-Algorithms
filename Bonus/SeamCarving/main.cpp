#include <iostream>
#include <iomanip> // for setprecision
#include <cmath>
#include <random>

#include "bitmap.h"
#include "array.h"
#include "util.h"

// Forward declaration (seamcut.cpp)
// return an array where the provided seam is cut
Array SeamCut(const Array& array, const std::vector<unsigned>& seam);

// Forward declaration (seamcut.cpp)
// create an array comprising all energies
Array energies(const Array& array);

// Forward declaration (seamcut.cpp)
// get the energy of a seam in an array
double GetSeamEnergy(const Array& array, const std::vector<unsigned>& seam);

// Forward declaration (seamcut.cpp)
// compute the minimum vertcial seam in an array
// the returned vector contains the x-coordinate at position y
std::vector<unsigned> GetMinSeam(const Array& array);

// this is used in order to make the seams unique
void randomize(Array& array){
  std::mt19937 gen(42);
  std::normal_distribution<double> d(0,0.0001);
  for (unsigned y = 0; y<array.Height(); ++y){
    for (unsigned x = 0; x<array.Width(); ++x){
      array(x,y) += d(gen);
      if (array(x,y) > 1) array(x,y) = 1;
      if (array(x,y) < 0) array(x,y) = 0;
     }
  }
}


int main() {

    // load image data (see util.h)
    Array img = get_data();
    randomize(img); // for unique seams
    unsigned iterations = 1;
    std::cout << "Number of iterations? ";
    std::cin >> iterations;
    unsigned seams = 1;
    std::cout << "Number of seams to be removed per iteration? ";
    std::cin >> seams;
    
    // std::cerr << "before image0" << std::flush;
    ShowImage(img,"1_original");
    // std::cerr << "after image0\n" << std::flush;
    ShowImage(energies(img),"0_energy");
    Array result = img;
    //imgs.push_back(result);
    for (unsigned i = 1; i <= iterations; ++i){
      double energy = 0;
      for (unsigned j = 1; j <= seams; ++j){
        std::vector<unsigned> seam = GetMinSeam(result);
        energy = GetSeamEnergy(result, seam);
        result = SeamCut(result, seam);
      }
      img = result;
      std::cout << "Extracted seams. Last seam energy was " << energy << std::endl;
      ShowImage(result, "2_seam", i); 
    }
    
    return 0;
}
