// -------------------------------
// Joe Peacock
// CS 378 Project 2
// SMP
// 6/18/12
//
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

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TextTestRunner.h"          // TextTestRunner

#include "SMP.h"

// -----------
// TestCollatz
// -----------

struct TestSMP : CppUnit::TestFixture {

    // -----
    // solve  (only one method to test)
    // -----

    //seemed like an interesting case - everyone has the same prefs list
    void test_solve_1 () {
        std::istringstream r("1\n5\n1 1 2 3 4 5\n2 1 2 3 4 5\n3 1 2 3 4 5\n4 1 2 3 4 5\n5 1 2 3 4 5\n1 1 2 3 4 5\n2 1 2 3 4 5\n3 1 2 3 4 5\n4 1 2 3 4 5\n5 1 2 3 4 5");
        std::ostringstream w;
        std::streambuf *buf, *bak;
        bak = cout.rdbuf();
        buf = w.rdbuf();
        cout.rdbuf(buf);
        
        smp_solve(r);
        
        cout.rdbuf(bak);
        CPPUNIT_ASSERT(w.str() == "1 1\n2 2\n3 3\n4 4\n5 5\n");}
	
	//men and women have opposite lists
	void test_solve_2 () {
        std::istringstream r("1\n5\n1 1 2 3 4 5\n2 1 2 3 4 5\n3 1 2 3 4 5\n4 1 2 3 4 5\n5 1 2 3 4 5\n1 5 4 3 2 1\n2 5 4 3 2 1\n3 5 4 3 2 1\n4 5 4 3 2 1\n5 5 4 3 2 1");
        std::ostringstream w;
        std::streambuf *buf, *bak;
        bak = cout.rdbuf();
        buf = w.rdbuf();
        cout.rdbuf(buf);
        
        smp_solve(r);
        
        cout.rdbuf(bak);
        CPPUNIT_ASSERT(w.str() == "1 5\n2 4\n3 3\n4 2\n5 1\n");}
        
        //testing a trivial case: only one pair
    void test_solve_3 () {
        std::istringstream r("1\n1\n1 1\n1 1");
        std::ostringstream w;
        std::streambuf *buf, *bak;
        bak = cout.rdbuf();
        buf = w.rdbuf();
        cout.rdbuf(buf);
        
        smp_solve(r);
        
        cout.rdbuf(bak);
        CPPUNIT_ASSERT(w.str() == "1 1\n");}
   
        //changing input order should still work 
    void test_solve_4 () {
        std::istringstream r("1\n5\n5 1 2 3 4 5\n4 1 2 3 4 5\n3 1 2 3 4 5\n2 1 2 3 4 5\n1 1 2 3 4 5\n5 5 4 3 2 1\n4 5 4 3 2 1\n3 5 4 3 2 1\n2 5 4 3 2 1\n1 5 4 3 2 1");
        std::ostringstream w;
        std::streambuf *buf, *bak;
        bak = cout.rdbuf();
        buf = w.rdbuf();
        cout.rdbuf(buf);
        
        smp_solve(r);
        
        cout.rdbuf(bak);
        CPPUNIT_ASSERT(w.str() == "1 5\n2 4\n3 3\n4 2\n5 1\n");}
        
        //adding extra whitespace shouldn't hurt anything 
    void test_solve_5 () {
        std::istringstream r("     1  \n5\n5            1 2 3 4 5\n4 1 2 3 4 5\n3 1 2           3 4 5\n2 1 2 3 4 5\n1 1 2 3 4 5\n5 5 4 3 2 1\n4 5 4 3 2 1\n3 5 4 3 2 1\n2 5 4 3 2 1\n1 5 4 3 2 1");
        std::ostringstream w;
        std::streambuf *buf, *bak;
        bak = cout.rdbuf();
        buf = w.rdbuf();
        cout.rdbuf(buf);
        
        smp_solve(r);
        
        cout.rdbuf(bak);
        CPPUNIT_ASSERT(w.str() == "1 1\n2 4\n3 3\n4 2\n5 1\n");}
    
    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestSMP);
    
    CPPUNIT_TEST(test_solve_1);
    CPPUNIT_TEST(test_solve_2);
    CPPUNIT_TEST(test_solve_3);
    CPPUNIT_TEST(test_solve_4);
    CPPUNIT_TEST(test_solve_5);
    
    CPPUNIT_TEST_SUITE_END();};

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
