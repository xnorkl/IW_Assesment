#include <iostream>
#include <memory>

class BabyGroot {
  public: 
    virtual ~BabyGroot() = default; // Deleting an object through a pointer to a type without a virtual destructor results in undefined behavior.
    virtual void Speak();
};

void BabyGroot::Speak() {
  std::cout << "i am groot" << std::endl;
}

class Groot final : public BabyGroot { // Delete could reference a subclass. Final prevents that.
  public:
    void Speak() override;
};

void Groot::Speak() {
  std::cout << "I am Groot!" << std::endl;
}

void A() {
  std::cout << "== A ==" << std::endl;
  BabyGroot baby;
  Groot groot;
  baby=groot;
  baby.Speak(); 
}

void B() {
  std::cout << "== B ==" << std::endl;
  BabyGroot *baby=new BabyGroot(); //baby pointer is never read
  Groot *groot=new Groot();
  baby=groot; //pointer never changes
  baby->Speak();
  // FIXME: memory leak
}

void C() {
  std::cout << "== C ==" << std::endl;
  std::unique_ptr<BabyGroot> baby (new BabyGroot);
  std::unique_ptr<Groot> groot (new Groot);
  std::cout << "get the object that baby points to and access Speak()" <<std::endl;
  //baby->Speak();
  std::cout << "get the object that groot points to and access Speak()" <<std::endl;
  groot->Speak();
  // Avoid memory leak
}

int main() {
  A();
  B();
  C();
  return 0;
}

/*
 * Note: Value Stored to baby (line 31:14) is never read. 
 * line 34: baby->Speak is identical to (*groot).Speak()
 */
