#include<stdlib.h>
#include"Debug_New.h"
#if defined(_DEBUG)
#define new DEBUG_NEW
#endif //defined(_DEBUG)

void main() {
	int *p = new int();
	*p = 1;
	printf("%i\n", *p);
	delete p;
}