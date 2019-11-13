//---------------------------------------------------------------------------
#include "Unit1.h"
//---------------------------------------------------------------------------
//вывод строки
 void String::PrintStr ()
{
	for (int i = 0; i < size; i++) {
		printf("%c",str[i]);
	}
	printf("\n");
return;
}
//расчет длины строки str
inline int StrLen(const char* str)
{
	int i = 0;
	for (i; str[i] != '\0'; i++);
	return i;
}
//конструктор определения
String :: String (const char* str1){
	size = StrLen(str1);
	str = new char[size];
	for (int i = 0; i < size; i++)
		str[i] = str1[i];
	str[size] = '\0';
}
//конструктор копирования
String :: String (const String& s, const int& n)
{
	if (!str) {
		delete[] str;
	}
	size = n;
	str = new char[n];
	for (int i = 0; i < n; i++) {
		str[i] = s.str[i];
	}
	str[n] = '\0';
}
//деструктор
String :: ~String()
{
	delete[] str;
}
//расчет длинны value
inline int Length(int value)
{
	int i = 0;
	for (i; value; value = value/10, i++);
	return i;
}
//перевод в строку
 void String::IntToStr (const int& value)
{
	size = Length(value);
	str = new char[size];
	sprintf(str, "%d", value);
	str[size] = '\0';
	return;
}
//перевод в число
 int String::StrToInt()
{
	int k = 0, t = 0;
	for (int i = size - 1; i >= 0; i--)
	{
	  t += (str[i] - '0')*pow(10.0,k++);
	}
	return t;
}
