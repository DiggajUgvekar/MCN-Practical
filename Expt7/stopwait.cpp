#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Simulated transmission delay
const int TRANSMISSION_DELAY = 1000; // in milliseconds

// Simulated ACK/NACK loss probability
const double ACK_LOSS_PROBABILITY = 0.1;

// Sliding window size
const int WINDOW_SIZE = 3;

// Timeout duration in milliseconds
const int TIMEOUT_DURATION = 2000;

// Packet structure
struct Packet {
    int sequenceNumber;
    bool isAcked;
    string data;
};

// Function to simulate transmission delay
void delay(int milliseconds) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

// Function to simulate ACK/NACK loss
bool isAckLost() {
    return (rand() / (RAND_MAX + 1.0)) < ACK_LOSS_PROBABILITY;
}

// Sender function
void sender(Packet packets[], int numPackets) {
    int base = 0;
    int nextSeqNum = 0;

    while (base < numPackets) {
        // Send packets in the window
        for (int i = base; i < min(base + WINDOW_SIZE, numPackets); ++i) {
            if (!packets[i].isAcked) {
                // Simulate transmission delay
                delay(TRANSMISSION_DELAY);
                cout << "Sending packet with sequence number " << packets[i].sequenceNumber << endl;
            }
        }

        // Receive ACKs
        for (int i = base; i < min(base + WINDOW_SIZE, numPackets); ++i) {
            if (!packets[i].isAcked) {
                // Simulate ACK loss
                if (!isAckLost()) {
                    cout << "Received ACK for packet with sequence number " << packets[i].sequenceNumber << endl;
                    packets[i].isAcked = true;
                    nextSeqNum = max(nextSeqNum, packets[i].sequenceNumber + 1);
                }
            }
        }

        // Move the base
        while (base < numPackets && packets[base].isAcked) {
            ++base;
        }
    }
}

// Receiver function
void receiver(Packet packets[], int numPackets) {
    int expectedSeqNum = 0;

    for (int i = 0; i < numPackets; ++i) {
        // Simulate transmission delay
        delay(TRANSMISSION_DELAY);

        // Simulate packet loss
        if (!isAckLost()) {
            if (packets[i].sequenceNumber == expectedSeqNum) {
                cout << "Received packet with sequence number " << packets[i].sequenceNumber << endl;
                ++expectedSeqNum;
            }
            // Send ACK
            cout << "Sending ACK for packet with sequence number " << packets[i].sequenceNumber << endl;
        } else {
            cout << "Packet with sequence number " << packets[i].sequenceNumber << " lost." << endl;
        }
    }
}

int main() {
    srand(time(0)); // Initialize random seed

    // Number of packets to be sent
    const int numPackets = 10;

    // Generate packets with sequence numbers and random data
    Packet packets[numPackets];
    for (int i = 0; i < numPackets; ++i) {
        packets[i].sequenceNumber = i;
        packets[i].isAcked = false;
        packets[i].data = "Packet " + to_string(i);
    }
    // Simulate sender and receiver
    cout << "Sender:" << endl;
    sender(packets, numPackets);

    cout << "\nReceiver:" << endl;
    receiver(packets, numPackets);

    return 0;
}
