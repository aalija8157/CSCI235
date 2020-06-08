#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "List.h"

TEST_CASE("ACCESS")
{
    List *l = new List();
    l->insert("one");
    l->insert("two");
    CHECK((*l)[0] == "two");
    CHECK((*l)[1] == "one");
    CHECK((*l)[2] == "");
    delete l;
}

TEST_CASE("PUSHBACK")
{
    List *l = new List();
    l->pushback("one");
    l->pushback("two");
    l->insert("three");
    CHECK((*l)[0] == "three");
    CHECK((*l)[1] == "one");
    CHECK((*l)[2] == "two");
    delete l;
}

TEST_CASE("REMOVE")
{
    List *l = new List();
    l->insert("one");
    l->pushback("two");
    l->pushback("three");
    l->insert("four");
    // array looks like: four -> one -> two -> three
    CHECK(l->length() == 4);
    CHECK((*l)[0] == "four");
    l->remove(0);
    // now it is one->two->three
    CHECK(l->length() == 3);
    CHECK((*l)[0] == "one");
    CHECK((*l)[1] == "two");
    CHECK((*l)[2] == "three");
    CHECK((*l)[3] == "");
    // now it is one -> three
    l->remove(1);
    CHECK((*l)[0] == "one");
    CHECK((*l)[1] == "three");
    CHECK(l->length() == 2);
    l->remove(2); // this idx doesnt exist
    CHECK(l->length() == 2);
}
