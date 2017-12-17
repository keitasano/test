/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include "dynamicArray.h"

/*struct DynArr
{
	TYPE *data;		// データの配列
	int size;		// 配列内の要素数
	int capacity;	// 配列のサイズ
};
*/


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* 初期化 (データ配列のメモリ割り当て含む) dynamic array.

	param: 	v		動的配列のポインタ
	param:	cap 	動的配列のサイズ
	pre:	v はnullではない(前提条件）
	post:	配列内のデータはcapの数のデータを持てる
	post:	v->dataはnullではない
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

/* 動的配列のメモリ割り当てと初期化

	param:	cap 	動的配列に設定したいサイズ
	pre:	none
	post:	none
	ret:	キャパシティcapで要素数0のnullじゃない動的配列のポインタ
*/
DynArr* createDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* 動的配列内のデータの領域の解放

	param: 	v		動的配列のポインタ
	pre:	none
	post:	d.dataをnullにする
	post:	サイズも許容量も0
	post:	v->dataに使われたメモリ領域が解放されている
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* 動的配列のデータと動的配列自身の領域の解放

	param: 	v		動的配列のポインタ
	pre:	none
	post:	v->dataが使っていたメモリ領域の解放される
	post:	dの使っていたメモリ領域が解放される
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* 元の配列をcapnのサイズに変更する

	param: 	v		動的配列のポインタ
	param:	cap		更新される配列のサイズ
	pre:	vはnullじゃない
	post:	vは新たにcapのサイズを持っている
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);
	//新たな領域の確保
	TYPE *p = (TYPE *) malloc(sizeof(TYPE) * newCap);
	for(int i = 0; i < v->size; i++)
	{
		p[i] = v->data[i];
	}
	free(v->data);
	v->data = p;

	v->capacity = newCap;
	//printf("call_test size:%d, cap:%d\n", v->size, v->capacity);
}

/* 動的配列のサイズを取得する

	param: 	v		動的配列のポインタ
	pre:	vはnullじゃない
	post:	none
	ret:	動的配列のサイズ
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	要素を動的配列の最後に追加する

	param: 	v		動的配列のポインタ
	param:	val		動的配列の最後に追加する値
	pre:	動的配列はnullではない
	post:	sizeを1増やす
	post:	もし、capacityに要素数が達したら、サイズを2倍にする
	post:	valが動的配列の最後の要素
*/
void addDynArr(DynArr *v, TYPE val)
{
	/* FIXME: ここに処理を実装して下さい */
  assert(v != 0);
	if(v->size >= v->capacity)
	{
		_dynArrSetCapacity(v, 2 * v->capacity);
	}
	//printf("dataaddress:%d,add:%p\n", v->data[100] ,v->data + sizeof(TYPE) * v->size);
	//printf("memory:%ld\n", sizeof(v->data));
	//printf("memory:%d\n", sizeof(v->data));
	*(v->data + v->size) = val;
	v->size++;
	/*
	for(int i = 0; i < sizeDynArr(v); i++)
	{
		printf("addtest:%d", *(v->data + i));
	}
	printf("\n");
	*/
}

/*	指定した位置の要素を取得する

	param: 	v		動的配列のポインタ
	param:	pos		取得したい要素の整数のindex(0から始まる要素の位置)
	pre:	vはnullじゃない
	pre:	vのデータは空じゃない
	pre:	pos < 配列のsize　且つ >= 0
	post:	動的配列は変更されない
	ret:	index posに保持されている値
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);
	assert(v->size != 0);
  assert(pos < v->size && pos >= 0);

	/* FIXME: 返却値を変更して下さい */
	return v->data[pos];
}

/*	要素を動的配列の指定の位置に格納します。要素がある場合上書きされます。

	param: 	v		動的配列のポインタ
	param:	pos		要素を入れるindex
	param:	val		格納される値
	pre:	vはnullじゃない
	pre:	vは空じゃない
	pre:	pos >= 0 且つ pos < 配列のsize
	post:	index posに新しい要素valが保持されている
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);
	assert(v->size != 0);
	assert(pos >= 0 && pos < v->size);

	v->data[pos] = val;
}

/*	配列の2つの指定された要素を入れ替えます

	param: 	v		動的配列のポインタ
	param:	i,j		入れ替えられる用ののindex
	pre:	vはnullじゃない
	pre:	vは空じゃない
	pre:	i, j >= 0 かつ i,j < 動的配列のサイズ
	post:	index iがjにあった要素を保持していてindex jがiにあった要素を持っている
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);
	assert(v->size != 0);
	assert(i >= 0 && j >= 0 && i < v->size && j < v->size);

	//tmpを介して値を入れ替える
	TYPE tmp;
	tmp = v->data[i];
	v->data[i] = v->data[j];
	v->data[j] = tmp;
}

/*	指定した位置にある要素を取り除き、その空いた隙間を埋めるために後の要素を前に詰める
	param: 	v		動的配列のポインタ
	param:	idx		削除する要素のindex
	pre:	vはnullじゃない
	pre:	vは空じゃない
	pre:	idx < size かつ idx >= 0
	post:	idxにあった要素が取り除かれている
	post:	idxの後にあった要素が1つ前にずらされている
*/
void removeAtDynArr(DynArr *v, int idx)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);
	assert(v->size != 0);
	assert(idx < v->size && idx >= 0);

  for(int i = idx; i < v->size - 1; i++)
	{
		v->data[i] = v->data[i + 1];
	}

	v->size--;
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	動的配列に要素があるかboolean型を返却する

	param:	v		動的配列のポインタ
	pre:	動的配列はnullじゃない
	post:	なし
	ret:	1:空の場合, 0:それ以外
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);

	if(v->size == 0)
	{
		return 1;
	}

	/* FIXME:  返却値を変更して下さい */
	return 0;
}

/* 	スタックの先頭に要素を追加する

	param:	v		動的配列のポインタ
	param:	val		スタックに追加する要素
	pre:	vはnullじゃない
	post:	sizeが1増やされている
			許容量に達したら、2倍の領域に変更されている
			valがスタックの先頭に入れられている
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: ここに処理を実装して下さい */
	assert(v != 0);

	addDynArr(v, val);
}

/*	スタックの先頭の要素を取得する

	param:	v		動的配列のポインタ
	pre:	vはnullじゃない
	pre:	vは空じゃない
	post:	スタックに変更がない
*/
TYPE topDynArr(DynArr *v)
{
	/* FIXME: ここに処理を実装して下さい */
  assert(v != 0);
	assert(v->size != 0);

	/* FIXME: 返却値を変更して下さい */
	return getDynArr(v, v->size - 1);
}

/* Removes the element on top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
	assert(v != 0);
	assert(v->size != 0);

	removeAtDynArr(v, v->size - 1);
}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	assert(v != 0);
	assert(v->size != 0);

	for(int i = 0; i < v->size; i++)
	{
		if(v->data[i] == val)
		{
			return 1;
		}
	}
	/* FIXME:  You will change this return value */
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */
	assert(v != 0);
	assert(v->size != 0);

	for(int i = 0; i < v->size; i++)
	{
		if(v->data[i] == val)
		{
			removeAtDynArr(v, i);
			return;
		}
	}
}
