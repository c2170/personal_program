#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/head.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Line m, n;
			m.A = 3;	m.B = 7;	m.C = 10;
			n.A = 6;	n.B = 14;	n.C = 15;
			int x = isParallel(m, n);
			//int x = 1;
			Assert::AreEqual(x, 1);
		}
	};
}
