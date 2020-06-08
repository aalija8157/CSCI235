#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "myVector.h"
#include <string>

TEST_CASE("myVector tests")
{
    myVector<int> v;
    v.push(2);
    CHECK(v[0] == 2);
    CHECK(v.size() == 1);
    v[0] = v[0] + 3;
    CHECK(v[0] == 5);
    v.pop();
    CHECK(v.size() == 0);

    myVector<std::string> v2;
    v2.push("2");
    CHECK(v2[0] == "2");
    v2[0] = v2[0] + "3";
    CHECK (v2[0] == "23");
}
