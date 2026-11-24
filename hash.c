#include "DS.h"

/*
  Оюутны мэдээлэл оруулах функц: `p_hash`-ын зааж байгаа хайш хүснэгтэд
  `x`-д хадгалсан оюутны мэдээллийг оруулна.
 */

void ht_insert(HashTable *p_hash, const Student x)
{
        int h = ht_hash(x.id);
        Elm *p_elm = l_search(&p_hash->h[h], x.id);
        if (p_elm == NULL)
        {
                l_push_back(&p_hash->h[h], x);
                p_hash->len++;
        }
}


/*
  Хайш тооцоолох функц: `s` тэмдэгтэн цувааны хайшыг тооцоолоод,
  тооцоолсон хайшыг буцаах функц.
 */
int ht_hash(const char s[])
{
        /*
          Энд функцыг хэрэгжүүл
        */
  unsigned int hash = 0;
  for (int i = 0; s[i] != '\0'; i++)
       hash = (hash *31u + (unsigned char)s[i]) % HASH_TABLE_SIZE;
  return (int)hash;
}

/*
  Хайш хүснэгтийн утгуудыг эхлүүлэх функц:  Хайш хүснэгтийн бүх элементийн `head`, `tail` утгуудад
  `NULL` оноох ёстой.
 */
void ht_init(HashTable *p_hash)
{
    int i;
    p_hash->h = (List *)malloc(sizeof(List) * HASH_TABLE_SIZE);

    if (p_hash->h == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    p_hash->len = 0;

    for (i = 0; i < HASH_TABLE_SIZE; i++) {
        p_hash->h[i].head = NULL;
        p_hash->h[i].tail = NULL;
        p_hash->h[i].len = 0;
    }
}

/*
  Хайх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж,
  олдсон оюутны хаягийг буцаах функц. Олдохгүй бол `NULL` хаяг буцаана.
 */
Student *ht_search(HashTable *p_hash, const char id[])
{
        /*
          Энд функцыг хэрэгжүүл
        */
  int h = ht_hash(id);
  Elm *p_elm = l_search(&p_hash->h[h], id);
  if (p_elm == NULL)
    return NULL;
  return &p_elm->x;
}

/*
  Мэдээлэл өөрчлөх функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `x.id`-аар
  оюутныг хайж олоод, овог нэрийг `x.ner`, `x.ovog`-оор солино.
  Олдохгүй бол `x` оюутныг шинээр оруулна.
 */
void ht_update(HashTable *p_hash, const Student x)
{
        /*
          Энд функцыг хэрэгжүүл 
        */
  int h = ht_hash(x.id);
  Elm *p_elm = l_search(&p_hash->h[h], x.id);
  if(p_elm == NULL)
  {
    ht_insert(p_hash, x);
    return;
  }
  strcpy(p_elm->x.ovog, x.ovog);
  strcpy(p_elm->x.ner, x.ner);
}

/*
  Устгах функц: `p_hash`-ыг зааж буй хайш хүснэгтээс `id`-тай оюутныг хайж
  олж устгана. Олдохгүй бол юу ч хийхгүй.
 */
void ht_del(HashTable *p_hash, const char id[])
{
        /*
          Энд функцыг хэрэгжүүл 
        */
  int h = ht_hash(id);
  List *p_list = &p_hash->h[h];
  Elm *p_elm = p_list->head;
  int pos = 0;
  while (p_elm != NULL)
    {
      if(strcmp(p_elm->x.id, id) == 0)
      {
        l_erase(p_list, pos);
        p_hash->len--;
        return;
      }
      p_elm = p_elm->next;
      pos++;
    }
}

/*
  Хайш хүснэгтийг чөлөөлөх: Ойн цоорхой үүсгэлгүй, бүх элементийг устган, хаягийг чөлөөлнө.
 */
void ht_release(HashTable *p_hash)
{
        int i;
        for (i = 0; i < HASH_TABLE_SIZE; i++) {
                while (p_hash->h[i].head != NULL)
                        l_pop_front(&p_hash->h[i]);
        }
        free(p_hash->h);
        p_hash->h = NULL;
        p_hash->len = 0;
}

/*
  Оюутны мэдээллийг хэвлэх функц: `p`-ын зааж буй оюутны овог, нэр, ID-г хэвлэнэ.
 */
void student_print(FILE *fout, const Student *p)
{
        if (p == NULL)
                fprintf(fout, "xooson\n");
        else
                fprintf(fout, "%s %s %s\n", p->ovog, p->ner, p->id);
}