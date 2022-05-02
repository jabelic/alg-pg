#include <iostream>
#include <set>
#include <string.h>
#include <vector>

using namespace std;

// ASCIIを仮定する
// 文字数はどれくらいだろう？
// 挿入、削除、置き換えを１度だけやれば等価になる文字列2つ


bool oneLetterInsert(string arg1, string arg2){
    long long arg1_len = arg1.length();
    long long arg2_len = arg2.length();
    long long count = 0;
    if(abs((long long)arg1_len - (long long)arg2_len) > 1) return false;
    if(abs((long long)arg1_len - (long long)arg2_len) == 1){
        // CASE: 少ない方に挿入すれば解決
        if((long long)arg1_len > (long long)arg2_len){
            for(long long i = 0; i < arg1_len; i++){
                if(arg1.substr(0,i) + arg1.substr(i+1,-1) == arg2){
                    return true;
                }
            }
        }else if((long long)arg1_len < (long long)arg2_len){
            for(long long i = 0; i < arg2_len; i++){
                if(arg1 == arg2.substr(0,i) + arg2.substr(i+1,-1)){
                    return true;
                }
            }
        }
    }
    return false;
}
bool oneLetterReplace(string arg1, string arg2){
    long long arg1_len = arg1.length();
    long long arg2_len = arg2.length();
    long long count = 0;
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
}


bool isConvertable(string arg1, string arg2){
    long long arg1_len = arg1.length();
    long long arg2_len = arg2.length();
    bool flag = false;
    if(abs((long long)arg1_len - (long long)arg2_len) == 0){
        flag = oneLetterReplace(arg1, arg2);
    }else{
        flag = oneLetterInsert(arg1, arg2);
    }
    return flag;
}

int main(){
    string success_case[8][2] = {{"hoge", "hog"},
    {"hoge", "hogo"},
    {"hoge", "hoe"},
    {"hge", "hoge"},
    {"hogehogehuga", "hogohogehuga"},
    {"hogehogehuga123123", "hogohogehuga123123"},
    {"hogehogehuga", "hogehogehuga1"},
    {"ppap","ppp"}
    };
    for(int i = 0; i < 7 ; i++){
        cout << (isConvertable(success_case[i][0], success_case[i][1])) << endl;
    }
    string fail_case[3][2] = {{"","hge"},{"hogehogehuga", "hogehogehuga12"},{"hogehogehuga", "hogehogeHUga"}};
    for(int i = 0; i < 2 ; i++){
        cout << (isConvertable(fail_case[i][0], fail_case[i][1])==0) << endl;
    }
    return 0;
}