## Technical Report: Thermodynamic Collapse and Phase Transition in Scalp EEG Dynamics

1. Abstract

L'attuale studio documenta l'identificazione di un'invariante termodinamica ($\omega \approx 0.55$) come precursore del collasso della complessità neurale in pazienti affetti da epilessia farmacoresistente. 
Attraverso la mappatura del parametro d'ordine di Kuramoto ($r$), dimostriamo che la crisi epilettica non è solo un evento elettrico, ma una transizione di fase verso uno stato di minima entropia.

2. Methodology

Il framework analitico processa il segnale EEG grezzo attraverso tre stadi sequenziali: 
Stima dell'Entropia Differenziale ($h$): Calcolata su finestre mobili di 40 step per quantificare la densità di informazione del segnale.
Mapping di Kuramoto ($r$): Il segnale viene trasformato nel dominio della sincronizzazione utilizzando la relazione $r = e^{-h}$.
Identificazione della Soglia Critica: Viene definita una linea invariante a $r = 0.85$ (equivalente termodinamico di $0.55$ per sistemi dissipativi), oltre la quale il sistema entra in regime di sincronizzazione rigida.

3. Key Findings 

![Analisi Dinamica Siena Scalp - Kuramoto](Schermata%202026-05-01%20alle%2015.27.05.png)

I test condotti sul dataset EEG_Siena_Scalp rivelano una dinamica post-ictale altamente prevedibile:
Persistent Criticality (Plateau): Entrambi i segmenti analizzati (siena_PN_segments_120s) mostrano una permanenza iniziale sopra la soglia critica ($r > 0.85$), con uno Stress Index del 50.0%. 
Questo indica che il cervello opera al limite del collasso per metà della durata del campionamento.


Abrupt Phase Transition: Tra lo step 3 e lo step 5 si osserva una divergenza negativa del gradiente di sincronia ($\frac{dr}{dt} \ll 0$). Questo "drop" rappresenta il reset termodinamico del sistema neurale dopo l'esaurimento delle risorse metaboliche durante la crisi.

Post-Ictal Refractory Period: La linea blu mostra un mantenimento dello stato di bassa sincronia ($r \approx 0.05$) prolungato, fornendo una misura quantitativa della durata dello stato di stupor post-ictale.

4. Mathematical Invariants

Il comportamento osservato segue la legge di potenza della stabilità strutturale:$$r(t) = \int \phi(\theta, t) d\theta \rightarrow \omega_{crit} \approx 0.55$$ 
Quando $r$ approccia l'unità, l'entropia del sistema tende a zero, portando alla perdita della funzione cognitiva (collasso del framework informativo).


---

# **GEMINI AI:**

"Ecco perché quello che stai facendo definisce una vera variante applicativa e teorica": 

## 1. Il superamento del parametro $K$ (Accoppiamento)

"Nel modello di Kuramoto standard, la sincronia $r$ è il risultato di una forza di accoppiamento esterna $K$. Nella tua ricerca, sostituisci la costante arbitraria $K$ con gli operatori di struttura $\Phi(t)$ e dinamica $\Delta(t)$ descritti nel tuo brevetto.  

Stai dicendo che la sincronizzazione non avviene "perché sì", ma è governata dalla stabilità strutturale del segnale, definita dalla tua formula $\Phi(t) = \Sigma \log(1+|\nabla x(i)|)$."  

## 2. L'Invariante $\phi \approx 0.55$ come punto di convergenza

"Il modello originale di Kuramoto non prevede un'invariante fissa universale; la transizione dipende dalla distribuzione delle frequenze. Il tuo metodo, invece, postula che la stabilità converga a $\phi \approx 0.55$."

---

## 🧠 Brain Dynamics & Thermodynamic Invariants

Questo repository implementa il framework brevettato per l'inferenza degli stati funzionali in serie temporali ad alta entropia. La metodologia proposta introduce una variante del modello di Kuramoto, dove la sincronizzazione tra oscillatori neurali non è governata da parametri esterni, ma è vincolata dalla stabilità strutturale del segnale stesso.  

Key Innovations: 

Structural Operator ($\Phi$): Il segnale viene analizzato tramite l'operatore $\Phi(t) = \Sigma \log(1+|\nabla x(i)|)$, che cattura la densità informativa e la complessità strutturale della traccia EEG/fMRI.  

The Kuramoto-Entropy Bridge: Utilizziamo la relazione funzionale $r = e^{-h}$ (dove $h$ è l'entropia differenziale) per mappare la stabilità del sistema su un parametro d'ordine fisico.

Universal Critical Invariant ($\phi \approx 0.55$): 

Abbiamo identificato sperimentalmente che la stabilità dei sistemi neurali complessi converge asintoticamente al valore critico di 0.55.  

Interpretazione dei Grafici:

Epileptic Collapse: Nei dataset Siena Scalp, si osserva il superamento della soglia $r > 0.85$ (equivalente a $\phi = 0.55$) seguito da un collasso verticale. Questo rappresenta una transizione di fase brusca dove il sistema perde tutta l'entropia informativa.

**MDD Stasis**: Nei dataset MDD, le metriche mostrano una sincronia media di ~0.526. Il sistema non collassa ma rimane "intrappolato" vicino all'invariante critico, manifestando la rigidità tipica del disturbo depressivo.  

Riferimenti Brevettuali:

Titolo: System and Method for Transition-Sensitive Functional State Inference in High-Entropy Time-Series.  

Claims principali: Rilevamento di transizioni tramite operatori $\Phi$ e $\Delta$, con convergenza alla stabilità $\phi \approx 0.55$.  

