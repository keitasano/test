#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX 


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* リストの初期化

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q) 
{
	q->size = 0;
	q->Sentinel = _createLink(0);
	q->Sentinel->prev = q->Sentinel;
	q->Sentinel->next = q->Sentinel;
}

/*
 リストの作成
 
 */
struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* 値からリンクを作成する

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	struct DLink *lnk = (struct DLink *)malloc(sizeof(struct DLink));
	lnk->value = val;

	return lnk;
}

/* 新しい要素のリンクを指定のリンクの後に追加する

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque 
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 要素を最後に追加する

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val) 
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 先頭に要素を追加する

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 先頭の値を取得する

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q) 
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 最後の値を取得する

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 指定の要素をリストから取り除く

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
    /* FIXME: ここに処理を実装して下さい */

}

/* 先頭の要素をリストから取り除く

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {

    /* FIXME: ここに処理を実装して下さい */

}

/* 最後の要素をリストから取り除く

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
    /* FIXME: ここに処理を実装して下さい */

}

/* リストの全ての要素を解放する

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	struct DLink *lnk = q->Sentinel->next;
	 while (lnk != q->Sentinel) {

		 struct DLink *temp = lnk;
		 lnk = lnk->next;

		 free(temp);
	}
	 free(q->Sentinel);
}

/* 	リストのすべての要素とリスト自体を解放する

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteCirListDeque(struct cirListDeque *q) {
	assert(q != 0);
	freeCirListDeque(q);
	free(q);
}

/* リストが空か確認する

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {

    /* FIXME: ここに処理を実装して下さい */

}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	struct DLink *lnk = q->Sentinel->next;
	while (lnk != q->Sentinel) {

		printf("value : %f\n", lnk->value);
		lnk = lnk->next;
	}
}

/* リストのすべての要素の並びを逆にする

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
    /* FIXME: ここに処理を実装して下さい */

}
