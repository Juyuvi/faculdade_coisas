# Exercício 605 do Leetcode, "Can Place Flowers"

A ideia é que recebemos um canteiro de flores com espaços individuais para uma, alguns já ocupados, e um número de flores para tentarmos inserir no canteiro. No entanto, todas as flores devem ter pelo menos 1 espaço de distância dos dois lados de outras flores. Ou seja, todas flores devem ser inseridas sem adjacência.

Meu primeiro código passou em testes comuns, mas falhava em testes extremos. Ele foi escrito tentando seguir uma regra matemática que não estava 100% correta. Basicamente, estava procurando que o sufixo e prefixo 0's deviam ser pares e as sequências de 0's do meio deveriam ser ímpares, e com essa ideia seria "possível" encontrar o número de lugares possíveis para plantar.

Depois de chegar em casa, e pesquisar um pouco, pude entender o que estava errado em meu approach e reescrever o código (ainda tentando seguir uma lógica matemática, explicarei mais depois), depois de uma noite bem dormida, e o código atual passa em todos os test cases do Leetcode:

![Test cases completos](https://imgur.com/WBSvx4j.png)

De acordo com a I.A. do site, ele tem a complexidade de tempo de O(n) (linear):
![Time complexity de acordo com a IA do leetcode](https://imgur.com/nbqOzXM.png)

## Aprroach do código escrito durante a aula

A ideia inicial era pegar a sequência de zeros no sufixo e prefixo, então dividir pelo maior número par, para ter o número de espaços disponíveis neles.

exemplo: se o número da sequência inicial (sufixo) de zeros fosse 5, iria ser calculado (avaPlots == Available Plots): avaPlots += (int) 5 / 2. (2 pares de 2, logo, 2 espaços disponíveis)

E uma ideia semelhante para o meio, mas invés de contabilizar a cada número par de espaços, seria contabilizado a cada número ímpar (maior que 1) de espaços.

## Problemas da primeira abordagem (durante a aula)

A ideia de que o sufixo e prefixo deveriam ser um número minimamente par e o meio ímpar não exatamente estava correto, o que, conforme comentei anteriormente, causava muitos problemas nos casos extremos específicos, tendo que adicionar if's e else's para essas exceções.

Casos como flowerbed = [1], [0], [0, 0, 0] e [1, 1, 1] facilmente quebravam o algoritmo. Então claramente ele tava seguindo uma regra com tantas exceções que não daria pra chamar de regra.

## Approach dos outros

Depois de não conseguir passar em todos os test cases do leetcode (principalmente por causa dos casos extremos), dei uma olhada [nesse](https://www.youtube.com/watch?v=WEtHB3Ewc8I) e [nesse](https://www.youtube.com/watch?v=ZGxqqjljpUI) vídeo, para entender a lógica usada por outros, para entender o que eu deveria ter feito e por que meu código não funcionava completamente.

A principal diferença que notei, era:
1. O canteiro de flores era visualizado literalmente como um canteiro, e cada flor posta no array, era literalmente nele inserida se houvesse o espaço necessário (checando se não haviam flores adjacentes).
2. A ideia de que, no array, haviam espaços vazios nos extremos do canteiro, além do array dado.
3. Havia uma constante checagem dos espaços adjacentes, direito e esquerdo, na hora de inserir uma flor no canteiro.

## Como a abordagem dos outros me ajudou entender o que estava de errado no meu

Desde o início, eu estava tendo uma visão puramente matemática e numérica do canteiro, invés de realmente imaginar um canteiro e flores sendo postas nos espaços 1 por 1. Além disso, também encarei os espaços dos extremos do canteiro como um padrão à parte, enquanto, imaginando como se fosse outro canteiro com espaços vazios invisível, era possível aplicar a mesma regra para todos intevalos do array.

Então cheguei na ideia que a sequência de espaços vazios resultaria em um espaço disponível a cada momento que a sequência atingisse um número ímpar maior que um. Isso visualizando o canteiro com mais dois espaços vazios nos dois extremos.

```
if ( !( currZeroSequence % 2 == 0 ) && ( currZeroSequence > 1 ) ) {
    avaPlots++;
}
```

E ao tentar implementar esse algoritmo... funcionou 🥳.

## Por que decidi usar uma abordagem semelhante a anteriormente falha

Pode parecer (e realmente ser) burrice tentar uma abordagem seguindo quase a mesma lógica da que antes falhou, invés de só aceitar e seguir a ideia de outros, que consistia principalmente em checar os elementos adjacentes e alterar o valor do array (realmente colocando uma flor no canteiro). Mas isso significaria jogar completamente a lógica que pensei fora (que não estava 100% errada) e só copiar de outros que já realizaram o exercício, o que não sou fã.

Além disso, eu estava tentando, desde a primeira abordagem, não alterar o array e seguir um padrão numérico para fazer o mínimo de checagens possíveis (pode não parecer, mas o código original era para ser enxuto).

No fim, como minha nova abordagem funcionou, preferi defender minha ideia inicial do que apenas copiar, pois não iria me sentir bem caso contrário.

## Por que funciona

Se considerarmos a existência de dois espaços vazios nos extremos do canteiro, o número mínimo de espaços disponíveis para inserir uma flor é um número ímpar maior que 1, ou seja, 3. Independente de onde a sequência de espaços se encontra, e cada 2 espaços novos na sequência (ou seja, o próximo número ímpar) se torna possível inserir mais uma flor.

Casos como flowerbed = [0] são tratados como se houvesse uma sequência de 3 espaços vazios. E casos como flowerbed = [0, 0, 0], são tratados como se houvessem 5, tornando possível aplicar a regra encontrada.

Por outro lado, outros casos extremos como flowerbed = [1] ou [1, 1, 1] são facilmente eliminados como possbilidades pois não nenhuma sequência ímpar maior que 1 disponível.

and it works.
