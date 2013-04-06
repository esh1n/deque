// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "deque.h"
#ifdef _UNICODE
#  define tcout  wcout
#  define tcin   wcin
#  define tprintf   wprintf
#else
#  define TCOUT  cout
#  define TCIN   cin
#  define tprintf   printf
#endif




// TODO: ”становите здесь ссылки на дополнительные заголовки, требующиес€ дл€ программы
