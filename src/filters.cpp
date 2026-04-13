#include <vector>

extern "C" {
    // A simple function to smooth out noisy signal arrays
    void moving_average(double* input_signal, double* output_signal, int length, int window_size) {
        for (int i = 0; i < length; i++) {
            double sum = 0.0;
            int count = 0;
            for (int j = 0; j < window_size; j++) {
                if (i - j >= 0) {
                    sum += input_signal[i - j];
                    count++;
                }
            }
            output_signal[i] = sum / count;
        }
    }
}