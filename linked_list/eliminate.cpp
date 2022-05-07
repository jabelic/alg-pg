#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

/**
 * @brief 間の要素を削除:単方向連結リストにおいて、間の要素(必ずしもちょうど中央というわけではなく、最初と最後の要素以外)で、
 * その要素 のみアクセス可能であるとします。その要素を削除するアルゴリズムを実装してください。
 例 入力:a―>b―>c―>d―>e―>fという連結リストのcが与えられます。 結果:何も返しませんが、リストはa‐>b―>d―>e―>fのように見えます。
* 
 */

forward_list<int> init_forward_list()
{
    forward_list<int> list{3, 2, 22, 3, 4, 1, 6, 54, 6, 7, 2, 10, 2};
    return list;
}

forward_list<int> eliminate(forward_list<int> arg, int target){
    for (forward_list<int>::iterator itr = arg.begin(); next(itr) != arg.end(); itr++)
    {
        if(*next(itr) == target) arg.erase_after(itr);
    }
    return arg;
}
void print_forward_list(forward_list<int> arg)
{
    for (_Fwd_list_iterator<int> itr = arg.begin(); itr != arg.end(); itr++)
    {
        cout << *itr << ", ";
    }
    cout << endl;
}
/** 重複した要素がないとする */
/** 最初と最後は考えなくて良い */
int main(){
    int target = 22;
    forward_list<int> list = init_forward_list();
    print_forward_list(list);
    forward_list<int> eliminated_list = eliminate(list, target);
    print_forward_list(eliminated_list);
    return 0;
}