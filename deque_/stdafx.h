// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include<string>
#include <tchar.h>
#include <iostream>
#include "deque.h"
#ifdef _UNICODE
#  define tcout  wcout
#  define tcin   wcin
#  define tString   wstring
#  define tprintf   wprintf
#else
#  define TCOUT  cout
#  define TCIN   cin
#  define tString   string
#  define tprintf   printf
#endif




// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
