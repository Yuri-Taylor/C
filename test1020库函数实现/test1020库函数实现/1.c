#include<stdio.h>
#include<assert.h>
#include<string.h>
//strlen
int my_strlen(char* str)//字符串长度
{
	char* tmp = str;
	int count = 0;
	while (*tmp != '\0')
	{
		tmp++;
		count++;
	}
	return count;
}
//strcpy
char* my_strcpy(char* strDest, const char* strSrc)//字符串拷贝
{
	char* p = NULL;
	assert(strDest != NULL && strSrc != NULL);
	p = strDest;
	while ((*strDest++ = *strSrc++) != '\0');
	return p;
}
//strcat
char* my_strcat(char* strDest, const char* strSrc)//字符串拷贝到末尾
{
	assert(strDest != NULL && strSrc != NULL);
	char* p = strDest;
	while (p != '\0')
		p++;
	while ((*p++ = *strSrc++) != '\0');
	return p;
}
//strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{
		str1++;
		str2++;
	}
	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	return 0;
}
//strncpy
char* my_strncpy(char* strDest, const char* strSrc, int len)
{
	assert(strDest != NULL && strSrc != NULL);
	char* p = strDest;
	while ((*p++ = *strSrc++)!='\0' && len)
	{
		len--;
	}
	if (len)
	{
		while (--len)
			*p++ = '\0';
	}
	return p;
}
//strncat
char* my_strncat(char* strDest, const char* strSrc, int len)
{
	assert(strDest != NULL && strSrc != NULL);
	char* p = strDest;
	while (*p != '\0')
	{
		p++;
	}
	while ((*p++ = *strSrc++) != '\0'&&len)
	{
		len--;
	}
	return p;
}
//strncmp
int my_strncmp(const char* str1, const char* str2,int len)
{
	assert(str1 != NULL && str2 != NULL);
	int ret = 0;
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && len)
	{
		len--;
		str1++;
		str2++;
	}
	if (ret > 0)
		return 1;
	else if (ret < 0)
		return -1;
	return 0;
}
//strstr
const char* my_strstr(const char* str1, const char* str2)//判断str2是否是str1的子串，如果是返回子串及以后的字符串，否则返回NULL
{
	if (str1 == NULL || str2 == NULL)
		return str1;
	char* p1;
	char* p2;
	while (*str1)
	{
		p1 = str1;
		p2 = str2;
		do {
			if (!(*p2))
				return str1;
		} while (*p1++ == *p2++);
		str1++;
	}
	return NULL;
}
//strtok
char* my_strtok(char* str, const char* del)//按照给定的字符分割字符串
{
	if (del == NULL)
		return str;
	 char* tmp = NULL;
	 char* ret = NULL;
	 if (str != NULL)
		 tmp = str;
	 if (tmp == NULL)
		 return NULL;
	 ret = tmp;
	 char* p = strstr(tmp, del);
	 if (p != NULL)
	 {
		 tmp = p + strlen(del);
		 int i = 0;
		 for (i = 0; i < strlen(del); i++)
		 {
			 *(p + i) = '\0';
		 }
	 }
	 else 
	 {
		 tmp = NULL;
	 }
	 return ret;

}
//memcpy
void* my_memcpy(void* dest, const void* src, int count)
{
	if (dest == NULL || src == NULL)
		return NULL;
	char* pdest = (char*)dest;
	char* psrc = (char*)src;
	while (count--)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}
//memmove
//当src和dest区域重叠时使用memmove
void* my_memmove(void* dest, const char* src, int n)
{
	assert(dest != NULL && src != NULL);
	char* pdest = (char*)dest;
	const char* psrc = (const char*)src;
	if (psrc > pdest)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	else if (psrc < pdest)
	{
		pdest = pdest + n - 1;
		psrc = psrc + n - 1;
		while (n--)
			*pdest-- = *psrc--;
	}
	return dest;
}

int main()
{
	return 0;
}