#include "../include/rectangle.h"
#include "../include/rhombus.h"
#include "../include/trapezoid.h"
#include "../include/array.h"
#include <gtest/gtest.h>
#include <sstream>
#include <string>

std::string captureStdout(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

// Тесты для Rectangle
TEST(RectangleTest, AreaAndCenter) {
    Rectangle r(0.0, 0.0, 4.0, 3.0);
    EXPECT_NEAR(static_cast<double>(r), 12.0, 1e-9);
    auto c = r.Center();
    EXPECT_NEAR(c.first, 2.0, 1e-9);
    EXPECT_NEAR(c.second, 1.5, 1e-9);
}

TEST(RectangleTest, Equality) {
    Rectangle r1(0, 0, 2, 3);
    Rectangle r2(2, 3, 0, 0);
    EXPECT_TRUE(r1 == r2);
}

TEST(RectangleTest, IO) {
    Rectangle r(1, 2, 3, 4);
    std::stringstream ss;
    ss << r;
    Rectangle r2;
    ss >> r2;
    EXPECT_TRUE(r == r2);
}

// Тесты для Rhombus
TEST(RhombusTest, AreaAndCenter) {
    Rhombus rh(6.0, 8.0, {1.0, 2.0});
    EXPECT_NEAR(static_cast<double>(rh), 24.0, 1e-9);
    auto c = rh.Center();
    EXPECT_NEAR(c.first, 1.0, 1e-9);
    EXPECT_NEAR(c.second, 2.0, 1e-9);
}

// Тесты для Array 
TEST(ArrayTest, AddAndSize) {
    Array arr;
    EXPECT_EQ(arr.Size(), 0);
    arr.add(new Rectangle(0, 0, 1, 1));
    EXPECT_EQ(arr.Size(), 1);
    arr.add(new Rhombus(2, 2, {0, 0}));
    EXPECT_EQ(arr.Size(), 2);
}

TEST(ArrayTest, TotalArea) {
    Array arr;
    arr.add(new Rectangle(0, 0, 2, 2));      
    arr.add(new Rhombus(4, 4, {0, 0}));      
    arr.add(new Trapezoid(1, 3, 2, {0, 0})); 

    std::string output = captureStdout([&]() { arr.totalArea(); });
    double total;
    std::stringstream(output) >> total;
    EXPECT_NEAR(total, 16.0, 1e-6);
}

TEST(ArrayTest, Remove) {
    Array arr;
    arr.add(new Rectangle(0, 0, 1, 1)); 
    arr.add(new Rectangle(0, 0, 2, 2)); 

    EXPECT_EQ(arr.Size(), 2);

    double areaBefore = std::stod(captureStdout([&]() { arr.totalArea(); }));

    arr.remove(0);

    EXPECT_EQ(arr.Size(), 1);

    double areaAfter = std::stod(captureStdout([&]() { arr.totalArea(); }));
    EXPECT_NEAR(areaAfter, 4.0, 1e-6);
    EXPECT_NEAR(areaBefore, 5.0, 1e-6);
}

TEST(ArrayTest, PrintAll) {
    Array arr;
    Rectangle* r = new Rectangle(0, 0, 1, 1);
    arr.add(r);

    std::string output = captureStdout([&]() { arr.printFigures(); });
    EXPECT_NE(output.find("0 0 1 1"), std::string::npos);
}

TEST(ArrayTest, CopyConstructor) {
    Array arr1;
    arr1.add(new Rectangle(0, 0, 1, 1));

    Array arr2 = arr1;

    double area1 = std::stod(captureStdout([&]() { arr1.totalArea(); }));
    double area2 = std::stod(captureStdout([&]() { arr2.totalArea(); }));
    EXPECT_NEAR(area1, area2, 1e-6);
    EXPECT_NEAR(area1, 1.0, 1e-6);

    EXPECT_EQ(arr1.Size(), arr2.Size());
}