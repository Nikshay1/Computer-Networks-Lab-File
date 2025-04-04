#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void stopAndWait(int totalFrames) {
    int ack;
    srand(time(NULL));
    for (int i = 1; i <= totalFrames; i++) {
        cout << "Sending frame " << i << "...\n";
        if (rand() % 2 == 0) {
            cout << "ACK received for frame " << i << "\n";
        } else {
            cout << "Frame " << i << " lost. Retransmitting...\n";
            i--;  // Retransmit the same frame
        }
    }
    cout << "All frames sent successfully!\n";
}

int main() {
    int totalFrames;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;
    stopAndWait(totalFrames);
    return 0;
}
