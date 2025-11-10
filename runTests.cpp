/*
 * CSC-301
 * runTests.cpp
 * Fall 2025
 * Eric A. Autry
 * 11/23/22
 */

#include "runTests.hpp"

using namespace std;

/*
 * getDist
 * 
 * This function takes in two coordinates and returns the great circle distance
 * between them (in kilometers).
 * 
 * INPUTS
 * double lat1, long1: the latitude and longitude of the first city.
 * double lat2, long2: the latitude and longitude of the second city.
 * 
 * OUTPUTS
 * double dist: the great circle distance between the two cities (km).
 */
double getDist(double lat1, double long1, double lat2, double long2) {
    // Convert to radians.
    lat1 = lat1*M_PI/180;
    long1 = long1*M_PI/180;
    lat2 = lat2*M_PI/180;
    long2 = long2*M_PI/180;

    // Calculate the change in lat and long.
    double dLat = lat2 - lat1;
    double dLong = long2 - long1;

    // Set the radius of the Earth.
    double R = 6371; // km

    // Calculate the distance using the formula for distance on a great circle.
    double a = pow(sin(dLat/2),2) + cos(lat1) * cos(lat2) * pow(sin(dLong/2),2);
    if (abs(a) < 1e-15) {
        a = 0;
    }
    if (abs(1-a) < 1e-15) {
        a = 1;
    }
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double dist = R*c;
    return dist; // km
}

/*
 * getMap
 * 
 * This function will fill the adjacency list, adjacency matrix, and edge list
 * as well as print info about the optimal tour for the selected scenario.
 * 
 * INPUTS
 * int mapNum: the number of which map to select.
 * vector<Vertex> &adjList: the adjacency list to fill.
 * vector<double> &adjMat: the adjacency matrix to fill.
 * vector<Edge> &edgeList: the edge list to fill.
 * 
 * OUTPUTS
 * optTour.str(): a string printing info about the opt tour for this case
 * Note: will also fill the adjList, adjMat, and edgeList.
 */
string getMap(int mapNum, vector<Vertex> &adjList, vector<double> &adjMat,
              vector<Edge> &edgeList) {
    stringstream optTour;
    vector<string> cityList;
    vector<double> mat;
    vector<double> lats;
    vector<double> longs;

    if (mapNum == 0) {
        cityList = {"a","b","c","d"};
        mat = {0,2,8,5,
               2,0,7,4,
               8,7,0,6,
               5,4,6,0};
        adjMat = mat;
        optTour << "Optimal Tour:\na, b, c, d, a";
        optTour << "\nWeight of Optimal Tour:\n20";
    } else if (mapNum == 1) {
        cityList = {"a","b","c","d"};
        mat = {0,2,2,3,
               2,0,3,2,
               2,3,0,2,
               3,2,2,0};
        adjMat = mat;
        optTour << "Optimal Tour:\na, b, d, c, a";
        optTour << "\nWeight of Optimal Tour:\n8";
    } else if (mapNum == 2) {
        cityList = {"NYC","Urbandale","Chicago","Durham","LA",
                                   "Seattle","Washington DC"};
        lats = {40.71,41.63,41.88,35.99,34.05,47.61,38.91};
        longs = {74.01,93.71,87.63,78.90,118.24,122.33,77.04};
        optTour << "Optimal Tour:\nNYC, Chicago, Urbandale, Seattle, LA, ";
        optTour << "Durham, Washington DC, NYC";
        optTour << "\nWeight of Optimal Tour:\n9796";
    } else if (mapNum == 3) {
        cityList = {"London","Paris","Madrid","Rome","Berlin",
                                   "Istanbul","Moscow","Athens","Copenhagen"};
        lats = {51.51,48.86,40.42,41.90,52.52,41.01,55.76,37.98,55.68};
        longs = {0.13,-2.35,3.70,-12.50,-13.41,-28.98,-37.62,-23.73,-12.57};
        optTour << "Optimal Tour:\nLondon, Berlin, Copenhagen, Moscow, ";
        optTour << "Istanbul, Athens, Rome, Madrid, Paris, London";
        optTour << "\nWeight of Optimal Tour:\n8978";
    } else if (mapNum == 4) {
        cityList = {"NYC","Urbandale","Chicago","Durham","LA",
                                   "Seattle","Washington DC","Houston",
                                   "Phoenix","Denver","San Francisco",
                                   "Honolulu","Boston","Cleveland"};
        lats = {40.71,41.63,41.88,35.99,34.05,47.61,38.91,
                29.76,33.45,39.74,37.77,21.31,42.36,41.50};
        longs = {74.01,93.71,87.63,78.90,118.24,122.33,77.04,
                 95.37,112.07,104.99,122.42,157.86,71.06,81.69};
        optTour << "Optimal Tour: ?";
    } else if (mapNum == 5) {
        cityList = {"London","Paris","Madrid","Rome","Berlin",
                                   "Istanbul","Moscow","Athens","Copenhagen",
                                   "Dublin","Warsaw","Kiev"};
        lats = {51.51,48.86,40.42,41.90,52.52,41.01,55.76,37.98,
                55.68,53.35,52.23,50.45};
        longs = {0.13,-2.35,3.70,-12.50,-13.41,-28.98,-37.62,
                 -23.73,-12.57,6.26,-21.01,-30.52};
        optTour << "Optimal Tour:\nLondon, Paris, Madrid, Rome, Athens, ";
        optTour << "Istanbul, Kiev, Moscow, Warsaw, Berlin, Copenhagen";
        optTour << "\nWeight of Optimal Tour:\n9911";
    } else if (mapNum == 6) {
        cityList = {"London","Paris","Madrid","Rome","Berlin",
                                   "Istanbul","Moscow","Athens","Copenhagen",
                                   "Dublin","Warsaw","Kiev","St. Petersburg",
                                   "Stockholm"};
        lats = {51.51,48.86,40.42,41.90,52.52,41.01,55.76,37.98,
                55.68,53.35,52.23,50.45,59.93,59.33};
        longs = {0.13,-2.35,3.70,-12.50,-13.41,-28.98,-37.62,
                 -23.73,-12.57,6.26,-21.01,-30.52,-30.34,-18.07};
        optTour << "Optimal Tour: ?";
    } else if (mapNum == 7) {
        for (int lab=0; lab<75; lab++) {
            cityList.push_back(to_string(lab));
            double lat = lab*360.0/75;
            if (lat > 180) {
                longs.push_back(170);
                lat = 270 - lat;
                lats.push_back(lat);
            } else {
                longs.push_back(-10);
                lat = lat - 90;
                lats.push_back(lat);
            }
        }
        lats[lats.size()-1] = -lats[lats.size()-1];
        if (longs[longs.size()-1] == 170) {
            longs[longs.size()-1] = -10;
        } else {
            longs[longs.size()-1] = 170;
        }
        optTour << "Optimal Tour: 40030.173592";

    } else if (mapNum == 8) {
        for (int lab=0; lab<75; lab++) {
            cityList.push_back(to_string(lab));
            double lat = lab*360.0/75;
            if (lat > 180) {
                longs.push_back(170);
                lat = 270 - lat;
                lats.push_back(lat);
            } else {
                longs.push_back(-10);
                lat = lat - 90;
                lats.push_back(lat);
            }
        }
        lats[lats.size()-1] = -lats[lats.size()-1];
        if (longs[longs.size()-1] == 170) {
            longs[longs.size()-1] = -10;
        } else {
            longs[longs.size()-1] = 170;
        }
        lats.insert(lats.begin(),*(--lats.end()));
        lats.pop_back();
        longs.insert(longs.begin(),*(--longs.end()));
        longs.pop_back();
        optTour << "Optimal Tour: 40030.173592";
    } else {
        return "Not a valid map number!";
    }

    // If not yet set, get the distances and insert into the adjacency matrix.
    if (adjMat.size() < 1) {
        vector<double> mat(cityList.size()*cityList.size(),0);
        for (int r=0; r<cityList.size(); r++) {
            for (int c=0; c<cityList.size(); c++) {
                mat[r*cityList.size() + c] = getDist(lats[r],longs[r],
                                                     lats[c],longs[c]);
                mat[c*cityList.size() + r] = mat[r*cityList.size() + c];
            }
            mat[r*cityList.size() + r] = 0;
        }
        adjMat = mat;
    }

    // Create the vertices and fill the adjList.
    for (int i=0; i<cityList.size(); i++) {
        Vertex v(i, cityList[i]);
        adjList.push_back(v);
    }

    // Create the list of edges and fill the neighbors.
    for (int r1=0; r1<adjList.size(); r1++) {
        for (int r2=r1+1; r2<adjList.size(); r2++) {
            if (adjMat[r1*adjList.size() + r2] != 0) {
                adjList[r1].neighbors.push_back(r2);
                adjList[r2].neighbors.push_back(r1);
                Edge e(adjList[r1], adjList[r2], 
                       adjMat[r1*adjList.size() + r2]);
                edgeList.push_back(e);
            }
        }
    }

    // Sort the list of edges!
    sort(edgeList.begin(), edgeList.end());

    // Return the string containing info about the opt tour for printing later.
    return optTour.str();
}

/*
 * getMSTWeight
 * 
 * This function will return the total weight of the MST given its edges.
 * 
 * INPUTS
 * vector<Edge> &mst: the list of edges in the MST.
 * 
 * OUTPUTS
 * double totalWeight: the sum of the weights.
 */
double getMSTWeight(vector<Edge> &mst) {
    double totalWeight = 0;
    for (int i=0; i<mst.size(); i++) {
        totalWeight += mst[i].weight;
    }
    return totalWeight;
}

/*
 * getTourWeight
 * 
 * This function will return the total weight of the TSP tour.
 * 
 * INPUTS
 * vector<int> &tour: the list of vertex labels of the tour.
 * vector<Vertex> &adjList: the adjacency list.
 * vector<double> &adjMat: the adjacency matrix.
 * 
 * OUTPUTS
 * double tourWeight: the total weight of the tour, inf if no tour.
 */
double getTourWeight(vector<int> &tour, vector<Vertex> &adjList, 
                     vector<double> &adjMat) {
    if (tour.size() > 0) {
        double tourWeight = 0;
        for (int i=0; i<tour.size()-1; i++) {
            tourWeight += adjMat[tour[i]*adjList.size() + tour[i+1]];
        }
        return tourWeight;
    } else {
        return numeric_limits<double>::infinity();
    }
}

/*
 * testMaps
 * 
 * This function will test your code on the various maps.
 * 
 * INPUTS
 * bool verb: verbosity flag, if true will print info on solutions.
 *            defaulted to false
 * 
 * OUTPUTS
 * No return value, but prints info indicating number of tests passed.
 */
void testMaps(bool verb=false) {
    int primPass = 0;
    int kruskalPass = 0;
    int tspPass = 0;
    int numTests = 9;
    double tol = 1e-6;
    
    // Expected MST weights for the test maps.
    vector<double> MSTws = {12,6,5999.977279,6909.105275,11810.893206,
                            7724.194671,8813.919553,38962.702296,38962.702296};

    // Loop over the tests.
    for (int ind=0; ind<numTests; ind++) {
        bool primFailed = false;
        bool kruskalFailed = false;
        bool TSPfailed = false;

        if (verb) {
            cout << "##########################" << endl << endl;
            cout << "Testing map " << ind << "." << endl << endl;
        }

        // Initialize the graph(s) for this test.
        double MSTw = MSTws[ind];
        vector<Vertex> adjListPrim;
        vector<double> adjMat;
        vector<Edge> edgeList;
        string optTour = getMap(ind, adjListPrim, adjMat, edgeList);
        vector<Vertex> adjListKruskal(adjListPrim);

        // Test Prim's.
        vector<Edge> mstPrim = prim(adjListPrim, adjMat);
        if (mstPrim.size() < adjListPrim.size()-1) {
            if (verb) {
                cout << "Test " << ind << ": Not enough edges in Prim MST.";
                cout << endl;
            }
            primFailed = true;
        }
        if (mstPrim.size() > adjListPrim.size()-1) {
            if (verb) {
                cout << "Test " << ind << ": Too many edges in Prim MST.";
                cout << endl;
            }
            primFailed = true;
        }
        double primW = getMSTWeight(mstPrim);
        if (primW < MSTw-tol) {
            if (verb) {
                cout << "Test " << ind << ": Prim MST weight too low.";
                cout << endl;
            }
            primFailed = true;
        }
        if (primW > MSTw+tol) {
            if (verb) {
                cout << "Test " << ind << ": Prim MST weight too high.";
                cout << endl;
            }
            primFailed = true;
        }
        bool badPrimNeigh = false;
        bool noPrimNeigh = false;
        for (Vertex u : adjListPrim) {
            if (u.mstNeighbors.size() == 0) {
                noPrimNeigh = true;
            }
            for (int vLab : u.mstNeighbors) {
                bool doubleConnect = false;
                for (int tLab : adjListPrim[vLab].mstNeighbors) {
                    if (tLab == u.label) {
                        doubleConnect = true;
                    }
                }
                if (not doubleConnect) {
                    badPrimNeigh = true;
                }
            }
        }
        if (badPrimNeigh) {
            if (verb) {
                cout << "Test " << ind << ": Prim mstNeighbors not ";
                cout << "connected correctly (reverse edges missing).";
                cout << endl;
            }
            primFailed = true;
        }
        if (noPrimNeigh) {
            if (verb) {
                cout << "Test " << ind << ": Prim mstNeighbors does not ";
                cout << "connect to every vertex.";
                cout << endl;
            }
            primFailed = true;
        }

        if (verb) {
            if (primFailed) {
                cout << "Test " << ind << ": Prim FAILED!";
                cout << endl << endl;
            } else {
                cout << "Test " << ind << ": Prim MST Correct!";
                cout << endl << endl;
            }
        }

        if (verb) {
            cout << "Reported Prim MST Weight: " << primW << endl;
            cout << "Correct MST Weight: " << MSTw;
            cout << endl << endl;
        }

        // Test Kruskal's.
        vector<Edge> mstKruskal = kruskal(adjListKruskal, edgeList);
        if (mstKruskal.size() < adjListKruskal.size()-1) {
            if (verb) {
                cout << "Test " << ind;
                cout << ": Not enough edges in Kruskal MST.";
                cout << endl;
            }
            kruskalFailed = true;
        }
        if (mstKruskal.size() > adjListKruskal.size()-1) {
            if (verb) {
                cout << "Test " << ind << ": Too many edges in Kruskal MST.";
                cout << endl << endl;
            }
            kruskalFailed = true;
        }
        double kruskalW = getMSTWeight(mstKruskal);
        if (kruskalW < MSTw-tol) {
            if (verb) {
                cout << "Test " << ind << ": Kruskal MST weight too low.";
                cout << endl;
            }
            kruskalFailed = true;
        }
        if (kruskalW > MSTw+tol) {
            if (verb) {
                cout << "Test " << ind << ": Kruskal MST weight too high.";
                cout << endl;
            }
            kruskalFailed = true;
        }
        bool badKruskalNeigh = false;
        bool noKruskalNeigh = false;
        for (Vertex u : adjListKruskal) {
            if (u.mstNeighbors.size() == 0) {
                noKruskalNeigh = true;
            }
            for (int vLab : u.mstNeighbors) {
                bool doubleConnect = false;
                for (int tLab : adjListKruskal[vLab].mstNeighbors) {
                    if (tLab == u.label) {
                        doubleConnect = true;
                    }
                }
                if (not doubleConnect) {
                    badKruskalNeigh = true;
                }
            }
        }
        if (badKruskalNeigh) {
            if (verb) {
                cout << "Test " << ind << ": Kruskal mstNeighbors not ";
                cout << "connected correctly (reverse edges missing).";
                cout << endl;
            }
            kruskalFailed = true;
        }
        if (noKruskalNeigh) {
            if (verb) {
                cout << "Test " << ind << ": Kruskal mstNeighbors does not ";
                cout << "connect to every vertex.";
                cout << endl;
            }
            kruskalFailed = true;
        }

        if (verb) {
            if (kruskalFailed) {
                cout << "Test " << ind << ": Kruskal FAILED!";
                cout << endl << endl;
            } else {
                cout << "Test " << ind << ": Kruskal MST Correct!";
                cout << endl << endl;
            }
        }

        if (verb) {
            cout << "Reported Kruskal MST Weight: " << kruskalW << endl;
            cout << "Correct MST Weight: " << MSTw;
            cout << endl << endl;
        }

        // If we got a successful MST, test the TSP.
        if (not primFailed or not kruskalFailed) {

            vector<Vertex> adjList;
            if (not primFailed) {
                adjList = adjListPrim;
            } else {
                adjList = adjListKruskal;
            }

            vector<int> tour = tsp(adjList, adjList[0]);
            double tourWeight = getTourWeight(tour, adjList, adjMat);

            if (tour.size() != adjList.size()+1) {
                if (verb) {
                    cout << "Test " << ind << ": TSP should be length ";
                    cout << adjList.size()+1 << "." << endl;
                }
                TSPfailed = true;
            }

            if (tour.size() == 0) {
                if (verb) {
                    cout << "Test " << ind << ": No TSP reported.";
                    cout << endl;
                }
                TSPfailed = true;
            } else {
                if (tourWeight > 2*MSTw+2*tol) {
                    if (verb) {
                        cout << "Test " << ind << ": TSP too large.";
                        cout << endl;
                    }
                    TSPfailed = true;
                }
                if (tourWeight <= MSTw-tol) {
                    if (verb) {
                        cout << "Test " << ind << ": TSP too small.";
                        cout << endl;
                    }
                    TSPfailed = true;
                }

                if (tour[0] != tour[tour.size()-1]) {
                    if (verb) {
                        cout << "Test " << ind << ": TSP start != end.";
                        cout << endl;
                    }
                    TSPfailed = true;
                }

                vector<int> counts(adjList.size(),0);
                for (int c=1; c<tour.size(); c++) { // skip repeat, start at 1.
                    counts[tour[c]] += 1;
                }
                for (int i=0; i<counts.size(); i++) {
                    if (counts[i] > 1) {
                        if (verb) {
                            cout << "Test " << ind << ": Repeated City in TSP.";
                            cout << endl;
                        }
                        TSPfailed = true;
                    }
                }
            }

            if (ind == 7) {
                double ans = 40030.173592;
                if ((tourWeight < ans - tol) or (tourWeight > ans + tol)) {
                    if (verb) {
                        cout << "Test " << ind << ": Wrong TSP!";
                        cout << endl;
                    }
                    TSPfailed = true;
                }
            }
            if (ind == 8) {
                double ans = 77925.404593;
                if ((tourWeight < ans - tol) or (tourWeight > ans + tol)) {
                    if (verb) {
                        cout << "Test " << ind << ": Wrong TSP!";
                        cout << endl;
                    }
                    TSPfailed = true;
                }
            }

            if (verb) {
                cout << "Reported Tour Weight: " << tourWeight;
                cout << endl << endl;
                cout << optTour;
                cout << endl << endl;
            }

        } else {
            if (verb) {
                cout << "Test " << ind << ": Wrong MST so no TSP!";
                cout << endl << endl;
            }
            TSPfailed = true;
        }

        // Record results.
        if (not primFailed) {
            primPass += 1;
        }
        if (not kruskalFailed) {
            kruskalPass += 1;
        }
        if (not TSPfailed) {
            tspPass += 1;
            if (verb) {
                cout << "Test " << ind << ": TSP Correct!";
                cout << endl << endl;
            }
        }
    }

    if (verb) {
        cout << "##########################" << endl << endl;
    }

    cout << "Passed " << primPass << "/" << numTests << " Prim Tests, ";
    cout << kruskalPass << "/" << numTests << " Kruskal Tests, ";
    cout << "and " << tspPass << "/" << numTests << " TSP Tests.";
    cout << endl << endl;

    return;
}

/* main
 * 
 * This function will test Prim, Kruskal, and the TSP DFS.
 *
 * Run this function with the command:
 *     ./runTests
 *
 * Note: you can turn on verbosity with a -v flag:
 *     ./runTests -v
 *
 */
int main(int argc, char* argv[]) {
    // Check for verbosity.
    bool verbosity = false;
    for ( int ii=1; ii<argc; ii++ ) {
        if ( strcmp(argv[ii], "-v") == 0 ) {
            // Verbosity flag.
            verbosity = true;
        }
    }
    cout << endl;

    testMaps(verbosity);

    return 0;
}
