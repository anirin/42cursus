#!/bin/bash

# 生成する数を指定（例: 10）
n=341 # 341 は大丈夫

# "8 " を n 回生成
eights=$(seq 1 $n | xargs -I{} echo -n "8 ")
eights=${eights% }

# "* " を n-1 回生成
stars=$(seq 1 $(($n - 1)) | xargs -I{} echo -n "* ")
stars=${stars% }

minus="1 2 -"
bonus="1 +"

# 実行コマンドを表示
echo "\"$eights $stars\""
