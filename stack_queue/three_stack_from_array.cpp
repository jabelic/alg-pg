#include <iostream>
#include <array>
#include <stack>
#include <stdlib.h>
// #include <vector>
// using namespace std;
using std::cout; using std::endl;
using std::stack; using std::array;
//  3つのスタック:1つ の配列を使って3つ のスタックを実装するにはどのようにすればよいのか述べてください。
/** 
 * 問題の意図がわからない
 * 配列１つだけを使って, stack構造を擬似的に表現するの？
 * -> どうやら配列の要素を3つのスタックに振り分けるだけみたい
 */

void ary_turn_to_stacks(int *ary, int ARY_SIZE,stack<int> *st1,stack<int> *st2,stack<int> *st3){
    for(int i=0; i < ARY_SIZE; i++){
        switch(i%3){
            case 1:
                cout << "case 1: " << ary[i] << endl;
                (*st1).push(ary[i]);
                break;
            case 2:
                cout << "case 2: " << ary[i] << endl;
                (*st2).push(ary[i]);
                break;
            case 0:
                cout << "case 0: " << ary[i] << endl;
                (*st3).push(ary[i]);
                break;
        }
    }
}



int *init_array(int *ary, int ARY_SIZE){
    for(int i=0; i < ARY_SIZE; i++) ary[i] = i/2;
    return ary;
}


int main(){
    size_t ARY_SIZE = 10;
    int *ary = (int *)calloc(ARY_SIZE,sizeof(int));
    ary = init_array(ary, ARY_SIZE);
    stack<int> st1;
    stack<int> st2;
    stack<int> st3;
    ary_turn_to_stacks(ary,ARY_SIZE,&st1,&st2,&st3);
    cout << st1.top() << endl;
    cout << st2.top() << endl;
    cout << st3.top() << endl;
    return 0;
}