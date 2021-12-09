# IDM - TP6 
## Compilation
On utilise cmake pour la compilation :
```bash
mkdir build && cd build
cmake ..
make
```
## Résultats
### Sans correction 
```cpp
idm::VectorSumCalculator<idm::AccumulateSum<std::plus<double>>>().evaluate(vector);
```
Temps d'exécution : ~60ms


### Somme de Kahan
```cpp 
idm::VectorSumCalculator<idm::AccumulateSum<idm::KahanVectorSum>>().evaluate(vector);
```
Temps d'exécution : ~300ms

### Somme de Kahan Babushka Klein
```cpp
idm::VectorSumCalculator<idm::ForEachSum<idm::KahanBabushkaKleinVectorSum>>().evaluate(vector);
```
Temps d'exécution : ~190ms
