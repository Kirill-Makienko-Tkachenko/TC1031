#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> // For sorting
#include "listas_t.h"

using namespace std;

int main() {
    ifstream file("bitacora2.csv"); // Replace "bitacora2.csv" with the actual CSV file name

    if (!file.is_open()) {
        cerr << "Failed to open the CSV file." << endl;
        return 1;
    }

    string line;
    vector<string> headers;
    map<string, int> ipAddressCount; // Use a map to store IP addresses and their counts

    // Read the header row
    if (getline(file, line)) {
        istringstream headerStream(line);
        string header;
        while (getline(headerStream, header, ',')) {
            headers.push_back(header);
        }
    }

    // Find the index of the column named "ip"
    int ipColumnIndex = -1;
    for (int i = 0; i < headers.size(); ++i) {
        if (headers[i] == "ip") {
            ipColumnIndex = i;
            break;
        }
    }

    if (ipColumnIndex == -1) {
        cerr << "Column named 'ip' not found in the CSV file." << endl;
        return 1;
    }

    // Create a linked list to store IP counts
    List<string, int> ipCountList;

    // Read the IP addresses from the "ip" column and count occurrences
    while (getline(file, line)) {
        istringstream lineStream(line);
        string cell;
        int columnIndex = 0;

        while (getline(lineStream, cell, ',')) {
            if (columnIndex == ipColumnIndex) {
                // Process the "ip" column containing the IP addresses
                // Assuming each cell contains a single IP address
                ipAddressCount[cell]++; // Increment the count for this IP address
                string* ip = &cell;
                int count = 1;
                // Check if the IP address already exists in the list
                if (ipCountList.find(&ip)) {
                    // If it exists, update the count
                    Nodo<string, int>* existingNode = ipCountList.getFirst();
                    while (existingNode != nullptr) {
                        if (existingNode->getInfo() == ip) {
                            existingNode->setInfo2(existingNode->getInfo2() + count);
                            break;
                        }
                        existingNode = existingNode->getSig();
                    }
                } else {
                    // If it doesn't exist, add it to the list
                    ipCountList.addBoth(ip, count);
                }
            }
            columnIndex++;
        }
    }

    file.close();

    // Print the IP counts from the linked list
    Nodo<string, int>* currentNode = ipCountList.getFirst();
    while (currentNode != nullptr) {
        cout << "IP Address: " << *(currentNode->getInfo()) << " Count: " << currentNode->getInfo2() << endl;
        currentNode = currentNode->getSig();
    }

    return 0;
}
