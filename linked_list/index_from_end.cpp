#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

/**
 * @brief 後ろからK番目を返す:単方向連結リストにおいて、末尾から数えてk番目の要素を見つけるアルゴリズムを実装してください。
 * 
 */

forward_list<int> init_forward_list()
{
    forward_list<int> list{3, 2, 2, 3, 4, 1, 6, 54, 6, 7, 2, 2, 2};
    return list;
}
vector<int> record(forward_list<int> list){
    vector<int> vec;
    for(forward_list<int>::iterator itr = list.begin(); itr != list.end(); itr++){
        vec.push_back(*itr);
    }
    return vec;
}

int main(){
    forward_list<int> flist = init_forward_list();
    vector<int> tmp = record(flist);
    int k = 4; // 後ろからk番目
    size_t vec_size =  tmp.size();
    for(int i = 0; i < tmp.size(); i++){
        cout << tmp[i] << ", ";
    }
    cout << endl;
    printf("%d the element from back of forward_list is : %d", k, tmp[vec_size - k]);
    return 0;
}