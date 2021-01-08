#include <stdio.h>
#include <vector>

using namespace std;

bool recusive_binary_search(vector<int> &sort_array, int begin, int end, int target) {
  if(begin>end) {
    return false;
  }
  int mid = begin + (end-begin)/2;
  if(target == sort_array[mid]) {
    return true;
  }
  else if(sort_array[mid]>target) {
    return recusive_binary_search(sort_array, begin, mid-1, target);
  }
  else if(sort_array[mid]<target) {
    return recusive_binary_search(sort_array, begin+1, mid, target);
  }
}

bool loop_binary_search(vector<int> &sort_array, int target) {
  int begin = 0;
  int end = sort_array.size()-1;
  while(begin<=end) {
    int mid = begin + (end-begin)/2;
    if(target == sort_array[mid]) {
      return true;
    }
    else if(target > sort_array[mid]) {
      begin = mid+1;
    }
    else if(target < sort_array[mid]) {
      end = mid-1;
    }
  }

  return false;
}