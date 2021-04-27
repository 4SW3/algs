#include <iostream>
#include <vector>
#define pb push_back
using namespace std;



template<typename T>
class SortingAlgs {

public:
  void swapT(T &x, T &y) {
    T t = x;
    x = y;
    y = t;
  }

  void print(vector<T> &v) {
    cout << "Vec: ";
    for(int i = 0; i < v.size(); ++i) {
      cout << v[i] << " ";
    }
    cout << endl;
  }

  void naiveSort(vector<T> &v) {
    for (size_t i = 0; i < v.size() - 1; ++i) {
      for (size_t j = i + 1; j < v.size(); ++j) {
        if (v[i] > v[j]) {
          swapT(v[i], v[j]);
        }
      }
    } 
  }

  int binSearch(vector<T> &v, int l, int r, int a) {
    if (l > r) return -1;
    int mid = (l + r) / 2;
    if (v[mid] == a) return mid;
    if (v[mid] < a) return binSearch(v, mid + 1, r, a);
    if (v[mid] > a) return binSearch(v, l, mid - 1, a);
  }

  void bubbleSort(vector<T> &v) {
    for (size_t i = 0; i < v.size() - 1; ++i)
      for (size_t j = 0; j < v.size() - i - 1; ++j)
        if (v[j] > v[j+1])
          swapT(v[j], v[j+1]);

  }

  void insertionSort(vector<T> &v) {
    int i, j, t;
    for (i = 1; i < v.size(); ++i) {
      t = v[i];
      for (j = i - 1; j >= 0 && v[j] > t; --j) 
        v[j+1] = v[j];
      v[j+1] = t;
    }
  }

  void selectionSort(vector<T> &v) {
    size_t swapIdx;
    for (size_t i = 0; i < v.size() - 1; ++i) {
      swapIdx = i;
      for (size_t j = i + 1; j < v.size(); ++j) {
          if (v[swapIdx] > v[j])
            swapIdx = j;
      }

      if (v[i] != v[swapIdx]) swapT(v[i], v[swapIdx]);
    }
  }

  vector<T> merge(vector<T> left, vector<T> right) {
    size_t i = 0, j = 0, n1 = left.size(), n2 = right.size();
    vector<T> res;

    while (i < n1 && j < n2) {
      if (left[i] <= right[j]) res.pb(left[i++]);
      else                     res.pb(right[j++]);
    }

    while (i < n1) res.pb(left[i++]);
    while (j < n2) res.pb(right[j++]);

    return res;
  }
  
  vector<T> mergeSort(vector<T> &vec) {
    if (vec.size() <= 1) return vec;
    size_t mid = vec.size() / 2;
    vector<T> left(vec.begin(), vec.begin() + mid);
    vector<T> right(vec.begin() + mid, vec.end());
    return merge(mergeSort(left), mergeSort(right));
  }
};

int main() {
  SortingAlgs<int> sa;
  vector<int> v{ 3,-3,1,-1,0,2,-2};

  return 0;
}
