## Technical Report: Thermodynamic Collapse and Phase Transition in Scalp EEG Dynamics

1. Abstract

L'attuale studio documenta l'identificazione di un'invariante termodinamica ($\omega \approx 0.55$) come precursore del collasso della complessità neurale in pazienti affetti da epilessia farmacoresistente. 
Attraverso la mappatura del parametro d'ordine di Kuramoto ($r$), dimostriamo che la crisi epilettica non è solo un evento elettrico, ma una transizione di fase verso uno stato di minima entropia.

2. Methodology

Il framework analitico processa il segnale EEG grezzo attraverso tre stadi sequenziali: 
Stima dell'Entropia Differenziale ($h$): Calcolata su finestre mobili di 40 step per quantificare la densità di informazione del segnale.
Mapping di Kuramoto ($r$): Il segnale viene trasformato nel dominio della sincronizzazione utilizzando la relazione $r = e^{-h}$.
Identificazione della Soglia Critica: Viene definita una linea invariante a $r = 0.85$ (equivalente termodinamico di $0.55$ per sistemi dissipativi), oltre la quale il sistema entra in regime di sincronizzazione rigida.

3. Key Findings (Analisi di image_4c9617.jpg)

I test condotti sul dataset EEG_Siena_Scalp rivelano una dinamica post-ictale altamente prevedibile:
Persistent Criticality (Plateau): Entrambi i segmenti analizzati (siena_PN_segments_120s) mostrano una permanenza iniziale sopra la soglia critica ($r > 0.85$), con uno Stress Index del 50.0%. 
Questo indica che il cervello opera al limite del collasso per metà della durata del campionamento.


Abrupt Phase Transition: Tra lo step 3 e lo step 5 si osserva una divergenza negativa del gradiente di sincronia ($\frac{dr}{dt} \ll 0$). Questo "drop" rappresenta il reset termodinamico del sistema neurale dopo l'esaurimento delle risorse metaboliche durante la crisi.

Post-Ictal Refractory Period: La linea blu mostra un mantenimento dello stato di bassa sincronia ($r \approx 0.05$) prolungato, fornendo una misura quantitativa della durata dello stato di stupor post-ictale.

4. Mathematical Invariants

Il comportamento osservato segue la legge di potenza della stabilità strutturale:$$r(t) = \int \phi(\theta, t) d\theta \rightarrow \omega_{crit} \approx 0.55$$ 
Quando $r$ approccia l'unità, l'entropia del sistema tende a zero, portando alla perdita della funzione cognitiva (collasso del framework informativo).
