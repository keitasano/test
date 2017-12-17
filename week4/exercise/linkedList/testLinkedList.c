#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void assertTrue(int predicate, char *message)
{
	printf("%s: ", message);
	if (predicate)
		printf("PASSED\n");
	else
		printf("FAILED\n");
}

int main(){
	struct linkedList* b;

	b = createLinkedList();

	printf("\n\n******* Test linkedlist start *******\n");
	assertTrue(isEmptyList(b), "Testing... isEmptyList: empty");

	printf("\n****** Test Deque Interface start ******\n");
	printf("\nTesting... addBackList\n");
	addBackList(b, 10);
	_printList(b);
	assertTrue(!isEmptyList(b), "Testing... isEmptyList: [10]");
	printf("\nTesting... addBackList [10, 0]\n");
	addBackList(b, 0);
	_printList(b);
	assertTrue(EQ(backList(b), 0), "BackList [10, 0]");

	printf("\nTesting... addFrontList[10, 0]\n");
	addFrontList(b, 3);
	assertTrue(EQ(frontList(b), 3), "frontList[3, 10, 0]");
	printf("\nTesting... removeBackList[3, 10, 0]\n");
	removeBackList(b);
	assertTrue(EQ(backList(b), 10), "backList[3, 10]");
	removeBackList(b);
	assertTrue(EQ(frontList(b), 3), "frontList[3]");
	assertTrue(EQ(backList(b), 3), "backList[3]");
	removeBackList(b);
	printf("\nTesting... removeBackList[3]\n");
	assertTrue(isEmptyList(b), "Testing... isEmptyList: empty");
	// assert error
	//removeBackList(b);
	//removeFrontList(b);
	printf("Testing... addFrontList[]\n");
	addFrontList(b, 2);
	printf("Testing... addFrontList[2]\n");
	addFrontList(b, 5);
	assertTrue(EQ(frontList(b), 5), "Testing... frontList[5, 2]");
	assertTrue(EQ(backList(b), 2), "Testing... backList[5, 2]");
	printf("\nTesting... removeFrontList\n");
	removeFrontList(b);
	assertTrue(!isEmptyList(b), "isEmptyList: false");
	assertTrue(EQ(frontList(b), 2), "Testing... frontList[2]");
	assertTrue(EQ(backList(b), 2), "Testing... backList[2]");
	printf("Testing... removeFrontList\n");
	removeFrontList(b);
	assertTrue(isEmptyList(b), "isEmptyList: empty");
	// assertError
//	frontList(b);
//	backList(b);
	printf("****** Test Deque Interface end ******\n");
	printf("\n****** Test Stack Interface start ******\n");
	printf("Testing... addList(8)[]\n");
	addList(b, 8);
	assertTrue(!isEmptyList(b), "isEmptyList: false");
	assertTrue(EQ(frontList(b), 8), "Testing... frontList[8]");
	assertTrue(EQ(backList(b), 8), "Testing... backList[8]");
	printf("Testing... addList(9) [8]\n");
	addList(b, 9);
	assertTrue(EQ(frontList(b), 8), "Testing... frontList[8, 9]");
	assertTrue(EQ(backList(b), 9), "Testing... backList[8, 9]");
	assertTrue(!containsList(b, 0), "Testing... containsList(0) false[8,9]");
	assertTrue(!containsList(b, 1), "Testing... containsList(1) false[8,9]");
	assertTrue(!containsList(b, 2), "Testing... containsList(2) false[8,9]");
	assertTrue(!containsList(b, 3), "Testing... containsList(3) false[8,9]");
	assertTrue(!containsList(b, 4), "Testing... containsList(4) false[8,9]");
	assertTrue(!containsList(b, 5), "Testing... containsList(5) false[8,9]");
	assertTrue(!containsList(b, 6), "Testing... containsList(6) false[8,9]");
	assertTrue(!containsList(b, 7), "Testing... containsList(7) false[8,9]");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");

	removeList(b, 0);
	printf("\nTesting... removeList(0)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 1);
	printf("Testing... removeList(1)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 2);
	printf("Testing... removeList(2)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 3);
	printf("Testing... removeList(3)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 4);
	printf("Testing... removeList(4)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 5);
	printf("Testing... removeList(5)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 6);
	printf("Testing... removeList(6)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 7);
	printf("Testing... removeList(7)[8, 9] not founded\n");
	assertTrue(containsList(b, 8), "Testing... containsList(8) true[8,9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[8,9]");
	removeList(b, 8);
	printf("Testing... removeList(8)[8, 9]\n");
	assertTrue(!containsList(b, 8), "Testing... containsList(8) false[9]");
	assertTrue(containsList(b, 9), "Testing... containsList(9) true[9]");
	removeList(b, 9);
	printf("Testing... removeList(9)[9]\n");
//	assertTrue(containsList(b, 8), "Testing... containsList(8) false[]");
//	assertTrue(containsList(b, 9), "Testing... containsList(9) false[]");
	assertTrue(isEmptyList(b), "isEmptyList: empty");

	printf("addList(linkedList, i) i= 0 to 30 \n");
	for(int i = 0 ; i < 29; i++) {
		addList(b, (TYPE)i);/*Add elements*/
	}

	assertTrue(!isEmptyList(b), "Testing... isEmptyList");

//	for(i=0; i<b->size; i++) {
//		containsList(b, i);
//	}

	/* delete the linked list */
	deleteLinkedList(b);
	printf("\nTesting... deleteLinkedList emptyList\n");
	b = createLinkedList();
	addFrontList(b, 2);
	printf("Testing... deleteLinkedList with a item addFrontList[2]\n");
	assertTrue(EQ(backList(b), 2), "Testing... backList[2]");
	deleteLinkedList(b);
	printf("Testing... deleteLinkedList with a item\n");
	printf("\n****** Test Stack Interface end ******\n");

	printf("******* Test linkedlist start *******\n\n");

	return 0;
}
