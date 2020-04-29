#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB3/LAB3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//#define N 4
namespace Floyd
{

	Assert assert;
	TEST_CLASS(Floyd)
	{
	public:
		
		TEST_METHOD(namecity_)
		{
			int i = 0;
			string name ="St Petersburg";
			assert.AreEqual(namecity(i), name);
		}

		TEST_METHOD(floydwarshell_)
		{
			int adjMatrix[][N] =
			{
				{	   0, 10,	  14, 20 },
				{	   20,	   0,	   40, INT_MAX },
				{ INT_MAX, 35,	   0,	   8},
				{ INT_MAX,	  INT_MAX, 13,	   0 }
			};
			int res[N][N] =
			{
				{0, 10, 14, 20},
				{20, 0, 34, 40},
				{55, 35, 0, 8},
				{68, 48, 13, 0}
			};
			int tess = false;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (res[i][j] == (adjMatrix[i][j]))
					{
						tess = true;
					};
				}
			}
			assert.IsTrue(tess);
		}
		TEST_METHOD(namecity_err)
		{
			int i = 0;
			string name = "Petersburg";
			try
			{
				namecity(i);
			}
			catch (invalid_argument error)
			{
				assert.AreEqual(error.what(), "invalid city name");
			}

		}

	};
}
