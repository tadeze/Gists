#include<iostream>
/*
void UpdateWeight(const float *grad,float eta, float lambda,
int n, float *weight){
  for(int i=0;i<n;i++){
    weight[i] = -eta*(grad[i]+ lambda*weight[i]);
  }
}  //Pre-allocated weight and grad variables. Let's get performance gain
//  Can we write like this ?
void UpdateWeightI(const Vec& grad,float eta, float lambda,
int n, Vec& weight){
    weight = -eta*(grad+ lambda*weight);

}*/
// Naive solution
/*
struct Vec {
  int len;
  float* dplr;
  Vec(int len):(len){
    dplr = new float[len];
  };
  Vec(const Vec& src):len(src.len){ //copy constructor.
    dplr = new float[len];
    memcpy(dplr,src.dplr,sizeof(float)*len); //copy content of the src vec.
  }
  ~Vec(void){
    delete[] dplr;
  }
  inline Vec operator+(const Vec &lhs, const Vec &rhs){  //operator overloading
    Vec res(lhs.len);
    for(int i=0;i<lhs.len;i++)
    res.dplr[i] = lhs.dplr[i] + rhs.dplr[i];
    return res;
  }
}
*/
// this is expression, all expressions must inheritate it,
//  and put their type in subtype
template<typename SubType>
struct Exp {
  // returns const reference of the actual type of this expression
  inline const SubType& self(void) const {
    return *static_cast<const SubType*>(this);
  }
};

// binary add expression
// note how it is inheritates from Exp
// and put its own type into the template argument
template<typename TLhs, typename TRhs>
struct BinaryAddExp: public Exp<BinaryAddExp<TLhs, TRhs> > {
  const TLhs &lhs;
  const TRhs &rhs;
  BinaryAddExp(const TLhs& lhs, const TRhs& rhs)
      : lhs(lhs), rhs(rhs) {}
  // evaluation function, evaluate this expression at position i
  inline float Eval(int i) const {
    return lhs.Eval(i) + rhs.Eval(i);
  }
};
// no constructor and destructor to allocate
// and de-allocate memory, allocation done by user
struct Vec: public Exp<Vec> {
  int len;
  float* dptr;
  Vec(void) {}
  Vec(float *dptr, int len)
      :len(len), dptr(dptr) {}
  // here is where evaluation happens
  template<typename EType>
  inline Vec& operator= (const Exp<EType>& src_) {
    const EType &src = src_.self();
    for (int i = 0; i < len; ++i) {
      dptr[i] = src.Eval(i);
    }
    return *this;
  }
  // evaluation function, evaluate this expression at position i
  inline float Eval(int i) const {
    return dptr[i];
  }
};
// template add, works for any expressions
template<typename TLhs, typename TRhs>
inline BinaryAddExp<TLhs, TRhs>
operator+(const Exp<TLhs> &lhs, const Exp<TRhs> &rhs) {
  return BinaryAddExp<TLhs, TRhs>(lhs.self(), rhs.self());
}

const int n = 3;
int main(void) {
  float sa[n] = {1, 2, 3};
  float sb[n] = {2, 3, 4};
  float sc[n] = {3, 4, 5};
  Vec A(sa, n), B(sb, n), C(sc, n);
  // run expression, this expression is longer:)
  A = B + C + C;
  for (int i = 0; i < n; ++i) {
    printf("%d:%f == %f + %f + %f\n", i,
           A.dptr[i], B.dptr[i],
           C.dptr[i], C.dptr[i]);
  }
  return 0;
}
