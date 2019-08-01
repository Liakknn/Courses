#include <stdio.h>

void print_memory(const void* ptr) {
	printf("Bytes from #%llu:\n", (unsigned long long) ptr);
	for (size_t i = 0; i < 32; ++i) {
		putc(((const char*)ptr)[i], stdout);
	}
	putchar('\n');
}

int main(/*int argc, const char** argv */) {
	//for (int i = 0; i < argc; ++i) {
	//	printf("%s\n", argv[i]);
	//}
	char str[8] = { 0 };
	int a = 65;
	printf("%llu %llu\n", (unsigned long long)str, (unsigned long long) &a);
	print_memory(str + sizeof(str));
	printf("'%s' %d\n", str, a);
	scanf("%s", str);
	printf("'%s' %d\n", str, a);
}