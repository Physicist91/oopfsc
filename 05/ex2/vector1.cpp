#include <vector>
#include <cmath>

//Has-a relation
class NumVector:private std::vector<double>{

public:
  
  NumVector(int s):std::vector<double>(s){};

  double norm() const{
    double accum = 0;
    for(int i=0;i<(*this).size();++i)
      //accum += v[i] * v[i];
      accum += (*this)[i] * (*this)[i];
    return std::sqrt(accum);
  }

  using std::vector<double>::operator[]; //forward this method from the parent
  using std::vector<double>::at;
  using std::vector<double>::size;
};
