// Copyright 2022 UNN-CS
#include "circle.h"

void Circle::updateFromRadius() {
    ference = 2.0 * MY_PI * radius;
    area = MY_PI * radius * radius;
}

void Circle::updateFromFerence() {
    radius = ference / (2.0 * MY_PI);
    area = MY_PI * radius * radius;
}

void Circle::updateFromArea() {
    radius = std::sqrt(area / MY_PI);
    ference = 2.0 * MY_PI * radius;
}

Circle::Circle(double r) {
    if (r < 0) throw std::invalid_argument("Radius cannot be negative");
    radius = r;
    updateFromRadius();
}

void Circle::setRadius(double r) {
    if (r < 0) throw std::invalid_argument("Radius cannot be negative");
    radius = r;
    updateFromRadius();
}

void Circle::setFerence(double f) {
    if (f < 0) throw std::invalid_argument("Ference cannot be negative");
    ference = f;
    updateFromFerence();
}

void Circle::setArea(double a) {
    if (a < 0) throw std::invalid_argument("Area cannot be negative");
    area = a;
    updateFromArea();
}

double Circle::getRadius() const { return radius; }
double Circle::getFerence() const { return ference; }
double Circle::getArea() const { return area; }

