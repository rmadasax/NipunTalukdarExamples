#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;


template <class T>
class Tree 
{
private:
    T val;
    Tree *right = nullptr;
    Tree *left = nullptr;
    void printPathsInternal(vector<T>& vals);
    
public:
    Tree(T val);
    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;
    bool add(T val);
    int32_t maxDepth();
    int32_t size();
    void printPaths();

};

template <class T>
Tree<T>::Tree(T val) {
    this->val = val;
    this->right = nullptr;
    this->left = nullptr;
}

template <class T>
bool Tree<T>::add(T val) 
{
    if (this->val == val) {
        return false;
    }
    if (val < this->val) {
        if (left == nullptr) {
            left = new Tree(val);
            return true;
        }
        return left->add(val);
    }
    if (val > this->val) {
        if (right == nullptr) {
            right = new Tree(val);
            return true;
        }
        return right->add(val);
    }
    return true;
}


template<class T>
int32_t Tree<T>::size()
{
    int32_t count = 1;
    if (right != nullptr) {
        count += right->size();
    }
    if (left != nullptr) {
        count += left->size();
    }

    return count;
}

template<class T>
int32_t Tree<T>::maxDepth()
{
    int32_t depth = 1;
    int32_t rightdepth = 0;
    int32_t leftdepth = 0;
    if (right != nullptr) {
        rightdepth = right->maxDepth();
    }
    if (left != nullptr) {
        leftdepth = left->maxDepth();
    }
    return 1 + max(leftdepth, rightdepth);
}

template<class T>
void Tree<T>::printPaths()
{
    if (left == nullptr && right == nullptr) {
        cout << val << endl;
        return;
    }
    vector<T> paths = {val};
    if (left) {
        left->printPathsInternal(paths);
    }
    if (right) {
        right->printPathsInternal(paths);
    }
}

template<class T>
void Tree<T>::printPathsInternal(vector<T>& vals)
{
    if (left == nullptr && right == nullptr) {
        for (auto &x : vals) {
            cout << x << " ";
        }
        cout << val << endl;
        return;
    }
    vals.push_back(val);
    if (left) {
        left->printPathsInternal(vals);
    }
    if (right) {
        right->printPathsInternal(vals);
    }
    vals.pop_back();
}

int main() {
    Tree<int> a(0);
    cout << boolalpha << a.add(0) << endl;
    cout << boolalpha << a.add(1) << endl;
    srand(time(nullptr));
    int i = 0;
    while (i++ < 100) {
        a.add(rand());
    }
    cout << "Size :" << a.size() << endl;
    cout << "Depth :" << a.maxDepth() << endl;
    a.printPaths();
    return 0;
}
