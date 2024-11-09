C++98にはインターフェースは存在しません（C++20にもありません）。しかし、純粋仮想クラスは一般的にインターフェースと呼ばれます。そこで、この最後の課題では、インターフェースを実装することで、このモジュールを理解したことを確認しましょう。

以下の`AMateria`クラスの定義を完成させ、必要なメンバー関数を実装してください。

```c++
class AMateria
{
protected:
           [...]
    public:
        AMateria(std::string const & type);
        [...]
        std::string const & getType() const; //マテリアの種類を返す
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
```

具象クラス`Ice`と`Cure`を実装してください。種類を設定するために、小文字の名前（`Ice`には"ice"、`Cure`には"cure"）を使用してください。もちろん、`clone()`メンバー関数は同じ種類の新しいインスタンスを返します（つまり、`Ice`マテリアをクローンすると、新しい`Ice`マテリアが取得されます）。

`use(ICharacter&)`メンバー関数は以下を表示します：
* Ice: "* shoots an ice bolt at <name> *"
* Cure: "* heals <name>’s wounds *"

`<name>`はパラメータとして渡されたキャラクターの名前です。山括弧（`<`と`>`）は出力しないでください。

あるマテリアを別のマテリアに代入する際に、種類をコピーすることは意味がありません。

以下のインターフェースを実装する具象クラス`Character`を作成してください。

```c++
class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
```

`Character`は4つのスロット、つまり最大4つのマテリアを持つインベントリを所有します。インベントリは構築時に空です。マテリアは最初に見つかった空のスロットに装備されます。つまり、スロット0からスロット3の順です。いっぱいのインベントリにマテリアを追加しようとした場合、または存在しないマテリアを使用/装備解除しようとした場合は、何もしないでください（ただし、バグは禁止です）。`unequip()`メンバー関数はマテリアを削除してはいけません！

キャラクターが床に置いたマテリアは、好きなように処理してください。
`unequip()`などを呼び出す前にアドレスを保存してください。ただし、メモリリークを避ける必要があることを忘れないでください。

`use(int, ICharacter&)`メンバー関数は、`slot[idx]`にあるマテリアを使用し、`target`パラメータを`AMateria::use`関数に渡す必要があります。

キャラクターのインベントリは、あらゆる種類の`AMateria`をサポートできます。

`Character`は、名前をパラメータとして受け取るコンストラクタを持つ必要があります。`Character`のコピー（コピーコンストラクタまたはコピー代入演算子を使用）はディープコピーである必要があります。コピー中は、新しいマテリアがインベントリに追加される前に、`Character`のマテリアを削除する必要があります。もちろん、`Character`が破棄されるときにもマテリアは削除される必要があります。

以下のインターフェースを実装する具象クラス`MateriaSource`を作成してください。

```c++
class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};
```

* `learnMateria(AMateria*)`
パラメータとして渡されたマテリアをコピーし、後でクローンできるようにメモリに保存します。`Character`と同様に、`MateriaSource`は最大4つのマテリアを認識できます。必ずしも一意である必要はありません。

* `createMateria(std::string const &)`
新しいマテリアを返します。これは、`MateriaSource`が以前に学習したマテリアのうち、パラメータとして渡された種類と一致するマテリアのコピーです。種類が不明な場合は0を返します。

要するに、`MateriaSource`はマテリアの「テンプレート」を学習し、必要に応じてそれらを作成できる必要があります。そして、種類を識別する文字列だけを使用して、新しいマテリアを生成できるようになります。

以下のコードを実行すると:

```c++
int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
```

以下の出力が得られるはずです。

```
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
* shoots an ice bolt at bob *$
* heals bob's wounds *$
```

短くして、出力を消すとこんな感じ

```c++
int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
	me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
	delete bob;
    delete me;
    delete src;
}
```

いつものように、上記よりも多くのテストを実装して提出してください。
