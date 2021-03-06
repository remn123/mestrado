#include <vector>


// Solution Class
class DVector
{
private:
  std::vector<double> q;
public:
	DVector(){this->q = std::vector<double>(4, 0.0);};
  DVector(const std::vector<double>& sol) : q(sol){};
  DVector(const DVector& rhs){this->q = rhs.q;};
  ~DVector(){this->q.clear();};
  
  size_t size (void)
  {
    return this->q.size();
  }

  /* Access ith element operator */
  double operator [](const unsigned int& i)
  {
    return this->q[i];
  }

  /* Assignment = operator*/
  // Assigning a scalar
  template <typename T>
  DVector& operator = (const T& scalar)
  {
    auto q_size = this->q.size();

    if (q_size > 0)
    {
      for (unsigned int i = 0; i<this->q.size(); i++)
      {
        this->q[i] = (double) scalar;
      }
    }
    else
    {
      this->q.reserve(1);
      this->q[0] = (double) scalar;
    }
    return *this;
  }
  // Assigning a DVector
  DVector& operator = (const DVector& rhs)
  {
    auto rhs_size = rhs.q.size();

    this->q.clear();
    this->q.resize(rhs_size);

    this->q = rhs.q; // copy

    return *this;
  }
  
  // Assigning a std::vector
  DVector& operator = (const std::vector<double>& rhs)
  {
    auto rhs_size = rhs.size();

    this->q.clear();
    this->q.resize(rhs_size);

    this->q = rhs; // copy

    return *this;
  }
  

  /* ADDITION AND SUBTRACTION */
  // +=
  template <typename T>
  DVector& operator += (const T& scalar)
  {
    for (unsigned int index = 0; index<this->q.size(); index++)
    {
      this->q[index] += scalar; 
    }
    return *this;
  }

  // -=
  template <typename T>
  DVector& operator -= (const T& scalar)
  {
    for (unsigned int index = 0; index<this->q.size(); index++)
    {
      this->q[index] -= (double) scalar; 
    }

    return *this;
  }

  DVector& operator += (const DVector& rhs)
  {
    if(this->size() < rhs.q.size())
    {
      this->q.resize(rhs.q.size());
    }
    unsigned int index = 0; 
    for (auto& val : rhs.q)
    {
      index++;
      this->q[index-1] += val; 
    }

    return *this;
  }

  // -=
  DVector& operator -= (const DVector& rhs)
  {
    unsigned int index = 0; 
    for (auto& val : rhs.q)
    {
      index++;
      this->q[index-1] -= val; 
    }

    return *this;
  }

  // DVector addition
  DVector operator + (const DVector& rhs)
  {
    DVector result {*this};
    return result += rhs;
  }

  // DVector subtraction
  DVector operator - (const DVector& rhs)
  {
    DVector result (*this);
    return result -= rhs;
  }

  /* MULTIPLICATIONS */
  // *=
  DVector& operator *= (const DVector& rhs)
  {
    unsigned int index = 0; 
    for (auto& val : rhs.q)
    {
      index++;
      this->q[index-1] *= val; 
    }

    return *this;
  }

  template<typename T>
  DVector& operator *= (const T& scalar)
  {
    for (unsigned int index = 0; index<this->q.size(); index++)
    {
      this->q[index] *= (double) scalar; 
    }
    return *this;
  }

  // DVector multiplication
  DVector operator * (const DVector& rhs)
  {
    DVector result (*this);
    return result *= rhs;
  }

  DVector operator - () const // in order to be able to apply it on const objects
  { 
    DVector result {*this};
    return result *= -1;
  }
  

};

// Scalar multiplication
template<typename T>
DVector operator * (const DVector& rhs, const T& scalar)
{
  DVector result {rhs};
  return result *= scalar;
}

// DVector addition
template <typename T>
DVector operator + (const DVector& rhs, const T& scalar)
{
  DVector result {rhs};
  return result += scalar;
}

// DVector subtraction
template <typename T>
DVector operator - (const DVector& rhs, const T& scalar)
{
  DVector result {rhs};
  return result -= scalar;
}

template <typename T>
DVector operator * (const T& scalar, const DVector& rhs) 
{
  DVector lhs {rhs*scalar};
  return lhs;
}

template <typename T>
DVector operator + (const T& scalar, const DVector& rhs) 
{
  DVector lhs {rhs+scalar};
  return lhs;
}

template <typename T>
DVector operator - (const T& scalar, const DVector& rhs) 
{
  DVector lhs {-rhs+scalar};
  return lhs;
}
