# NeuroCore Unified Kernel

An advanced, lightweight neurophysiological data ingestion and feature engineering framework designed for real-time brain state transition mapping and robust biomarker extraction from multi-format EEG data.

---

## 🧠 Overview
Traditional EEG classification pipelines increasingly rely on heavy, black-box Deep Learning architectures that demand massive computational power and lack clinical explainability.

The **NeuroCore Unified Kernel** addresses this bottleneck by leveraging principles of statistical physics and nonlinear dynamics—specifically focusing on convergence toward the **Kuramoto Critical Invariant**. It extracts highly predictive, high-frequency deterministic features capable of capturing critical state transitions (such as epileptic seizure onset or motor imagery signatures) with minimal computational overhead, making it ideal for Edge AI and continuous clinical monitoring applications.

---

## 🛠️ Key Features
* **Multi-Format Ingestion Pipeline:** Standardized, BIDS-compliant parsing for highly heterogeneous clinical and neuroscientific data formats including EEGLAB (`.set`/`.fdt`), BrainVision (`.vhdr`), and standard `.edf` files.
* **Nonlinear Evolutionary Operators:** Implements a specialized computational engine that extracts deterministic dynamical metrics:
  * $\Phi(t)$: Local signal complexity mapping.
  * $\Delta(t)$: Complexity gradient, optimized as a mathematical *early-warning* indicator.
  * $K(t)$: Dynamic variance-to-mean ratio ($\sigma / \mu$) designed to track abrupt statistical collapses during ictal states.
  * $L(t)$: Logistic normalized energy function constrained within a stable $[0, 1]$ phase space.
* **Predictive Transition Scoring:** Combines evolutionary operators into a unified `TransitionScore` capable of calculating early predictive *Lead Times* prior to acute neurological events.
* **Robust by Design:** Native mitigation of motion and channel artifacts using a Mediana/MAD-driven **Robust Z-Score** normalization layer, ensuring high signal fidelity across diverse experimental paradigms (e.g., tACS post-stroke language tasks, tDCS motor imagery).

---

## 📊 Repository Structure
* `/notebooks`: Contains core development environments (`NCResearch.ipynb`, validation pipelines, and multi-dataset experiments).
* `/signatures`: Output location for extracted digital neurophysiological signatures (e.g., `TDCS_MI_signature.csv`).
* `/reports`: Automated clinical and statistical summary exports in PDF format.

---

## ☣️ Dataset & Privacy Note
This repository contains only the framework logic, algorithmic notebooks, and aggregated features. Raw clinical data blocks (including CHB-MIT and IRCCS stroke rehabilitation datasets) are excluded to fully comply with GDPR/HIPAA regulations and institutional data privacy requirements.
