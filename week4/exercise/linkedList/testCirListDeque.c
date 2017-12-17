#include "cirListDeque.h"
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
	struct cirListDeque* c;

	c = createCirListDeque();
	printf("\n\n******* Test linkedlist start *******\n");

	assertTrue(isEmptyCirListDeque(c), "Testing... isEmptyCirListDeque");
	addBackCirListDeque(c, 6);
	printf("\nTesting... addBackCirListDeque(6)[]\n");
	assertTrue(EQ(frontCirListDeque(c), 6), "frontCirDeque[6]");
	assertTrue(!isEmptyCirListDeque(c), "Testing... isEmptyCirListDeque");
	addBackCirListDeque(c, 7);
	printf("Testing... addBackCirListDeque(7)[6]\n");
	assertTrue(EQ(frontCirListDeque(c), 6), "frontCirListDeque[6, 7]");
	assertTrue(EQ(backCirListDeque(c), 7), "backCirListDeque[6, 7]");
	printCirListDeque(c);

	addFrontCirListDeque(c, 9);
	printf("Testing... addFrontCirListDeque [6, 7]\n");
	assertTrue(EQ(frontCirListDeque(c), 9), "frontCirListDeque [9, 6, 7]");
	addFrontCirListDeque(c, 8);
	printf("Testing... addFrontCirListDeque [9, 6, 7]\n");
	assertTrue(EQ(frontCirListDeque(c), 8), "frontCirListDeque [8, 9, 6, 7]");
	printCirListDeque(c);

	removeFrontCirListDeque(c);
	printf("\nTesting... removeFrontCirListDeque[8, 9, 6, 7]\n");
	assertTrue(EQ(frontCirListDeque(c), 9), "frontCirListDeque[9, 6, 7]");
	removeFrontCirListDeque(c);
	printf("Testing... removeFrontCirListDeque[9, 6, 7]\n");
	assertTrue(EQ(frontCirListDeque(c), 6), "frontCirListDeque[6, 7]");
	removeFrontCirListDeque(c);
	printf("Testing... removeFrontCirListDeque[6, 7]\n");
	assertTrue(EQ(frontCirListDeque(c), 7), "frontCirListDeque[7]");
	removeFrontCirListDeque(c);
	printf("Testing... removeFrontCirListDeque[7]\n");
	assertTrue(isEmptyCirListDeque(c), "isEmptyCirListDeque");
	printCirListDeque(c);

	addFrontCirListDeque(c, 2);
	printf("Testing... addFrontCirListDeque []\n");
	assertTrue(EQ(frontCirListDeque(c), 2), "frontCirListDeque [2]");
	addFrontCirListDeque(c, 4);
	printf("Testing... addFrontCirListDeque [2]\n");
	assertTrue(EQ(frontCirListDeque(c), 4), "frontCirListDeque [4, 2]");
	addFrontCirListDeque(c, 5);
	printf("Testing... addFrontCirListDeque [4, 2]\n");
	assertTrue(EQ(frontCirListDeque(c), 5), "frontCirListDeque [5, 4, 2]");
	printCirListDeque(c);

	removeBackCirListDeque(c);
	printf("Testing... removeBackCirListDeque[5, 4, 2]\n");
	assertTrue(EQ(backCirListDeque(c), 4), "backCirListDeque[5, 4]");
	removeBackCirListDeque(c);
	printf("Testing... removeBackCirListDeque[5, 4]\n");
	assertTrue(EQ(backCirListDeque(c), 5), "backCirListDeque[5]");
	removeBackCirListDeque(c);
	printf("Testing... removeBackCirListDeque[5]\n");
	assertTrue(isEmptyCirListDeque(c), "isEmptyCirListDeque");

	addFrontCirListDeque(c, 4);
	printf("\nTesting... addFrontCirListDeque []\n");
	reverseCirListDeque(c);

	assertTrue(EQ(frontCirListDeque(c), 4), "frontCirListDeque [4]");
	assertTrue(EQ(backCirListDeque(c), 4), "backCirListDeque[4]");

	addFrontCirListDeque(c, 3);
	printf("Testing... addFrontCirListDeque [4]\n");
	addFrontCirListDeque(c, 2);
	printf("Testing... addFrontCirListDeque [3, 4]\n");
	addFrontCirListDeque(c, 1);
	printf("Testing... addFrontCirListDeque [2, 3, 4]\n");
	addBackCirListDeque(c, 5);
	printf("Testing... addBackCirListDeque[1, 2, 3, 4]\n");
	addBackCirListDeque(c, 6);
	printf("Testing... addBackCirListDeque[1, 2, 3, 4, 5]\n");
	addBackCirListDeque(c, 7);
	printf("Testing... addBackCirListDeque[1, 2, 3, 4, 5, 6]\n");

	reverseCirListDeque(c);
	printf("\nreverseCirListDeque [7, 6, 5, 4, 3, 2, 1]\n");
	assertTrue(EQ(frontCirListDeque(c), 7), "frontCirListDeque[7, 6, 5, 4, 3, 2, 1]");
	assertTrue(EQ(backCirListDeque(c), 1), "backCirListDeque[7, 6, 5, 4, 3, 2, 1]");
	printCirListDeque(c);

	deleteCirListDeque(c);
	printf("Testing... deleteCirListDeque\n");
	
	return 0;
}
