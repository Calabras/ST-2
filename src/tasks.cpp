// Copyright 2025 UNN-CS Team
#include "tasks.h"
#include "circle.h"

double ropeTask() {
    const double earthRadiusKm = 6378.1;
    const double earthRadiusM = earthRadiusKm * 1000.0;

    Circle earth(earthRadiusM);
    double originalFerence = earth.getFerence();

    earth.setFerence(originalFerence + 1.0);
    double newRadius = earth.getRadius();

    return newRadius - earthRadiusM;
}

double poolConcreteCost() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double pricePerSqm = 1000.0;

    Circle pool(poolRadius);
    Circle outer(poolRadius + pathWidth);

    double pathArea = outer.getArea() - pool.getArea();
    return pathArea * pricePerSqm;
}

double poolFenceCost() {
    const double poolRadius = 3.0;
    const double pathWidth = 1.0;
    const double pricePerMeter = 2000.0;

    Circle outer(poolRadius + pathWidth);
    return outer.getFerence() * pricePerMeter;
}
