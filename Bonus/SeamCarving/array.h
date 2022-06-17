#pragma once

#include "bitmap.h"

class Array{
    private:
    double* data = nullptr;
    unsigned int width;
    unsigned int height;
    
    void swap(Array& a);

public:
    Array(unsigned int w, unsigned int h);
    
    Array(const Array& a);
    
    ~Array();
    
    Array& operator=(const Array& a);
    
    double& operator()(unsigned int x, unsigned int y);

    double operator()(unsigned int x, unsigned int y) const;
    
    unsigned int Width() const;

    unsigned int Height() const;
};



Array BitmapToArray (const Bitmap& bitmap);

Bitmap ArrayToBitmap (const Array& array);