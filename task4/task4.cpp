#include <iostream>
#include <string>
#include <locale>

class Groot {
  public:
    void Speak();
    void lSpeak();
};  

void Groot::Speak(){
  std::locale loc;
  std::string motto="I am Groot!\n";
  
  std::cout << motto;  
}

void Groot::lSpeak() {
  std::locale loc;
  std::string motto="I am Groot!\n";
  
  for(auto elem:motto)
    std::cout << std::tolower(elem,loc);
}

void Post(Groot *groot) {
  groot->Speak();
}

void Report(Groot *groot) {
  groot->lSpeak();
}

int main() {
  Groot *groot=new Groot();
  Post(groot);
  delete groot;

  groot=new Groot();
  Report(groot);
  delete groot;

  return 0;
}
