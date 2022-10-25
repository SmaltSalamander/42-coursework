/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:44:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 18:25:19 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include <list>
#ifdef STD
# include <map>
# include <vector>
# include <stack>
# include <set>
namespace ft = std;
#else
# include "vector.hpp"
# include "pair.hpp"
# include "map.hpp"
# include "stack.hpp"
#endif

void vectortest();
void pairtest();
void testvectorreviter();
void maptest();
void testmapfind();
void testmapinsert();
void testmapreviter();
void stacktest();
void constructor_std_test();

int main(int argc, char **argv)
{
	std::string 				cont_ns;

	#ifdef STD
		cont_ns = "STD";
	#else
		cont_ns = "FT";
	#endif
	if (argc == 1)
	{
		vectortest();
		pairtest();
		maptest();
		stacktest();
	}
	else
	{
		std::string	tests(argv[1]);
		if (tests.find('v') != std::string::npos)
			vectortest();
		if (tests.find('p') != std::string::npos)
			pairtest();
		if (tests.find('m') != std::string::npos)
			maptest();
		if (tests.find('s') != std::string::npos)
			stacktest();
	}
	return(0);
}

void vectortest()
{
	ft::vector<int>				wa2;

	wa2.push_back(5);
	wa2.push_back(5);
	wa2.push_back(7);
	ft::vector<int>::iterator	test2(wa2.end());
	ft::vector<int>::reverse_iterator	testrev(wa2.end());
	--test2;
	std::cout << *test2 << std::endl;
	test2 = wa2.begin();
	*test2 = 8;
	std::cout << "Test before insert: " << std::endl;
	while (test2 != wa2.end())
		std::cout << *test2++ << std::endl;
	std::cout << "Test before insert end" << std::endl;
	std::cout << "Testing insert " << ": " << std::endl;
	wa2.insert(wa2.begin() + 1, 42);
	test2 = wa2.begin();
	while (test2 != wa2.end())
		std::cout << *test2++ << std::endl;
	std::cout << "Testing insert (fill) " << ": " << std::endl;
	wa2.insert(wa2.begin() + 1, 7,  21);
	test2 = wa2.begin();
	while (test2 != wa2.end())
		std::cout << *test2++ << std::endl;	
	std::cout << "Testing insert (iters) " << ": " << std::endl;
	ft::vector<int>	insertest2(30, 84);
	wa2.insert(wa2.begin() + 1, insertest2.begin() + 2,  insertest2.begin() + 4);
	test2 = wa2.begin();
	while (test2 != wa2.end())
		std::cout << *test2++ << std::endl;
	ft::vector<int>				testConstr(41, 54);
	std::cout << "Testing constructor (fill) " << ": " << std::endl;
	test2 = testConstr.begin();
	while (test2 != testConstr.end())
		std::cout << *test2++ << std::endl;
	for (int i = 3; i < 11; i++)
	{
		*(testConstr.begin() + i) = i - 2;
	}
	std::cout << "Testing constructor (iter range) " << ": " << std::endl;
	ft::vector<int>				testConstrIters(testConstr.begin() + 3, testConstr.begin() + 10);
	test2 = testConstrIters.begin();
	while (test2 != testConstrIters.end())
		std::cout << *test2++ << std::endl;
	try
	{
		testConstr.at(100);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << " was caught" << std::endl;
	}
	ft::vector<int>				testCpyConstr(testConstrIters);
	std::cout << "Testing constructor (copy) " << ": " << std::endl;
	test2 = testCpyConstr.begin();
	while (test2 != testCpyConstr.end())
		std::cout << *test2++ << std::endl;
	std::cout << "Vector test end" << std::endl;
    std::cout << "Test const_iterators" << std::endl;
	ft::vector<int>::const_iterator			testconst(wa2.end());
	if (testconst == test2)
		std::cout << "blah";
	testconst = wa2.begin();
	std::cout << *testconst << '\n';
	ft::vector<int>				contesting;
	contesting.assign(10, 13);
	ft::vector<int>::iterator	checking(contesting.begin());
	while (checking != contesting.end())
	{
		std::cout << *checking << std::endl;
		++checking;
	}
	ft::vector<int>testassign(7);
	testassign.assign(4, 3);
	std::cout << "Size of testassign: " << testassign.size() << std::endl;
	ft::vector<int>::iterator it = testassign.begin(), ite = testassign.end();
	std::cout << "len: " << (ite - it) << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	ft::vector<std::string> vct(10);
	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);
	std::cout << "size: " << vct.size() << " capacity :" << vct.capacity() << std::endl;
	std::cout << "Test before erasure" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}

	vct.erase(vct.begin() + 2);
	std::cout << "Erase 3rd:" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	vct.erase(vct.begin());
	std::cout << "Erase 1st:" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	vct.erase(vct.end() - 1);
	std::cout << "Erase last:" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	std::cout << "size: " << vct.size() << " capacity :" << vct.capacity() << std::endl;
	vct.erase(vct.begin(), vct.begin() + 3);
	std::cout << "Erase first 3:" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	std::cout << "Insert 3rd:" << std::endl;
	ft::vector<std::string>::iterator insertret = vct.insert(vct.begin() + 2, "trying");
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	std::cout << *insertret << std::endl;
	insertret = 1 + insertret;
	std::cout << "Comparison check:" << std::endl;
	ft::vector<std::string> vct2(vct);
	if (vct2 == vct)
		std::cout << "Comparison returned true (expected)" << std::endl;
	else
		std::cout << "Something went wrong" << std::endl;
	if (vct2 >= vct)
		std::cout << "Comparison returned true (expected)" << std::endl;
	else
		std::cout << "Something went wrong" << std::endl;
	if (vct2 <= vct)
		std::cout << "Comparison returned true (expected)" << std::endl;
	else
		std::cout << "Something went wrong" << std::endl;
	if (vct2 > vct)
		std::cout << "> Comparison returned true (wrong)" << std::endl;
	else
		std::cout << "> Comparison returned false (expected)" << std::endl;
	if (vct2 < vct)
		std::cout << "< Comparison returned true (wrong)" << std::endl;
	else
		std::cout << "< Comparison returned false (expected)" << std::endl;
	vct2.push_back("addition");
	vct[1] = "5";
	if (vct2 > vct)
		std::cout << "> Comparison returned true (expected)" << std::endl;
	else
		std::cout << "> Comparison returned false (wrong)" << std::endl;
	if (vct2 < vct)
		std::cout << "< Comparison returned true (wrong)" << std::endl;
	else
		std::cout << "< Comparison returned false (expected)" << std::endl;
	if (vct2 >= vct)
		std::cout << ">= Comparison returned true (expected)" << std::endl;
	else
		std::cout << ">= Comparison returned false (wrong)" << std::endl;
	if (vct2 <= vct)
		std::cout << "<= Comparison returned true (wrong)" << std::endl;
	else
		std::cout << "<= Comparison returned true (expected)" << std::endl;
	std::cout	<< "Deeper reverse iterator test" << std::endl;
	std::cout	<< "Check contents" << std::endl;
	for (ft::vector<std::string>::iterator wa = vct.begin(); wa != vct.end(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	std::cout	<< "Test rev iter" << std::endl;
	std::cout	<< "Construct 2" << std::endl;
	ft::vector<std::string>::iterator	basetest = vct.begin() + 2;
	ft::vector<std::string>::reverse_iterator basetest2(basetest);
	std::cout	<< "Test dereferencing base iter and rev" << std::endl;
	std::cout	<< *basetest << " and " << *basetest2 << std::endl;
	ft::vector<std::string>::reverse_iterator revingtest = vct.rend();
	--revingtest;
	ft::vector<std::string>::iterator	step1 = revingtest.base();
	std::string	step2 = *(step1);
	std::cout << step2 << std::endl;
	--revingtest;
	std::cout << *revingtest.base() << std::endl;
	std::cout << *(revingtest - 2) << std::endl;
	std::cout	<< "Iter through all" << std::endl;
	for (ft::vector<std::string>::reverse_iterator wa = vct.rbegin(); wa != vct.rend(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	revingtest[0] = "qwa";
	std::cout << *(revingtest) << std::endl;
	std::cout	<< "Iter through all" << std::endl;
	for (ft::vector<std::string>::reverse_iterator wa = vct.rbegin(); wa != vct.rend(); wa++)
	{
		std::cout << *wa << std::endl;
	}
	step1 = vct.end();
	revingtest += 1;
	ft::vector<std::string> vctcomptest(vct);
	std::cout << (vct != vctcomptest) << std::endl;
	std::cout << (vct == vctcomptest) << std::endl;
	testvectorreviter();
	constructor_std_test();
}

void testvectorreviter()
{
	std::cout << "Test vector rev iter" << std::endl;
	ft::vector<int>		test;
	for (int i = 0; i < 10; i++)
		test.push_back(i * 3);
	ft::vector<int>::iterator	iter1, iter2;

	iter1 = test.begin();
	iter2 = test.begin() + 2;
	std::cout << iter1 - iter2 << std::endl;
	ft::vector<int>::reverse_iterator	reviter1, reviter2;
	iter1.base();
	ft::map<int, char>::iterator	basetest;
}


void constructor_std_test()
{
	ft::vector<int> v;
	ft::vector<int> vector(3, 3);
	ft::vector<int> tmp(1000 * 3, 4);
	ft::vector<int> tmp2(tmp.begin(), tmp.end());
	v.push_back(tmp2.size());
	v.push_back(tmp2.capacity());
	for (size_t i = 0; i < tmp.size(); ++i)
		v.push_back(tmp2[i]);
	std::cout << "Size: " << v.size() << " Capacity: " << v.capacity() << std::endl;
}

void pairtest()
{
	std::cout << "Pair testing" << std::endl;
	ft::pair<int, char> a_pair(5, 'b');
	ft::pair<int, char> b_pair;
	ft::pair<int, char> c_pair(a_pair);
	std::cout << c_pair.first << " " << c_pair.second << std::endl;
	ft::make_pair(42, "Wolfsburg");
	std::cout << c_pair.first << " " << c_pair.second << std::endl;
	ft::pair<char, int>	testpair('g', 3);
	ft::pair<char, int>	testpair2('g', 4);
	if (testpair >= testpair2)
		std::cout << "False" << std::endl;
	else
		std::cout << "True" << std::endl;
	if (testpair <= testpair2)
		std::cout << "False" << std::endl;
	else
		std::cout << "True" << std::endl;
	if (testpair < testpair2)
		std::cout << "False" << std::endl;
	else
		std::cout << "True" << std::endl;
	if (testpair != testpair2)
		std::cout << "False" << std::endl;
	else
		std::cout << "True" << std::endl;
}

void maptest()
{
	std::cout << "Testing map " << ": " << std::endl;
	ft::map<int, std::string>	maptest;
	ft::pair<int, std::string>	testpair3(3922, "why");
	maptest.insert(testpair3);
	maptest.insert(ft::pair<int, std::string>(42, "WOB"));
	maptest.insert(ft::pair<int, std::string>(30, "Thir"));
	maptest.insert(ft::pair<int, std::string>(82, "Eig"));
	ft::map<int, std::string>::iterator mapiter;
	std::cout << maptest[42] << std::endl;
	mapiter = maptest.begin();
	std::cout << "Iterator test: " << mapiter->first << " and " << mapiter->second << std::endl;
	ft::map<int, std::string>::iterator mapiter2;
	ft::map<char,int> mymap;
	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;
  // show content:
  	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
	ft::map<int, int>	testingmap;
	testingmap[13] = 4;
	testingmap[7] = 2;
	testingmap[1] = 1;
	testingmap[9] = 3;
	testingmap[15] = 5;
	testingmap[14] = 51;
	testingmap[17] = 6;
	for (ft::map<int,int>::iterator it=testingmap.begin(); it!=testingmap.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	ft::map<int,int>::iterator testingremoval = testingmap.begin();
	++testingremoval;
	testingmap.erase(testingremoval);
	std::cout << "Check after deletion" << std::endl;
	testingremoval = testingmap.begin();
	while (testingremoval != testingmap.end())
	{
		std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
		++testingremoval;
	}
	std::cout << "Testing find: " << std::endl;
	testingremoval = testingmap.find(15);
	std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
	testingremoval = testingmap.find(101);
	std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
	--testingremoval;
	std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
	std::cout << "Removing last: " << std::endl;
	testingremoval = testingmap.find(15);
	testingmap.erase(17);
	std::cout << "Test iter validity" << std::endl;
	std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
	testingremoval = testingmap.begin();
	while (testingremoval != testingmap.end())
	{
		std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
		++testingremoval;
	}
	std::cout << "Removing first: " << std::endl;
	testingmap.erase(1);
	testingremoval = testingmap.begin();
	while (testingremoval != testingmap.end())
	{
		std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
		++testingremoval;
	}
	std::cout << "Test lower bound: " << std::endl;
	testingremoval = testingmap.lower_bound(16);
	std::cout << testingremoval->first << " => " << testingremoval->second << '\n';
	std::cout << "Test equal range: " << std::endl;
	ft::pair<ft::map<int,int>::iterator, ft::map<int,int>::iterator> pairange = testingmap.equal_range(13);
	std::cout << pairange.first->first << " => " << pairange.second->first << '\n';
	std::cout << "Testing const_iterators: " << std::endl;
	ft::map<int, std::string>::const_iterator	coniter(maptest.begin());
	coniter = (maptest.begin());
	if (maptest.value_comp()(ft::make_pair<int, std::string>(4, "42"), ft::make_pair<int, std::string>(7, "84")) == true)
		std::cout << "true" << std::endl;
	maptest.value_comp()(*(maptest.begin()), *(++(maptest.begin())));
	maptest.value_comp()(*(coniter), *(coniter));
	testmapfind();
	testmapinsert();
	testmapreviter();
}

void testmapfind()
{
	ft::map<int, char>	mapp;
	mapp[0] = 'a';
	mapp[-3] = 'Z';
	mapp.count(-1);
}

void testmapinsert()
{
	ft::map<int, char>	mapp;
	mapp.insert(ft::make_pair<int, char>(123, 's'));
	mapp.insert(ft::make_pair<int, char>(-3, 'z'));
	ft::map<int, char>::iterator strmap(mapp.begin());
	mapp.insert(strmap, ft::make_pair<int, char>(170, 'p'));
	for (ft::map<int, char>::iterator st = mapp.begin(); st != mapp.end(); st++)
	{
		std::cout << st->first << ": " << st->second << std::endl;
	}
}

void testmapreviter()
{
	std::cout << "Testing iterators" << std::endl;
	ft::map<int, char>	mapp;
	for (int i = 1; i < 10; i++)
		mapp.insert(ft::make_pair<int, char>(i, i + '0'));
	ft::map<int, char>::reverse_iterator	test;
	ft::map<int, char>::iterator	normal;
	normal = mapp.begin();
	test = mapp.rend();
	--test;
	std::cout << normal->first << std::endl;
	std::cout << test->first << std::endl;
	for (ft::map<int, char>::reverse_iterator st = mapp.rbegin(); st != mapp.rend(); st++)
	{
		std::cout << st->first << ": " << st->second << std::endl;
	}
}

void stacktest()
{
	std::cout << "Testing Stacks" << std::endl;
	ft::stack<int, ft::vector<int> >	a;
	ft::vector<int> b;
	a.push(42);
	b.push_back(42);
	for (int i = 0; i < 10; i++)
	{
		a.push(i + 2 * 3);
		b.push_back(i + 2 * 3);
	}
	ft::stack<int, ft::vector<int> >	c(b);
	std::cout << "Comp: " << (a == c) << std::endl;
	ft::stack<int, std::list<char> >	teststd;
	int i = 11;
	while (i)
	{
		std::cout << a.top() << std::endl;
		a.pop();
		--i;
	}
}
