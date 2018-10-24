#include "Program.h"

int main()
{
	std::unique_ptr<Program> p(new Program());
	p->Run();

	return 0;
}