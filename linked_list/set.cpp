#include <iostream>
#include <list>
#include <forward_list>
/**
 * @brief 重複要素の削除:ソートされていない連結リストから、重複する要素を削除するコードを書いてください。
   発展問題 もし、一時的なパッファが使用できないとすれば、どうやってこの問題を解きますか?
 *
 */

using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

Node init_linked_list()
{
    Node *head = NULL;
    Node *current = new Node();
    for (int i = 1; i < 12; i++)
    {
        current->data = int(i / 2);
        Node *forward = new Node();
        current->next = forward;
        if (head == NULL)
        {
            head = current;
            current = forward;
        }
        else
        {
            current = forward;
        }
    }
    return *head;
}

// sortをして前の要素を見るか、追加の領域(Map)を使うか
void print_linked_list(Node arg)
{
    for (Node itr = arg; itr.next != NULL; itr = *itr.next)
    {
        cout << itr.data << endl;
    }
}
/**
 */
void eliminate_linked_list(Node list)
{
    bool isFirst = false;
    // for(Node itr = list; itr.next != NULL; itr = *itr.next){
    Node itr = list;
    while (itr.next != NULL)
    {
        if (itr.data == itr.next->data)
        {
            itr.next = itr.next->next;
            itr = *itr.next;
        }
        else
        {
            itr = *itr.next;
        }
    }
    // }
}

/** 上は使ってない... */

/** using forward_list */

forward_list<int> init_forward_list()
{
    forward_list<int> list{3, 2, 2, 3, 4, 1, 6, 54, 6, 7, 2, 2, 2};
    return list;
}
void print_forward_list(forward_list<int> arg)
{
    for (_Fwd_list_iterator<int> itr = arg.begin(); itr != arg.end(); itr++)
    {
        cout << *itr << ", ";
    }
    cout << endl;
}


forward_list<int> eliminate_forward_list(forward_list<int> arg)
{
    _Fwd_list_iterator<int> itr = arg.begin();
    while (next(itr)!=arg.end()){
        if(*itr == *next(itr)){
            arg.erase_after(itr);
        }else{
            itr++;
        }
    }
    return arg;
}


int main()
{
    forward_list<int> flist = init_forward_list();
    flist.sort(); // NlogN
    print_forward_list(flist);
    flist = eliminate_forward_list(flist); // flist.unique(); でも良い...
    print_forward_list(flist);

    return 0;
}