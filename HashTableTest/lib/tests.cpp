#include "HashTable.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;

namespace {
    class ClassTest : public testing::Test {
    public:
        HashTable table;
    protected:
        void SetUp() {
            auto table = HashTable();
           }
    };
}

TEST_F(ClassTest, test1)
{
    struct Value value1 = {13, 50};
    ASSERT_TRUE(table.empty());
    table.insert("John",value1);
    ASSERT_TRUE(table.contains("John"));
    ASSERT_EQ(table["John"].age,13);
    ASSERT_EQ(table["John"].weight,50);
    table.erase("John");
    ASSERT_TRUE(table.empty());
}

TEST_F(ClassTest, test2)
{
    struct Value value1 = {13, 50};
    table.insert("John",value1);
    ASSERT_EQ( table.insert("John",value1),0);
}

TEST_F(ClassTest, test3)
{
    struct Value value1 = {13, 50};
    table.insert("John",value1);
    ASSERT_EQ( table.at("John").age,13);
    ASSERT_EQ( table.at("John").weight,50);
    table.insert("Dan",value1);
    table.insert("Roy",value1);
    ASSERT_EQ(table.size(),8);
}

TEST_F(ClassTest, test4)
{
    struct Value value1 = {13, 50};
    table.insert("John",value1);
    table.insert("Dan",value1);
    table.insert("Roy",value1);

    HashTable table1 = table;
    ASSERT_EQ((table1 == table), true);
}


TEST_F(ClassTest, test5)
{
    HashTable table1 = std::move(table);

    ASSERT_FALSE(table1 == table);
}

TEST_F(ClassTest, test6)
{
    HashTable table1 = table;

    ASSERT_TRUE(table1 == table);
}


TEST_F(ClassTest, test7)
{
    HashTable table1 = HashTable(10);
    ASSERT_EQ(table1.countOfLists, 10);
}

TEST_F(ClassTest, test8)
{

    const struct Value value1 = {13, 50};
    table.insert("John",value1);
    struct Value value2 = table.at("John");

    ASSERT_EQ(value2.age, 13);
}
