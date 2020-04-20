#include <exception>
#include <string>

class Ball : public std::exception {};
class P;

class P{
private:
  P* Target;
public:
  P(P* target){
    Target = target;
  }
  P(){};
  void aim(Ball ball){
    try{
      throw ball; //6. Throw exception
    } catch(Ball b){
      Target->aim(b); //7. Upon receiving the exception, this catch block calls the "aim" method of the target.
      //8. this "aim" method will be called recursively, with the target switched between parent and child.
    }
  }

  static void main(std::string args){
    P* Parent = new P(); //1. This line is executed first
    P* Child = new P(Parent); //2. This line is next, parent becomes the target for the child
    Parent->Target = Child; //3. Parent's target is assigned to the child
    Ball b = Ball(); //4. Create an instance of the ball (i.e. the exception to be thrown)
    Parent->aim(b); //5. aim at child
  }

};
