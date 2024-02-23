## TypingGame BP pro  
:) The game project is to type words while they are going down at a certain speed, and the game ends when the capacity is filled.




#include <iostream>
#include <vector>

struct Point {
    int x, y, z;
};

int main() {
    std::vector<Point> points(7);

    std::cout << "Enter the coordinates of 7 points on the rectangular cube:\n";
    for (int i = 0; i < 7; ++i) {
        std::cout << "Enter coordinates for point " << i + 1 << " (x y z): ";
        std::cin >> points[i].x >> points[i].y >> points[i].z;
    }

    Point eighthPoint;

    // Find the coordinates of the eighth point
    eighthPoint.x = points[0].x + points[3].x - points[1].x;
    eighthPoint.y = points[0].y + points[3].y - points[1].y;
    eighthPoint.z = points[0].z + points[3].z - points[1].z;

    std::cout << "Coordinates of the eighth point are: (" << eighthPoint.x << ", " << eighthPoint.y << ", " << eighthPoint.z << ")\n";

    return 0;
}