#include <iostream>
#include <algorithm>
#include <vector>
/**
 * @file check_order.cpp
 * @author jabelic
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 順列チェック:2つの文字列が与えられたとき、片方がもう片方の並び替えになっているかどうかを決定するメソッドを書いてください。
 */

using namespace std;

/** 
 * 大文字小文字は区別する？
 * 空白はどうする？
 *  */
bool is_sorted(string str_1,string str_2){
    sort(str_1.begin(), str_1.end());
    sort(str_2.begin(), str_2.end());
    return (str_2 == str_1);
}

int main(){
    string str_1;
    cin >> str_1;
    string str_2;
    cin >> str_2;
    cout << (is_sorted(str_1, str_2) ? "made by same chars." : "diff chars.") << endl;
    return 0;
}