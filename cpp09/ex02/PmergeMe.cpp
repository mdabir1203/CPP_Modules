/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:11:53 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/29 17:36:36 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) {
    *this = copy;
}

// check if the arg are numbers and then put into the vector and list
// Why Choosing them ?
//  -> Performance, consistent interface for storing and manipulating data
//
// -> std::vector -> fast access elements at random positions,
//                    allocates memory as needed,
// Weak Point: slow insertion and delete oper
// -> std::list -> allocates memory for all of the elements in list upfront
// -> Fast insertion and deletion , bidirectional iterators
// Ford Johnson -> breaking large problem into smaller ones
// Divide the list into smaller sublist -> sort each list(insertion) -> merge sorted sublist with merge sort


PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
    if (this != &copy) {
        vec = copy.vec;
        lst = copy.lst;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


//  Functn to modify input vec in place, so sorted elements are stored in same vector

void PmergeMe::insertion_sort_vec(std::vector<int> &vec, int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = vec[i];
        int j = i - 1;
        
        while (j >= left && vec[j] > key) {
            vec[j+1] = vec[j];
            j--;
        }
        
        vec[j+1] = key;
    }
}

// calculates -> size of two subarrays
// -> sorted elements are stored in same vector
void PmergeMe::merge_vec(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    std::vector<int> L(n1), R(n2);
    // TODO: copy elements into L and R
    for (int i = 0; i < n1; ++i) {
        L[i] = vec[left + i];
    }
    
    for (int j = 0; j < n2; ++j) {
        R[j] = vec[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
  // TODO: copy smaller elements into vec at index k  
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        }
        else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

// k-> threshold value to switch to insertion sort
// -> If only 1 element- > already sorted and return
// Merge sort -> divide and conquer algo (take whole card -> divide into two halves -> sort each half -> merge them into one sorted array ))

void PmergeMe::sort_vec(std::vector<int> &vec, int left, int right, int k)
{
    if (left < right) {
        if (right - left + 1 <= k) {
            insertion_sort_vec(vec, left, right);
        }
        else { 
            int mid = left + (right - left) / 2;

            sort_vec(vec, left, mid, k);
            sort_vec(vec, mid+1, right, k);
            merge_vec(vec, left, mid, right);
        }
    }
}

int PmergeMe::check_is_num(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

// Using iterators here -> for list 

std::list<int> PmergeMe::merge_lst(std::list<int> &left, std::list<int> &right)
{
  std::list<int> result;

  while (!left.empty() && !right.empty()) {
    if (left.front() <= right.front()) {
      result.push_back(left.front());
      left.pop_front();
    } else {
      result.push_back(right.front());
      right.pop_front();
    }
  }

  while (!left.empty()) {
    result.push_back(left.front());
    left.pop_front();
  }

  while (!right.empty()) {
    result.push_back(right.front());
    right.pop_front();
  }

  return result;
}

void PmergeMe::sort_lst(std::list<int> &list)
{
if (list.empty() || list.size() == 1) {
    return;
  }

  std::list<int> left, right;
  size_t count = 0;
  for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
    if (count < list.size() / 2) {
      left.push_back(*it);
    } else {
      right.push_back(*it);
    }
    count++;
  }
  sort_lst(left);
  sort_lst(right);
  list = merge_lst(left, right);
}

double PmergeMe::sorter(char **av)
{
    std::clock_t s, e;
    double v_time, l_time;
    for (int i = 1; av[i]; i++)
    {
        if (av[i][0] == '-')
            throw std::invalid_argument("Error");
        if (check_is_num(av[i]))
        {
            vec.push_back(std::stoi(av[i]));
            lst.push_back(std::stoi(av[i]));
        }
        else
            throw std::invalid_argument("Error");
    }
    std::cout << "Before: ";
    if (vec.size() <= (size_t)5)
    {
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
            std::cout << vec[i] << " ";
        std::cout << "[...]" << std::endl;
    }
    s = std::clock();
    sort_vec(vec, 0, vec.size() - 1, vec.size() / 4);
    e = std::clock();
    v_time = (double)(e - s) / CLOCKS_PER_SEC * 1000;
    s = std::clock();
    sort_lst(lst);
    e = std::clock();
    l_time = (double)(e - s) / CLOCKS_PER_SEC * 1000;
    std::cout << "After:  ";
    if (vec.size() <= (size_t)5)
    {
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;
    }
    else
    {
        for (size_t i = 0; i < 5; i++)
            std::cout << vec[i] << " ";
        std::cout << "[...]" << std::endl;
    }
    std::cout << "Time to process a range of " << vec.size()<< " elements with std::vector: " << std::setprecision(5) << v_time << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size() <<" elements with std::list: " << std::setprecision(5) << l_time << " us" << std::endl;
    return 0;
}