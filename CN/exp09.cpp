#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void slidingWindow(int totalFrames, int windowSize) {
    int ack, i = 1;
    srand(time(NULL));
    while (i <= totalFrames) {
        int j;
        for (j = i; j < i + windowSize && j <= totalFrames; j++) {
            cout << "Sending frame " << j << "...\n";
        }
        for (j = i; j < i + windowSize && j <= totalFrames; j++) {
            if (rand() % 2 == 0) {
                cout << "ACK received for frame " << j << "\n";
            } else {
                cout << "Frame " << j << " lost. Retransmitting...\n";
                break;
            }
        }
        if (j == i + windowSize || j > totalFrames) {
            i += windowSize;
        } else {
            i = j;  // Retransmit from the lost frame
        }
    }
    cout << "All frames sent successfully!\n";
}

int main() {
    int totalFrames, windowSize;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;
    slidingWindow(totalFrames, windowSize);
    return 0;
}
