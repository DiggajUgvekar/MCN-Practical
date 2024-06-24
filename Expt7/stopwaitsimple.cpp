#include<bits/stdc++.h>
using namespace std;

int arr[5] = {1, 1, 1, 1, 1};

bool simulatePacketLoss() {
    return rand() % 5 == 0; // 20% chance of packet loss
}

void sender() {
    cout<<"Sender:"<<endl;
    int frame = 0;
    bool ackReceived = true;

    while (frame < 5) { // Let's assume we are sending 5 frames
        if (ackReceived) {
            cout << "Sender: Sending frame " << frame << endl;
        }

        cout << "Sender: Waiting for ACK..." << endl;

        // Simulate receiving ACK
        if (simulatePacketLoss()) {
            cout << "Sender: ACK not received for frame " << frame << endl;
            arr[frame] = 0;
            ackReceived = false;
        } else {
            cout << "Sender: ACK received for frame " << frame << endl;
            ackReceived = true;
            frame++;
        }

        if (!ackReceived) {
            cout << "Sender: Timeout, resending frame " << frame << endl;
        }
    }
    cout << "Sender: All frames sent successfully." << endl;
}

void receiver() {
    cout<<endl<<"Receiver:"<<endl;
    int expectedFrame = 0;

    while (expectedFrame < 5) { // Let's assume we are receiving 5 frames
        if (arr[expectedFrame]==0){
            cout << "Receiver: Frame " << expectedFrame << " lost in transit." << endl;
        }
       
        cout << "Receiver: Received frame " << expectedFrame << endl;
        cout << "Receiver: Sending ACK for frame " << expectedFrame << endl;
        expectedFrame++;
    }
}

int main() {
    //srand(time(0)); // Seed for random number generation

    sender();
    receiver();

    return 0;
}
