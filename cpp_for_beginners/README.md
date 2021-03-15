# 参考資料集
- bits/stdc++.hについて
  - [AF - 4.01.includeディレクティブ](https://atcoder.jp/contests/apg4b/tasks/APG4b_af)
  - [bits/stdc++.hに関するQ & A ](https://atcoder.jp/contests/APG4b)
- コンパイルエラーについて
  - [AP3 - 付録3.コンパイルエラー集](https://atcoder.jp/contests/apg4b/tasks/APG4b_am)
- [AtCoder Beginners Selection](https://atcoder.jp/contests/abs)
- [AtCoder Problems 過去問](https://kenkoooo.com/atcoder/#/table/)
- [AtCoder Scores 過去問](http://atcoder-scores.herokuapp.com/)
- [AtCoder に登録したら次にやること ～ これだけ解けば十分闘える！過去問精選 10 問 ～](https://qiita.com/drken/items/fd4e5e3630d0f5859067#%E7%AC%AC-8-%E5%95%8F--abc-085-c---otoshidama-300-%E7%82%B9)

# 配列

### いろいろな配列の書き方
- `vector<int> data(3);` // vectorによる配列（推奨）
- `int data[3];` // Cの配列（非推奨）
- `array<int, 3> data;` // arrayによる配列

### 安全に[] でアクセスする方法
- []はエラーが発見しにくいが、先頭に `#define _GLIBCXX_DEBUG` と記述すると .at()でアクセスするのと同程度に安全に扱える



