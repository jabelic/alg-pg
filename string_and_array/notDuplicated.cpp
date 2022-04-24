/**
 * @file notDuplicated.cpp
 * @author jabelic
 * @brief 
 * @version 0.1
 * @date 2022-04-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <set>
#include <string.h>
#include <vector>
/**
 * 重複のない文字列:ある文字列が、すべて固有である(重複する文字がない)かどうかを判定するアルゴリズムを実装 してください。
 * また、それを実装するのに新たなデータ構造が使えない場合、どのようにすればよいですか? ヒント:#44′ #117′ #132
 */

// ASCII? Unicode?
// -> ASCIIに限定する
// 新たなデータ構造って何？
using namespace std;

bool isDuplicateChar(string s){
    int string_length = s.length();
    char *container;
    string stack;
    for(int i=0; i < string_length; i++){
        if(i==0 || !(stack.find(s[i]) != string::npos)){
            stack += s[i];
        }else{
            return true;
        }
    }
    return false;
}

bool isDuplicated (string s){
    const int ASCII_SIZE = 128;
    vector<bool> each_ascii_char_exists(ASCII_SIZE);

    /** init Array */
    for(int i = 0; i < ASCII_SIZE; i++) {
        each_ascii_char_exists[i] = false;
    }

    /** stringをvector<char>に変換 */
    vector<char> vec_str(s.begin(), s.end());

    for(int index = 0; index < s.length(); index++) {
        /** int(char)でASCII値がsetされる */
        if(each_ascii_char_exists[int(vec_str[index])]) return true;
        else each_ascii_char_exists[int(vec_str[index])] = true;
    }
    return false;
}

int main () {
    string s;
    cin >> s;
    // ASCIIなら128文字しかない
    if(s.length() > 128){
        fprintf(stderr, "dublicated!!");
        return 0;
    }
    // cout << "output: " << s << endl;
    // cout <<  (isDuplicateChar(s) ? "duplicate" : "not duplicate") << endl;
    cout <<  (isDuplicated(s) ? "duplicate" : "not duplicate") << endl;

  return 0;
}

