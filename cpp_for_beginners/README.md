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


### 多次元配列
#### 配列の復習
- 宣言 `vector<要素の型> 変数名(要素数, 初期値)`;
- 初期値は省略可 `vector<要素の型> 変数名(要素数)`
#### キーポイント
- 2次元配列は2次元の表を扱うときに便利
- `vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値))` で宣言できる
- 初期値は省略可能
- `変数名.at(i).at(j)` でi行目j列目へアクセスできる
- `変数名.size()` で縦の大きさを取得できる
- `変数名.at(0).size()` で横の大きさを取得できる
- 要素を指定して初期化する例

```cpp
vector<vector<int>> data = {
  {7, 4, 0, 8},
  {2, 0, 3, 5},
  {6, 1, 7, 0},
};
```

- 2次元以上の配列を多次元配列という
- vectorをN個入れ子にしたものをN次元配列という

#### 宣言
- 宣言方法

```cpp
vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値));
vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2));  // 初期値を省略
```

- 例：縦に3行、横に4行の整数の2次元配列の宣言
```cpp
vector<vector<int>> data(3, vector<int>(4))>
```

- Nx0の二次元配列 (「要素数0の配列」の配列)
`vector<vector<型>> 変数名(N)`  // 外側のvectorの初期値を省略して、N個の配列の要素数はそれぞれ0になる

- 3次元配列の宣言
```cpp

// データ構造
  [
   [
     ['-', '○', '-'],
     ['-', '○', '-'],
     ['-', '○', '-']
   ],
   [
     ['-', '○', '-'],
     ['-', '○', '-'],
     ['-', '○', '-']
    ]
  ]

// 宣言
vector<vector<vector<char>>> data(2, vector<vector<char>>(3, vector<char>(3)));
```

```cpp
vector<
  vector<
    vector<char>             // 1次元の型
  >
> data(2,                    // ３次元の要素数
    vector<vector<char>>(3,  // 2次元の要素数
       vector<char>(3)));    // 1次元の要素数

```

# 参照
### キーポイント
- ｀参照先の型 &参照の名前 = 参照先;` で参照を宣言できる
- 参照を宣言するときは、参照先を指定する必要がある
- 関数の引数に参照を用いる場合は、その関数を呼び出すときに渡した変数が参照先になる
- 参照先を後から変更することはできない
- 引数が参照になっている関数を呼び出すことを参照渡しという
- 参照私は、無駄なコピーを避けたり複数の結果を返したいときに便利

```cpp
int a = 0;
int &b = a;
```

# 再帰関数

```cpp
// n を受け取って、0〜n の総和を計算して返す関数
int sum (int n) {
  // ベースケース
  if (n == 0) {
    return 0;
  }

  // 再帰ステップ
  int s = sum(n - 1);
  return s + n;
}
```

## 実装例
- a から　bまでの総和

```cpp

int sum_range(int a, int b) {
  if (a == b) {
    return a;
  }

  return sum_range(a,b - 1) + b;
}

int main() {
  cout << sum_range(0, 4) << endl;
  cout << sum_range(5, 8) << endl;
}

```

- 配列の要素の総和

```cpp
int array_sum_from_i (vector<int> &data, int i) {
  if (i == data.size()) {
    return 0;
  }
  return array_sum_from_i(data, i + 1) + data.at(i);
}

int array_sum(vector<int> &data) {
  return array_sum_from_i(data, 0);
}
```

- Nが素数であるかの判定

```cpp
// i 〜 N-1 の範囲にNの約数があるか判定する
bool has_divisor(int N, int i) {
  // ベースケース１
  if (i == N) {
    // 対象となる整数が無いのでFalse
    return false;
  }

  // ベースケース２
  if (N % 2 == 0) {
    return true;
  }

  // 再帰ステップ
  return has_divisor(N, i + 1);
}


bool is_prime(int N) {
  if (N == 1) {
    return false
  }
  else if (N == 2) {
    return true
  }
  else {
    // 2〜(N-1)の範囲に約数がなければ、Nは素数
    return !has_divisor(N, 2)
  }
}


```