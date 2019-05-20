#include <string>
#include <iostream>
#include "strutils.h"

using std::cout;
using std::endl;
using std::string;

//���Գ���
int main()
{
	string str1 = "   Hello, World!   ";
	string str2 = "I am a junior programmer.";
	string str3 = "2019-05-20";
	string str4 = "Accept: */*\r\nAccept-Language: zh-cn\r\nAccept-Encoding: gzip, deflate\r\nHost: 10.2.1.60\r\n";

	//ȥ���ַ���ǰ��ո�
	cout << "str1:"<< str1 << endl;
	cout << "trim(str1):"<< trim(str1) << endl; 
	cout << "--------------------------------" << endl;

	//תΪ��д
	cout << "str2:" << str2 << endl;
	cout << "toUpper(str2):" << toUpper(str2) << endl;	
	cout << "--------------------------------" << endl;

	//ɾ��ָ���ַ���
	cout << "str3:" << str3 << endl;
	cout <<"SErase(str3, \"-\"):"<< SErase(str3, "-") << endl;
	cout << "--------------------------------" << endl;

	//�ָ��ַ���
	std::vector<string> v;
	v = split(str4, "\r\n");

	for (std::vector<string>::iterator iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter  << endl;
	}
	cout << "--------------------------------" << endl;

	//�ַ�����ʽ��
	string str = SFormat("hello world, {0}, {0}, {1}, {2}, {3}", 123, 1.23, "123", std::string("123"));
	cout << str << endl;

	getchar();
	return 0;
}