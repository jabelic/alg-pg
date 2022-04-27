#include <iostream>
#include <vector>
#include <stdlib.h>
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

string my_space_replace(string arg, int string_length){
    // string_lengthはspaceを除いた文字列の長さ
    int len = arg.length();
    /** 空白の数 */
    int space_count = len - string_length;
    int index = string_length+space_count*3;
    string ret = "";
    if(string_length < arg.length()) arg += '\0';
    for(int i = 0; i  < index; i++){
        if(isspace(arg[i])){
            ret += "%20";
        }else{
            ret += arg[i];
        }
    }
    ret += '\0';
    return ret;
}


string space_replace(string arg, int string_length){
    // string_lengthはspaceを除いた文字列の長さ
    int len = arg.length();
    /** 空白の数 */
    int space_count = len - string_length;
    /** retのindex */
    int index = string_length+space_count*3;
    char *ret;
    ret = (char *)calloc(index, sizeof(char));
    if(string_length < arg.length()) arg += '\0';
    for(int i = len-1; i >= 0; i--){
        if(isspace(arg[i])){
            ret[index-1] = *"0";
            ret[index-2] = *"2";
            ret[index-3] = *"%";
            index -= 3;
        }else{
            ret[index-1] = arg[i];
            index--;
        }
    }
    return ret;
}


int main(){
    cout << my_space_replace("hoge huga piyo", 12) << endl;
    cout << space_replace("hoge huga piyo", 12) << endl;
    return 0;
}
