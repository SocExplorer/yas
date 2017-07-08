
// Copyright (c) 2010-2017 niXman (i dot nixman dog gmail dot com). All
// rights reserved.
//
// This file is part of YAS(https://github.com/niXman/yas) project.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef __yas__tests__base__include__boost_cont_flat_multiset_hpp
#define __yas__tests__base__include__boost_cont_flat_multiset_hpp

/***************************************************************************/

template<typename archive_traits>
bool boost_cont_flat_multiset_test(std::ostream &log, const char *archive_type, const char *test_name) {
	boost::container::flat_multiset<int> set1, set2;
	set1.emplace(0);
	set1.emplace(1);
	set1.emplace(2);
	set1.emplace(3);
	set1.emplace(4);
	set1.emplace(5);
	set1.emplace(6);
	set1.emplace(7);
	set1.emplace(8);
	set1.emplace(9);

	typename archive_traits::oarchive oa;
	archive_traits::ocreate(oa, archive_type);
	oa & YAS_OBJECT_NVP("obj", ("set", set1));

	typename archive_traits::iarchive ia;
	archive_traits::icreate(ia, oa, archive_type);
	ia & YAS_OBJECT_NVP("obj", ("set", set2));

	if ( set1.size() != 10 || set2.size() != 10 || set1 != set2 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	boost::container::flat_multiset<std::string> set3, set4;
	set3.emplace("1");
	set3.emplace("2");
	set3.emplace("3");

	typename archive_traits::oarchive oa2;
	archive_traits::ocreate(oa2, archive_type);
	oa2 & YAS_OBJECT_NVP("obj", ("set", set3));

	typename archive_traits::iarchive ia2;
	archive_traits::icreate(ia2, oa2, archive_type);
	ia2 & YAS_OBJECT_NVP("obj", ("set", set4));

	if ( set3.size() != 3 || set4.size() != 3 || set3 != set4 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	return true;
}

/***************************************************************************/

#endif // __yas__tests__base__include__boost_cont_flat_multiset_hpp
