#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<assert.h>

   strlen
	�����������޷�����

int main()
{
	const char* p1 = "abcdef";
	const char* p2 = "abcqwer";
	int ret = strcmp(p1, p2);
	int ret = strncmp(p1, p2, 3);
					    ָ���Ƚϼ����ַ�
					���ڷ���>0 ,С�ڷ���<0, ���ڷ���0
	printf("%d ", ret);
	return 0;
}

			NULL - ��ָ��
		Null/NUL - '\0'=\0

				strstr �ַ�������

				ģ��ʵ��
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
		const char* p3 = p1;		�Լ�д�ģ���Щ���⣬�������������
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
	const char* s2 = p2;	//  �洢 p1,p2�����������䱻�޸�
	const char* cur = p1;
	if (*p2 == '\0')	//  p2�����'\0'��֮�䷵��p1
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
			s1++;	// ���߶����㣬s1,s2��ʼͬʱ���++
			s2++;
		}
		if (*s2 == '\0')
		{	// s2��++��\0��s1δ��������Է���cur��ַ
			return (char*)cur;
		}
		cur++;	//  ��ʱs1 != s2����s1����Ҫ����ʼλ�����+1,s2��Ҫ����ʼλ�ÿ�ʼ��ֱ������s1=s2
		if (*s1 == '\0')
		{
			return NULL;
		}
	}
	return NULL;	// û����ֱ�ӷ���NULL

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
		printf("û��");
	}
	else
	{
		printf("%s ", ret);
		 ���def �����Ҳ��ӡ����,ֱ������\0
		  ���ص���p2��һ�γ��ֵĵ�ַ
		printf("%p ", ret);// d �ĵ�ַ
	}
	return  0;
}