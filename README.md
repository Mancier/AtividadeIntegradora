# Pipeline Calculation
Esse projeto faz calcúlos de pipeline escalar e superescalar, uma atividade solicitada pela faculdade.
```
Type: int => Tipo de pipeline __1 - Escalar__, __2 - Superescalar__
Cores: int => Quantidade de Núcleos para o processamento
Total of Stages: int => Quantidade total de Estágios(fases) da pipeline
Stages: [int] => Cada estágio tem um tempo, sendo assim, coloque no array os valores de acordo com a fase de modo sequencial
Instrucions: int => Total de Instruções
```
## Exemplo
```
Type: 2
Cores: 2
Total of Stages: 5
Stages: [5,3,6,2,4]
Instructions: 5
```