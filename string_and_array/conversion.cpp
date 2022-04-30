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
    if(abs((long long)arg1_len - (long long)arg2_len) > 1) return false;
    if(abs((long long)arg1_len - (long long)arg2_len) == 1){
        if((long long)arg1_len > (long long)arg2_len){
            return (arg1.substr(0, arg1_len-1)==arg2 || arg1.substr(1, arg1_len)==arg2);
        }else if((long long)arg1_len < (long long)arg2_len){
            return (arg2.substr(0, arg2_len-1)==arg1 || arg2.substr(1, arg2_len)==arg1);
        }
    }
    else if(abs((long long)arg1_len - (long long)arg2.length()) == 0){
        if(arg2==arg1)return true;
        else{
            for(long long i = 0; i < arg1_len; i++){
               if(arg2.substr(0,i)==arg1.substr(0,i) && arg2.substr(i+1,-1)==arg1.substr(i+1,-1)){
                //    cout << arg1.substr(0,i) << " : " << arg1.substr(i+1, -1) << endl;
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
    string h = "abcdefg";
    cout << h.substr(0,-1) << endl;
    cout << isConvertable("hoge", "hog") << endl;
    cout << isConvertable("hoge", "hogo") << endl;
    cout << isConvertable("hogehogehuga", "hogohogehuga") << endl;
    cout << isConvertable("hogehogehuga123123", "hogohogehuga123123") << endl;
    cout << isConvertable("hogehogehuga", "hogehogehuga1") << endl;
    cout << isConvertable("hogehogehuga", "hogehogehuga12") << endl; // 0
    cout << isConvertable("hogehogehuga", "hogehogeHUga") << endl; // 0
    return 0;
}