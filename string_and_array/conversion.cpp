#include <iostream>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

// ASCIIを仮定する
// 文字数はどれくらいだろう？
// 挿入、削除、置き換えを１度だけやれば等価になる文字列2つ
bool isConvertable(string arg1, string arg2){
    long long arg1_len = arg1.length();
    long long arg2_len = arg2.length();
    long long count = 0;
    // 文字列の長さが2以上違う場合はfalse
    if(abs((long long)arg1_len - (long long)arg2_len) > 1) return false;
    if(abs((long long)arg1_len - (long long)arg2_len) == 1){
        // CASE: 少ない方に挿入すれば解決
        if((long long)arg1_len > (long long)arg2_len){
            // return (arg1.substr(0, arg1_len-1)==arg2 || arg1.substr(1, arg1_len)==arg2);
            for(long long i = 0; i < arg1_len; i++){
                if(arg1.substr(0,i) + arg1.substr(i+1,-1) == arg2){
                    return true;
                }
            }
        }else if((long long)arg1_len < (long long)arg2_len){
            // return (arg2.substr(0, arg2_len-1)==arg1 || arg2.substr(1, arg2_len)==arg1);
            for(long long i = 0; i < arg2_len; i++){
                if(arg1 == arg2.substr(0,i) + arg2.substr(i+1,-1)){
                    return true;
                }
            }
        }
    }
    else if(abs((long long)arg1_len - (long long)arg2.length()) == 0){
        if(arg2==arg1)return true;
        else{
            // CASE: 1文字だけ違う場合
            for(long long i = 0; i < arg1_len; i++){
               if(arg2.substr(0,i)==arg1.substr(0,i) && arg2.substr(i+1,-1)==arg1.substr(i+1,-1)){
                   count++;
               };
            }
            return (count == 1);
        }
    }else{
        return false;
    }
    return false;
}

int main(){
    string success_case[7][2] = {{"hoge", "hog"},
    {"hoge", "hogo"},
    {"hoge", "hoe"},
    {"hge", "hoge"},
    {"hogehogehuga", "hogohogehuga"},
    {"hogehogehuga123123", "hogohogehuga123123"},
    {"hogehogehuga", "hogehogehuga1"},
    };
    for(int i = 0; i < 7 ; i++){
        cout << (isConvertable(success_case[i][0], success_case[i][1])) << endl;
    }
    string fail_case[2][2] = {{"hogehogehuga", "hogehogehuga12"},{"hogehogehuga", "hogehogeHUga"}};
    for(int i = 0; i < 2 ; i++){
        cout << (isConvertable(fail_case[i][0], fail_case[i][1])==0) << endl;
    }
    return 0;
}