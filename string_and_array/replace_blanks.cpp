#include <iostream>
#include <vector>
#include <ctype.h>

/**
 * @brief RLify:文字列内に出現するすべての空白文字を“%20"で置き換えるメソッドを書いてください。
 * ただし、文字列の後 ろには新たに文字を追加するためのスペースが十分にある
 * (パッファのサイズは気にしなくてもよい)ことと、
 * その追加用スペースを除いた文字列の真の長さが与えられます
* (注意:Javaで実装する場合は、追加の領域を使用せずに処理できるよう文字配列を使ってください)。
 * 
 */
using namespace std;

// TODO: intert位置は二分法で見つけたい
// TODO: 見つけた時にすぐに挿入したい

string space_replace(string arg){
    int len = arg.length();
    vector<int> indexes(len);
    int space_index =  0;
    for(int i = 0; i < arg.length(); i++){
        if (isspace(arg[i])){
            indexes[space_index++] = i;
        };
    }
    string return_str;
    int insert = 0;
    for(int i = 0; i < len; i++){
        if(indexes[insert] == i){
            return_str += "%20";
            insert++;
        }else{
            return_str += arg[i];
        }
    }
    return return_str;
}
int main(){
    cout << space_replace("hoge huga piyo") << endl;
    return 0;
}
