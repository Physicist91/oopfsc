#include <vector>
#include <cmath>

class NumVector{
private:
  std::vector<double> v;
public:
  NumVector(int s){
    v.resize(s);
  }

  double norm() const{
    double accum = 0;
    for(int i=0; i<v.size();++i)
      accum += v[i] * v[i];
    return std::sqrt(accum);
  }

  const double& operator[](int i) const{
    return v[i];
  }

  double& operator[](int i) {
    return v[i];
  }

  int size() const{
    return v.size();
  }

  NumVector(const NumVector& w){
    v.resize(w.size());
    for(int i=0;i<v.size();++i) v[i] = w[i];
  }

  NumVector& operator=(const NumVector& w){
    v.resize(w.size());
    for(int i=0;i<v.size();++i) v[i] = w[i];
    return *this;
  }
};

//Another NumVector using array, just for learning!
class NumVector2 {
private:
  int sz;
  double* elem;
public:
  NumVector2(int s):sz{s}, elem{new double[s]}{} //size of vector is fixed in the constructor
  //~NumVector();

  double norm() const{
    double accum = 0;
    for(int i=0; i<sz; ++i)
      accum += elem[i] * elem[i];
    return std::sqrt(accum);
  }

  const double& operator[](int i) const{
    return elem[i];
  }

  double& operator[](int i){
    return elem[i];
  };

  NumVector2(const NumVector2& v):sz{v.sz}{
    elem = new double[sz];
    for(int i=0; i<sz; ++i) elem[i] = v.elem[i];
  }

  NumVector2& operator=(const NumVector2& v){
    double* pointer = new double[v.sz];
    for(int i=0; i<v.sz;++i) pointer[i] = v.elem[i];
    delete[] elem;
    elem = pointer;
    sz = v.sz;
    return *this;
  }

};
