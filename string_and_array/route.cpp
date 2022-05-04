#include <iostream>
#include <vector>
#include <array>
#define ARY_SIZE 1000
/**
 * 
 * 行列の回転:NxNの行列に描かれた、1つのピクセルが4バイト四方の画像があります。
 * その画像を90度回転させるメソッドを書いてください。あなたはこれを追加の領域なしでできますか?
 * 
 * 未完了！！！
 */


using namespace std;

void print_arrays(int ary[][ARY_SIZE], int actual_size){
    if(sizeof(ary[0])/sizeof(int) < actual_size) return;
    int loops = actual_size;
    for(int index = 0; index < loops; index++){
        for(int column = 0; column < loops; column++){
            cout << ary[index][column];
        }
        cout << endl;
    }
}

void switch_element(int images[][ARY_SIZE],int actual_size){
    int loops = actual_size;
    print_arrays(images, actual_size);
    int half_loops = loops/2;
    for(int index = 0; index < loops; index++){
        for(int column = 0; column < half_loops; column++){
            // int tmp = images[index][column];
            // images[index][column] = images[index][loops - column - 1];
            // images[index][loops - column - 1] = tmp;
        }
    }
}

void init_array(int images[][ARY_SIZE], int actual_size){
    int loops = sizeof(images[0])/sizeof(int);
    for(int index = 0; index < loops; index++){
        for(int column = 0; column < loops; column++){
            if(index < actual_size && column < actual_size)images[index][column] = index+1;
            else images[index][column] = 0;
        }
    }
}

int main(){
    int images[ARY_SIZE][ARY_SIZE];
    int actual_size = 4;
    init_array(images,actual_size);
    switch_element(images,actual_size);
    return 0;
}
