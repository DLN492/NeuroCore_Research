# NeuroCore – Functional State Inference

A **domain-agnostic computational framework** for detecting and tracking **functional state transitions** in high-entropy time-series.

---

## Overview

NeuroCore models a signal not only by its instantaneous value, but by its **structural stability over time**.  
The framework separates:

- **Observation layer**: raw signal \( x(t) \)  
- **Functional layer**: latent regime \( z(t) \)

\[
x(t) \rightarrow z(t)
\]

The goal is to identify **when** a system is stable, **when** it is transitioning, and **how** its internal organization evolves.

---

## Core Operators

NeuroCore relies on a minimal set of operators:

### 1. Local Dynamics (Φ)
\[
\Phi(t) = \sum_{i=t-\tau}^{t} \log\left(1 + |\nabla x(i)|\right)
\]

Captures **local structural variation** in the signal.

---

### 2. Transition Sensitivity (Δ)
\[
\Delta(t) = |\Phi(t) - \Phi(t-1)|
\]

Detects **temporal instability** and abrupt changes.

---

### 3. Global Stability (K)
\[
K(t) = \frac{\sigma}{\mu}
\]

Provides a **dispersion-based proxy** of system stability.

---

### 4. Asymptotic Operator (L)

\[
\lim_{t \to \infty} L(x_t) = \phi
\quad \text{with} \quad \phi \approx 0.55
\]

The **L-operator** estimates an **asymptotic stability anchor**:

- Stable regimes → convergence toward \( \phi \approx 0.55 \)  
- Transitional regimes → deviation from the anchor  

This acts as a **baseline of functional organization**, independent of signal amplitude or domain-specific features.

---

## Functional Interpretation

The system produces a fused representation:

\[
z(t) = [\Delta(t), K(t), L(t), z_E(t)]
\]

which is mapped to a regime label:

\[
\lambda(t) = f(z(t))
\]

This enables:
- **state segmentation**
- **transition detection**
- **stability tracking**

---

## Why the Asymptotic Operator Matters

The asymptotic anchor \( \phi \approx 0.55 \) provides:

- A **reference baseline** for functional stability  
- A **domain-independent comparator**  
- A way to detect **deviation from organized states**

Instead of measuring absolute values, NeuroCore measures:
> how far a system is from its **functional equilibrium**

---

## Application Domains (Dual-Use Nature)

NeuroCore is inherently **dual-use**, as it operates on general time-series structure.

### Biomedical Signals
- EEG / fNIRS analysis  
- anesthesia and consciousness transitions  
- functional state monitoring  

### Industrial & Complex Systems
- anomaly detection in high-noise environments  
- stability tracking in telemetry streams  

### Research & Computational Modeling
- regime detection in stochastic systems  
- phase-transition analysis  

> Note: this repository focuses on **scientific and analytical use cases**.  
> Any high-security or restricted applications are outside the scope of the public release.

*The framework exhibits a dual interpretative capability, where non-ideal signal conditions (including artifacts) are not merely treated as noise, but as informative perturbations enabling the simultaneous evaluation of structural stability and transition sensitivity.*


---

## Positioning

NeuroCore is not a classifier and not a traditional signal-processing pipeline.

It is a **transition-sensitive regime inference framework** that shifts analysis from:

\[
\text{signal value} \rightarrow \text{functional organization}
\]

---

## Repository Structure

- `/NeuroCore/` → core concepts, documentation, controlled materials  
- `/Data/` → dataset references and links  
- `/Zenodo/` → archived releases and technical documents  

---

## License & Usage

This repository is intended for:
- research
- evaluation
- conceptual exploration

Full operational implementations and validated pipelines are **not publicly distributed**.

---

## Disclaimer

Results depend on:
- dataset quality  
- preprocessing integrity  
- correct event alignment  

Improper pipelines may produce misleading outcomes (e.g. inflated metrics).


---

## Author

*Nicoletti Davide Luca*
