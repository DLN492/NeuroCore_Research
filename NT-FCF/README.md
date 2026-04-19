# NeuroCore – Controlled Core Disclosure
## Private Technical Core Annex
### Restricted Operational Layer | Confidential

**Classification**: Private Repository Material  
**Distribution**: Restricted  
**Access Condition**: NDA / MNDA or explicit written authorization by the owner  

---

## 1. Scope of This Document

This annex describes the **protected operational core** of the NeuroCore framework at a level sufficient for:

- technical due diligence
- institutional review
- licensing evaluation
- controlled reproducibility assessment

This document is **not** a public implementation guide and must not be interpreted as authorization to reproduce, deploy, redistribute, reverse engineer, or adapt the framework in any form outside explicit written agreement.

---

## 2. Protected Core Definition

Within the NeuroCore ecosystem, the **Core** refers to the non-public operational layer that determines actual functional performance.

It includes:

1. **Signal transformation operators**
2. **Temporal windowing logic**
3. **Stability and transition estimators**
4. **Fusion logic and regime inference sequence**
5. **Preprocessing and label-alignment procedures**
6. **Dataset-specific safeguards against methodological artefacts**
7. **Parameter sets and empirical thresholds**
8. **Validation logic and exclusion criteria**
9. **Implementation modules, notebooks, and experimental kernels**

The public repository may disclose the architectural rationale, but not the full operational reproducibility layer.

---

## 3. Core Architecture Boundary

The NeuroCore framework is divided into two distinct layers:

### A. Public Layer
Contains:
- conceptual architecture
- mathematical intuition
- high-level operator descriptions
- non-sensitive diagrams
- positioning statements
- non-replicable summaries of validation outcomes

### B. Protected Core Layer
Contains:
- executable operational logic
- implementation-specific operator definitions
- window schedules and parameterization
- normalization strategies
- event synchronization rules
- threshold calibration logic
- reproducibility-critical preprocessing
- dataset routing and exclusion logic
- empirical validation routines

Only the **Protected Core Layer** determines practical reproducibility.

---

## 4. Operational Principle

The framework transforms an observed time-series $x(t)$ into a regime-sensitive representation through a layered observation model:

$$
x(t) \rightarrow [\Phi(t), \Delta(t), K(t), L(t), z_E(t)] \rightarrow z(t) \rightarrow \lambda(t)
$$

where:

- $\Phi(t)$ = local dynamical operator
- $\Delta(t)$ = transition-sensitive instability variation
- $K(t)$ = global dispersion/stability proxy
- $L(t)$ = asymptotic functional anchor estimator
- $z_E(t)$ = structured feature-space embedding
- $\lambda(t)$ = inferred functional regime label

This annex does not disclose the full executable mapping used in production-grade notebooks.

---

## 5. Protected Components

### 5.1 Local Operator Layer
Protected content includes:
- effective implementation of $\Phi(t)$
- smoothing/stabilization rules
- finite-window handling
- gradient conditioning
- non-linear compression details
- outlier containment logic

### 5.2 Transition Layer
Protected content includes:
- construction of $\Delta(t)$
- transition gating rules
- temporal persistence constraints
- spike rejection logic
- transition scoring heuristics

### 5.3 Global Stability Layer
Protected content includes:
- computation of $K(t) = \sigma/\mu$
- admissibility constraints
- low-mean instability protections
- variance stabilization logic
- critical threshold handling

### 5.4 Asymptotic Layer
Protected content includes:
- practical estimation of $L(x_t)$
- convergence scheduling
- drift control
- empirical tolerance bounds around $\phi \approx 0.55$
- exclusion of pseudo-convergent windows

### 5.5 Feature Embedding Layer
Protected content includes:
- feature extraction sequence
- structured embedding pipeline
- feature pruning
- dimensionality control
- weighting and integration strategy for $z_E$

### 5.6 Fusion Layer
Protected content includes:
- ordering of fusion operations
- weighting logic between $\Delta, K, L, z_E$
- admissibility conditions
- regime segmentation rules
- confidence scoring procedures

---

## 6. Reproducibility-Critical Hidden Variables

The following elements are considered **core confidential variables** because they materially affect performance:

- temporal window size(s)
- overlap ratio(s)
- threshold schedule(s)
- signal normalization rules
- subject/session exclusion criteria
- event alignment offsets
- baseline construction rules
- train/test segregation logic
- artefact rejection conditions
- adaptive tolerance parameters

Disclosure of these variables is restricted.

---

## 7. Dataset Handling Constraints

The effective performance of NeuroCore depends not only on operators but on **data governance logic**.

Protected handling includes:

- EEG/fNIRS file parsing rules
- event-table reconciliation
- timestamp realignment
- missing-label handling
- subject-wise segregation logic
- invalid-record detection
- anti-leakage safeguards
- anti-artefact validation filters

This is especially critical in contexts where naïve pipelines may generate inflated results (e.g. trivial separability, label leakage, malformed event alignment, unrealistic AUC inflation).

---

## 8. Validation Protection Statement

Any claim derived from NeuroCore must be interpreted only within the validation conditions defined by the owner.

The protected validation layer includes:

- admissible datasets
- accepted preprocessing routes
- benchmark comparison conditions
- exclusion criteria for unreliable runs
- minimum quality thresholds for reporting
- rules distinguishing exploratory from reportable outputs

No third party may claim faithful reproduction without access to the protected validation protocol.

---

## 9. Permitted Review Modes

Access to the protected core may be granted under one of the following review modes:

### Mode 1 – Conceptual Review
Access to:
- architecture
- rationale
- equations
- selected figures

No executable content.

### Mode 2 – Controlled Technical Review
Access to:
- partial notebooks
- selected preprocessing descriptions
- bounded parameter ranges
- redacted implementation details

No unrestricted redistribution.

### Mode 3 – Licensing Evaluation
Access to:
- executable demonstration environment
- curated benchmark outputs
- controlled parameter exposure
- restricted runtime inspection

Use limited to evaluation only.

### Mode 4 – Full Private License Access
Access to:
- agreed implementation subset
- deployment modules
- selected notebooks/scripts
- versioned documentation

Granted only under formal private agreement.

---

## 10. Repository Segmentation Policy

The private NeuroCore repository should remain segmented as follows:

```text
/private-neurocore/
├── README_PRIVATE.md
├── LICENSE_PRIVATE.txt
├── NOTICE_RESTRICTED.txt
├── /docs
│   ├── core_disclosure_annex.md
│   ├── validation_scope.md
│   ├── operator_notes_redacted.md
│   └── access_policy.md
├── /src_redacted
│   ├── interfaces_only/
│   └── pseudocode_only/
├── /notebooks_private
│   ├── controlled_demo.ipynb
│   ├── validation_review.ipynb
│   └── benchmark_notes.ipynb
├── /configs_private
│   ├── ranges_only/
│   └── deployment_profiles/
├── /results_curated
│   ├── reportable_outputs/
│   └── benchmark_exports/
└── /legal
    ├── nda_template_reference.md
    └── licensing_paths.md
