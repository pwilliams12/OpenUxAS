#include "visilibity.h"
#include "Visilibity_Test.h"

namespace VisiLibity {

TEST_F(Visilibity_Test, VisilibityTest) {
    // Test basic calculation methods within Visilibity
    double t1 = 61.5;
    double t2 = 100.576;

    ASSERT_DOUBLE_EQ(t1, uniform_random_sample(t1, t1));
    for (unsigned int i = 0; i < 100; ++i) {
        double val = uniform_random_sample(t1,t2);
        ASSERT_LT(t1, val);
        ASSERT_GT(t2, val);
    }


    // Construct 1st polygon
    std::vector<Point> pts1;
    pts1.push_back(Point(0,0));
    pts1.push_back(Point(10,0));
    pts1.push_back(Point(10,10));
    pts1.push_back(Point(0,10));

    // Construct 2nd polygon
    std::vector<Point> pts2;
    // pts2.push_back(Point(10,0));
    // pts2.push_back(Point(16,5));
    // pts2.push_back(Point(10,10));

    pts2.push_back(Point(20,-10));
    pts2.push_back(Point(20,20));
    pts2.push_back(Point(8,8));
    pts2.push_back(Point(15,5));
    pts2.push_back(Point(8,2));
    
    // Construct polygon vector
    std::vector<Polygon> myPolys;
    myPolys.push_back(Polygon(pts1));
    myPolys.push_back(Polygon(pts2));

    std::vector<Polygon> returnPolys;
    double eps = 1e-10;

    if(Polygon::boost_union(myPolys, returnPolys, eps)) {
        std::cout << "Successfully joined!" << std::endl;
        std::cout << "Return polys size = " << returnPolys.size() << std::endl;
        for (auto& poly : returnPolys) {
            std::cout << "Poly, area = " << poly.area() << ":" << std::endl;
            for (int i = 0; i < poly.n(); ++i) {
                std::cout << "   Point <" << poly[i].x() << "," << poly[i].y() << ">" << std::endl;
            }
        }
    } else {
        std::cout << "DID NOT JOIN polys" << std::endl;
    }



    // -- dataTypes
    // boost_point
    // boost_polygon

    // -- methods
    
    //boost_union
    //find_overlap
    //snap_near

    //std::vector<Polygon> to_visiLibity(boost_polygon x)
    //Point to_visiLibity(boost_point x)
    //boost_polygon to_boost(std::vector<Polygon> x)
    //boost_point to_boost(Point visPoint)
}

}