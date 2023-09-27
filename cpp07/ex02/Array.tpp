template <typename T>
Array<T>::Array(void) : arr_(NULL), _size(0){}

Array<T>::Array(unsigned int n) : data(new T[n], _size(n)){}

template <typename T>
Array<T>::Array(const Array& copy)
{
  size_ = copy.size_;
  arr_ = new T[size_];
  unsigned int i = 0;
  while (i++ < size_)
  {
    arr_[i] = copy.array[i];
  }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
  if (this != &copy) {
    delete[] arr_;

    size_ = copy.size_;
    arr_ = new T[size_];
    unsigned int i = 0;
    while (i++ < size_)
    {
      arr_[i] = copy.array[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::~Array()
{
  delete[] arr_;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
  if (idx >= size_)
  {
    throw std::exception();
  }
  return arr_[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
  if (idx >= size_)
    throw std::exception();
  return arr_[idx];
}