#include <cmath>
#include <iostream>
#include "array.h"
#include "bitmap.h"

// the underlying distance between two pixel values: absolute distance
double distance(double p1, double p2){
  return std::abs(p1-p2);
}

// Calculates the energy of a pixel by summing the distance to surrounding pixels
double energy(const Array& array, unsigned x, unsigned y){
  if ((x == 0 || x == array.Width() - 1) && (y == 0 || y == array.Height() - 1))
    return 1; // max distance at the corners
  // otherwise: sum of all (available) surrounding pixels
  double result = 0;
  if (x > 0)
    result += distance(array(x, y), array(x - 1, y));
  if (x < array.Width() - 1)
    result += distance(array(x, y), array(x + 1, y));
  if (y > 0)
    result += distance(array(x, y), array(x, y - 1));
  if (y < array.Height() - 1)
    result += distance(array(x, y), array(x, y + 1));
  return result;
}

// create an array comprising all energies
Array energies(const Array& array){
  unsigned w = array.Width();
  unsigned h = array.Height();
  Array e (w,h);
  for (unsigned x = 0; x != w; ++x){
    for (unsigned y = 0; y != h; ++y){
      e(x,y) = energy(array,x,y);
    }
  }
  return e;
}

// cut a pixel from a horizontal line
// omit: the pixel to cut. E.g., omit = 0 -> cut the first pixel
// y: the horizontal line
void cut_x(const Array& array, Array& copy, unsigned omit, unsigned y){
  for (unsigned x = 0; x != omit; ++x){
    copy(x,y) = array(x,y);
  }
  for (unsigned x = omit+1; x != array.Width(); ++x){
    copy(x-1,y) = array(x,y);
  }
}

// get the energy of all pixels of a seam
double GetSeamEnergy(const Array& array, const std::vector<unsigned>& seam){
  double total = 0;
  for (unsigned y = 0; y < seam.size(); ++y){
    total += energy(array,seam[y],y);
  }
  return total;
}

// the DP algorithm
// compute and return the minimum energy vertical seam in an array
// the returned vector contains at position y the x-coordinate to y
std::vector<unsigned> GetMinSeam(const Array& array){
  unsigned w = array.Width();
  unsigned h = array.Height();
  std::vector<unsigned> seam(h);
  
  Array table = energies(array);
  
  for (size_t y = 1; y < h; y++)
  {
    for (size_t x = 0; x < w; x++) 
    {
      size_t xadd = x;
      if (x > 0 && table(xadd, y-1) > table(x-1, y-1)) xadd = x-1;
      if (x < w-1 && table(xadd, y-1) > table(x+1, y-1)) xadd = x+1;
      table(x,y) += table(xadd, y-1);
    }
  }
  
  size_t x = 0;
  for (size_t xp = 1; xp < w; xp++)
    if (table(xp, h-1) < table(x, h-1)) x = xp;
  
  seam[h-1] = x;
  
  for (size_t y = h-1; y > 0; y--)
  {
    x = seam[y];
    seam[y-1] = x;
    if (x > 0 && table(x-1, y-1) < table(seam[y-1], y-1)) seam[y-1] = x-1;
    if (x < w-1 && table(x+1, y-1) < table(seam[y-1], y-1)) seam[y-1] = x+1;
  }
  
  return seam;
}

// remove the seam specified by seam from the array
Array SeamCut(const Array& array, const std::vector<unsigned>& seam)
{
  unsigned w = array.Width();
  unsigned h = array.Height();
  Array copy(w-1,h);
  
  for (size_t y = 0; y < h; y++)
    cut_x(array, copy, seam[y], y);
    
  return copy;
}

// PUT THE ASYMPTOTIC RUNTIME OF YOUR ALGORITHM BELOW
// RUNTIME: O(w*h)