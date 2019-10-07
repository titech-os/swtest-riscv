swtest-riscv
------
RISC-V版xv6の `swtch` の動作を理解するためのサンプルコード

## 必要なもの

* RISC-V用ツールチェイン
* RISC-Vシミュレータ(Spike)

macOSの場合，HomeBrewを使って以下のようにインストールできる．

```sh
$ brew tap riscv/riscv
$ brew install riscv-tools
```

## ビルド方法

```sh
$ make
```

## 実行方法

```sh
$ make run
foo: 0
bar: 0
baz: 0
foo: 1
bar: 2
baz: 3
foo: 2
bar: 4
baz: 6
foo: 3
bar: 6
baz: 9
...
```

