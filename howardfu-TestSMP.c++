// --------------------------------
// projects/smp/TestSMP.c++
// Copyright (C) 2011
// Glenn P. Downing
// --------------------------------

/*
To test the program:
    % ls /usr/include/cppunit/
    ...
    HelperMacros.h
    ...
    % locate libcppunit.a
    /usr/lib/libcppunit.a
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestSMP.c++ -o TestSMP.c++.app
    % valgrind TestSMP.c++.app >& TestSMP.c++.out
*/

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <vector>
#include <queue>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "SMP.h"

// -----------
// TestSMP
// -----------

struct TestSMP : CppUnit::TestFixture {
	
    // ----
    // findPairs
    // ----

    	void test_find () {
		using namespace std;
		static const int arr1[] = {1,2};
		vector<int> prefa (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
       		woman a = {1, false, 0, prefa};
        	woman b = {2, false, 0, prefa};
		man c = {1, 0, 0, prefa};
		man d = {2, 0, 0, prefa};

		queue<man> men;
		vector<woman> women;
		vector<man> finalmen (2, c);

		men.push(d);
		men.push(c);
		women.push_back(a);
		women.push_back(b);

		finalmen = findPairs(women, men, finalmen);
	
        	CPPUNIT_ASSERT(finalmen[0].engagedTo == 1);
        	CPPUNIT_ASSERT(finalmen[1].engagedTo == 2);
	}

	void test_find_2() {
		using namespace std;
		static const int arr1[] = {1,2};
		static const int arr2[] = {2,1};
		vector<int> prefa (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
		vector<int> prefb (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
        	woman a = {1, false, 0, prefb};
        	woman b = {2, false, 0, prefa};
		man c = {1, 0, 0, prefa};
		man d = {2, 0, 0, prefa};

		queue<man> men;
		vector<woman> women;
		vector<int> prefm;
		man dummy = {0,0,0,prefm};
		vector<man> finalmen (2, dummy);

		men.push(d);
		men.push(c);
		women.push_back(a);
		women.push_back(b);

		finalmen = findPairs(women, men, finalmen);
	
        	CPPUNIT_ASSERT(finalmen.at(0).engagedTo == 2);
        	CPPUNIT_ASSERT(finalmen.at(1).engagedTo == 1);

	}

	void test_find_3() {
		using namespace std;
		static const int arr1[] = {1,2};
		static const int arr2[] = {2,1};
		vector<int> prefa (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
		vector<int> prefb (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
        	woman a = {0, false, 0, prefb};
        	woman b = {0, false, 0, prefa};
		man c = {0, 0, 0, prefa};
		man d = {0, 0, 0, prefa};

		queue<man> men;
		vector<woman> women;
		vector<man> finalmen;

		finalmen.push_back(c);
		finalmen.push_back(d);
		women.push_back(a);
		women.push_back(b);

		finalmen = findPairs(women, men, finalmen);
	
        	CPPUNIT_ASSERT(finalmen.at(0).engagedTo == 0);
        	CPPUNIT_ASSERT(finalmen.at(1).engagedTo == 0);
	}

    
    // -----
    // printOutput
    // -----

    void test_print () {
	using namespace std;
        static const int arr1[] = {1,2};
	static const int arr2[] = {2,1};
	vector<int> prefa (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	vector<int> prefb (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
	man c = {1, 1, 1, prefa};
	man d = {2, 1, 2, prefb};

	vector<man> men;
	men.push_back(c);
	men.push_back(d);
	std::ostringstream w;
	printOutput(w, men);
        CPPUNIT_ASSERT(w.str() == "1 1\n2 2\n");}
   
    void test_print_2 () {
	using namespace std;
        static const int arr1[] = {1,2,3};
	static const int arr2[] = {2,1,3};
	vector<int> prefa (arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]) );
	vector<int> prefb (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );
	man c = {1, 1, 2, prefa};
	man d = {2, 1, 1, prefb};
	man e = {3, 2, 3, prefb};

	vector<man> men;
	men.push_back(c);
	men.push_back(d);
	men.push_back(e);
	std::ostringstream w;
	printOutput(w, men);
        CPPUNIT_ASSERT(w.str() == "1 2\n2 1\n3 3\n");}

    void test_print_3 () {
	using namespace std;
        std::ostringstream w;
	vector<man> men;
        printOutput(w, men);
        CPPUNIT_ASSERT(w.str() == "");}

    // -----
    // smp_solve
    // -----

    void test_solve () {
        std::istringstream r("1\n2\n1 1 2\n2 1 2\n1 1 2\n2 1 2\n");
        std::ostringstream w;
        smp_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 1\n2 2\n");}

    void test_solve_2() {
        std::istringstream r("1\n2\n1 1 2\n2 1 2\n1 2 1\n2 1 2\n");
        std::ostringstream w;
        smp_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 2\n2 1\n");}

    void test_solve_3() {
        std::istringstream r("0\n999999\n1 1 1\n");
        std::ostringstream w;
        smp_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "");}


    void test_solve_4() {
        std::istringstream r("2\n4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1\n4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1\n");
        std::ostringstream w;
        smp_solve(r, w);
        CPPUNIT_ASSERT(w.str() == "1 3\n2 2\n3 1\n4 4\n1 3\n2 2\n3 1\n4 4\n");
	}


 
    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestSMP);
    CPPUNIT_TEST(test_print);
    CPPUNIT_TEST(test_print_2);
    CPPUNIT_TEST(test_print_3);
    CPPUNIT_TEST(test_solve);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_find);
    CPPUNIT_TEST(test_find_2);
    CPPUNIT_TEST(test_find_3);
    CPPUNIT_TEST_SUITE_END();
};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestSMP.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestSMP::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}
