
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

#ifndef __yas__tests__base__include__boost_fusion_list_hpp
#define __yas__tests__base__include__boost_fusion_list_hpp

#include <boost/fusion/container/generation/make_list.hpp>
#include <boost/fusion/include/make_list.hpp>

/***************************************************************************/

template<typename archive_traits>
bool boost_fusion_list_test(std::ostream &log, const char *archive_type, const char *test_name) {
	boost::fusion::list<int, double> list1(33, 3.14), list2;

	typename archive_traits::oarchive oa;
	archive_traits::ocreate(oa, archive_type);
	oa & YAS_OBJECT_NVP("obj", ("list", list1));

	typename archive_traits::iarchive ia;
	archive_traits::icreate(ia, oa, archive_type);
	ia & YAS_OBJECT_NVP("obj", ("list", list2));
	if ( list1 != list2 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	std::set<std::string> set;
	set.insert("2");
	set.insert("3");
	set.insert("4");

	boost::fusion::list<
		std::string,
		std::set<std::string>
	> list3("1", set), list4;

	typename archive_traits::oarchive oa2;
	archive_traits::ocreate(oa2, archive_type);
	oa2 & YAS_OBJECT_NVP("obj", ("list", list3));

	typename archive_traits::iarchive ia2;
	archive_traits::icreate(ia2, oa2, archive_type);
	ia2 & YAS_OBJECT_NVP("obj", ("list", list4));
	if ( list3 != list4 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}


	typename archive_traits::oarchive oa3;
	archive_traits::ocreate(oa3, archive_type);
	oa3 & YAS_OBJECT_NVP("obj", ("list", boost::fusion::make_list(33,44)));

	boost::fusion::list<int, int> list5;
	typename archive_traits::iarchive ia3;
	archive_traits::icreate(ia3, oa3, archive_type);
	ia3 & YAS_OBJECT_NVP("obj", ("list", list5));

	if ( list5 != boost::fusion::make_list(33,44) ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	static const char str[] = "str";
	boost::fusion::list<boost::uint64_t, std::string> list6(33, str), list7;

	typename archive_traits::oarchive oa4;
	archive_traits::ocreate(oa4, archive_type);
	oa4 & YAS_OBJECT_NVP("obj", ("list", list6));

	typename archive_traits::iarchive ia4;
	archive_traits::icreate(ia4, oa4, archive_type);
	ia4 & YAS_OBJECT_NVP("obj", ("list", list7));

	if ( list6 != list7 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	typename archive_traits::oarchive oa5;
	archive_traits::ocreate(oa5, archive_type);
    auto v9 = boost::fusion::make_list<boost::uint64_t, std::string>(33, "str");
	oa5 & YAS_OBJECT_NVP("obj", ("list", std::move(v9)));

	typename archive_traits::iarchive ia5;
	archive_traits::icreate(ia5, oa5, archive_type);
	ia5 & YAS_OBJECT_NVP("obj", ("list", list7));

	if ( list6 != list7 ) {
		YAS_TEST_REPORT(log, archive_type, test_name);
		return false;
	}

	return true;
}

/***************************************************************************/

#endif // __yas__tests__base__include__boost_fusion_list_hpp
