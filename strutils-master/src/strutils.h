//strutils.h

/*
* @Data    : 2019/5/20 
* @Author  : Harley
* @Software: Visual Studio 2015
* @Extension��Add some common extension functions to std::string
*	
*/


#pragma once

#include <string.h>
#include <stdarg.h>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

#pragma warning(disable:4996)

/**
* ���ܣ��ָ��ַ���
* ������
*  @str���ַ���
*  @pattern���ָ��
* ����ֵ�����ش洢�ָ��Ӵ�������
*/
std::vector<std::string> split(const std::string &str, const std::string &pattern)
{
	char * strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());   //stringת����C-string
	std::vector<std::string> res;
	char* temp = strtok(strc, pattern.c_str());
	while (temp != NULL)
	{
		res.push_back(std::string(temp));
		temp = strtok(NULL, pattern.c_str());
	}
	delete[] strc;
	return res;
}


/**
* ����:ɾ�������������Ӵ�
* ������
*  @str������
*  @substr���Ӵ�
* ����ֵ�����ؽ��
*/
std::string SErase(const std::string &str, const std::string &substr)
{
	if (str.empty())
		return str;

	std::string strs = str;
	size_t pos = strs.find(substr);

	while (pos != strs.npos)
	{
		strs = strs.erase(pos, substr.size());
		pos = strs.find(substr);
	}

	return strs;
} 

/**
* ���ܣ�ȥ���ַ�����ͷ�ո�
* ������
*  @s���ַ���
* ����ֵ��ȥ����ͷ�ո���ַ���
*/
std::string &ltrim(std::string &s)
{
	if (s.empty()) return s;
	std::string::const_iterator iter = s.begin();
	while (iter != s.end() && isspace(*iter++));
	s.erase(s.begin(), --iter);
	return s;
}

/**
* ���ܣ�ȥ���ַ�����β�ո�
* ������
*  @s���ַ���
* ����ֵ��ȥ����β�ո���ַ���
*/
std::string &rtrim(std::string &s)
{
	if (s.empty()) return s;
	std::string::const_iterator iter = s.end();
	while (iter != s.begin() && isspace(*--iter));
	s.erase(++iter, s.end());
	return s;
}

/**
* ���ܣ�ȥ���ַ�����ͷ�ͽ�β�ո�
* ������
*  @s���ַ���
* ����ֵ��ȥ����ͷ�ͽ�β�ո���ַ���
*/
std::string &trim(std::string &s)
{
	ltrim(s);
	rtrim(s);
	return s;
}

/**
* ���ܣ��ж��ַ����Ƿ���ָ��ǰ׺
* ������
*  @str���ַ���
*  @prefix��ǰ׺
* ����ֵ���ɹ�����ture��ʧ�ܷ���false
*/
bool startsWith(const std::string &str, const std::string &prefix)
{
	return prefix.size() <= str.size() &&
		std::equal(prefix.cbegin(), prefix.cend(), str.cbegin());
}

/**
* ���ܣ��ж��ַ����Ƿ���ָ����׺
* ������
*  @str���ַ���
*  @suffix����׺
* ����ֵ���ɹ�����ture��ʧ�ܷ���false
*/
bool endsWith(const std::string &str, const std::string &suffix)
{
	return suffix.size() <= str.size() &&
		std::equal(suffix.crbegin(), suffix.crend(), str.crbegin());
}

/**
* ���ܣ������ַ����ִ��ڸ������״γ��ֵ�λ��
* ������
*  @str������
*  @substr���Ӵ�
* ����ֵ�������ַ����ִ��ڸ������״γ��ֵ�λ��
*/
std::string::size_type indexOf(const std::string &str, const std::string &substr)
{
	return str.find(substr);
}

/**
* ���ܣ��ַ���ת��Ϊ��д
* ������
*  @str���ַ���
* ����ֵ�����ش�д�ַ���
*/
std::string toUpper(const std::string &str)
{
	std::string upper(str.size(), '\0');
	std::transform(str.cbegin(), str.cend(), upper.begin(), ::toupper);
	return upper;
}

/**
* ���ܣ��ַ���ת��ΪСд
* ������
*  @str���ַ���
* ����ֵ������Сд�ַ�
*/
std::string toLower(const std::string &str)
{
	std::string lower(str.size(), '\0');
	std::transform(str.cbegin(), str.cend(), lower.begin(), ::tolower);
	return lower;
}



/**
* ���ܣ���ʽ���ַ���
* ���Ͱ�ȫ
* ֧�ֿɱ����
* ������������
* ��ʽ���ַ�������ָ���������� 
* ��ʽ���ַ�������ָ����Ч����
* ������ ToString ��չ�Զ�������
* ����ֵ����ʽ���Ľ���ַ���
*/

/*
ʾ����

//  c++ code

auto str = SFormat("hello world, {0}, {0}, {1}, {2}, {3}", 123, 1.23, "123", std::string("123"));

//  output:

hello world, 123, 123, 1.23, 123, 123
*/

namespace std {
	template <class T>
	std::string to_string(T && val)
	{
		static_assert(false);
	}
}

template <class T>
inline void ToString(std::string & ret, T && val)
{
	ret.append(std::to_string(std::forward<T>(val)));
}

inline void ToString(std::string & ret, const std::string & val)
{
	ret.append(val);
}

inline void ToString(std::string & ret, const char * val)
{
	ret.append(val);
}

template <int N>
struct SFormatN {
	static std::string Format(const char * fmt)
	{
		static_assert(false, "");
	}
};

template <>
struct SFormatN<0> {
	template <class ...ARGS>
	static std::string Format(const char * fmt, const std::tuple<ARGS...> &)
	{
		return fmt;
	}
};

template <class ...ARGS>
std::string SFormat(const char * fmt, const ARGS &...args)
{
	const auto tuple = std::forward_as_tuple(args...);
	return SFormatN<sizeof...(args)>::Format(fmt, tuple);
}

#define FMT_N(idx)	case idx: ToString(ret, std::get<idx>(args)); break;

#define FMT_PARSE(N, ...)															\
template <>																			\
struct SFormatN<N> {																\
	template <class... ARGS>														\
	static std::string Format(const char * fmt, const std::tuple<ARGS...> & args)	\
	{	std::string ret;															\
		while (*fmt != '\0') { auto idx = -1;										\
			if (*fmt == '{') { idx = 0; ++fmt;										\
				while (*fmt >= '0' && *fmt <= '9')									\
					{ idx *= 10; idx += (int)(*fmt++ - '0'); }						\
				if (*fmt != '}') idx = -1; else ++fmt;								\
			}																		\
			switch (idx) { __VA_ARGS__ default: ret.append(1, *fmt++); break; }		\
		}																			\
		return ret;																	\
	}																				\
};

FMT_PARSE(1, FMT_N(0))
FMT_PARSE(2, FMT_N(0) FMT_N(1))
FMT_PARSE(3, FMT_N(0) FMT_N(1) FMT_N(2))
FMT_PARSE(4, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3))
FMT_PARSE(5, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4))
FMT_PARSE(6, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5))
FMT_PARSE(7, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6))
FMT_PARSE(8, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7))
FMT_PARSE(9, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8))
FMT_PARSE(10, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9))
FMT_PARSE(11, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10))
FMT_PARSE(12, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11))
FMT_PARSE(13, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12))
FMT_PARSE(14, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13))
FMT_PARSE(15, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14))
FMT_PARSE(16, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15))
FMT_PARSE(17, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16))
FMT_PARSE(18, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17))
FMT_PARSE(19, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18))
FMT_PARSE(20, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18) FMT_N(19))
FMT_PARSE(21, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18) FMT_N(19) FMT_N(20))
FMT_PARSE(22, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18) FMT_N(19) FMT_N(20) FMT_N(21))
FMT_PARSE(23, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18) FMT_N(19) FMT_N(20) FMT_N(21) FMT_N(22))
FMT_PARSE(24, FMT_N(0) FMT_N(1) FMT_N(2) FMT_N(3) FMT_N(4) FMT_N(5) FMT_N(6) FMT_N(7) FMT_N(8) FMT_N(9) FMT_N(10) FMT_N(11) FMT_N(12) FMT_N(13) FMT_N(14) FMT_N(15) FMT_N(16) FMT_N(17) FMT_N(18) FMT_N(19) FMT_N(20) FMT_N(21) FMT_N(22) FMT_N(23))


/**
* ���ܣ���ʽ���ַ���
* ������
*  @fmt����ʽ����
*  @...����������
* ����ֵ����ʽ���Ľ���ַ���
*/
std::string format(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	int len = _vsnprintf(nullptr, 0, fmt, args);
	va_end(args);
	std::string buf(len + 1, '\0');
	va_start(args, fmt);
	_vsnprintf(&buf[0], buf.size(), fmt, args);
	va_end(args);
	buf.pop_back();
	return buf;
}

/**
* ���ܣ���ʽ���ַ���
* ������
*  @pszFmt����ʽ����
*  @...����������
* ����ֵ����ʽ���Ľ���ַ���
*/
std::string Format(const char *pszFmt, ...)
{
	std::string str;
	va_list args;
	va_start(args, pszFmt);
	{
		int nLength = _vscprintf(pszFmt, args);
		nLength += 1;  //���淵�صĳ����ǰ���\0���������
		std::vector<char> vectorChars(nLength);
		_vsnprintf(vectorChars.data(), nLength, pszFmt, args);
		str.assign(vectorChars.data());
	}
	va_end(args);
	return str;
}
