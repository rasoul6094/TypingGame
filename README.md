## TypingGame BP pro  
:) The game project is to type words while they are going down at a certain speed, and the game ends when the capacity is filled.




#include <iostream>
#include <unordered_map>

struct Point {
    int x;
    int y;
    int z;

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y && z == other.z;
    }
};

struct PointHash {
    std::size_t operator()(const Point &point) const {
        std::size_t h1 = std::hash<int>{}(point.x);
        std::size_t h2 = std::hash<int>{}(point.y);
        std::size_t h3 = std::hash<int>{}(point.z);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

Point findMissingPoint(Point points[], int n) {
    std::unordered_map<Point, int, PointHash> pointCount;
    
    // Count occurrences of each point
    for (int i = 0; i < n; ++i) {
        pointCount[points[i]]++;
    }

    // Find the point with only 1 occurrence
    Point missingPoint;
    for (int i = 0; i < n; ++i) {
        if (pointCount[points[i]] == 1) {
            missingPoint = points[i];
            break;
        }
    }
    
    return missingPoint;
}

int main() {
    Point points[7] = {
        {7, 9, 9},
        {7, 9, 3},
        {8, 9, 3},
        {8, 9, 9},
        {8, 8, 3},
        {7, 8, 3},
        {7, 8, 9}
    };

    Point missingPoint = findMissingPoint(points, 7);

    std::cout << "The coordinates of the missing 8th point are: (" 
              << missingPoint.x << ", " << missingPoint.y << ", " << missingPoint.z << ")" << std::endl;

    return 0;
}