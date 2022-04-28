#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <map>

/** 
 * 回文の順列:文字列が与えられたとき、その文字列が回文の順列であるかを調べる関数を書いてください。
 * 回文とは 前から読んでも後ろから読んでも同じになる単語やフレーズのことです。
 * 順列とは文字を並び替えたものです。回文に含まれる単語は辞書に書かれているものに限りません
例
入力:Tact Coa
出力:True(順列:"taco cat‖ ′"atco cta",等 )
ヒント:#106′ #121′ #134′ #136
*/
using namespace std;
bool isArgPalindrome(string arg){
    int len = arg.length();
    if(arg.length() == 0) return false;
    map<int, int> seqLen;
    for(int i = 0; i < len; i++) seqLen[int(arg[i])]++;
    int odd_els_count = 0;
    for( auto i = seqLen.begin(); i != seqLen.end() ; ++i ) {
      if(i->second %2 != 0 && odd_els_count == 1) return false;
      else if(i->second %2 != 0)odd_els_count++;
    }
    return true;
}



/** ちょっとよくわからない。1.4の解法3 */

int toggle(int bitVector, int index){
  if(index < 0)return bitVector;
  // 'bitVector' bit分, 左シフト
  int mask = 1 << index;
  // cout << mask << endl;
  if((bitVector && mask) == 0){
    // bit or演算子
    bitVector |= mask;
  }else{
    // bit and演算子
    // bit not演算子
    bitVector &= ~mask;
  }
  return bitVector;
}
/** 
 * 整数値から1減算したものと元の数とのANDを取り、
 * 1ビットだけが1になっているかどうかをチェックする
*/
bool checkExactlyOneBitSet(int bitVector){
  return (bitVector && (bitVector - 1))==0;
}
int createBitVector(string phrase){
  int bitVector = 0;
  for(int c = 0; c < phrase.length(); c++){
    int x = int(phrase[c]);
    bitVector = toggle(bitVector, x);
  }
  return bitVector;
}

bool isPermutation0fPalindrome(string phrase){
  int bitVector = createBitVector(phrase);
  return bitVector == 0 || checkExactlyOneBitSet(bitVector);
}
int main(){
    // ASCII文字に限定する
    cout << isArgPalindrome(
      "AAABBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
      ) << endl;
    // cout <<
    // isPermutation0fPalindrome(
    //   "AAABBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    // )
    //  << endl;
    return 0;
}
