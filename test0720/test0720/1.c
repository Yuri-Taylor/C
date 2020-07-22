#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	char *p = "abcdef";
//	char *q = "abcdef";
//	if (p == q)
//	{
//		printf("p==q");
//	}
//	else
//	{
//		printf("p!=q");
//	}
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//	char str1[20];
//	char str2[20];
//	strcpy(str1, "Hello ");
//	strcpy(str2, "i am a student");
//	strncat(str1, str2, 7);
//	puts(str1);
//	return 0;
//}
//
//
//#include <stdio.h> 
//#include <string.h>
//
//int main() {
//	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
//	int n;
//	printf("Looking for R2 astromech droids :\n");
//	for (n = 0; n < 3; n++)
//		if (strncmp(str[n], "R2xx", 2) == 0)
//		{
//			printf("found %s\n", str[n]);
//		}
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//int main() 
//{ 
//	char str[] = "This is a simple string"; 
//	char * pch;
//	pch = strstr(str, "simple"); 
//	strncpy(pch, "sample", 6);
//	printf("%s\n", str);
//	return 0;
//}

//#include <stdio.h> 
//#include <string.h>
//int main() 
//{
//	int i; 
//	char strtext[] = "129th"; 
//	char cset[] = "1234567890";
//	i = strspn(strtext, cset); 
//	printf("The initial number has %d digits.\n", i);  
//	return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main() 
//{ 
//	char str[] = "- This, a sample string."; 
//	char * pch; 
//	printf("Splitting string \"%s\" into tokens:\n", str); 
//	pch = strtok(str, " ,.-"); 
//	while (pch != NULL) 
//	{ 
//		printf("%s\n", pch); 
//		pch = strtok(NULL, " ,.-"); 
//	} 
//	return 0; 
//}


//#include <stdio.h> 
//int main()
//{
//	char *p = "Taylor@163.com";
//	const char* sep = ".@";
//	char arr[30];
//	char *str = NULL;
//	strcpy(arr, p);//将数据拷贝一份，处理arr数组的内容  
//	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
//	{
//		printf("%s\n", str);
//	}
//}

//
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main() {
//	FILE * pFile;
//	pFile = fopen("unexist.ent", "r"); 
//	if (pFile == NULL) 
//		printf("Error opening file unexist.ent: %s\n", strerror(errno)); 
//	//errno: Last error number ?
//	return 0; 
//} 

//#include <stdio.h> 
//#include <string.h>
//
//struct { 
//	char name[40];
//	int age; 
//}person, person_copy;
//
//int main()
//{
//	char myname[] = "Taylor de Fermat";
//	//using memcpy to copy string: 
//	memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 22;
//	//using memcpy to copy structure:
//	memcpy(&person_copy, &person, sizeof(person));
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//	return 0;
//}

//#include <stdio.h> 
//#include <string.h>
//
//int main() 
//{
//	char str[] = "memmove can be very useful......";
//	memmove(str + 20, str + 15, 11);
//	puts(str); 
//	return 0; 
//}


//#include <stdio.h>
//#include <string.h>
//
//int main() 
//{
//	char buffer1[] = "DWgaOtP12df0";
//	char buffer2[] = "DWGAOTP12DF0";
//	int n;
//	n = memcmp(buffer1, buffer2, sizeof(buffer1));
//	if (n > 0)
//		printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	else if (n < 0) 
//		printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	return 0;
//}

//计数器方式 
//int my_strlen(const char * str) 
//{    
//	int count = 0;    
//	while(*str)  
//	{      
//		count++;    
//		str++;  
//	}   
//	return count;
//}


//int my_strlen(const char * str) 
//{ 
//	if (*str == '\0')    
//		return 0;   
//	else       
//		return 1 + my_strlen(str + 1); 
//}
//


//int my_strlen(char *s) 
//{ 
//	char *p = s;
//	while (*p != '\0')
//		p++;
//	return p - s;
//}

#include<stdio.h>
//char *my_strcpy(char *dest, const char*src) 
//{
//	char *ret = dest;    
//	assert(dest != NULL);
//	assert(src != NULL);       
//	while ((*dest++ = *src++)) 
//	{ ; }   
//	return ret;
//}


//char *my_strcat(char *dest, const char*src)
//{
//	char *ret = dest;  
//	assert(dest != NULL); 
//	assert(src != NULL);  
//	while (*dest)
//	{ 
//		dest++;
//	}   
//	while ((*dest++ = *src++)) 
//	{ ; } 
//	return ret;
//}


//char *my_strstr(const char* str1, const char* str2) 
//{
//	assert(str1);    
//	assert(str2);   
//	char *cp = (char*)str1;  
//	char *substr = (char *)str2;  
//	char *s1 = NULL;     
//	if (*str2 == '\0')  
//		return NULL;  
//	while (*cp) 
//	{
//		s1 = cp;     
//		substr = str2;   
//		while (*s1 && *substr && (*s1 == *substr))
//		{
//			s1++; 
//			substr++; 
//		}    
//		if (*substr == '\0') 
//			return cp;
//		cp++;
//	}
//}

//void * memcpy(void * dst, const void * src, size_t count) 
//{
//	void * ret = dst;     
//	assert(dst);
//	assert(src); 
//	//copy from lower addresses to higher addresses
//	while (count--) 
//	{
//		*(char *)dst = *(char *)src;
//		dst = (char *)dst + 1;
//		src = (char *)src + 1; 
//	}
//	return(ret);
//}


//void * memcpy(void * dst, const void * src, size_t count)
//{
//	void * ret = dst;
//	if (dst <= src || (char *)dst >= ((char *)src + count))
//	{ 
//		//Non-Overlapping Buffers
//		//copy from lower addresses to higher addresses
//		while (count--) 
//		{ 
//			*(char *)dst = *(char *)src;
//			dst = (char *)dst + 1;
//			src = (char *)src + 1;
//		}
//	}
//	else {
//		//Overlapping Buffers
//		//copy from higher addresses to lower addresses
//		dst = (char *)dst + count - 1;
//		src = (char *)src + count - 1;
//		while (count--) { *(char *)dst = *(char *)src;
//		dst = (char *)dst - 1;
//		src = (char *)src - 1;
//		}
//	}
//	return(ret);
//}

//#include <stdio.h> 
//int main ()
//{ 
//	FILE * pFile;
//	pFile=fopen ("unexist.ent","rb");  
//	if (pFile == NULL)   
//		perror ("The following error occurred");
//	else    
//		fclose (pFile);  
//	return 0;
//}

//#include <stdio.h>      /* printf, fopen */ 
//#include <stdlib.h>     /* exit, EXIT_FAILURE */
//int main() 
//{
//	FILE * pFile;
//	pFile = fopen("myfile.txt", "r");  
//	if (pFile == NULL)
//	{ 
//		printf("Error opening file");  
//		exit(EXIT_FAILURE);
//	}
//	else
//	{   
//		/* file operations here */
//	}
//	return 0;
//}


//#include <stdio.h>
//int main () 
//{ 
//	FILE * pFile; 
//	pFile = fopen ("myfile.txt","w");
//	if (pFile!=NULL)
//	{  
//		fputs ("fopen example",pFile); 
//		fclose (pFile); 
//	}
//	return 0;
//}

//#include <stdio.h> 
//int main () 
//{ 
//	FILE * pFile;
//	pFile = fopen ("myfile.txt","wt"); 
//	fprintf (pFile, "fclose example"); 
//	fclose (pFile); 
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int c;
//	puts("Enter text. Include a dot ('.') in a sentence to exit");
//	do
//	{   
//		//getchar 是从标准输?入获取?一个字符  
//		c=getchar();   
//		//putchar 是向标准输出流输出?一个字符   
//		putchar (c);  
//	} while (c != '.'); 
//	return 0; 
//}

//#include <stdio.h>
//int main ()
//{ 
//	FILE * pFile;  
//	int c; 
//	int n = 0; 
//	pFile=fopen ("myfile.txt","r"); 
//	if (pFile==NULL)
//		perror ("Error opening file"); 
//	else 
//	{    
//		do   
//		{    
//			c = getc (pFile);   
//			if (c == '$') n++; 
//		} 
//		while (c != EOF); 
//		fclose (pFile); 
//		printf ("File contains %d$.\n",n);
//	}  
//	return 0; 
//}


//#include <stdio.h>
//int main() 
//{
//	char string[256]; 
//	printf("Insert your full address: ");  
//	gets(string);     
//	// warning: unsafe (see fgets instead)  
//	printf ("Your address is: %s\n",string); 
//	puts(string);
//	return 0; 
//}


//#include <stdio.h>
//int main() {
//	FILE * pFile;  
//	char mystring[100];
//	pFile = fopen("myfile.txt", "r");  
//	if (pFile == NULL)
//		perror("Error opening file"); 
//	else 
//	{
//		if (fgets(mystring, 100, pFile) != NULL)   
//			puts(mystring);    
//		fclose(pFile); 
//	}  
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	FILE * pFile;
//	char sentence[256];
//	printf("Enter sentence to append: ");
//	fgets(sentence, 256, stdin);
//	pFile = fopen("mylog.txt", "a");
//	fputs(sentence, pFile);
//	fclose(pFile);
//	return 0;
//}


//#include <stdio.h>
//int main() 
//{
//	char str[80]; 
//	float f; 
//	FILE * pFile;
//	pFile = fopen("myfile.txt", "w+"); 
//	fprintf(pFile, "%f %s", 3.1416, "PI"); 
//	rewind(pFile); 
//	fscanf(pFile, "%f", &f); 
//	fscanf(pFile, "%s", str); 
//	fclose(pFile); 
//	printf("I have read: %f and %s \n", f, str);
//	return 0;
//}

//#include <stdio.h> 
//#include <stdlib.h>
//int main() 
//{
//	FILE * pFile; 
//	long lSize; 
//	char * buffer;
//	size_t result;
//	pFile = fopen("myfile.bin", "rb");
//	if (pFile == NULL) 
//	{ 
//		fputs("File error", stderr); 
//		exit(1);
//	}
//	// obtain file size:  
//	fseek (pFile , 0 , SEEK_END);  
//	lSize = ftell (pFile);  
//	rewind (pFile);
//	// allocate memory to contain the whole file: 
//	buffer = (char*) malloc (sizeof(char)*lSize);  
//	if (buffer == NULL) 
//	{
//		fputs ("Memory error",stderr); 
//		exit (2);
//	}
//	// copy the file into the buffer:  
//	result = fread (buffer,1,lSize,pFile);  
//	if (result != lSize) 
//	{
//		fputs ("Reading error",stderr);
//		exit (3);
//	}
//	fclose(pFile); 
//	free(buffer); 
//	return 0;
//}

//#include <stdio.h>
//
//int main() 
//{
//	FILE * pFile; 
//	char buffer[] = { 'x' , 'y' , 'z' }; 
//	pFile = fopen("myfile.bin", "wb"); 
//	fwrite(buffer, sizeof(char), sizeof(buffer), pFile); 
//	fclose(pFile); 
//	return 0;
//}


//#include <stdio.h> 
//#include <stdlib.h>
//
//int main(void) 
//{
//	int c;
//	FILE* fp = fopen("test.txt", "r");
//	if(!fp) {
//		perror("File opening failed");
//		return EXIT_FAILURE;
//	}    
//	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF ? ?
//	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环 ?  
//	{
//		putchar(c);
//	}   
//	//判断是什么原因结束的 ? ?
//	if (ferror(fp))
//		puts("I/O error when reading");
//	else if (feof(fp))
//		puts("End of file reached successfully");
//	fclose(fp);
//}
