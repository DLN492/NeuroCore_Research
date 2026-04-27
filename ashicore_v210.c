/**
 * ASHI-CORE KERNEL v2.1.0 - INDUSTRIAL DUAL-USE
 * (C) 2026 Nicoletti Davide Luca
 *
 * Description: High-precision adaptive engine for Phase Transition Detection
 * using the Nicoletti Critical Threshold (Kc) and Welford's Robust Variance.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* --- ENCAPSULATION LAYER --- */
/* The static keyword ensures these variables are only visible within this binary. */
static const double ASHI_KC_INTERNAL = 1.441;
static const double PHI_ANCHOR_ASYMPTOTIC = 0.55;

typedef struct {
    long count;          // Sample size
    double mean;         // Rolling Mean (mu)
    double m2;           // Sum of squares of differences
    double last_sigma;   // Current Standard Deviation
    double kc;           // Injected constant for inference
} AshiAdaptiveKernel;

/* --- SCIENTIFIC ENGINE: WELFORD'S ALGORITHM --- */
/*
 * Welford's algorithm is used for numerically stable variance calculation.
 * It prevents catastrophic cancellation in floating-point math, critical
 * for defense-grade sensor telemetry.
 */
static void _update_statistics(AshiAdaptiveKernel *k, double new_value) {
    k->count++;
    double delta = new_value - k->mean;
    k->mean += delta / k->count;
    double delta2 = new_value - k->mean;
    k->m2 += delta * delta2;

    if (k->count > 1) {
        k->last_sigma = sqrt(k->m2 / (k->count - 1));
    } else {
        k->last_sigma = 0.0;
    }
}

/* --- DUAL-USE INFERENCE INTERFACE --- */

/**
 * Initializes the kernel state.
 */
void ashi_kernel_init(AshiAdaptiveKernel *k) {
    k->count = 0;
    k->mean = 0.0;
    k->m2 = 0.0;
    k->kc = ASHI_KC_INTERNAL;
    k->last_sigma = 0.0;
}

/**
 * Process a single data point and return the Transition Alert status.
 * @return 1 if Percolation/Criticality detected, 0 otherwise.
 */
int ashi_kernel_compute_step(AshiAdaptiveKernel *k, double input_value) {
    _update_statistics(k, input_value);

    if (k->count < 2) return 0;

    // Threshold Calculation based on Nicoletti's Universal Constant
    double dynamic_threshold = k->mean + (k->last_sigma * k->kc);

    // Phase Transition Detection
    if (input_value > dynamic_threshold) {
        return 1; // CRITICAL ALERT
    }
    return 0; // SYSTEM STABLE
}

/* --- DEMO ENTRY POINT --- */
int main() {
    AshiAdaptiveKernel engine;
    ashi_kernel_init(&engine);

    // Professional Simulation Stream
    double data_stream[] = {10.0, 10.2, 9.8, 10.1, 12.5, 15.0, 18.2}; 
    int size = sizeof(data_stream) / sizeof(data_stream[0]);

    printf("==========================================\n");
    printf("   ASHI-CORE v2.1.0 - ADAPTIVE RUN        \n");
    printf("   Propriety of Nicoletti Davide Luca     \n");
    printf("==========================================\n\n");

    for (int i = 0; i < size; i++) {
        int alert = ashi_kernel_compute_step(&engine, data_stream[i]);
        
        printf("[T+%d] In: %6.2f | Mu: %6.2f | Sigma: %6.2f | Status: %s\n", 
               i, data_stream[i], engine.mean, engine.last_sigma, 
               alert ? "!!! CRITICAL TRANSITION !!!" : "STABLE");
    }

    printf("\nProcess completed. Kernel Halted.\n");
    return 0;
}
