#if 0
#include<iostream>
#include"KListBox.h"

using std::cout;
using std::endl;

void main() {
	KListBox<int> kListBox;

	for (int i = 0; i < 20; ++i) {
		kListBox.Insert(i);
	}

	int iStart = kListBox.SetDisplayStart(15);
	kListBox.SetSelected(17);

	for (KListBox<int>::VITOR itor = kListBox.BeginDisplay(); itor != kListBox.EndDisplay(); ++itor) {
		if (kListBox.IsSelected(iStart))
			cout << "* ";
		else
			cout << "  ";
		cout << "element value = " << (*itor) << endl;
		++iStart;
	}
}
#endif
