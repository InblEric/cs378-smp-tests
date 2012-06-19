#include <iostream>
#include <sstream>
#include <string>

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h" // TestFixture
#include "cppunit/TextTestRunner.h" // TextTestRunner

#include "SMP.h"

// g++ -ansi -pedantic -lcppunit -ldl -Wall TestSMP.c++ -o TestSMP.c++.app
// valgrind TestSMP.c++.app >& TestSMP.c++.out


// -------
// TestSMP
// -------

struct TestSMP : CppUnit::TestFixture {
	// ------
	// Person
	// ------

	void test_Person_1 () {
		Person p;
		unsigned int expected_size = 0;
		int expected_engaged = 0;
		int expected_current = 0;
		CPPUNIT_ASSERT(p.list.size() == expected_size);
		CPPUNIT_ASSERT(p.engaged == expected_engaged);
		CPPUNIT_ASSERT(p.current == expected_current);
	}

	void test_Person_2 () {
		Person p;
		p.list.push_back(1);
		p.list.push_back(4);
		p.list.push_back(3);
		p.list.push_back(1);
		p.list.push_back(2);
		p.engaged = 1;
		p.current = 3;
		unsigned int expected_size = 5;
		int expected_0 = 1;
		int expected_1 = 4;
		int expected_2 = 3;
		int expected_3 = 1;
		int expected_4 = 2;
		int expected_engaged = 1;
		int expected_current = 3;
		int expected_current_target = 1;
		CPPUNIT_ASSERT(p.list.size() == expected_size);
		CPPUNIT_ASSERT(p.list[0] == expected_0);
		CPPUNIT_ASSERT(p.list[1] == expected_1);
		CPPUNIT_ASSERT(p.list[2] == expected_2);
		CPPUNIT_ASSERT(p.list[3] == expected_3);
		CPPUNIT_ASSERT(p.list[4] == expected_4);
		CPPUNIT_ASSERT(p.engaged == expected_engaged);
		CPPUNIT_ASSERT(p.current = expected_current);
		CPPUNIT_ASSERT(p.list[p.current] == expected_current_target);
	}

	void test_Person_3 () {
		Person p;
		p.list.push_back(2);
		p.list.push_back(2);
		p.list.push_back(1);
		p.list.push_back(3);
		p.list.push_back(4);
		p.engaged = 1;
		p.current = 2;
		unsigned int expected_size = 5;
		int expected_0 = 2;
		int expected_1 = 2;
		int expected_2 = 1;
		int expected_3 = 3;
		int expected_4 = 4;
		int expected_engaged = 1;
		int expected_current = 2;
		int expected_current_target = 1;
		CPPUNIT_ASSERT(p.list.size() == expected_size);
		CPPUNIT_ASSERT(p.list[0] == expected_0);
		CPPUNIT_ASSERT(p.list[1] == expected_1);
		CPPUNIT_ASSERT(p.list[2] == expected_2);
		CPPUNIT_ASSERT(p.list[3] == expected_3);
		CPPUNIT_ASSERT(p.list[4] == expected_4);
		CPPUNIT_ASSERT(p.engaged == expected_engaged);
		CPPUNIT_ASSERT(p.current == expected_current);
		CPPUNIT_ASSERT(p.list[p.current] == expected_current_target);
	}
	
	// ---------
	// Test_Case
	// ---------
	
	void test_Test_Case_1 () {
		Test_Case tc;
		unsigned int expected_num_marriages = 0;
		unsigned int expected_size_fm = 0;
		unsigned int expected_size_fw = 0;
		unsigned int expected_size_m = 0;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_size_fm);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_size_fw);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_size_m);
	}
	
	void test_Test_Case_2 () {
		Test_Case tc;
		tc.num_marriages = 4;
		Person pm1;
		pm1.list.push_back(2);
		Person pm2;
		pm2.list.push_back(1);
		Person pm3;
		pm3.list.push_back(3);
		Person pm4;
		pm4.list.push_back(4);
		Person pw1;
		pw1.list.push_back(2);
		Person pw2;
		pw2.list.push_back(1);
		Person pw3;
		pw3.list.push_back(3);
		Person pw4;
		pw4.list.push_back(4);
		tc.free_men.push_back(pm1);
		tc.free_men.push_back(pm2);
		tc.free_men.push_back(pm3);
		tc.free_men.push_back(pm4);
		tc.free_women.push_back(pw1);
		tc.free_women.push_back(pw2);
		tc.free_women.push_back(pw3);
		tc.free_women.push_back(pw4);
		unsigned int expected_num_marriages = 4;
		unsigned int expected_size_fm = 4;
		int expected_fm0_0 = 2;
		int expected_fm1_0 = 1;
		int expected_fm2_0 = 3;
		int expected_fm3_0 = 4;
		unsigned int expected_size_fw = 4;
		int expected_fw0_0 = 2;
		int expected_fw1_0 = 1;
		int expected_fw2_0 = 3;
		int expected_fw3_0 = 4;
		unsigned int expected_size_m = 0;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_size_fm);
		CPPUNIT_ASSERT(tc.free_men[0].list[0] == expected_fm0_0);
		CPPUNIT_ASSERT(tc.free_men[1].list[0] == expected_fm1_0);
		CPPUNIT_ASSERT(tc.free_men[2].list[0] == expected_fm2_0);
		CPPUNIT_ASSERT(tc.free_men[3].list[0] == expected_fm3_0);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_size_fw);
		CPPUNIT_ASSERT(tc.free_women[0].list[0] == expected_fw0_0);
		CPPUNIT_ASSERT(tc.free_women[1].list[0] == expected_fw1_0);
		CPPUNIT_ASSERT(tc.free_women[2].list[0] == expected_fw2_0);
		CPPUNIT_ASSERT(tc.free_women[3].list[0] == expected_fw3_0);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_size_m);
		pair<Person, Person> marriage_0 (tc.free_men.back(), tc.free_women.back());
		tc.marriages.push_back(marriage_0);
		expected_size_m = 1;
		int expected_m0_first = 4;
		int expected_m0_second = 4;
		CPPUNIT_ASSERT(tc.marriages.size() == expected_size_m);
		CPPUNIT_ASSERT(tc.marriages[0].first.list[0] == expected_m0_first);
		CPPUNIT_ASSERT(tc.marriages[0].second.list[0] == expected_m0_second);
	}
	
	void test_Test_Case_3 () {
		Test_Case tc;
		tc.num_marriages = 5;
		Person pm1, pm2, pm3, pm4, pm5, pw1, pw2, pw3, pw4, pw5;
		pm1.list.push_back(1);
		pm2.list.push_back(2);
		pm3.list.push_back(3);
		pm4.list.push_back(4);
		pm5.list.push_back(5);
		pw1.list.push_back(1);
		pw2.list.push_back(2);
		pw3.list.push_back(3);
		pw4.list.push_back(4);
		pw5.list.push_back(5);
		pair<Person, Person> e1(pm1, pw1);
		tc.marriages.push_back(e1);
		pair<Person, Person> e2(pm2, pw2);
		tc.marriages.push_back(e2);
		pair<Person, Person> e3(pm3, pw3);
		tc.marriages.push_back(e3);
		pair<Person, Person> e4(pm4, pw4);
		tc.marriages.push_back(e4);
		pair<Person, Person> e5(pm5, pw5);
		tc.marriages.push_back(e5);
		unsigned int expected_num_marriages = 5;
		unsigned int expected_fm_size = 0;
		unsigned int expected_fw_size = 0;
		unsigned int expected_m_size = 5;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_fm_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_fw_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_m_size);
		CPPUNIT_ASSERT(tc.marriages[0].first.list[0] == pm1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[1].first.list[0] == pm2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].first.list[0] == pm3.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].first.list[0] == pm4.list[0]);
		CPPUNIT_ASSERT(tc.marriages[4].first.list[0] == pm5.list[0]);
		CPPUNIT_ASSERT(tc.marriages[0].second.list[0] == pw1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[1].second.list[0] == pw2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].second.list[0] == pw3.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].second.list[0] == pw4.list[0]);
		CPPUNIT_ASSERT(tc.marriages[4].second.list[0] == pw5.list[0]);
		
	}
	

	// --------
	// SMP_Read
	// --------
	
	void test_SMP_read_1 () {
		istringstream s("4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1");
		Test_Case tc;
		SMP_read(tc, s);
		unsigned int expected_num_marriages = 4;
		unsigned int expected_free_men_size = 4;
		unsigned int expected_free_women_size = 4;
		unsigned int expected_marriages_size = 0;
		int expected_fm0_name = 1;
		int expected_fm0_1 = 3;
		int expected_fm0_2 = 2;
		int expected_fm0_3 = 4;
		int expected_fm0_4 = 1;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_free_men_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_free_women_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_marriages_size);
		CPPUNIT_ASSERT(tc.free_men[0].list[0] == expected_fm0_name);
		CPPUNIT_ASSERT(tc.free_men[0].list[1] == expected_fm0_1);
		CPPUNIT_ASSERT(tc.free_men[0].list[2] == expected_fm0_2);
		CPPUNIT_ASSERT(tc.free_men[0].list[3] == expected_fm0_3);
		CPPUNIT_ASSERT(tc.free_men[0].list[4] == expected_fm0_4);
	}
	
	void test_SMP_read_2 () {
		istringstream s("7\n1 3 4 2 1 6 7 5\n2 6 4 2 3 5 1 7\n3 6 3 5 7 2 4 1\n4 1 6 3 2 4 7 5\n5 1 6 5 3 4 7 2\n6 1 7 3 4 5 6 2\n7 5 6 2 4 3 7 1\n1 4 5 3 7 2 6 1\n2 5 6 4 7 3 2 1\n3 1 6 5 4 3 7 2\n4 3 5 6 7 2 4 1\n5 1 7 6 4 3 5 2\n6 6 3 7 5 2 4 1\n7 1 7 4 2 6 5 3");
		Test_Case tc;
		SMP_read(tc, s);
		unsigned int expected_num_marriages = 7;
		unsigned int expected_free_men_size = 7;
		unsigned int expected_free_women_size = 7;
		unsigned int expected_marriages_size = 0;
		int expected_fm0_name = 1;
		int expected_fm0_1 = 4;
		int expected_fm0_2 = 5;
		int expected_fm0_3 = 3;
		int expected_fm0_4 = 7;
		int expected_fm0_5 = 2;
		int expected_fm0_6 = 6;
		int expected_fm0_7 = 1;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_free_men_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_free_women_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_marriages_size);
		CPPUNIT_ASSERT(tc.free_men[0].list[0] == expected_fm0_name);
		CPPUNIT_ASSERT(tc.free_men[0].list[1] == expected_fm0_1);
		CPPUNIT_ASSERT(tc.free_men[0].list[2] == expected_fm0_2);
		CPPUNIT_ASSERT(tc.free_men[0].list[3] == expected_fm0_3);
		CPPUNIT_ASSERT(tc.free_men[0].list[4] == expected_fm0_4);
		CPPUNIT_ASSERT(tc.free_men[0].list[5] == expected_fm0_5);
		CPPUNIT_ASSERT(tc.free_men[0].list[6] == expected_fm0_6);
		CPPUNIT_ASSERT(tc.free_men[0].list[7] == expected_fm0_7);
	}
	
	void test_SMP_read_3 () {
		istringstream s("4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1\n7\n1 3 4 2 1 6 7 5\n2 6 4 2 3 5 1 7\n3 6 3 5 7 2 4 1\n4 1 6 3 2 4 7 5\n5 1 6 5 3 4 7 2\n6 1 7 3 4 5 6 2\n7 5 6 2 4 3 7 1\n1 4 5 3 7 2 6 1\n2 5 6 4 7 3 2 1\n3 1 6 5 4 3 7 2\n4 3 5 6 7 2 4 1\n5 1 7 6 4 3 5 2\n6 6 3 7 5 2 4 1\n7 1 7 4 2 6 5 3");
		Test_Case tc1;
		SMP_read(tc1, s);
		unsigned int expected_num_marriages_1 = 4;
		unsigned int expected_free_men_size_1 = 4;
		unsigned int expected_free_women_size_1 = 4;
		unsigned int expected_marriages_size_1 = 0;
		int expected_fm0_name_1 = 1;
		int expected_fm0_1_1 = 3;
		int expected_fm0_2_1 = 2;
		int expected_fm0_3_1 = 4;
		int expected_fm0_4_1 = 1;
		CPPUNIT_ASSERT(tc1.num_marriages == expected_num_marriages_1);
		CPPUNIT_ASSERT(tc1.free_men.size() == expected_free_men_size_1);
		CPPUNIT_ASSERT(tc1.free_women.size() == expected_free_women_size_1);
		CPPUNIT_ASSERT(tc1.marriages.size() == expected_marriages_size_1);
		CPPUNIT_ASSERT(tc1.free_men[0].list[0] == expected_fm0_name_1);
		CPPUNIT_ASSERT(tc1.free_men[0].list[1] == expected_fm0_1_1);
		CPPUNIT_ASSERT(tc1.free_men[0].list[2] == expected_fm0_2_1);
		CPPUNIT_ASSERT(tc1.free_men[0].list[3] == expected_fm0_3_1);
		CPPUNIT_ASSERT(tc1.free_men[0].list[4] == expected_fm0_4_1);
		Test_Case tc2;
		SMP_read(tc2, s);
		unsigned int expected_num_marriages_2 = 7;
		unsigned int expected_free_men_size_2 = 7;
		unsigned int expected_free_women_size_2 = 7;
		unsigned int expected_marriages_size_2 = 0;
		int expected_fm0_name_2 = 1;
		int expected_fm0_1_2 = 4;
		int expected_fm0_2_2 = 5;
		int expected_fm0_3_2 = 3;
		int expected_fm0_4_2 = 7;
		int expected_fm0_5_2 = 2;
		int expected_fm0_6_2 = 6;
		int expected_fm0_7_2 = 1;
		CPPUNIT_ASSERT(tc2.num_marriages == expected_num_marriages_2);
		CPPUNIT_ASSERT(tc2.free_men.size() == expected_free_men_size_2);
		CPPUNIT_ASSERT(tc2.free_women.size() == expected_free_women_size_2);
		CPPUNIT_ASSERT(tc2.marriages.size() == expected_marriages_size_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[0] == expected_fm0_name_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[1] == expected_fm0_1_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[2] == expected_fm0_2_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[3] == expected_fm0_3_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[4] == expected_fm0_4_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[5] == expected_fm0_5_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[6] == expected_fm0_6_2);
		CPPUNIT_ASSERT(tc2.free_men[0].list[7] == expected_fm0_7_2);
	}
	
	// -----------
	// SMP_arrange 
	// -----------
	
	void test_SMP_arrage_1 () {
		Test_Case tc;
		tc.num_marriages = 1;
		Person pm1, pw1;
		pm1.list.push_back(1);
		pm1.list.push_back(1);
		pw1.list.push_back(1);
		pw1.list.push_back(1);
		tc.free_men.push_back(pm1);
		tc.free_women.push_back(pw1);
		SMP_arrange(tc);
		unsigned int expected_num_marriages = 1;
		unsigned int expected_fm_size = 0;
		unsigned int expected_fw_size = 1;
		unsigned int expected_marriages_size = 2;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_fm_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_fw_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_marriages_size);
		CPPUNIT_ASSERT(tc.marriages[1].first.list[0] == pm1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[1].second.list[0] == pw1.list[0]);
	}
	
	void test_SMP_arrage_2 () {
		Test_Case tc;
		tc.num_marriages = 3;
		Person pm1, pm2, pm3, pw1, pw2, pw3;
		pm1.list.push_back(1);
		pm1.list.push_back(1);
		pm1.list.push_back(2);
		pm1.list.push_back(3);
		pm2.list.push_back(2);
		pm2.list.push_back(1);
		pm2.list.push_back(2);
		pm2.list.push_back(3);
		pm3.list.push_back(3);
		pm3.list.push_back(1);
		pm3.list.push_back(2);
		pm3.list.push_back(3);
		pw1.list.push_back(1);
		pw1.list.push_back(3);
		pw1.list.push_back(2);
		pw1.list.push_back(1);
		pw2.list.push_back(2);
		pw2.list.push_back(3);
		pw2.list.push_back(2);
		pw2.list.push_back(1);
		pw3.list.push_back(3);
		pw3.list.push_back(3);
		pw3.list.push_back(2);
		pw3.list.push_back(1);
		tc.free_men.push_back(pm1);
		tc.free_men.push_back(pm2);
		tc.free_men.push_back(pm3);
		tc.free_women.push_back(pw1);
		tc.free_women.push_back(pw2);
		tc.free_women.push_back(pw3);
		SMP_arrange(tc);
		unsigned int expected_num_marriages = 3;
		unsigned int expected_fm_size = 0;
		unsigned int expected_fw_size = 3;
		unsigned int expected_marriages_size = 4;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_fm_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_fw_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_marriages_size);
		CPPUNIT_ASSERT(tc.marriages[1].first.list[0] == pm1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[1].second.list[0] == pw3.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].first.list[0] == pm2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].second.list[0] == pw2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].first.list[0] == pm3.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].second.list[0] == pw1.list[0]);
	}
	
	void test_SMP_arrage_3 () {
		Test_Case tc;
		tc.num_marriages = 3;
		Person pm1, pm2, pm3, pw1, pw2, pw3;
		pm1.list.push_back(1);
		pm1.list.push_back(1);
		pm1.list.push_back(2);
		pm1.list.push_back(3);
		pm2.list.push_back(2);
		pm2.list.push_back(1);
		pm2.list.push_back(2);
		pm2.list.push_back(3);
		pm3.list.push_back(3);
		pm3.list.push_back(1);
		pm3.list.push_back(2);
		pm3.list.push_back(3);
		pw1.list.push_back(1);
		pw1.list.push_back(1);
		pw1.list.push_back(2);
		pw1.list.push_back(3);
		pw2.list.push_back(2);
		pw2.list.push_back(1);
		pw2.list.push_back(2);
		pw2.list.push_back(3);
		pw3.list.push_back(3);
		pw3.list.push_back(1);
		pw3.list.push_back(2);
		pw3.list.push_back(3);
		tc.free_men.push_back(pm1);
		tc.free_men.push_back(pm2);
		tc.free_men.push_back(pm3);
		tc.free_women.push_back(pw1);
		tc.free_women.push_back(pw2);
		tc.free_women.push_back(pw3);
		SMP_arrange(tc);
		unsigned int expected_num_marriages = 3;
		unsigned int expected_fm_size = 0;
		unsigned int expected_fw_size = 3;
		unsigned int expected_marriages_size = 4;
		CPPUNIT_ASSERT(tc.num_marriages == expected_num_marriages);
		CPPUNIT_ASSERT(tc.free_men.size() == expected_fm_size);
		CPPUNIT_ASSERT(tc.free_women.size() == expected_fw_size);
		CPPUNIT_ASSERT(tc.marriages.size() == expected_marriages_size);
		CPPUNIT_ASSERT(tc.marriages[1].first.list[0] == pm1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[1].second.list[0] == pw1.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].first.list[0] == pm2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[2].second.list[0] == pw2.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].first.list[0] == pm3.list[0]);
		CPPUNIT_ASSERT(tc.marriages[3].second.list[0] == pw3.list[0]);
	}
	
	// ---------
	// SMP_print
	// ---------
	
	void test_SMP_print_1(){
		ostringstream w;
		Test_Case tc;
		tc.num_marriages = 1;
		Person pm1, pw1;
		pm1.list.push_back(1);
		pm1.list.push_back(1);
		pw1.list.push_back(1);
		pw1.list.push_back(1);
		tc.free_men.push_back(pm1);
		tc.free_women.push_back(pw1);
		SMP_arrange(tc);
		SMP_print(tc, w);
		CPPUNIT_ASSERT(w.str() == "1 1\n");
	}
	
	void test_SMP_print_2(){
		ostringstream w;
		Test_Case tc;
		tc.num_marriages = 2;
		Person pm1, pm2, pw1, pw2;
		pm1.list.push_back(1);
		pm1.list.push_back(1);
		pm2.list.push_back(2);
		pm2.list.push_back(2);
		pw1.list.push_back(1);
		pw1.list.push_back(1);
		pw2.list.push_back(2);
		pw2.list.push_back(2);
		tc.free_men.push_back(pm1);
		tc.free_men.push_back(pm2);
		tc.free_women.push_back(pw1);
		tc.free_women.push_back(pw2);
		SMP_arrange(tc);
		SMP_print(tc, w);
		CPPUNIT_ASSERT(w.str() == "1 1\n2 2\n");
	}
	
	void test_SMP_print_3(){
		ostringstream w;
		Test_Case tc;
		tc.num_marriages = 3;
		Person pm1, pm2, pm3, pw1, pw2, pw3;
		pm1.list.push_back(1);
		pm1.list.push_back(3);
		pm1.list.push_back(2);
		pm1.list.push_back(1);
		pm2.list.push_back(2);
		pm2.list.push_back(3);
		pm2.list.push_back(2);
		pm2.list.push_back(1);
		pm3.list.push_back(3);
		pm3.list.push_back(3);
		pm3.list.push_back(2);
		pm3.list.push_back(1);
		pw1.list.push_back(1);
		pw1.list.push_back(3);
		pw1.list.push_back(2);
		pw1.list.push_back(1);
		pw2.list.push_back(2);
		pw2.list.push_back(3);
		pw2.list.push_back(2);
		pw2.list.push_back(1);
		pw3.list.push_back(3);
		pw3.list.push_back(3);
		pw3.list.push_back(2);
		pw3.list.push_back(1);
		tc.free_men.push_back(pm1);
		tc.free_men.push_back(pm2);
		tc.free_men.push_back(pm3);
		tc.free_women.push_back(pw1);
		tc.free_women.push_back(pw2);
		tc.free_women.push_back(pw3);
		SMP_arrange(tc);
		SMP_print(tc, w);
		CPPUNIT_ASSERT(w.str() == "1 1\n2 2\n3 3\n");
	}
	
	// ---------
	// SMP_solve
	// ---------
	
	void test_SMP_solve_1(){
		istringstream r("1\n4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1");
        	ostringstream w;
        	SMP_solve(r, w);
        	CPPUNIT_ASSERT(w.str() == "1 3\n2 2\n3 1\n4 4\n");
	}
	
	void test_SMP_solve_2(){
		istringstream r("2\n4\n1 4 3 1 2\n2 2 1 3 4\n3 1 3 4 2\n4 4 3 1 2\n1 3 2 4 1\n2 2 3 1 4\n3 3 1 2 4\n4 3 2 4 1\n7\n1 3 4 2 1 6 7 5\n2 6 4 2 3 5 1 7\n3 6 3 5 7 2 4 1\n4 1 6 3 2 4 7 5\n5 1 6 5 3 4 7 2\n6 1 7 3 4 5 6 2\n7 5 6 2 4 3 7 1\n1 4 5 3 7 2 6 1\n2 5 6 4 7 3 2 1\n3 1 6 5 4 3 7 2\n4 3 5 6 7 2 4 1\n5 1 7 6 4 3 5 2\n6 6 3 7 5 2 4 1\n7 1 7 4 2 6 5 3");
        	ostringstream w;
        	SMP_solve(r, w);
        	CPPUNIT_ASSERT(w.str() == "1 3\n2 2\n3 1\n4 4\n1 4\n2 5\n3 1\n4 3\n5 7\n6 6\n7 2\n");
	}
	
	void test_SMP_solve_3(){
		istringstream r("1\n7\n1 3 4 2 1 6 7 5\n2 6 4 2 3 5 1 7\n3 6 3 5 7 2 4 1\n4 1 6 3 2 4 7 5\n5 1 6 5 3 4 7 2\n6 1 7 3 4 5 6 2\n7 5 6 2 4 3 7 1\n1 4 5 3 7 2 6 1\n2 5 6 4 7 3 2 1\n3 1 6 5 4 3 7 2\n4 3 5 6 7 2 4 1\n5 1 7 6 4 3 5 2\n6 6 3 7 5 2 4 1\n7 1 7 4 2 6 5 3");
		stringstream w;
        	SMP_solve(r, w);
        	CPPUNIT_ASSERT(w.str() == "1 4\n2 5\n3 1\n4 3\n5 7\n6 6\n7 2\n");
	}

	// -----
	// suite
	// -----
	
	CPPUNIT_TEST_SUITE(TestSMP);
	CPPUNIT_TEST(test_Person_1);
	CPPUNIT_TEST(test_Person_2);
	CPPUNIT_TEST(test_Person_3);
	CPPUNIT_TEST(test_Test_Case_1);
	CPPUNIT_TEST(test_Test_Case_2);
	CPPUNIT_TEST(test_Test_Case_3);
	CPPUNIT_TEST(test_SMP_read_1);
	CPPUNIT_TEST(test_SMP_read_2);
	CPPUNIT_TEST(test_SMP_read_3);
	CPPUNIT_TEST(test_SMP_arrage_1);
	CPPUNIT_TEST(test_SMP_arrage_2);
	CPPUNIT_TEST(test_SMP_arrage_3);
	CPPUNIT_TEST(test_SMP_print_1);
	CPPUNIT_TEST(test_SMP_print_2);
	CPPUNIT_TEST(test_SMP_print_3);
	CPPUNIT_TEST(test_SMP_solve_1);
	CPPUNIT_TEST(test_SMP_solve_2);
	CPPUNIT_TEST(test_SMP_solve_3);
	CPPUNIT_TEST_SUITE_END();
};
	
// ----
// main
// ----
	
int main () {
	using namespace std;
	ios_base::sync_with_stdio(false);
	cout << "TestSMP.c++" << endl;
	
	CppUnit::TextTestRunner tr;
	tr.addTest(TestSMP::suite());
	tr.run();
	
	cout << "Done." << endl;
	return 0;
}
