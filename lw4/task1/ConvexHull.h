#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <iomanip>

using coordinate = float;

struct Point
{
    coordinate x;
    coordinate y;
    coordinate z;
    Point(coordinate x = 0, coordinate y = 0, coordinate z = 0) : x(x), y(y), z(z) {}
    Point operator-(const Point& other) const
    {
        return Point(x - other.x, y - other.y, z - other.z);
    }
    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y, z + other.z);
    }
    bool operator!= (const Point& other) const
    {
        return (x != other.x || y != other.y || z != other.z);
    }
    bool operator== (const Point& other) const
    {
        return (x == other.x && y == other.y && z == other.z);
    }
};

class ConvexHull
{
public:
    ConvexHull(const std::vector<Point>& points)
        : points_(points)
        , count_(points.size())
    {
        makeHull();
    }

    ConvexHull(const float vertices[60][3])
        : count_(60)
    { 
        for (size_t i = 0; i < 60; i++)
        {
            points_.push_back({ vertices[i][0], vertices[i][1], vertices[i][2] });
        }
        makeHull(); 
    }

    std::vector<Point> GetVertices() const;

private:
    struct Flatness
    {
        int first;
        int second;
        int third;
        Point normal; // нормаль к грани, изначально содержащее это ребро
        Flatness(int first, int second, int third, Point normal) :
            first(first), second(second), third(third), normal(normal) {}
        int Another(int one, int two)
        {
            if ((one == first && two == second) || (one == second && two == first))
            {
                return third;
            }
            if ((one == first && two == third) || (one == third && two == first))
            {
                return second;
            }
            if ((one == third && two == second) || (one == second && two == third))
            {
                return first;
            }
            return -1; // error
        }
    };

    struct Edge
    {
        int first;
        int second;
        int flatness; //номер грани
        bool is_close = false;

        Edge(int first, int second, int flatness = -1, Point normal = Point(0, 0, 0)) :
            first(first), second(second), flatness(flatness) {}
    };

    std::vector<Point> points_;
    std::vector<Flatness> verge_;
    std::vector<Edge> edges_;

    int count_; // Количество точек изначального множества

    int findMinZ() const;
    void findFirstFlatness();
    int returnIsEdgeInHull(int a, int b) const;
    void makeHull();
};