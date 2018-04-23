string (&reStrSzRef(string (&arrStr)[10]))[10];
typedef string arrStr[10];
arrStr &reStrSzRef(arrStr &arrstr);
auto reStrSzRef(string (&arr)[10]) -> string (&)[10];
string arrStr[10];
decltype(arrStr) &reStrSzRef(string (&arrStr)[10]);

