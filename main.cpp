#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include "function.h"
// Function to check if a tree is within the field of view


int main()
{

    double alpha;
    double maxTreesInSight = 0;
    double bestOrientation = 0;  // Best orientation for the person
    int treesInSight_PV_angle=0;
    int maxTreesInSight_PV_angle=0;
    // Read input from stdin
    std::tuple<double, double,double> person;
    std::vector<std::tuple<double, double>> trees;
    std::cout<<"Please enter Feild of view angle alpha"<<std::endl;
    std::cin>>alpha;
    std::cout<<"Please enter person x ,y and Person_view_angle values"<<std::endl;
    // Read person's position and  person_view_angle from input
    std::cin >> std::get<0>(person) >> std::get<1>(person) >> std::get<2>(person);
    std::cout<<"person x\t"<<std::get<0>(person)<<"person y\t"<<std::get<1>(person)<<"person view angle\t"<<std::get<2>(person)<<std::endl;
    //////
    int numTrees;
    std::cout<<"Please enter total number of tress\n";
    std::cin >> numTrees;

    // Read tree positions from input and store them in a vector of tuples
    for (int i = 0; i < numTrees; ++i) {
        std::tuple<double, double> tree;
        std::cout<<"Please tree "<<i+1<<" x and y coordinates\n";
        std::cin >> std::get<0>(tree) >> std::get<1>(tree);
        trees.push_back(tree);
    }
    std::cout<<"All tress added"<<std::endl;
    double orint=std::get<2>(person);
    for (const auto& tree : trees) {

        double halfAlpha = alpha / 2.0;
            if (isTreeInFieldOfView(person, tree, orint, halfAlpha)) {
                treesInSight_PV_angle++;
                std::cout<<"here\n";
            }
        }
    maxTreesInSight_PV_angle=treesInSight_PV_angle;
    std::cout<<"max tress at person view angle "<<maxTreesInSight_PV_angle<<std::endl;
    // Iterate through possible orientations
    for (double orientation = 0; orientation < 360; orientation += 1.0) {
        int treesInSight = 0;
        double halfAlpha = alpha / 2.0;

        // Check each tree if it's within the field of view
        for (const auto& tree : trees) {
            if (isTreeInFieldOfView(person, tree, orientation, halfAlpha)) {
                treesInSight++;
            }
        }

        // Update the best orientation if more trees are in sight
        if (treesInSight > maxTreesInSight ) {
            maxTreesInSight = treesInSight;
            bestOrientation = orientation;
            if(treesInSight <=maxTreesInSight_PV_angle){
            bestOrientation=orint;
        }
        }

    }

    // Output the best orientation and maximum number of trees in sight
    std::cout << "Best orientation: " << bestOrientation <<" degress from +iv x axies "<< "\nmax number of tree in sight "<<maxTreesInSight<< std::endl;
    //Outputs does the person need to rotate or not
    if(bestOrientation==orint)
    {
        std::cout<<"The person is at the optmial point of view"<<std::endl;
    }
    else{
        std::cout<<"The person need to move to "<<bestOrientation<<" degress from the +iv X axiese to have a view with most number of tress"<<std::endl;
    }

    return 0;

}