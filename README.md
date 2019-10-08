swtest-riscv
------
RISC-V版xv6の`swtch`の動作を理解するためのサンプルコード

## 必要なもの

* [RISC-V用GNUツールチェイン](https://github.com/riscv/riscv-gnu-toolchain)
* [RISC-Vシミュレータ(Spike)](https://github.com/riscv/riscv-isa-sim) （[Proxy Kernel](https://github.com/riscv/riscv-pk)も必要）

macOSの場合，以上はHomebrewを使って簡単にインストールできる．

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
$ make run-swtest
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

```sh
$ make run-schtest
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

