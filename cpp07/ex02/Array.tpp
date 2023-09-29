template <typename T>
Array<T>::Array() : data(), size_(0){
  data = new T[size_];
}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n)
{
  data = new T[size_]();
}

template <typename T>
Array<T>::Array(const Array& copy) : size_(copy.size_)
{
  data = new T[size_];
  std::copy(copy.data, copy.data + size_, data);
}

template <typename T>
Array<T>::~Array()
{
  delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) const
{
  if (idx >= size_){
    throw std::exception();
  }
  return data[idx];
}

template<typename T>
unsigned int Array<T>::size() const
{
  return size_;
}


