#include <iostream>
#include <string>

using namespace std;

/** 
 *
 * 文字列圧縮:文字の連続する数を使って基本的な文字列圧縮を行うメソッドを実装してください。
 * たとえば、「aabcccccaaa」は「a2blc5a3」のようにしてください。
 * もし、圧縮変換された文字列が元の文字列よりも短くならなかった場合は、元の文字列を返してください。
 * 文字列はアルファベットの大文字と小文字のみを想定してください。ヒント:#92′#110
*/

string compress(string test_case){
    long len = test_case.length();
    int count = 0;
    string val = "";
    char last_char;
    for(long i = 0; i < len; i++){
        // 先頭
        if(i==0){
            val += test_case[i];
            last_char =  test_case[i];
        // 前の文字が今の文字と違うとき
        }else if(test_case[i] != last_char){
            if(count == 0){
                val += test_case[i];
                last_char =  test_case[i];
            }else{
                val+=to_string(count+1);
                count = 0;
                val += test_case[i];
                last_char =  test_case[i];
            }
        // 文字が続いているとき
        }else if(test_case[i] == last_char){
            count++;
            last_char =  test_case[i];
            if(i == len-1)val+=to_string(count+1);
        }
    }
    return val;
}

int main(){
    // 辿って、やる
    // 前と同じ文字だったらカウントをup
    // 違ったらカウントを挿入してカウントを0にする
    string test_case = "aabcddddddaaaa";
    cout << (compress(test_case)=="a2bcd6a4") << endl;
    test_case = "aabcddddddaaaaac";
    cout << (compress(test_case)=="a2bcd6a5c") << endl;
    test_case = "aaaa";
    cout << (compress(test_case)=="a4") << endl;
    test_case = "a";
    cout << (compress(test_case)=="a") << endl;
    return 0;
}