assert(){
    cc main.c
    actual="$?"
    echo "実行結果: $actual"
}
assert