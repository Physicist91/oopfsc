#include <vector>
#include <cmath>
#include <exception>
#include <string>

class invalid_range : public std::exception{
  int ind;
  public:
    invalid_range(int intg):ind{intg}{}

    const char* what() const noexcept {
      std::string err = "NumVector::operator[]: Invalid indices: ";
      err += std::to_string(ind);
      char* err1 = new char[err.size()];
      for(int j=0; j<err.size(); ++j) err1[j] = err[j];
      return err1;
    }

};

class non_matching_dimension : public std::exception{
  int sz1, sz2;
  public:
    non_matching_dimension(int size1, int size2):sz1{size1}, sz2{size2}{}

    const char* what() const noexcept {
      std::string err = "Scalar product: arguments have different dimensions: ";
      err += std::to_string(sz1);
      err += " and ";
      err += std::to_string(sz2);
      char* err1 = new char[err.size()];
      for(int j=0; j<err.size(); ++j) err1[j] = err[j];
      return err1;
    }

};

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
    if(i<0 || i>=v.size()) throw invalid_range(i);
    return v[i];
  }

  double& operator[](int i) {
    if(i<0 || i>=v.size()) throw invalid_range(i);
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

double operator*(NumVector& v1, NumVector& v2){
  double accum = 0;
  if(v1.size() != v2.size()) throw non_matching_dimension(v1.size(), v2.size());
  for(int i = 0; i<v1.size();++i) accum += v1[i] * v2[i];
  return accum;
}
