# C++入門 AtCoder Programming Guide for beginners (APG4b) 
- [URL](https://atcoder.jp/contests/APG4b)
# 参考資料集
## 1章-2章
- bits/stdc++.hについて
  - [AF - 4.01.includeディレクティブ](https://atcoder.jp/contests/apg4b/tasks/APG4b_af)
  - [bits/stdc++.hに関するQ & A ](https://atcoder.jp/contests/APG4b)
- コンパイルエラーについて
  - [AP3 - 付録3.コンパイルエラー集](https://atcoder.jp/contests/apg4b/tasks/APG4b_am)
- [AtCoder Beginners Selection](https://atcoder.jp/contests/abs)
- [AtCoder Problems 過去問](https://kenkoooo.com/atcoder/#/table/)
- [AtCoder Scores 過去問](http://atcoder-scores.herokuapp.com/)

## ３章が終わったらやること
### 競技プログラミング
- [過去のコンテスト](https://atcoder.jp/contests/archive?ratedType=&category=&keyword=AtCoder+Beginner+Contests)
- [AtCoder版！蟻本](https://qiita.com/drken/items/e77685614f3c6bf86f44)
- [実践・最強最速のアルゴリズム勉強会](https://www.slideshare.net/chokudai/wap-atcoder1)
- [便利リンク集](https://atcoder.jp/posts/261)

### C++をより深く学ぶ
- [江添亮のC++入門](https://ezoeryou.github.io/cpp-intro/)
- [C++11/14コア言語](http://ezoeryou.github.io/cpp-book/C++11-Syntax-and-Feature.xhtml)
- [江添亮の詳説C++17](https://ezoeryou.github.io/cpp17book/)

### ゲーム開発
- [Siv3D](https://siv3d.github.io/ja-jp/)

## 4章メモ
- [Wandbox](https://wandbox.org/)
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

# 計算量
## キーポイント
- プログラムの実行時間 -> 時間計算量
- プログラムのメモリ使用量 -> 空間計算量
- オーダー記法で表す


# 数値型
## キーポイント
- オーバーフローを意識する
- intで扱えない値は int64_t型を使う
- doubleの小数点以下の値の指定は `cout << fixed << setprecision(桁数);` で行う
- 情報落ちに気を付ける
- 桁落ちに気を付ける
- 精度指定やたくさんの値を出力する場合は cout よりも `printf` を使う
  - `printf(フォーマット文字列, 変数1, 変数2...)`
- `scanf(フォーマット文字列, &変数1, &変数2...)` でフォーマットを指定した入力が可能
  - stringは利用できない（cinを使う)
- 数値型から文字列に変換する場合は`to_string`を用いる
- 文字列からint型に変換する場合は`stoi`を用いる


# pair/tupleとauto
## キーポイント
### pair
- pair型は2つの値の組を表す
- `pair<値1の型, 値2の型> 変数名;`で宣言する
- `変数名.first`で1番目の値、`変数名.second`で2番目の値にアクセスできる
- `make_pair(値1, 値2)`でpairを生成することができる
- `tie(変数1, 変数2) = pair型の値;`でpairを分解することができる
### tuple
- tuple型は複数個の値の組を表す
- `tuple<値1の型, 値2の型, 値3の型, (...)> 変数名;`(必要な分だけ型を書く)で宣言する
- `make_tuple(値1, 値2, 値3, (...))`でtupleを生成することができる
- `tie(変数1, 変数2, 変数3, (...)) = tuple型の値;`でtupleを分解することができる
### pair/tupleの比較
- 1番目の値から比較され、等しい場合は次の値で比較される
### auto
- 変数宣言や範囲for文において、autoを用いることで、型を省略して書くことができる
- autoで参照を作ることもできる

### 型エイリアス
- `using 新しい名前 = 型名` で型名を別名で定義できる
- 例： `using pii = pair<int, int>;`

# STLのコンテナ
## map
- 連想配列/辞書
- 宣言:`map<keyの型, valueの型> 変数名;`
- 追加:`変数[key] = value;` O(logN)
- 削除:`変数.erase(key);` O(logN)
- アクセス: `変数.at(key)` O(logN)
- 所属判定: `変数.count(key)` O(logN)
- 要素数の所得 `変数.size()` O(1)


## queue
- キュー・待ち行列：値を1つずつ追加し、追加した順で値を取り出す(FIFO)
- 宣言: `queue<型> 変数名;`
- 追加: `変数.push(値);` O(1)
- 先頭へのアクセス: `変数.front();` O(1)
- 先頭の削除: `変数.pop();` OZ(1)
- 要素数の取得:`変数.size();` O(1)

## priority_queue
- 優先度つきキュー
- 追加した要素のうち最も大きいものを取り出す という操作がやりやすい
- 宣言: `priority_queue<型> 変数名;`
- 追加: `変数.pop(値)` O(logN)
- 最大の要素の取得: `変数.top();` O(1)
- 最大の要素の削除: `変数.pop();` O(logN)
- 要素数の取得: `変数.size();` O(1)
- 値が小さい順に取り出されるpriority_queueの宣言: `priority_queue<型, vector<型>, greater<型>> 変数名;`

## ループ
- keyの値が小さい順にループを書く例
``cpp
for (pair<keyの型, valueの型> p: 変数名) {
  keyの型 key = p.first;
  valueの型 value = p.second;
  // key, valueを使う
}
```

- autoを使って簡潔に書く例
```cpp

for (auto p: 変数名) {
  auto key = p.first;
  auto value = p.second;
  // key, valueを使う
}

// 具体的にはこんな感じ
for (auto p: score) {
  auto k = p.first;
  auto v = p.second;
  cout << k << "=" << v << endl;
}
```

## set
- 重複の無いデータのまとまりを扱うデータ型
- keyだけのmapのようなイメージ。mapで代用することも可
- set型が有用な例
  - 配列の中に出現する値の種類数（重複が無い集合の要素数）
  - 集合の中にある値が含まれるかを高速に計算する
  - 集合の中に含まれる最小値（最大値）を求める
- 宣言: `set<型> 変数名;`
- 追加: `変数名.inset(値);`
- 削除: `変数名.erase(値);`
- 存在判定: `変数名.count(値);`
- 要素数: `変数名.size();`
- 空かどうかを判定: `変数名.empty();`
- 最小値の取得: `*begin(変数名);`
- 最大値の取得: `*rbegin(変数名);`

## stack
- 新しく追加したものを先に取り出すデータ構造(LIFO)
- 宣言: `stack<型> 変数名;`
- 追加: `変数名.push(値);`
- 削除: `変数名.pop();`
- 要素数: `変数名.size();`
- 空判定: `変数名.empty();`

## deque(デック)
- FIFOのキューの操作と、LIFOのスタックの操作を同時に行えるデータ構造（両端キュー）
- 宣言: `deque<型> 変数名;`
- 末尾へ追加: `変数名.push_back(値);`
- 先頭へ追加: `変数名.push_front(値);`
- 末尾へアクセス: `変数名.front();`
- 先頭へアクセス: `変数名.back();`
- i番目へアクセス: `変数名.at(i);`
- 先頭の削除: `変数名.pop_front();`
- 末尾の削除: `変数名.pop_back();`
- 要素数: `変数名.size();`
- 空判定: `変数名.empty();`

## unorderd_map
- 基本的にはmapと同じだが、アクセスや検索を高速に行える.ただし、制約がある
- 制約
  - pairやtupleなどのハッシュ関数が定義されていない型をkeyとして利用できない
  - ループで取り出すときの順番が保証されてない（どのような順番で取り出されるかわからない）
- 計算量の平均は`O(1)`となるy

## unorderd_set
- 制約がある代わりに高速な`set`
- 制約
  - pairやtupleなどのハッシュ関数が定義されていない型をkeyとして利用できない
  - ループで取り出すときの順番が保証されてない（どのような順番で取り出されるかわからない）
  - 最大値や最小値を取り出すことができない

## lower_bound/upper_bound(STLの関数)
- `lower_bound`: 昇順にソートされた配列において、「x以上の最小の要素を求める」
- `upper_bound`: 昇順にソートされた配列において、「xを超える最小の要素を求める」
- 使い方
  - `*lower_bound(配列.begin(), 配列.end(), 値)`
  - `*upper_bound(配列.begin(), 配列.end(), 値)`

## からのコンテナに対する操作

- 空のqueueに対して `.front()` などを呼び出した場合の動作は未定義で、実行時エラーになるとは限らない
- プログラムの1行目に、`#define _GLIBCXX_DEBUG` またはClang環境では`#define _LIBCPP_DEBUG 0` を書くと上記の操作をエラーにすることができる

## 構造体
- 構造体によって複数の型をまとめた新しい型を作ることができる
- 構造体型の値のことをオブジェクトという
- 変数の宣言: `構造体名 変数名;`
- autoを使った構造体の値の生成: `auto 変数名 = 構造体名();`
- 宣言と同時に初期化:

```cpp
struct 構造体名 {
  型1 メンバ変数名1
  型2 メンバ変数名2
  型3 メンバ変数名3
};
```

- メンバへのアクセス: `オブジェクト.メンバ変数`
- メンバ関数の定義：

```cpp
struct 構造体名 {
  返り値の型 メmば関数名(引数の型1 引数1, ...) {
    //関数の内容
    // ここではメンバ変数に直接アクセスできる
  }
}
```
- コンストラクタを定義して初期化時の内容を定義することもできる

```cpp
struct NumString {
  int length;
  string s;
  // コンストラクタ定義 (コンストラクタは複数定義可能)
  // 与える引数の型や個数によって自動的に呼び分けられる
  NumString() {
    count << "初期化無し" << endl; 
  }

 // コンストラクタ2
   NumString(int num) {
    cout << "constructor called" << endl;

    // 引数のnumを文字列かしたものをsに代入し、sの文字数をlengthに代入する
    s = to_string(num);
    length = s.size();
  }

  
}
```

## コピーコンストラクタ
- 構造体の宣言時に構造体のオブジェクトを引数に渡すなど特定の条件を満たすとコピーコンストラクタが呼ばれる
- 条件
  - 関数の引数にオブジェクトを渡した場合
  - 構造体の宣言時に `MyStruct new_obj = old_obj;` とした場合
  - 構造体の宣言時に `MyStruct new_obj(old_obj);` とした場合
- 例

```cpp
struct MyStruct {
  int x;
  string y;

  // コンストラクタ
  MyStruct(){
    count << "コンストラクタが呼ばれた" << endl;
  }

  // コピーコンストラクタ
  MyStruct(const MyStruct &old) {
    cout << "コピーコンストラクタが呼ばれた" << endl;
    x = old.x + 1;
    y = old.y + "new";
  }
};

int main() {
  MyStruct p; // コンストラクタが呼ばれる
  p.x = 12345;
  p.y = "hello";

  MyStruct q(p); // コピーコンストラクタが呼ばれる

  MyStruct r = q; // コピーコンストラクタが呼ばれる
}
```

## 演算子オーバーロード
- 構造体型のオブジェクトに対して、C++の演算子を使えることができ、この機能を演算子オーバーロードという
- 書き方

```cpp
struct 構造体名 {
  返り値の型 operator演算子 (引数の型 引数) {
    // 処理内容
  }

};

```

- 例
```cpp
struct MyPair {
  int x;
  string y;

  // 演算子オーバーロード
  MyPair operator+(const MyPair &other) {
    MyPair ret;
    ret.x = x + other.x;
    ret.y = y + other.y;
    return ret
  }
};

int main() {
  MyPair a = {123, "hello"};
  MyPair b = {456, "world"};

  // MyPair型の+が呼ばれる
  MyPair c = a + b;

  cout << c.x << endl; // 579
  cout << c.y << endl; // helloworld
}
```

