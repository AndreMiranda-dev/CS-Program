#include "pch.h"

// the global test environment setup and tear down
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    void SetUp() override
    {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    void TearDown() override {}
};

// create our test class to house shared data between tests
class CollectionTest : public ::testing::Test
{
protected:
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    {
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    {
        collection->clear();
        collection.reset(nullptr);
    }

    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// ------------------------------------------------------------
// BASE TESTS PROVIDED
// ------------------------------------------------------------

TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    ASSERT_TRUE(collection);
    ASSERT_NE(collection.get(), nullptr);
}

TEST_F(CollectionTest, IsEmptyOnCreate)
{
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);
}

TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}

// ------------------------------------------------------------
// REQUIRED TESTS (11 total + 2 custom)
// ------------------------------------------------------------

TEST_F(CollectionTest, CanAddToEmptyVector)
{
    ASSERT_TRUE(collection->empty());
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    EXPECT_FALSE(collection->empty());
    EXPECT_EQ(collection->size(), 1);
}

TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);
}

TEST_F(CollectionTest, MaxSizeIsGreaterOrEqualToSize)
{
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(1);
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(4);
    EXPECT_GE(collection->max_size(), collection->size());

    add_entries(5);
    EXPECT_GE(collection->max_size(), collection->size());
}

TEST_F(CollectionTest, CapacityIsGreaterOrEqualToSize)
{
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(1);
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(4);
    EXPECT_GE(collection->capacity(), collection->size());

    add_entries(5);
    EXPECT_GE(collection->capacity(), collection->size());
}

TEST_F(CollectionTest, ResizeIncreasesCollection)
{
    collection->resize(5);
    ASSERT_EQ(collection->size(), 5);

    collection->resize(10);
    EXPECT_EQ(collection->size(), 10);
}

TEST_F(CollectionTest, ResizeDecreasesCollection)
{
    collection->resize(10);
    ASSERT_EQ(collection->size(), 10);

    collection->resize(4);
    EXPECT_EQ(collection->size(), 4);
}

TEST_F(CollectionTest, ResizeToZero)
{
    collection->resize(8);
    ASSERT_EQ(collection->size(), 8);

    collection->resize(0);
    EXPECT_EQ(collection->size(), 0);
    EXPECT_TRUE(collection->empty());
}

TEST_F(CollectionTest, ClearErasesCollection)
{
    add_entries(5);
    ASSERT_EQ(collection->size(), 5);

    collection->clear();
    EXPECT_EQ(collection->size(), 0);
    EXPECT_TRUE(collection->empty());
}

TEST_F(CollectionTest, EraseRangeErasesCollection)
{
    add_entries(10);
    ASSERT_EQ(collection->size(), 10);

    collection->erase(collection->begin(), collection->end());
    EXPECT_EQ(collection->size(), 0);
    EXPECT_TRUE(collection->empty());
}

TEST_F(CollectionTest, ReserveIncreasesCapacityNotSize)
{
    size_t oldCapacity = collection->capacity();
    collection->reserve(50);

    EXPECT_GE(collection->capacity(), 50);
    EXPECT_EQ(collection->size(), 0);
    EXPECT_GE(collection->capacity(), oldCapacity);
}

TEST_F(CollectionTest, AtThrowsOutOfRange)
{
    add_entries(3);
    ASSERT_THROW(collection->at(100), std::out_of_range);
}

TEST_F(CollectionTest, PushBackStoresCorrectValue)
{
    collection->push_back(42);
    ASSERT_EQ(collection->size(), 1);
    EXPECT_EQ(collection->at(0), 42);
}

TEST_F(CollectionTest, PopBackOnEmptyVectorDoesNotCrash)
{
    EXPECT_NO_THROW({
        if (!collection->empty())
            collection->pop_back();
        });

    EXPECT_EQ(collection->size(), 0);
}
