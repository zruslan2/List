#include "List.h"
//#include <string>

void main() {
	//while(1){
	List_<int> s;
	for (size_t i = 0; i < 5; i++)
		s.push_back(i);
	for (size_t i = 0; i < 10; i++)
		s.push_front(i*i);
	//cout << s;
	s.insert(777, 0);
	s.insert(777, 2);
	s.insert(777, 13);

	cout << s<<endl<<"---------------\n";
	s.reverse();
	cout << s << endl << "---------------\n";

	//List_<int> s2;
	//s2.push_back(9999);
	//s = move(s2);

	//cout << s2 << endl << s << endl;
	//}
	system("pause");
}