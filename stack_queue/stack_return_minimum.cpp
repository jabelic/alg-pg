/**
 * @file stack_return_minimum.cpp
 * @author jabelic
 * @brief 最小値を返すスタック: pushと popに加えて、最小値の要素を返す関数minを持つスタックをどのようにデザインしますか?
 *        ただしpush、pop、min関数はすべて0(1)の実行時間になるようにしてください。
 * @date 2022-05-11
 */

#include <iostream>
#include <stack>
#include <stdlib.h>
#include <array>
#include <list>
#include <algorithm>
using namespace std;

// template <typename T>
class Stack{
private: 
int min_num;
public:
    // list<T> stack;
    list<int> stack;
    Stack():min_num(100){
    };
    // void push(T arg){
    void push(int arg){
        if(this->min_num > arg) this->min_num = arg;
        stack.push_back(arg);
    };
    void pop(){
        stack.pop_back();
    };
    int get_min_num(){
        return this->min_num;
    };
    void print(){
        std::for_each(stack.cbegin(), stack.cend(), [](int x){
            cout << x << " ";
        });
        cout << endl;
    };
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.print();
    s.pop();
    s.print();
    cout << s.get_min_num()<< endl;
    return 0;
}