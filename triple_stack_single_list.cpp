/// Implement 3 stacks using a single list

/// Status: Incomplete.
#include <ios>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <list>

using namespace std;

class MyStack {
  protected:
    list<int> &l;
    size_t size;
  public:
    virtual void push_back(int e);
    virtual int pop_last();  
    MyStack(list<int>& l_) : l(l_){} 
};

class Stack1;
class Stack2;
class Stack3;

class SharedList {
    list<int> l;
    MyStack* stacks[3];
public:
    friend class Stack1;
    friend class Stack2;
    friend class Stack3;
};

class Stack1 : public MyStack {
    using MyStack::MyStack;
public:
    void push_back(int e) override {
        l.push_front(e);
        size++;
    }
    int pop_last() override {
        if (!size) {return 0;}
        auto e = l.front();
        l.pop_front();
        size--;
        return e;
    }
};

class Stack2 : public MyStack {
    using MyStack::MyStack;
public:
    void push_back(int e) override {
        l.push_back(e);
        size++;
    }
    int pop_last() override {
        if (!size) {return 0;}
        auto e = l.back();
        l.pop_back();
        size--;
        return e;
    }
};


int main(int argc, const char * argv[]) {
    SharedList sol;
    // cout << std::numeric_limits<int>::max() << endl;

}