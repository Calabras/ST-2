// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>
#include "circle.h"
#include "tasks.h"

// --- Circle constructor tests ---

TEST(CircleTest, ConstructorSetsRadius) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, ConstructorSetsFerence) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * MY_PI * 5.0);
}

TEST(CircleTest, ConstructorSetsArea) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), MY_PI * 25.0);
}

TEST(CircleTest, ConstructorZeroRadius) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, ConstructorNegativeRadiusThrows) {
    EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

// --- setRadius tests ---

TEST(CircleTest, SetRadiusUpdatesRadius) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, SetRadiusUpdatesFerence) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * MY_PI * 10.0);
}

TEST(CircleTest, SetRadiusUpdatesArea) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_DOUBLE_EQ(c.getArea(), MY_PI * 100.0);
}

TEST(CircleTest, SetRadiusNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

// --- setFerence tests ---

TEST(CircleTest, SetFerenceUpdatesFerence) {
    Circle c(1.0);
    double newF = 2.0 * MY_PI * 7.0;
    c.setFerence(newF);
    EXPECT_DOUBLE_EQ(c.getFerence(), newF);
}

TEST(CircleTest, SetFerenceUpdatesRadius) {
    Circle c(1.0);
    double newF = 2.0 * MY_PI * 7.0;
    c.setFerence(newF);
    EXPECT_NEAR(c.getRadius(), 7.0, 1e-10);
}

TEST(CircleTest, SetFerenceUpdatesArea) {
    Circle c(1.0);
    double newF = 2.0 * MY_PI * 7.0;
    c.setFerence(newF);
    EXPECT_NEAR(c.getArea(), MY_PI * 49.0, 1e-10);
}

TEST(CircleTest, SetFerenceNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

// --- setArea tests ---

TEST(CircleTest, SetAreaUpdatesArea) {
    Circle c(1.0);
    double newA = MY_PI * 16.0;
    c.setArea(newA);
    EXPECT_NEAR(c.getArea(), newA, 1e-10);
}

TEST(CircleTest, SetAreaUpdatesRadius) {
    Circle c(1.0);
    double newA = MY_PI * 16.0;
    c.setArea(newA);
    EXPECT_NEAR(c.getRadius(), 4.0, 1e-10);
}

TEST(CircleTest, SetAreaUpdatesFerence) {
    Circle c(1.0);
    double newA = MY_PI * 16.0;
    c.setArea(newA);
    EXPECT_NEAR(c.getFerence(), 2.0 * MY_PI * 4.0, 1e-10);
}

TEST(CircleTest, SetAreaNegativeThrows) {
    Circle c(1.0);
    EXPECT_THROW(c.setArea(-1.0), std::invalid_argument);
}

// --- Additional Circle tests ---

TEST(CircleTest, UnitCircle) {
    Circle c(1.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * MY_PI);
    EXPECT_DOUBLE_EQ(c.getArea(), MY_PI);
}

TEST(CircleTest, LargeRadius) {
    Circle c(1e6);
    EXPECT_DOUBLE_EQ(c.getRadius(), 1e6);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * MY_PI * 1e6);
    EXPECT_DOUBLE_EQ(c.getArea(), MY_PI * 1e12);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
}

// --- Rope task tests ---

TEST(RopeTaskTest, GapIsPositive) {
    double gap = ropeTask();
    EXPECT_GT(gap, 0.0);
}

TEST(RopeTaskTest, GapValue) {
    double gap = ropeTask();
    double expected = 1.0 / (2.0 * MY_PI);
    EXPECT_NEAR(gap, expected, 1e-5);
}

// --- Pool task tests ---

TEST(PoolTaskTest, ConcreteCostIsPositive) {
    double cost = poolConcreteCost();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolTaskTest, ConcreteCostValue) {
    double cost = poolConcreteCost();
    double expectedArea = MY_PI * (16.0 - 9.0);
    double expected = expectedArea * 1000.0;
    EXPECT_NEAR(cost, expected, 1e-5);
}

TEST(PoolTaskTest, FenceCostIsPositive) {
    double cost = poolFenceCost();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolTaskTest, FenceCostValue) {
    double cost = poolFenceCost();
    double expected = 2.0 * MY_PI * 4.0 * 2000.0;
    EXPECT_NEAR(cost, expected, 1e-5);
}

