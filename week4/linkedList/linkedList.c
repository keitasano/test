#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*
	リストの初期化
	param lst the linkedList
	pre: lstはnullじゃない
	post: lstのサイズは0
*/
void _initList (struct linkedList *lst) {

	// allocate sentinels
	struct DLink *first = malloc(sizeof(struct DLink));
	struct DLink *last = malloc(sizeof(struct DLink));
	assert(first != 0);
	assert(last != 0);
	// set first
	first->prev = 0;
	first->next = last;
	// set last
	last->prev = first;
	last->next = 0;

	lst->firstLink = first;
	lst->lastLink = last;

	lst->size = 0;
}

/*
 リストの作成
 param: なし
 pre: なし
 post: firstLinkとlastLinkが番兵を指している
 */
struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
 指定のリンクlの前に要素を追加する
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lstはnullじゃない
	pre: lはnullじゃない
	post: lstは空じゃない
*/
void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(l != 0);

		//追加要素
		struct DLink *addLink = malloc(sizeof(struct DLink));
		addLink->value = v;
		addLink->next = l;
		addLink->prev = l->prev;

		//前後の要素それぞれに追加要素へのリンクを持たせる
		l->prev->next = addLink;
		l->prev = addLink;

		//printf("test%p,%p,%p\n", lst->lastLink->prev, addLink, lst->firstLink->next);
}

/*
  要素の削除
	_removeLink
	param: lst the linkedList
	param: l 削除する要素
	pre: lstはnullじゃない
	pre: lはnullじゃない
	post: lstのサイズが1減る
*/
void _removeLink(struct linkedList *lst, struct DLink *l)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(l != 0);

		//削除した要素へのリンクを入れ替える
		l->prev->next = l->next;
		l->next->prev = l->prev;

		free(l);

		lst->size--;
}

/*
  リストに要素がないか
	isEmptyList
	param: lst the linkedList
	pre: lstはnullじゃない
	post: none
	ret: isEmpty=1 not 0
*/
int isEmptyList(struct linkedList *lst)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);

		if(lst->size == 0)
		{
				return 1;
		}
		return 0;
}

/* リストの全てのリンクを解放する

	param: 	lst		pointer to the linked list
	pre:	none
	post:	All links (including the two sentinels) are de-allocated
*/
void freeLinkedList(struct linkedList *lst)
{
	while(!isEmptyList(lst)) {
		/* remove the link right after the first sentinel */
		_removeLink(lst, lst->firstLink->next);
	}
	/* remove the first and last sentinels */
	free(lst->firstLink);
	free(lst->lastLink);
}

/* 	リストの全てのリンクとリスト自体を解放する

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	the memory used by v->data is freed
*/
void deleteLinkedList(struct linkedList *lst)
{
	assert (lst != 0);
	freeLinkedList(lst);
	free(lst);
}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{

	struct DLink *lnk = lst->firstLink->next;
	while (lnk != lst->lastLink) {

		printf("value: %d\n", lnk->value);

		lnk = lnk->next;
	}
}

/* ************************************************************************
	Deque Interface Functions
************************************************************************ */

/*
  リストの先頭に要素を追加する
	addFrontList
	param: lst the linkedList
	param: e 追加する要素
	pre: lstはnullじゃない
	post: lstは空でなく、サイズが1増加する
*/
void addFrontList(struct linkedList *lst, TYPE e)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);

		struct DLink *addLink = malloc(sizeof(struct DLink));
		addLink->value = e;
		addLink->next = lst->firstLink->next;
		addLink->prev = lst->firstLink;

		lst->firstLink->next->prev = addLink;
		lst->firstLink->next = addLink;

		lst->size++;
}

/*
  リストの最後に値(要素)を追加する
	addBackList
	param: lst the linkedList
	param: e 追加する要素
	pre: lstはnullじゃない
	post: lstは空でなく、サイズが1増加する
*/
void addBackList(struct linkedList *lst, TYPE e)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);

		struct DLink *addLink = malloc(sizeof(struct DLink));
		addLink->value = e;
		addLink->next = lst->lastLink;
		addLink->prev = lst->lastLink->prev;

		lst->lastLink->prev->next = addLink;
		lst->lastLink->prev = addLink;

		lst->size++;
}

/*
  先頭の要素の値を取得する
	frontList
	param: lst the linkedList
	pre: lstはnullじゃない
	pre: lstは空じゃない
	post: none
*/
TYPE frontList (struct linkedList *lst) {

    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		return lst->firstLink->next->value;
}

/*
  最後の要素の値を取得する
	backList
	param: lst the linkedList
	pre: lstはnullじゃない
	pre: lstは空じゃない
	post: lstは空じゃない
*/
TYPE backList(struct linkedList *lst)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		return lst->lastLink->prev->value;
}

/*
  先頭の要素を削除する
	removeFrontList
	param: lst the linkedList
	pre:lstはnullじゃない
	pre: lstは空じゃない
	post: サイズが1減る
*/
void removeFrontList(struct linkedList *lst) {

    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		_removeLink(lst, lst->firstLink->next);
}

/*
  最後の要素を削除する
	removeBackList
	param: lst the linkedList
	pre: lstはnullじゃない
	pre:lstは空じゃない
	post: サイズが1減る
*/
void removeBackList(struct linkedList *lst)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		_removeLink(lst, lst->lastLink->prev);
}

/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*
	要素を先頭に追加する
	param: 	lst		the linkedList
	param: 	v		追加する値
	pre:	lstはnullじゃない
	post:	値が追加されサイズが1増加する
 */
void addList(struct linkedList *lst, TYPE v)
{
    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);

		addBackList(lst, v);
}

/*	指定の値がリストに存在するか確認する
	true = 1
	false = 0

	param:	lst		the linkedList
	param:	e		探す値
	pre:	lstはnullじゃない
	pre:	lstは空じゃない
	post:	リストには変化がない
*/
int containsList (struct linkedList *lst, TYPE e) {

    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		struct DLink *lnk = lst->firstLink->next;
		while (lnk != lst->lastLink)
		{
			if(lnk->value == e)
			{
				return 1;
			}
			lnk = lnk->next;
		}
		return 0;
}

/*	最初に見つかった指定の要素を削除する

	param:	lst		the linkedList
	param:	e		削除する値
	pre:	lstはnullじゃない
	pre:	lstは空じゃない
	post:	eが取り除かれる
	post:	サイズが1減る
*/
void removeList (struct linkedList *lst, TYPE e) {

    /* FIXME: ここに処理を実装して下さい */
		assert(lst != 0);
		assert(isEmptyList(lst) == 0);

		struct DLink *lnk = lst->firstLink->next;
		while (lnk != lst->lastLink)
		{
			if(lnk->value == e)
			{
				_removeLink(lst, lnk);
				return;
			}
			lnk = lnk->next;
		}
}
