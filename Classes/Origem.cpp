#include <iostream>
#include "GradeBook.h"

using namespace std;

int main()
{
	GradeBook myGradeBook1("Teste 1 de classe");
	GradeBook myGradeBook2("Teste 2 de classe");

	cout << "Classe1=" << myGradeBook1.getCourseName() << endl;
	cout << "Classe2=" << myGradeBook2.getCourseName() << endl;
}