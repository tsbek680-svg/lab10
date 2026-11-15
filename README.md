 
# Хайш хүснэгт

![Points](.github/badges/points.svg)

## Даалгаврын зорилго

Оюутны мэдээллийг хадгалах **гинжин хайш хүснэгт (Hash Table with Separate Chaining)** хэрэгжүүлнэ.

Хайш хүснэгтийн давхцлыг динамик холбоост жагсаалт ашиглан шийдвэрлэнэ. Та 7-р даалгаварт хэрэгжүүлсэн динамик жагсаалтаа `Student` төрөлтэй ажилладаг болгон өөрчилж ашиглана.

Оюутны ID-г түлхүүр болгон ашиглаж, мэдээллийг хайх, өөрчлөх, устгах үйлдлүүдийг хэрэгжүүлнэ.

**Гүйцэтгэлийн зорилт:** Програм 1 сая оюутны мэдээллийг боловсруулахад үр ашигтай ажиллах ёстой. 1 секундийн гүйцэтгэлийн шаардлагыг тусад нь шалгаж болно. Одоогийн автомат тестүүд энэ хэмжээг баталгаажуулахгүй.

## Автомат үнэлгээ

GitHub repository-д кодоо `push` хийх бүрд GitHub Actions автоматаар шалгана.

| Тест | Оноо |
|---|---:|
| small | 5 |
| big | 5 |
| **Нийт** | **10** |

- Үнэлгээний үр дүнг **Actions → Hash Table Autograding** хэсгээс харна.
- README-ийн эхэнд байрлах **Points** тэмдэглэгээ автоматаар шинэчлэгдэнэ.
- Хөрвүүлэлт амжилтгүй бол 0 оноо авна.
- Тест бүрийн гаралтыг хүлээгдэж буй гаралттай яг таг харьцуулна.
- `small` тестийн хугацааны хязгаар 2 секунд, `big` тестийнх 3 секунд байна.

**Анхаар:** Эдгээр нь оюутанд харагдах тестүүд бөгөөд бие даан шалгах зориулалттай. Багш эцсийн үнэлгээг нэмэлт тестээр баталгаажуулж болно.

## Оролт ба гаралт

Програм эхлээд `student.info` файлаас оюутнуудын мэдээллийг уншиж, хайш хүснэгтэд хадгална.

Дараа нь `input.txt` файлаас командуудыг уншиж гүйцэтгэнэ.

`search` командын үр дүнг `output.txt` файлд бичнэ.

### Үйлдлүүд

| Команд | Тайлбар |
|---|---|
| `search id` | ID-аар оюутныг хайна. Олдохгүй бол `xooson` гэж хэвлэнэ. |
| `update ovog ner id` | ID-тай оюутны овог, нэрийг өөрчилнө. Олдохгүй бол шинээр нэмнэ. |
| `delete id` | ID-тай оюутныг устгана. Олдохгүй бол юу ч хийхгүй. |

## student.info файл

Эхний мөрөнд оюутны тоо `n` байна.

Дараагийн `n` мөр бүрд овог, нэр, ID гэсэн гурван утга байна.

Жишээ:

```text
3
Dellamonica Frances DRS0183434
Buttermore Katlyn CFA8969603
Benzee Evalyn DHM6868470
```

`DS.h` файлд тодорхойлсон массивын хэмжээнд тохируулан:

- Овог: хамгийн ихдээ 19 тэмдэгт
- Нэр: хамгийн ихдээ 19 тэмдэгт
- ID: хамгийн ихдээ 10 тэмдэгт

байхаар оролтын өгөгдлийг бэлтгэнэ.

## input.txt файл

Эхний мөрөнд үйлдлийн тоо `m` байна.

Дараагийн `m` мөр бүрд нэг команд байна.

Жишээ:

```text
8
search OVE8511071
search DHM6868470
delete XFN9850033
update Alkire Cecelia DHM6868470
search CFA8969603
search DHM6868470
delete DRS0183434
search DRS0183434
```

Энд нийт 8 үйлдэл гүйцэтгэнэ.

## output.txt файл

Зөвхөн `search` үйлдлийн үр дүнг `output.txt` файлд, командын дарааллаар нэг мөрөнд нэг үр дүн бичнэ.

Оюутан олдвол:

```text
ovog ner id
```

Олдохгүй бол:

```text
xooson
```

Дээрх жишээний гаралт:

```text
xooson
Benzee Evalyn DHM6868470
Buttermore Katlyn CFA8969603
Alkire Cecelia DHM6868470
xooson
```

## Өгөгдлийн бүтэц

### Student бүтэц

Оюутны овог, нэр, ID-г дараах бүтцэд хадгална.

```c
struct Student {
    char ovog[20];
    char ner[20];
    char id[11];
};
typedef struct Student Student;
```

### Elm бүтэц

Гинжин хайш хүснэгтийн давхцлыг холбоост жагсаалтаар шийдвэрлэх учраас жагсаалтын элемент `Student` төрөлтэй байна.

```c
struct Elm {
    Student x;
    struct Elm *next;
};
typedef struct Elm Elm;
```

### List бүтэц

```c
struct List {
    Elm *head;
    Elm *tail;
    int len;
};
typedef struct List List;
```

### HashTable бүтэц

```c
#define HASH_TABLE_SIZE 1000000

struct HashTable {
    List *h;
    int len;
};
typedef struct HashTable HashTable;
```

`h` нь холбоост жагсаалтуудын массив юм.

Ижил хайш утгатай оюутнууд нэг жагсаалтад хадгалагдана.

## list.c файлд хэрэгжүүлэх функцүүд

7-р даалгаврын динамик жагсаалтыг `Student` төрөлтэй ажилладаг болгон өөрчилнө.

```c
void l_push_back(List *, Student);
void l_push_front(List *, Student);
void l_insert(List *, Student, int);
void l_pop_front(List *);
void l_pop_back(List *);
void l_erase(List *, int);
void l_print(List *);
Elm *l_search(List *, const char []);
```

Функцүүдийн үүрэг:

- `l_push_back` — жагсаалтын төгсгөлд нэмэх
- `l_push_front` — жагсаалтын эхэнд нэмэх
- `l_insert` — заасан байрлалд нэмэх
- `l_pop_front` — эхний элементийг устгах
- `l_pop_back` — сүүлийн элементийг устгах
- `l_erase` — заасан байрлалын элементийг устгах
- `l_print` — жагсаалтын элементүүдийг хэвлэх
- `l_search` — ID-аар хайж, олдсон `Elm`-ийн хаягийг буцаах; олдохгүй бол `NULL`

Жагсаалтын элемент нэмэх, устгах үед `head`, `tail`, `len` утгуудыг зөв шинэчилнэ.

## Аль хэдийн хэрэгжүүлсэн функцүүд

Дараах функцүүдийн кодыг загварт өгсөн тул дахин хэрэгжүүлэх шаардлагагүй.

### ht_insert

Оюутны ID-аар хайш тооцоолж, тухайн жагсаалтад оюутны мэдээллийг оруулна. Ижил ID аль хэдийн байвал дахин оруулахгүй.

```c
void ht_insert(HashTable *p_hash, const Student x)
{
    int h = ht_hash(x.id);
    Elm *p_elm = l_search(&p_hash->h[h], x.id);

    if (p_elm == NULL)
        l_push_back(&p_hash->h[h], x);
}
```

### ht_init

Хайш хүснэгтийн жагсаалтуудыг эхлүүлнэ.

```c
void ht_init(HashTable *p_hash)
{
    int i;

    p_hash->h = (List *)malloc(
        sizeof(List) * HASH_TABLE_SIZE
    );

    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        p_hash->h[i].head = NULL;
        p_hash->h[i].tail = NULL;
        p_hash->h[i].len = 0;
    }
}
```

### ht_release

Хайш хүснэгтийн бүх жагсаалтын элементүүдийг устгаж, эзэлсэн санах ойг чөлөөлнө.

```c
void ht_release(HashTable *p_hash)
{
    int i;

    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        while (p_hash->h[i].head != NULL)
            l_pop_front(&p_hash->h[i]);
    }

    free(p_hash->h);
}
```

### student_print

Оюутны мэдээллийг гаралтын файлд хэвлэнэ.

```c
void student_print(FILE *fout, const Student *p)
{
    if (p == NULL)
        fprintf(fout, "xooson\n");
    else
        fprintf(fout, "%s %s %s\n",
                p->ovog, p->ner, p->id);
}
```

## hash.c файлд хэрэгжүүлэх функцүүд

### 1. ht_hash

Тэмдэгтэн цувааны хайш утгыг тооцоолж буцаана.

```c
int ht_hash(const char s[]);
```

Буцаах утга нь `0`-ээс `HASH_TABLE_SIZE - 1` хүртэлх индекс байна.

### 2. ht_search

ID-аар оюутныг хайж, олдсон оюутны хаягийг буцаана.

Олдохгүй бол `NULL` буцаана.

```c
Student *ht_search(HashTable *p_hash, const char id[]);
```

### 3. ht_update

`x.id`-аар оюутныг хайж, олдвол овог, нэрийг өөрчилнө.

Олдохгүй бол шинэ оюутан оруулна.

```c
void ht_update(HashTable *p_hash, const Student x);
```

### 4. ht_del

ID-аар оюутныг хайж устгана.

Олдохгүй бол юу ч хийхгүй.

```c
void ht_del(HashTable *p_hash, const char id[]);
```

## Програмыг ажиллуулах

Linux эсвэл GCC суулгасан орчинд:

```bash
make
./hash
```

Програм `student.info`, `input.txt` файлуудыг уншиж, `output.txt` файлыг үүсгэнэ.

Хөрвүүлсэн файлуудыг цэвэрлэх:

```bash
make clean
```

## Даалгавар гүйцэтгэх заавар

1. `DS.h` файлд өгөгдсөн бүтцүүд болон функцүүдийн зарлалыг судална.
2. `list.c` файл дахь дутуу функцүүдийг хэрэгжүүлнэ.
3. `hash.c` файл дахь дутуу функцүүдийг хэрэгжүүлнэ.
4. Програмаа хөрвүүлж, жишээ оролтоор шалгана.
5. Өөрчлөлтөө GitHub repository-д commit болон push хийнэ.
6. **Actions** хэсгээс автомат үнэлгээний үр дүнг шалгана.
7. Алдаагаа засаж, дахин push хийж болно.

`DS.h`, `main.c`, тестийн өгөгдөл болон `.github/workflows/classroom.yml` файлыг өөрчлөх шаардлагагүй.

**Зорилго: Бүх функцийг зөв хэрэгжүүлж, автомат үнэлгээнээс 10/10 оноо авах.**
