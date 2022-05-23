#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

// Sehr einfaches Zeitmessgerät zur Messung der verstrichenen Zeit
struct timer {
  using timepoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
  
  timepoint start;
  timepoint end;
  
  void tick() {
    start = std::chrono::high_resolution_clock::now();
  }
  
  void tock() {
    end = std::chrono::high_resolution_clock::now();
  }
  
  unsigned long elapsed_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  }

  unsigned long elapsed_mus() {
    return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
  }
  
  std::string elapsed(std::string what) {
    std::ostringstream ss;
    ss << "    ► "
       << what
       << std::setw(5)
       << elapsed_mus() / 1000
       << "."
       << elapsed_mus() % 1000 / 10
       << " ms";
    return ss.str();
  }
};

// zeit Formattierung
