#include <iostream>
#include <list>
using namespace std;

/** 
 * リストの分割:ある数xが与えられたとき、連結リストの要素を並び替え、
 * xより小さいものが前にくるようにするコードを書いてください。
 * xがリストに含まれる場合、xの値はxより小さい要素の後にある必要があります(例 を参照してください)。
 * 区切り要素のxは右半分のどこに現れてもかまいません。左半分と右半分のちょうど間にある必要はないということです。
例
    入力:3->5‐>8->5->10->2->1 [区切り要素 =5]
    出力:3->1->2->10->5->5->8 ヒント:#3′ #24

    どういうこと？
    出力は一例(5より小さい数は右側には来てはいけないということなので。10と8はどちらにいても良い)
 */

list<int> init_list()
{
    list<int> list{3, 2, 2, 3, 4, 1, 3,5,6, 54, 6, 7, 2, 2, 2};
    return list;
}
list<int> swap_order(list<int> list, int split){
    for(auto itr = list.begin();itr!=list.end(); itr++){
        if(*itr < split){
            list.erase(itr);
            list.push_front(*itr);
        }
    }
    return list;
}
void print_list(list<int> arg)
{
    for (auto itr = arg.begin(); itr != arg.end(); itr++)
    {
        cout << *itr << ", ";
    }
    cout << endl;
}
int main(){
    std::list<int> list = init_list();
    std::list<int> swapped = swap_order(list, 5);
    print_list(swapped);
    return 0;
}