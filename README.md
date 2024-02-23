## TypingGame BP pro  
:) The game project is to type words while they are going down at a certain speed, and the game ends when the capacity is filled.
https://docs.google.com/spreadsheets/d/1y7vYCiSUMoxZ3DFENgQJ9IO2Y3x09xkuScVS3kPhgIE/edit#gid=0


#include <iostream>
#include <vector>
#include <cmath>

// Define a point structure in 3D space
struct Point {
    double x, y, z;
};

// Function to calculate the missing point
Point findMissingPoint(std::vector<Point>& points) {
    Point center = {0, 0, 0};

    // Calculate the center point of the given points
    for (const auto& p : points) {
        center.x += p.x;
        center.y += p.y;
        center.z += p.z;
    }

    center.x /= points.size();
    center.y /= points.size();
    center.z /= points.size();

    // Calculate the missing point
    Point missingPoint = {2 * center.x, 2 * center.y, 2 * center.z};

    return missingPoint;
}

int main() {
    std::vector<Point> points = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}, {19, 20, 21}};

    Point missingPoint = findMissingPoint(points);

    std::cout << "Missing point: (" << missingPoint.x << ", " << missingPoint.y << ", " << missingPoint.z << ")" << std::endl;

    return 0;
}
