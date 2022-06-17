bool graphics(){
  return true;
}

std::string GetImageFilename(const std::string& name, unsigned number){
    std::stringstream s;
    s << name;
    unsigned tn = number;
    unsigned d = 0;
    while (tn /= 10) d++;
    d = 3 - d;
    for (; d > 0; d--) s << "0";
    s << number;
    s << ".bmp";
    std::string result;
    s >> result;
    return "./out/"+result;
}

void ShowImage(const Array& result, std::string name, unsigned number = 0){
    if (graphics()){
      Bitmap resbmp =ArrayToBitmap(result);
      std::string resultF = GetImageFilename(name, number);
      resbmp.Save(resultF);
      std::cout << "Image " << resultF << " stored in Files" << std::endl;
    }
}

Array get_data(){
    std::cout << "image name (e.g. bird, peppers, sailboat, or city)? ";
    std::string filename;
    std::cin >> filename;
    Bitmap bitmap = readpgm("./" + filename + ".pgm");
    return BitmapToArray(bitmap);
}
