#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include "doctest.h"
#include "person.h"
#include "Node.h"
#include "hash_table.h"

TEST_CASE("insert/retrieval")
{
    hash_table* h = new hash_table();
    person p("poarma", "zamazzzz", "Mr.", 500.0);
    person p1("mike", "legend");
    person p2("will", "hunting");
    person p3("ben", "affleck");
    person p4("robin", "williams", 91204);
    person p5("robin", "williams");
    h->insert(p);
    h->insert(p1);
    h->insert(p2);
    CHECK(h->retrieve(p1).first == p1.first);
    // p4 has not been inserted yet.
    CHECK(h->retrieve(p5).first == "");
    h->insert(p4);
    CHECK(h->retrieve(p5).first == p5.first);
    CHECK(h->retrieve(p5).last == p4.last);
    
    // returns the full robin williams person object even though p5 only has first and last.
    CHECK(h->retrieve(p5).salary == 91204);
    // check if it was inserted at the hash index.
    CHECK(h->at(h->hash(p4))->getData() == p4);

    //checking if linked list is working correctly, normally would never do this in a hash table
    h->insert(p3, h->hash(p4));
    CHECK(h->at(h->hash(p4))->getNext()->getData().first == p3.first);
    CHECK(h->at(h->hash(p4))->getData().first == p4.first);
}

TEST_CASE("deletion")
{
    hash_table* h = new hash_table();
    person p("poarma", "zamazzzz", 500.0);
    person p1("mike", "legend");
    person p2("will", "hunting");
    person p3("ben", "affleck");
    person p4("robin", "williams");
    person p5("matt", "damon");

    h->insert(p);
    h->insert(p1);
    h->insert(p2);

    CHECK(h->at(h->hash(p))->getData().first == p.first);
    h->del(p);
    // check if the linked list is length 1 and the only element gets deleted, the element becomes null
    CHECK(h->at(h->hash(p)) == nullptr);
    // insert at the same element at p1, again this would never be a function in a hash_table but i
    // made it to make testing easier.
    
    h->insert(p3, h->hash(p1));
    h->del(p1);
    // if the first element of a linked list with size > 1 is deleted, the next ele becomes the new head
    CHECK(h->at(h->hash(p1))->getData().first == p3.first);

    // now linked list at index hash(p1) is p3->p4->p5. we will delete p4 and see if it works
    h->insert(p4, h->hash(p1));
    h->insert(p5, h->hash(p1));
    h->del(p4);

    // new linked list at idx hash(p1) is p3->p5 after p4 deletion.
    CHECK(h->at(h->hash(p1))->getData().first == p3.first);
    CHECK(h->at(h->hash(p1))->getNext()->getData().first == p5.first);

    h->del(p5);

    // p5 deleted, now its nullptr as it should be
    CHECK(h->at(h->hash(p1))->getNext() == nullptr);

    // now delete p5 again, it will return false since p5 isnt in the list.
    CHECK(h->del(p5) == false);
    delete h;
}

TEST_CASE("constructor/destructor")
{
    hash_table* h = new hash_table();
    person p1;
    person p5("a", "", "", 100);
    person p2("matt", "damon");
    person p3("george", "bush", "Mr.", 50000000);
    person p4("jeb", "bush", 30);
    person arr[] = {p5, p2, p3, p4};
    hash_table* h1 = new hash_table(arr, 4);
    CHECK(h1->at(h->hash(p3))->getData() == p3);
    h->insert(p1);
    h->insert(p2);
    h->insert(p3);
    h->insert(p4);
    h->insert(p5);
    delete h;
    // checking if every node was deleted. fixed  the issue by adding "virtual" to destructor, not sure why that worked though.
    CHECK(h->at(h->hash(p1)) == nullptr);
    CHECK(h->at(h->hash(p2)) == nullptr);
    CHECK(h->at(h->hash(p3)) == nullptr);
    CHECK(h->at(h->hash(p4)) == nullptr);
    CHECK(h->at(h->hash(p5)) == nullptr);
    h = nullptr;
}
