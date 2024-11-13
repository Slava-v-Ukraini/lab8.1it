#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // ��� strlen, strcpy

using namespace std;

int Count(const char* str)
{
    if (strlen(str) < 2)
        return 0;
    int k = 0;
    for (int i = 0; str[i + 1] != '\0'; i++)
        if (str[i] == ',' && str[i + 1] == '-')
            k++;
    return k;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 2)
        return str;

    // �������� ��������� ���'�� ��� ������ �����
    char* tmp = new char[len * 2 + 1]; // � �������
    char* t = tmp;
    size_t i = 0;

    while (i < len)
    {
        if (str[i] == ',' && str[i + 1] == '-')
        {
            // ����� ",-" �� "*"
            *t++ = '*';
            i += 2; // ���������� ",-"
        }
        else
        {
            // ������� ��������� ������
            *t++ = str[i++];
        }
    }
    *t = '\0'; // ���������� �����

    // ������� ������� ����� ����� � �����������
    strcpy_s(str, strlen(tmp) + 1, tmp);
    return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str) << " groups of ', - '" << endl;
	
    char* dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

    delete[] dest;

	return 0;
}