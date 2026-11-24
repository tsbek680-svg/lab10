 #include "DS.h"

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	Elm *elm = (Elm *)malloc(sizeof(Elm));
	if (elm == NULL)
		return ;
	elm->x = x;
	elm->next = NULL;
	if (p->tail == NULL)
		p->head = elm;
	else
		p->tail->next = elm;
	p->tail = elm;
	p->len++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ
   Бүх элементүүд нэг нэг байрлал хойшилно.
 */
void l_push_front(List *p, Student x)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	Elm *elm = (Elm *)malloc(sizeof(Elm));
	if (elm == NULL)
		return;
    elm->x = x;
    elm->next = p->head;
    p->head = elm;

    if (p->tail == NULL)
        p->tail = elm;

    p->len++;

}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
  pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
  Тухайн байрлал List-ийн сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, Student x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	if (pos <= 0 )
	{
		l_push_front(p, x);
		return ;
	}
	if (pos >= p->len)
	{
		l_push_back(p, x);
		return;
	}
	Elm *elm = (Elm *)malloc(sizeof(Elm));
	if (elm == NULL)
		return;
	elm->x = x;
	Elm *current = p->head;
	for (int i = 0; i < pos - 1; i++)
		current = current->next;
	elm->next = current->next;
	current->next = elm;
	p->len++;
}
		




/*
  p-ийн зааж буй List-н эхлэлээс гаргана.
  List-ийн бүх элементүүд нэг нэг байрлал урагшилна
 */
void l_pop_front(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (p->head == NULL)
		return;
	Elm *elm = p->head;
	p->head = elm->next;
	if (p->head == NULL)
		p->tail = NULL;
	free(elm);
	p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (p->head == NULL)
		return;
	if (p->head == p->tail)
	{
		free(p->head);
		p->head = NULL;
		p->tail = NULL;
		p->len = 0;
		return;
	}
	Elm *current = p->head;
	while (current->next != p->tail)
		current = current->next;
	free(p->tail);
	p->tail = current;
	p->tail->next = NULL;
	p->len--;
}

/* p-ийн зааж буй List-н pos байрлалаас гаргана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
   pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */
	if (pos < 0 || pos >= p->len)
		return;
	if (pos == 0)
	{
		l_pop_front(p);
		return;
	}
	Elm *previous = p->head;

    for (int i = 0; i < pos - 1; i++)
        previous = previous->next;

    Elm *elm = previous->next;
    previous->next = elm->next;

    if (elm == p->tail)
        p->tail = previous;

    free(elm);
    p->len--;
	
}

/*
  p-ийн зааж буй List-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void l_print(List *p)
{
        /* Энд хэвлэх үйлдлийг хийнэ үү */
	Elm *current = p->head;
	while (current != NULL)
		{
			printf("%s %s %s\n", current->x.ovog, current->x.ner, current->x.id);
			current = current->next;
		}
}

/*
  p-ийн зааж буй List-с id-тай оюутныг хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, const char id[])
{
        /*
          Энд хайх үйлдлийг хийнэ үү.
         */
	Elm *current = p->head;
	while (current != NULL)
		{
			if (strcmp(current->x.id, id) == 0)
				return current;
			current = current->next;
		}
	return NULL;
}
