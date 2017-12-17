#include "dynamicArray.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* 	VISUAL STUDIO (VS) USERS: COMMENT OUT THE LINE BELOW
	TO EXCLUDE THE MEMORY TEST CODE.
*/
#define MEMORY_TEST_INCLUDED

#ifdef MEMORY_TEST_INCLUDED
/* This header is needed for memory usage calculation. */
#include <sys/resource.h>

/* Function to get current memory usage in KB (Max Resident Set Size) */
long getMemoryUsage() {
	int who = RUSAGE_SELF;
	struct rusage usage;
	int ret;
	ret = getrusage(who, &usage);
	return usage.ru_maxrss;
}
#endif

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
   return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]){
	struct DynArr* b;
	int n, i;
	double t1, t2;

	if( argc != 2 ) return 0;
　n = atoi(argv[1]);/*number of elements to add*/

	//データ追加(最後に)///////////////////////////////////////
	b = createDynArr(1000);

	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	long m1, m2;
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	t1 = getMilliseconds();/*Time before contains()*/

	for( i = 0 ; i < n; i++) {
		addDynArr(b, (TYPE)i);/*Add elements*/
	}

	t2 = getMilliseconds();/*Time after contains()*/
	printf("Time for running putDynArr() on %d elements: %g ms\n", n, t2-t1);

	#ifdef MEMORY_TEST_INCLUDED
	/* memory used AFTER creating LinkedList */
	m2 = getMemoryUsage();
	printf("Memory used by LinkedList: %ld KB \n", m2-m1);
	#endif


	//ランダムな値のデータ検索///////////////////////////////////////

	//ランダムな整数値
	int randomInt = rand() % n;

	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	t1 = getMilliseconds();/*Time before contains()*/

	//ランダムな値の検索
	for( i = 0 ; i < n; i++)
	{
		containsDynArr(b, randomInt);
	}

	t2 = getMilliseconds();/*Time after contains()*/
	printf("Time for running containsDynArr() on %d elements: %g ms\n", n, t2-t1);

	#ifdef MEMORY_TEST_INCLUDED
	/* memory used AFTER creating LinkedList */
	m2 = getMemoryUsage();
	printf("Memory used by LinkedList: %ld KB \n", m2-m1);
	#endif


	//データ削除(最後の)///////////////////////////////////////

	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	t1 = getMilliseconds();/*Time before contains()*/

	for( i = 0 ; i < n; i++) {
		removeAtDynArr(b, b->size - 1);/*Add elements*/
	}

	t2 = getMilliseconds();/*Time after contains()*/
	printf("Time for running removeAtDynArr() on %d elements: %g ms\n", n, t2-t1);

	#ifdef MEMORY_TEST_INCLUDED
	/* memory used AFTER creating LinkedList */
	m2 = getMemoryUsage();
	printf("Memory used by LinkedList: %ld KB \n", m2-m1);
	#endif


	//データ追加(最初に)///////////////////////////////////////
	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	t1 = getMilliseconds();/*Time before contains()*/

	for( i = 0 ; i < n; i++) {
		if(b->size >= b->capacity)
		{
			_dynArrSetCapacity(b, 2 * b->capacity);
		}
		//printf("dataaddress:%d,add:%p\n", v->data[100] ,v->data + sizeof(TYPE) * v->size);
		//printf("memory:%ld\n", sizeof(v->data));
		//printf("memory:%d\n", sizeof(v->data));
		*b->data = i;
		b->size++;
	}

	t2 = getMilliseconds();/*Time after contains()*/
	printf("Time for running addFrontList() on %d elements: %g ms\n", n, t2-t1);

	#ifdef MEMORY_TEST_INCLUDED
	/* memory used AFTER creating LinkedList */
	m2 = getMemoryUsage();
	printf("Memory used by LinkedList: %ld KB \n", m2-m1);
	#endif


	//データ削除(最初の)///////////////////////////////////////
	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	t1 = getMilliseconds();/*Time before contains()*/

	for( i = 0 ; i < n; i++) {
		removeAtDynArr(b, 0);/*Add elements*/
	}

	t2 = getMilliseconds();/*Time after contains()*/
	printf("Time for running removeFrontList() on %d elements: %g ms\n", n, t2-t1);

	#ifdef MEMORY_TEST_INCLUDED
	/* memory used AFTER creating LinkedList */
	m2 = getMemoryUsage();
	printf("Memory used by LinkedList: %ld KB \n", m2-m1);
	#endif

	deleteDynArr(b);

	return 0;
}
