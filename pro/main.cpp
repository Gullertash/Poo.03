#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
#include <functional>
using namespace std;

// Base class - Shape
class Shape {
public:
    virtual ~Shape() {} // Virtual destructor

    virtual double area() const = 0; // Pure virtual function for calculating area

    virtual void display() const = 0; // Pure virtual function for display

    static int getCount() { // Static function to keep track of the number of shapes
        return shapeCount;
    }

protected:
    Shape() { ++shapeCount; } // Constructor increments the static counter
    static int shapeCount; // Static variable to keep track of the number of Shape objects
};

// Define the static variable outside the class
int Shape::shapeCount = 0;

// Derived class - Circle
class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        cout << "Circle with radius " << radius << " and area " << area() << endl;
    }

private:
    double radius;
};

// Derived class - Rectangle
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    void display() const override {
        cout << "Rectangle with width " << width << ", height " << height << " and area " << area() << endl;
    }

private:
    double width, height;
};

// Exception handling class
class ShapeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Shape-related exception occurred!";
    }
};

// Template class for handling shapes dynamically
template <typename T>
class ShapeManager {
public:
    void addShape(shared_ptr<T> shape) {
        shapes.push_back(shape);
    }

    void displayAll() const {
        for (const auto& shape : shapes) {
            shape->display();
        }
    }

private:
    vector<shared_ptr<T>> shapes;
};

int main() {
    try {
        ShapeManager<Shape> manager;

        shared_ptr<Shape> c1 = make_shared<Circle>(5.0); // Upcasting to Shape
        shared_ptr<Shape> r1 = make_shared<Rectangle>(4.0, 6.0); // Upcasting to Shape

        manager.addShape(c1);
        manager.addShape(r1);

        cout << "Total number of shapes: " << Shape::getCount() << endl;

        manager.displayAll(); // Display all shapes

        // Demonstrating exception handling
        if (Shape::getCount() < 2) {
            throw ShapeException();
        }

    } catch (const ShapeException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
