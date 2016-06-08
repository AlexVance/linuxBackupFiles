#include<stdio.h>

int main()
{
	
	int a = 5;
	short b = 10;
	char c = 15;
	char * d = "Hello, my name is Alex Vance\n";
	double e = 20.0;

	int * aPtr = &a;
	short * bPtr = &b;
	char * cPtr = &c;
	char ** dPtr = &d;
	double * ePtr = &e;
	void * vPtr = aPtr;

	printf("name \t\t type \t\t value \t\t address: \n");
	printf("%s \t\t %s \t\t %d \t\t %p \n", "a","int",a,&a);
	printf("%s \t\t %s \t\t %d \t\t %p \n", "b","short",b,&b);
	printf("%s \t\t %s \t\t %d \t\t %p \n", "c","char",c,&c);
	printf("%s \t\t %s \t\t %s \t\t %p \n", "d","char *",d,&d);
	printf("%s \t\t %s \t\t %d \t\t %p \n", "e","double",e,&e);
	printf("%s \t\t %s \t\t %p \t\t %p \n", "aPtr","int",aPtr,&aPtr);
	printf("%s \t\t %s \t\t %p \t\t %p \n", "bPtr","short",bPtr,&bPtr);
	printf("%s \t\t %s \t\t %s \t\t %p \n", "cPtr","char *",cPtr,&cPtr);
	printf("%s \t\t %s \t\t %p \t\t %p \n", "dPtr","char **",dPtr,&dPtr);
	printf("%s \t\t %s \t\t %p \t\t %p \n", "ePtr", "double *",ePtr,&ePtr);
	printf("%s \t\t %s \t\t %p \t\t %p \n", "vPtr","void *",vPtr,&vPtr);
	return 0;
}