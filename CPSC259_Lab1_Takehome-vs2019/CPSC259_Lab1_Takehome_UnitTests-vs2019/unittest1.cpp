#include "CppUnitTest.h"

/*
We need to 'include' the header file(s) for the project we are testing
*/

extern "C" {
#include "tide_analyzer.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TakeHomeUnitTests
{
  TEST_CLASS(UnitTest1)
  {
  public:

    TEST_METHOD(TestMethod1)
    {
      // TODO: Your test code here
    }

  };
}