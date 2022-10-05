#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>

   strlen
	返回类型是无符号数

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcqwer";
	int ret = strcmp(p1, p2);
	int ret = strncmp(p1, p2, 3);
					    指定比较几个字符
					大于返回>0 ,小于返回<0, 等于返回0
	printf("%d ", ret);
	return 0;
}

			NULL - 空指针
		Null/NUL - '\0'=\0

				strstr 字符串查找

				模拟实现
char* my_strstr(const char* p1,const char* p2)
{
	assert(p1);
	assert(p2);
	char* p3 = 0;
	while (*p1)
	{
		while (*p1 != *p2)
		{
			p1++;
		}
		const char* p3 = p1;		自己写的，有些问题，不满足所有情况
		while (*p1 == *p2)
		{
			p1++;
			p2++;
			if (*p2 == '\0')
			{
				return p3;
			}
		}
		return NULL;
	}

	const char* s1 = p1;
	const char* s2 = p2;	//  存储 p1,p2，尽量避免其被修改
	const char* cur = p1;
	if (*p2 == '\0')	//  p2如果是'\0'，之间返回p1
	{
		return (char*)p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = (char*)p2;
		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
		while (s1 && s2 && (*s1 == *s2))
		{
			s1++;	// 三者都满足，s1,s2开始同时向后++
			s2++;
		}
		if (*s2 == '\0')
		{	// s2已++到\0，s1未到，则可以返回cur地址
			return (char*)cur;
		}
		cur++;	//  此时s1 != s2，但s1仍需要从起始位置向后+1,s2需要从起始位置开始，直至满足s1=s2
		if (*s1 == '\0')
		{
			return NULL;
		}
	}
	return NULL;	// 没有则直接返回NULL

}
int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "def";
	const char* p3 = "abcdefgh\0i";
	const char* p4 = "abcdefabcdef";
	const char* p5 = "abbbcdef";
	const char* p6 = "bbc";
	const char* ret = strstr(p4, p2);
	const char* ret = my_strstr(p5, p6);
	if (ret == NULL)
	{
		printf("没有");
	}
	else
	{
		printf("%s ", ret);
		 会把def 后面的也打印出来,直到遇到\0
		  返回的是p2第一次出现的地址
		printf("%p ", ret);// d 的地址
	}
	return  0;
}