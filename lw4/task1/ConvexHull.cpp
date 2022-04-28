#include "ConvexHull.h"

coordinate Det2x2(coordinate a11, coordinate a12, coordinate a21, coordinate a22)
{
    return a11 * a22 - a12 * a21;
}

//[AB, AC]
Point VectorProduct(const Point& A, const Point& B, const Point& C)
{
    Point a = B - A;
    Point b = C - A;
    return Point(Det2x2(a.y, a.z, b.y, b.z),
        Det2x2(a.x, a.z, b.x, b.z),
        Det2x2(a.x, a.y, b.x, b.y));
}

//vector AB
double GetLenghtVector(Point A, Point B = Point(0, 0, 0))
{
    Point vec = B - A;
    double lenght = std::sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
    return lenght;
}

double GetAngle(const Point& n1, const Point& n2)
{
    double len_n1 = GetLenghtVector(n1);
    double len_n2 = GetLenghtVector(n2);
    double scalar_prod = n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
    if (scalar_prod == 0)
    {
        return 0;
    }
    return std::acos((scalar_prod) / (len_n1 * len_n2));
}

void ConvexHull::makeHull()
{
    findFirstFlatness();
    std::stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);

    while (!stack.empty())
    {
        Point new_normal;
        Edge e = edges_[stack.top()]; // берем верхнее ребро, рассматриваем его
        stack.pop();
        if (e.is_close) // если в ребро уже нельзя добавлять грани, мы этого не делаем
        {
            continue;
        }
        int min_id = -1;
        double min_angle = 7;

        for (int i = 0; i < count_; ++i)
        {
            int another = verge_[e.flatness].Another(e.first, e.second);
            if (i != another && e.first != i && e.second != i) // проверка, что точка не из той же грани
            {
                // нахождение нормали к плоскости, образуемой ребром и i-ой точкой
                Point current_normal = VectorProduct(points_[e.second], points_[e.first], points_[i]);
                double angle = GetAngle(current_normal, verge_[e.flatness].normal);

                if (min_angle > angle)
                {
                    min_angle = angle;
                    min_id = i;
                    new_normal = current_normal;
                }
            }
        }

        if (min_id != -1) // защита от дурака - если в оболочке меньше 4х вершин
        {
            e.is_close = true; // раз мы рассмоттрели это ребро, значит добавили уже вторую грань к этому ребру
            int count_flatness = verge_.size(); // номер нашей грани
            int first_edge_in_hull = returnIsEdgeInHull(e.first, min_id);
            int second_edge_in_hull = returnIsEdgeInHull(e.second, min_id);

            if (first_edge_in_hull == -1)
            {
                edges_.push_back(Edge(e.first, min_id, count_flatness));
                stack.push(edges_.size() - 1);
            }
            if (second_edge_in_hull == -1)
            {
                edges_.push_back(Edge(min_id, e.second, count_flatness));
                stack.push(edges_.size() - 1);
            }
            if (first_edge_in_hull != -1)
            {
                edges_[first_edge_in_hull].is_close = true;
            }
            if (second_edge_in_hull != -1)
            {
                edges_[second_edge_in_hull].is_close = true;
            }

            verge_.push_back(Flatness(e.first, e.second, min_id, new_normal));
        }

    } // закрытие while
} // закрытие метода

int ConvexHull::findMinZ() const
{
    int min_id = 0;
    for (int i = 1; i < count_; ++i)
    {
        if (points_[i].z < points_[min_id].z ||
            (points_[i].z == points_[min_id].z && points_[i].y < points_[min_id].y) ||
            (points_[i].z == points_[min_id].z && points_[i].y == points_[min_id].y &&
                points_[i].x < points_[min_id].x))
        {
            min_id = i;
        }
    }
    return min_id;
}

void ConvexHull::findFirstFlatness()
{
    int first_point, second_point, third_point;
    first_point = findMinZ();
    double min_angle = 7;
    int min_id = -1;
    for (int i = 0; i < count_; ++i)
    {
        if (first_point == i)
        {
            continue;
        }
        Point start = points_[first_point];
        Point next = points_[i];
        double angle = GetAngle(start - next, next - Point(next.x, next.y, start.z));
        if (min_angle > angle)
        {
            min_angle = angle;
            min_id = i;
        }
    }
    second_point = min_id;

    min_angle = 7;
    min_id = -1;
    for (int i = 0; i < count_; ++i)
    {
        if (first_point == i || second_point == i)
        {
            continue;
        }
        Point normal = VectorProduct(points_[first_point], points_[second_point], points_[i]);
        double angle = GetAngle(Point(0, 0, 1), normal);
        if (min_angle > angle)
        {
            min_angle = angle;
            min_id = i;
        }
    }
    third_point = min_id;

    // правильное ориентирование
    if (VectorProduct(points_[first_point], points_[second_point], points_[third_point]).z > 0)
    {
        std::swap(second_point, third_point);
    }
    Point new_normal = VectorProduct(points_[first_point], points_[second_point], points_[third_point]);
    verge_.push_back(Flatness(first_point, second_point, third_point, new_normal)); // перая грань
    edges_.push_back(Edge(first_point, second_point, 0));
    edges_.push_back(Edge(second_point, third_point, 0));
    edges_.push_back(Edge(third_point, first_point, 0));
}

int ConvexHull::returnIsEdgeInHull(int a, int b) const
{
    for (int i = 0; i < edges_.size(); ++i)
    {
        if ((edges_[i].first == a && edges_[i].second == b) ||
            (edges_[i].first == b && edges_[i].second == a))
        {
            return i;
        }
    }

    return -1;
}

std::vector<Point> ConvexHull::GetVertices() const
{
    return points_;
}