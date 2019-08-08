#include "unity.h"
#include "unity_fixture.h"
#include "../src/doublylinkedlist.h"

TEST_GROUP(DoublyLinkedList);

static DLList *dllist;

TEST_SETUP(DoublyLinkedList)
{
    dllist = llist_new();
}

TEST_TEAR_DOWN(DoublyLinkedList)
{
    llist_destroy(dllist);
}

