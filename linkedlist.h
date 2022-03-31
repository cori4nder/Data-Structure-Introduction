#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct no No;

No * ll_create_no(int info);
int ll_is_empty(No* lhead);
int ll_size(No* lhead);
int ll_insert_first(No **lhead, int info);
int ll_insert_last(No **lhead, int info);
int ll_exists(No* lhead, int info);
void ll_print(No* lhead, char* message);
void ll_clear(No** lhead);
int ll_remove(No** lhead, int info);
int ll_insert_sorted(No ** lhead, int info);

#endif // LISTAEN_H